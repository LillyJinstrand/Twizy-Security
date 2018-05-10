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
   breakConstant : constant Distance := 1.0;

   -- Checks if a point is inside a danger zone
   -- Look at objects inside of a 100x100 m square around the car
   function PointInDangerZone(P : in LocalPoint; DZ : in DangerZone) return Boolean with
	 Pre => P.Y > 0.0 and abs P.X < 50.0 and abs P.Y < 50.0,
	 Global => null;

   function breakingDistance (s : in Speed) return Distance with
	 Pre => S > 0.0,
     Post => BreakingDistance'Result >= 0.0;

   function GetDangerZone(S : in Speed; SteeringAngle : in Steering_Angle; Obj_Type : in C_type)
	 return DangerZone with
	 Pre => S > 0.0,
     Global => null;

   function GetDZEdge(DZ : DangerZone; Left : Boolean) return Line with
	 Pre => DZ.Radius < Cartesian_Coordinate'Last / 2.0,
	 Global => null;

   function GetOrientation(P1 : LocalPoint; P2 : LocalPoint; P3 : LocalPoint) return Orientation
	 with
	 Pre => P1.X * P1.X < Cartesian_Coordinate'Last / 2.0
	    and P2.X * P2.X < Cartesian_Coordinate'Last / 2.0
	    and P3.X * P3.X < Cartesian_Coordinate'Last / 2.0
	    and P1.Y * P1.Y < Cartesian_Coordinate'Last / 2.0
	    and P2.Y * P2.Y < Cartesian_Coordinate'Last / 2.0
	    and P3.Y * P3.Y < Cartesian_Coordinate'Last / 2.0,
	 Global => null;

   function IsIntersecting(L1 : Line; L2 : Line) return Boolean
	 with Global => null;

   function PerceptionCheck(Obstacle : in Perception_Obstacle_ada; Pose : in Pose_Ada; S : in Speed) return Boolean with
	 Pre => S >= 0.0 and
	 Cartesian_Coordinate(Obstacle.Position.X) + Cartesian_Coordinate(Obstacle.Length) + Cartesian_Coordinate(Obstacle.Width) < Cartesian_Coordinate'Last / 2.0 and
	 Cartesian_Coordinate(Obstacle.Position.Y) + Cartesian_Coordinate(Obstacle.Length) + Cartesian_Coordinate(Obstacle.Width) < Cartesian_Coordinate'Last / 2.0 and
	        Cartesian_Coordinate(Pose.Position.X) < Cartesian_Coordinate'Last / 2.0 and
	        Cartesian_Coordinate(Pose.Position.Y) < Cartesian_Coordinate'Last / 2.0,
     Global => null;

end perception;
