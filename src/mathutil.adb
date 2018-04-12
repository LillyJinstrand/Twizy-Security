with Ada.Numerics.Generic_Elementary_Functions;

package body Mathutil with SPARK_Mode => Off is
	package FloatingMath is
		new Ada.Numerics.Generic_Elementary_Functions(FloatingNumber);

	function ArcTan(Y : FloatingNumber; X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.ArcTan(Y / X, 1.0, 360.0);
	end ArcTan;

	function Sin(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Sin(X, 360.0);
	end;

	function Cos(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Cos(X, 360.0);
	end;

	function Tan(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Tan(X, 360.0);
	end;

	function Sin_r(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Sin(X);
	end;

	function Cos_r(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Cos(X);
	end;

	function Tan_r(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Tan(X);
	end;

	function Sqrt(X : FloatingNumber) return FloatingNumber
	is
	begin
	   return FloatingMath.Sqrt(X);
	end Sqrt;

end;
