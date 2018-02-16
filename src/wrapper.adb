package body Wrapper
    with SPARK_Mode
is
    procedure Init_ada is
    begin
        Initialized := True;
    end Init_ada;

    function Is_Initialized return Boolean
    is
    begin
        return Initialized;
    end Is_Initialized;

    function Update_ada return Boolean
    is
    begin
        return True;
    end Update_ada;

begin
    null;
end Wrapper;
