package Wrapper
    with SPARK_Mode
is
    Initialized : Boolean := False;
    procedure Init 
    with 
        Global => (In_Out => Initialized),
        Convention => C,
        Export,
        External_Name => "init_ada";
    function Is_Initialized return Boolean
    with
        Global => (Input => Initialized),
        Convention => C,
        Export,
        External_Name => "is_initialized_ada";

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
    function Update return Boolean 
    with 
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_ada";
    
end Wrapper;
