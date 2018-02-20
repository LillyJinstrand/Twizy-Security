package body perception with SPARK_Mode is

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
		  if (BreakingDist >= Distance'Round(Distance'Last / BreakingDistScale)) then
			 BreakingDist := Distance'Last;
		  else
			 BreakingDist := BreakingDist * BreakingDistScale; -- Change this constant later
		  end if;
		  LidarAngle := 60.0;
	   end if;
	   return (ScopeAngle => LidarAngle, Radius => BreakingDist, SteeringAngleOffset => SteeringAngle);
	end GetDangerZone;

	function pccheck(O : in Obstacle; S : in Speed) return Boolean
	is
		breakingDist : constant Distance := BreakingDistance(s);
	begin
		return not (abs O.Ang <= Scopeangle and then O.Dist <= BreakingDist);
	end pccheck;
end;
