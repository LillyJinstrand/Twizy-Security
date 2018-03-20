package body Interface_utils
    with SPARK_Mode
is
    function Convert_C_Bool(input : Extensions.bool) return Boolean
    is
    begin
        if (input > 0) then
            return True;
        else 
            return False;
        end if;
    end Convert_C_Bool;
begin
    null;
end Interface_utils;
