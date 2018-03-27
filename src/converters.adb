with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with Ada.Numerics.Generic_Elementary_Functions;


with gpsModule; use gpsModule;



package body converters with SPARK_Mode is

   
   
   testb : Double := 3.0;
   testrov : Lat := 30.0;
      
   function doubleconv (doub : Double) return Lat
     
   is
         temp : Lat range -90.0 .. 90.0 := Lat(doub);
      
   begin
      
   if (-180.0 < temp  and temp < 180.0)
     
     then
      
       return temp; 
      
         
      else
         
       return testrov;
         
      end if;
      
      
   end doubleconv; 
   
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
