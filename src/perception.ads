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

   type DangerZone is
	  record
		 ScopeAngle : Lidar_Angle;
		 Radius: Distance;
		 SteeringAngleOffset : Lidar_Angle;
	  end record;

   type Obstacle is
	  record
         obj_type : Object_type;
         ang : Lidar_angle;
         dist : Distance;
      end record;

   scopeangle : constant Lidar_angle := 45.0;
   breakConstant : constant Distance := 150.0;


   function breakingDistance (s : in Speed) return Distance with
   Pre => S > 0.0;

   function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in Object_Type)
	 return DangerZone with
	 Pre => S > 0.0,
     Global => null;

   function pccheck(O : in Obstacle; S : in Speed) return Boolean with
	 Pre => S > 0.0,
	 Post => (if pccheck'Result then abs O.ang > scopeangle or o.dist > breakingDistance(S)) and
	         (if not pccheck'Result then  abs O.ang <= scopeangle and O.dist <= breakingDistance(S)),
     Global => null;



end perception;
