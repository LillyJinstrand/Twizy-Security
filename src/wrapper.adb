with Interface_utils; use Interface_utils;
with speedModule; use speedModule;
with converters; use converters;
with Interfaces.C; use Interfaces.C;
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
        Initialized := True;
    end Init;

    function Is_Initialized return Boolean
    is
    begin
        return Initialized;
    end Is_Initialized;

    procedure Update_Perception
        (perception_data : in perception_obstacle_ada) 
    is
    begin
        null;
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
            null;
            --Safe := gpsModule.gpstest(localization_estimate.pose.position.x, localization_estimate.pose.position.y);
            return;
        end if;
        -- Gps values are compleately wrong meaning we can't trust it. 
        -- The car cannot function without the gps so we brake.
        Safe := False;
    end Update_GPS;

    procedure Update_Speed(speed : in speed_ada) is
    begin 
        if not (Convert_C_Bool(speed.valid_speed)) then
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
        end if;
    end Update_Speed;

    function Is_Safe return Boolean
    is
    begin
        return Safe;
    end Is_Safe;

begin
    null;
end Wrapper;
