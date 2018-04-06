with Interfaces.C; use Interfaces.C;
with perception; use perception;
with gpsModule; use gpsModule;
with speedModule; use speedModule;
with perception_data_h; use perception_data_h;
with common_data_h; use common_data_h;
with speed_data_h; use speed_data_h;


package converters with SPARK_Mode is
   
   function double_to_lat (doub : Double) return Lat with
       pre => doub < 90.0 and -90.0 < doub;
   
   function double_to_speed (d : double) return speed with
       Pre => d > -80.0 and d < 80.0 ; 
   
   function point_to_cart_x (p : point_3d) return Cartesian_Coordinate with
       pre => p.x < 180.0 and -180.0 < p.x ;
   
   function point_to_cart_y (p : point_3d) return Cartesian_Coordinate with
       pre => p.y < 180.0 and -180.0 < p.y ;
   
   function point_to_cart_z (p : point_3d) return Cartesian_Coordinate with
       pre => p.z < 180.0 and -180.0 < p.z ;

   function speed_ada_to_speed (s : speed_ada) return Speed with
       pre => s.speed > -80.0 and s.speed < 80.0;

end converters;
