with Ada.Numerics.Generic_Elementary_Functions;

package body Mathutil with SPARK_Mode => Off is

	function ArcTan(X : FloatingNumber) return FloatingNumber
	is
	   package FloatingMath is
		  new Ada.Numerics.Generic_Elementary_Functions(FloatingNumber);
	begin
	   return FloatingMath.ArcTan(X);
	end ArcTan;

	function Sqrt(X : FloatingNumber) return FloatingNumber
	is
	   package FloatingMath is
		  new Ada.Numerics.Generic_Elementary_Functions(FloatingNumber);
	begin
	   return FloatingMath.Sqrt(X);
	end Sqrt;

end;
