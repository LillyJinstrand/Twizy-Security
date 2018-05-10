with Perception; use Perception;
with Ada.Text_IO; use Ada.Text_IO;
with Types; use Types;

procedure Perception_Test is
   package Bool_IO is new Ada.Text_IO.Enumeration_IO(Boolean);
   ZoneA : constant DangerZone := (Radius => 3.0, ScopeAngle => 45.0, SteeringAngleOffset => 0.0);

   procedure Test_Value(Value : Boolean; Expected : Boolean; Name : String)
   is
	  Res : constant Boolean := Value = Expected;
   begin
	  if Res then
		 Ada.Text_IO.Put("Passed test: ");
		 Ada.Text_IO.Put(Name);
	  else
		 Ada.Text_IO.Put("Failed test: ");
		 Ada.Text_IO.Put(Name);
		 Ada.Text_IO.Put("(Expected: ");
		 Bool_Io.Put(Expected);
		 Ada.Text_IO.Put(", Got: ");
		 Bool_IO.Put(Value);
	  end if;
	  Ada.Text_IO.New_Line(1);
   end;

begin
   Ada.Text_IO.Put_Line("DANGER ZONE");
   Ada.Text_IO.New_Line(1);
   -- point in DZ
   Test_Value(PointInDangerZone((0.0, 4.0, 0.0), ZoneA), False, "PiDZ: 0.0:4.0");
   Test_Value(PointInDangerZone((0.0, 3.0, 0.0), ZoneA), True, "PiDz: 0.0:3.0");
   Test_Value(PointInDangerZone((0.0, 2.0, 0.0), ZoneA), True, "PiDz: 0.0:2.0");
   Test_Value(PointInDangerZone((0.0, 1.0, 0.0), ZoneA), True, "PiDz: 0.0:1.0");
   Test_Value(PointInDangerZone(((-0.3), 2.0, 0.0), ZoneA), True, "PiDz: -0.3:2.0");
   Test_Value(PointInDangerZone((0.5, 1.0, 0.0), ZoneA), True, "PiDz: 0.5:1.0");
   Test_Value(PointInDangerZone((2.0, 2.0, 0.0), ZoneA), True, "PiDz: 2.0:2.0");
   Test_Value(PointInDangerZone((-2.0, 2.0, 0.0), ZoneA), True, "PiDz: -2.0:2.0");
   Ada.Text_IO.New_Line(1);

   Ada.Text_IO.Put_Line("LINE INTERSECTION");
   Ada.Text_IO.New_Line(1);
   -- Line intersections
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, False), ((0.0, 1.0, 0.0),(2.0, 1.0, 0.0))), True, "Int: 0.0:1.0 2.0:0.1");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, False), ((0.0, -1.0, 0.0),(2.0, 1.0, 0.0))), False, "Int: 0.0:-1.0 2.0:1.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, False), ((2.0, 1.0, 0.0),(0.0, 1.0, 0.0))), True, "Int: 2.0:1.0 0.0:1.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, False), ((2.0, 1.0, 0.0),(0.0, -1.0, 0.0))), False, "Int: 2.0:1.0 0.0:-1.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, True), ((-2.0, 1.0, 0.0),(0.0, 1.0, 0.0))), True, "Int: -2.0:1.0 0.0:1.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, True), ((-2.0, 1.0, 0.0),(0.0, -1.0, 0.0))), False, "Int: -2.0:1.0 0.0:-1.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, True), ((-2.0, 1.0, 0.0),(0.0, 2.0, 0.0))), True, "Int: -2.0:1.0 0.0:2.0");
   Test_Value(IsIntersecting(GetDZEdge(ZoneA, False), ((2.0, 1.0, 0.0),(0.0, 2.0, 0.0))), True, "Int: 2.0:1.0 0.0:2.0");
end;
