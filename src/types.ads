package types is

   type FloatingNumber is digits 12;
   subtype Speed is FloatingNumber range -80.0 .. 80.0;

   -- unit is meters
   subtype Distance is FloatingNumber range -100000000000000000.0 .. 10000000000000000000000.0;

   subtype Cartesian_Coordinate is Distance;

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

end types;
