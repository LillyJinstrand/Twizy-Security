package Wrapper
    with SPARK_Mode
is
    Initialized : Boolean := False;
    procedure Init_ada 
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
    function Update_ada return Boolean 
    with 
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_ada";
    
end Wrapper;
