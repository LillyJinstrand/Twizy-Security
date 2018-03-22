with Spark.Float_Arithmetic_Lemmas;
with Mathutil;

package body perception with SPARK_Mode is

	use Spark.Float_Arithmetic_Lemmas;

	function breakingDistance (s : in Speed) return Distance
	is
	   Dist : Distance;
	begin
	   pragma Assert(BreakConstant > 0.0);
	   Dist := Distance(S) * Distance(S);
	   return abs (Dist / BreakConstant);
	end breakingDistance;

	function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in Object_Type) return DangerZone
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
			 pragma Assume(BreakingDist * BreakingDistScale < Distance'Last);
			 pragma Assume(BreakingDist * BreakingDistScale > 0.0);
			 BreakingDist := BreakingDist * BreakingDistScale; -- Change this constant later
		  end if;
		  LidarAngle := 60.0;
	   end if;
	   return (ScopeAngle => LidarAngle, Radius => BreakingDist, SteeringAngleOffset => SteeringAngle);
	end GetDangerZone;

	function PointInDangerZone(P : in LocalPoint; DZ : in DangerZone) return Boolean
	is
		Ang  : Lidar_Angle := 0.0;

		pragma Assume(P.X * P.X + P.Y * P.Y > 0.0);
		pragma Assume(P.X * P.X + P.Y * P.Y < 6000.0);
		Dist2 : constant Distance := Distance(P.X * P.X + P.Y * P.Y);
		pragma Assume(Dist2 > 0.0);
		Dist : constant Distance := Mathutil.Sqrt(Dist2);
	begin
	    if Dist > DZ.Radius then
		   return False;
		else
			if P.X /= 0.0 and P.Y /= 0.0 then
				Ang := Lidar_Angle(Mathutil.ArcTan(P.Y, P.X));
			elsif P.Y = 0.0 then
			    pragma Assume(P.X / P.X = 1.0 or P.X / P.X = -1.0);
				Ang := 90.0 * Lidar_Angle(P.X / P.X);
			end if;
	   end if;
	   return abs Ang <= DZ.ScopeAngle;
	end PointInDangerZone;

	-- this fails proofs but will need to be rewritten anyway
	function WorldToLocal(P : in Point; C : in Point) return LocalPoint
	is
	begin
	   return (P.X - C.X, P.Y - C.Y, P.Z - C.Z);
	end WorldToLocal;

	function pccheck(O : in Obstacle; S : in Speed) return Boolean
	is
		breakingDist : constant Distance := BreakingDistance(s);
	begin
		return not (abs O.Ang <= Scopeangle and then O.Dist <= BreakingDist);
	end pccheck;
end;
