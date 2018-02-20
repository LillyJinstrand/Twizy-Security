package Wrapper
    with SPARK_Mode
is
    Initialized : Boolean := False;
    -- Here should any initialzation code be run
    procedure Init 
    with 
        Global => (In_Out => Initialized),
        Convention => C,
        Export,
        External_Name => "init_ada";
    -- Simply returns if the init function has been run or not
    function Is_Initialized return Boolean
    with
        Global => (Input => Initialized),
        Convention => C,
        Export,
        External_Name => "is_initialized_ada";

    -- This block is the callback functions for the c++ wrapper to attatch to the ROS topics
    procedure Update_Perception
    with
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_perception_ada";
    procedure Update_GPS
    with
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_gps_ada";
    procedure Update_Speed
    with
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_speed_ada";

    -- Returns whether we are safe or not
    -- The result is based on the last run of the callback functions
    -- Once it has switched to unsafe, it will not switch back without resetting
    function Is_Safe return Boolean 
    with 
        Global => Null,
        Convention => C,
        Export,
        External_Name => "is_safe_ada";
    
end Wrapper;
