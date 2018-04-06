package body converters with SPARK_Mode is
   function double_to_speed (d : double) return speed
   is temp : Speed;
   begin
       if (d <= -79.0) then
           temp := -79.0;
           return temp;
       end if;
       if (d >= 79.0) then
           temp :=  79.0;
           return temp;
       end if;
       pragma Assert(d > -79.0);
       pragma Assert(d < 79.0);
       pragma Assume(d > -79.0);
       pragma Assume(d < 79.0);
       temp := Speed(d);
       return temp;
   end double_to_speed;
      
   function double_to_lat (doub : Double) return Lat
   is
         temp : Lat;
   begin
       temp := Lat(doub);
       return temp; 
   end double_to_lat; 
   
   function point_to_cart_x (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate;
   begin
       temp := Cartesian_Coordinate(p.x);
       return temp;
   end point_to_cart_x;
   
   function point_to_cart_y (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate;
      begin
          temp := Cartesian_Coordinate(p.y);
          return temp;
   end point_to_cart_y;
   
   function point_to_cart_z (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate;
      begin
          temp := Cartesian_Coordinate(p.z);
          return temp;
   end point_to_cart_z;
   
   function speed_ada_to_speed (s : speed_ada) return speed
   is
       temp : speed;
   begin
       temp := double_to_speed(s.speed);
       return temp;
   end speed_ada_to_speed;
end converters;
