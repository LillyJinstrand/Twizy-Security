package Wrapper
    with SPARK_Mode
is
    procedure Init_ada 
    with 
        Global => Null,
        Convention => C,
        Export,
        External_Name => "init_ada";
    function Update_ada return Boolean 
    with 
        Global => Null,
        Convention => C,
        Export,
        External_Name => "update_ada";
    
end Wrapper;
