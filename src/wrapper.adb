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

    procedure Update_Perception is
    begin
        null;
    end Update_Perception;

    procedure Update_GPS is
    begin
        null;
    end Update_GPS;

    procedure Update_Speed is
    begin 
        null;
    end Update_Speed;

    function Is_Safe return Boolean
    is
    begin
        return True;
    end Is_Safe;

begin
    null;
end Wrapper;
