package body Wrapper
    with SPARK_Mode
is
    procedure Init is
    begin
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
        Valid_id_test := Convert_C_Bool(perception_data.valid_id);
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

    procedure Update_Speed is
    begin 
        null;
    end Update_Speed;

    function Is_Safe return Boolean
    is
    begin
        return Safe;
    end Is_Safe;

begin
    null;
end Wrapper;
