package body perception with SPARK_Mode is

   function breakingDist (s : in Speed) return Distance
   is
   begin
      return Distance(S * S) / breakConstant;
   end breakingDist;

   function pccheck(O : in Obstacle; S : in Speed) return Boolean
   is
      breakingDist : constant Distance := Distance(S * S) / breakConstant;
   begin
      if (abs O.ang <= abs scopeangle) then
         if O.dist <= breakingDist then
            return False;
         else
            return True;
         end if;
      else
         return True;
      end if;

   end pccheck;
end;
