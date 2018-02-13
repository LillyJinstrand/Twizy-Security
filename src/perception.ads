with types;
use types;

package perception is
   -- perhaps extend to provide a human type
   type Object_type is (STATIC, DYNAMIC, UNKNOWN);
   
   -- angle from lidar (0 is straight forward)
   type Angle is delta 0.1 range -360.0 .. 360.0;
   subtype Steering_angle is Angle range -90.0 .. 90.0; 
   subtype Lidar_angle is Angle range -90.0 .. 90.0;
   
   -- max value is range of the lidar
   type Distance is delta 0.01 range 0.0 .. 100.0;
   
   type Obstacle is 
      record
         obj_type : Object_type;
         ang : Lidar_angle;
         dist : Distance;
      end record;

   
end perception;
