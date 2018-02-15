with types;
use types;

package perception with SPARK_Mode is
   -- perhaps extend to provide a human type
   type Object_type is (STATIC, DYNAMIC, UNKNOWN);
   

   subtype Distance is fixedNumber range 0.0 .. 160.0;
   
   
   -- angle from lidar (0 is straight forward)
   type Angle is delta 0.1 range -360.0 .. 360.0;
   subtype Steering_angle is Angle range -90.0 .. 90.0; 
   subtype Lidar_angle is Angle range -90.0 .. 90.0;
   
   -- max value is range of the lidar
    
   
   type Obstacle is 
      record
         obj_type : Object_type;
         ang : Lidar_angle;
         dist : Distance;
      end record;
   
   scopeangle : constant Lidar_angle := 45.0;
   breakConstant : constant Distance := 150.0;
   
   
   
   function breakingDist (s : in Speed) return Distance;
   
   function pccheck(O : in Obstacle; S : in Speed) return Boolean with
    Post => (if pccheck'Result then abs O.ang > scopeangle or o.dist > breakingDist(S)) and
    (if not pccheck'Result then  abs O.ang <= scopeangle and O.dist <= breakingDist(S)),
     Global => null;
   

   
end perception;
