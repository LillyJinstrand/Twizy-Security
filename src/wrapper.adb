package body Wrapper
    with SPARK_Mode
is
    procedure Init is
    begin
        if not (Safe) then
            -- Runnin init in a non fresh state is wrong
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
        if Convert_C_Bool(localization_estimate.valid_pose) then
            null;
            --Safe := gpsModule.gpstest(localization_estimate.pose.position.x, localization_estimate.pose.position.y);
        end if;
        null;
    end Update_GPS;

    procedure Update_Speed(speed : in speed_ada) is
    begin 
        if not (Convert_C_Bool(speed.valid_speed)) then
            return;
        end if;
        if not (speedModule.speedtest(speed_ada_to_speed(speed)) = True) then
            Safe := False;
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
