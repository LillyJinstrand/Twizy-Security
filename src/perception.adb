package body perception with SPARK_Mode is

   function breakingDistance (s : in Speed) return Distance
   is
   begin
      return Distance(S * S) / breakConstant;
   end breakingDistance;

   function pccheck(O : in Obstacle; S : in Speed) return Boolean
   is
      breakingDist : constant Distance := BreakingDistance(s);
   begin
	  return not (abs O.Ang <= Scopeangle and then O.Dist <= BreakingDist);
   end pccheck;
end;
