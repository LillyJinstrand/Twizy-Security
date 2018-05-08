with Interface_utils; use Interface_utils;
with speedModule; use speedModule;
with converters; use converters;
with Interfaces.C; use Interfaces.C;
with perception;
package body Wrapper
    with SPARK_Mode
is
    procedure Init is
    begin
        if not (Safe) then
            -- Running init in a non fresh state is wrong
            Initialized := False;
            return;
        end if;
        CurrentSpeed := 0.0;
        Initialized := True;
        -- Busy-wait until we have recived data from all sensors

    end Init;

    procedure WaitForData is
    begin
        null;
    end WaitForData;

    function Is_Initialized return Boolean
    is
    begin
        return Initialized;
    end Is_Initialized;

    procedure Update_Perception
        (perception_data : in perception_obstacle_ada)
    is
    begin
        if (CurrentSpeed < 0.0) then
            -- Our sensors and logic does not work if we are reversing
            -- Therefore it should not be done in autonomus mode
            Safe := False;
        else
            pragma Assume (CurrentSpeed >= 0.0);
            if not perception.PerceptionCheck(perception_data, CurrentPosition, CurrentSpeed) then
                -- PerceptionCheck reports not safe, set safe to false
                Safe := False;
            end if;
            LastPerceptionTimestamp := perception_data.timestamp;
        end if;
    end Update_Perception;

    procedure Update_GPS
        (localization_estimate : in localization_estimate_ada)
    is
    begin
        if Convert_C_Bool(localization_estimate.valid_pose)
            -- TODO: These checks are wrong, fix after talking to perception
            --and ( localization_estimate.pose.position.x < 180.0 and localization_estimate.pose.position.x > -180.0)
            --and ( localization_estimate.pose.position.y < 90.0 and localization_estimate.pose.position.y > -90.0)
        then
            --Safe := gpsModule.gpstest(localization_estimate.pose.position.x, localization_estimate.pose.position.y);
            CurrentPosition := localization_estimate.pose;
            LastPositionTimestamp := localization_estimate.measurement_time;
            return;
        end if;
        -- Gps values are compleately wrong meaning we can't trust it.
        -- The car cannot function without the gps so we brake.
        Safe := False;
    end Update_GPS;

    procedure Update_Speed(speed : in speed_ada) is
    begin
        if not (Convert_C_Bool(speed.valid_speed) and not Convert_C_Bool(speed.valid_timestamp)) then
            return;
        end if;
        if not (speed.speed > -80.0 and speed.speed < 80.0) then
            -- Data is way out of range, so we assume something is wrong
            Safe := False;
            return;
        else
            if not (speedModule.speedtest(speed_ada_to_speed(speed))) then
                -- Speed check fails
                -- Set safe to false to brake
                Safe := False;
            end if;
            -- Update the cached value of the current speed
            CurrentSpeed := speed_ada_to_speed(speed);
            LastSpeedTimestamp := speed.timestamp;
        end if;
    end Update_Speed;

    procedure CheckTimestamps(currentTime : in Interfaces.C.double) is
    begin
        pragma Assume (currentTime > 0.0);
        pragma Assume (LastSpeedTimestamp > 0.0);
        pragma Assume (LastPositionTimestamp > 0.0);
        pragma Assume (LastPerceptionTimestamp > 0.0);
        if (currentTime - LastSpeedTimestamp > MaxSpeedDelay) or
            (currentTime - LastPositionTimestamp > MaxPositionDelay) or
            (currentTime - LastPerceptionTimestamp > MaxPerceptionDelay)
        then
            Safe := False;
            return;
        end if;
    end CheckTimestamps;

    function Is_Safe return Boolean
    is
    begin
        return Safe;
    end Is_Safe;

begin
    null;
end Wrapper;
