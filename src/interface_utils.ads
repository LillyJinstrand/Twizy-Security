with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;

package Interface_utils
    with SPARK_Mode
is
    function Convert_C_Bool(input : in Extensions.bool) return Boolean
    with
        Global => Null;
end Interface_utils;
