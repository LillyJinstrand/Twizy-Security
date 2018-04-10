with types;
use types;
with Perception_Data_H;
use Perception_Data_H;
with Localization_Data_H;
use Localization_Data_H;
-- The car's coordinate system is defined as having the car being 0,0
-- The y axis increases in the direction the car is facing
-- The x axis increases to the right of the car
-- This means positive angles are to the right of the center of the car
-- and negative angles are the the left of the car

package perception with SPARK_Mode is
   -- dynamic and static indicate unknown object with a know moving state
   --type Object_type is (UNKNOWN, DYNAMIC, STATIC, PEDESTRIAN, BICYCLE, VEHICLE);

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

   type Point is
	  record
		 X : Cartesian_Coordinate;
		 Y : Cartesian_Coordinate;
		 Z : Cartesian_Coordinate;
	  end record;

   subtype LocalPoint is Point;

   -- for now, lines ignore the Z coordinate, we will filter out the height of objects
   -- before we get there
   type Line is
	  record
		 P : LocalPoint;
		 Q : LocalPoint;
	  end record;

   -- Counter-clockwise, clockwise, co-linear
   type Orientation is (CCW, CW, CL);

   scopeangle : constant Lidar_angle := 45.0;
   breakConstant : constant Distance := 150.0;

   -- Checks if a point is inside a danger zone
   -- Look at objects inside of a 100x100 m square around the car
   function PointInDangerZone(P : in LocalPoint; DZ : in DangerZone) return Boolean with
	 Pre => P.Y > 0.0 and abs P.X < 50.0 and abs P.Y < 50.0,
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

   function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in C_type)
	 return DangerZone with
	 Pre => S > 0.0,
     Global => null;

   function GetDZEdge(DZ : DangerZone; Left : Boolean) return Line with
	 Global => null;

   function GetOrientation(P1 : LocalPoint; P2 : LocalPoint; P3 : LocalPoint) return Orientation
	 with
	 Global => null;

   function IsIntersecting(L1 : Line; L2 : Line) return Boolean
	 with Global => null;

   function PerceptionCheck(Obstacle : in Perception_Obstacle_ada; Pose : in Pose_Ada; S : in Speed) return Boolean with
	 Pre => S > 0.0,
     Global => null;

end perception;
