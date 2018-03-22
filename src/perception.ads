with types;
use types;
-- The car's coordinate system is defined as having the car being 0,0
-- The y axis increases in the direction the car is facing
-- The x axis increases to the right of the car
-- This means positive angles are to the right of the center of the car
-- and negative angles are the the left of the car

package perception with SPARK_Mode is
   -- dynamic and static indicate unknown object with a know moving state
   type Object_type is (UNKNOWN, DYNAMIC, STATIC, PEDESTRIAN, BICYCLE, VEHICLE);

   -- unit is meters
   subtype Distance is FloatingNumber range 0.0 .. 100000.0;

   subtype Cartesian_Coordinate is FloatingNumber range -1000.0 .. 1000.0;

   -- angle from lidar (0 is straight forward)
   subtype Angle is FloatingNumber range -360.0 .. 360.0;
   subtype Steering_angle is Angle range -90.0 .. 90.0;
   subtype Lidar_angle is Angle range -180.0 .. 180.0;

   type DangerZone is
	  record
		 ScopeAngle : Lidar_Angle;
		 Radius: Distance;
		 SteeringAngleOffset : Lidar_Angle;
	  end record;

   type Obstacle is
	  record
         Obj_Type : Object_type;
         Ang : Lidar_angle;
         Dist : Distance;
		 Heading: Angle; -- heading in the world coordinate system
      end record;

   type Point is
	  record
		 X : Cartesian_Coordinate;
		 Y : Cartesian_Coordinate;
		 Z : Cartesian_Coordinate;
	  end record;

   subtype LocalPoint is Point;

   scopeangle : constant Lidar_angle := 45.0;
   breakConstant : constant Distance := 150.0;

   -- Checks if a point is inside a danger zone
   function PointInDangerZone(P : in LocalPoint; DZ : in DangerZone) return Boolean with
	 Pre => P.Y > 0.0 and abs P.X < 80.0 and abs P.Y < 80.0,
	 Global => null;

   -- Transforms a point P in the world space to the local space
   -- around the car given the car's position in the world space,
   -- i.e. the car/dangerzone is the origin
   function WorldToLocal(P : in Point; C : in Point) return LocalPoint with
	 Global => null;

   -- transforms a point A to a coordinate system with matrix B
   -- TODO: matrix type
   -- function TransformAtoB(A : in Point; B : in Point) return Point with
   -- Global => null;

   function breakingDistance (s : in Speed) return Distance with
	 Pre => S > 0.0,
     Post => BreakingDistance'Result >= 0.0;

   function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in Object_Type)
	 return DangerZone with
	 Pre => S > 0.0,
     Global => null;

   function pccheck(O : in Obstacle; S : in Speed) return Boolean with
	 Pre => S > 0.0,
	 Post => (if pccheck'Result then abs O.ang > scopeangle or O.dist > breakingDistance(S)) and
	         (if not pccheck'Result then  abs O.ang <= scopeangle and O.dist <= breakingDistance(S)),
     Global => null;

end perception;
