with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with Ada.Numerics.Generic_Elementary_Functions;


with speedModule; use speedModule;

with gpsModule; use gpsModule;



package body converters with SPARK_Mode is

   
   
   testb : Double := 3.0;
   testlat : Lat := 30.0;
   
   function double_to_speed (d : double) return speed
     
   is temp : Speed := Speed(d);
   
      begin
      
      return temp;
      
   end double_to_speed;
      
      
   function double_to_lat (doub : Double) return Lat
     
   is
         temp : Lat := Lat(doub);
      
   begin
      
       return temp; 
      
      
   end double_to_lat; 
   
   function point_to_cart_x (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate := Cartesian_Coordinate(p.x);
   
      begin
      
      return temp;
      
   end point_to_cart_x;
   
   
   function point_to_cart_y (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate := Cartesian_Coordinate(p.y);
   
      begin
      
      return temp;
      
   end point_to_cart_y;
   
   function point_to_cart_z (p : point_3d) return Cartesian_Coordinate 
   is
      temp : Cartesian_Coordinate := Cartesian_Coordinate(p.z);
   
      begin
      
      return temp;
      
   end point_to_cart_z;
   

end converters;
