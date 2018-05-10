package body converters with SPARK_Mode is
   function double_to_speed (d : double) return Types.speed
   is temp : Types.Speed;
   begin
       if (d <= double(-80.0)) then
           temp := Types.Speed(-79.0);
           return temp;
       end if;
       if (d >= double(80.0)) then
           temp :=  Types.Speed(79.0);
           return temp;
       end if;
       temp := Types.Speed(d);
       return temp;
   end double_to_speed;

   function point_to_cart_x (p : point_3d) return Types.Cartesian_Coordinate
   is
      temp : Types.Cartesian_Coordinate;
   begin
       temp := Types.Cartesian_Coordinate(p.x);
       return temp;
   end point_to_cart_x;

   function point_to_cart_y (p : point_3d) return Types.Cartesian_Coordinate
   is
      temp : Types.Cartesian_Coordinate;
      begin
          temp := Types.Cartesian_Coordinate(p.y);
          return temp;
   end point_to_cart_y;

   function point_to_cart_z (p : point_3d) return Types.Cartesian_Coordinate
   is
      temp : Types.Cartesian_Coordinate;
      begin
          temp := Types.Cartesian_Coordinate(p.z);
          return temp;
   end point_to_cart_z;

   function speed_ada_to_speed (s : speed_ada) return Types.speed
   is
       temp : Types.speed;
   begin
       temp := double_to_speed(s.speed);
       return temp;
   end speed_ada_to_speed;
end converters;
