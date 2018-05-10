pragma SPARK_Mode(ON);

with Types; use Types;

package gpsModule with SPARK_Mode is
   Top_Left : constant Types.Point := (667271.0, 6398091.0, 0.0);
   Bottom_Right : constant Types.Point := (677862.0, 6397724.0, 0.0);

   function gpstest(Position : Types.Point) return Boolean with
    Post => (if Gpstest'Result then (Position.X > Top_Left.X and Position.Y < Top_Left.Y
	                            and Position.X < Bottom_Right.X and Position.Y > Bottom_Right.Y)) and
	 (if not Gpstest'Result then not (Position.X > Top_Left.X and Position.Y < Top_Left.Y
	                            and Position.X < Bottom_Right.X and Position.Y > Bottom_Right.Y)),
     Global => null;



end gpsModule;
