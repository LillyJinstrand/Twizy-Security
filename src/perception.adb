with Ada.Numerics.Generic_Elementary_Functions;

package body perception with SPARK_Mode is

	package Value_Functions is new Ada.Numerics.Generic_Elementary_Functions (
		FloatingNumber);

	use Value_Functions;

	function breakingDistance (s : in Speed) return Distance
	is
	begin
		return Distance(S * S) / breakConstant;
	end breakingDistance;

	function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in Object_Type)
	  return DangerZone
	is
	   -- These values chage when test for real values
	   BreakingDist : Distance := BreakingDistance(S);
	   LidarAngle : Lidar_Angle := 45.0;
	   BreakingDistScale : constant Distance := 1.23;
	begin
	   if not (Obj_Type = STATIC) then
		  if (BreakingDist >= Distance'Last / BreakingDistScale) then
			 BreakingDist := Distance'Last;
		  else
			 BreakingDist := BreakingDist * BreakingDistScale; -- Change this constant later
		  end if;
		  LidarAngle := 60.0;
	   end if;
	   return (ScopeAngle => LidarAngle, Radius => BreakingDist, SteeringAngleOffset => SteeringAngle);
	end GetDangerZone;

	function PointInDangerZone(P : in LocalPoint; DZ : in DangerZone) return Boolean
	is
		Ang  : constant Lidar_Angle := Lidar_Angle(ArcTan(P.X / P.Y));
		Dist : constant Distance := Sqrt(P.X * P.X + P.Y * P.Y);
	begin
	   return abs Ang <= DZ.ScopeAngle and then Dist <= DZ.Radius;
	end PointInDangerZone;

	function WorldToLocal(P : in Point; C : in Point) return LocalPoint
	is
	begin
	   return (P.X - C.X, P.Y - C.Y, P.Z - C.Z);
	end WorldToLocal;

	-- function TransformAtoB(A : in Point; B : in Point) return Point
	-- is
	-- begin
	--    return (A.X, B.Y, 0.0);
	-- end TransformAtoB;

	function pccheck(O : in Obstacle; S : in Speed) return Boolean
	is
		breakingDist : constant Distance := BreakingDistance(s);
	begin
		return not (abs O.Ang <= Scopeangle and then O.Dist <= BreakingDist);
	end pccheck;
end;
