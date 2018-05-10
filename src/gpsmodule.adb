package body gpsmodule with SPARK_Mode is

   function gpstest(Position : Types.Point) return Boolean
   is
   begin
	  return (Position.X > Top_Left.X and Position.Y < Top_Left.Y
	      and Position.X < Bottom_Right.X and Position.Y > Bottom_Right.Y);
	end gpstest;
end gpsmodule;
