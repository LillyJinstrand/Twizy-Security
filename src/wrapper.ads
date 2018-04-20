with perception_data_h;
use perception_data_h;
with localization_data_h;
use localization_data_h;
with speed_data_h;
use speed_data_h;
with gpsModule;
with types; 
use types;
with Interfaces.C;

package Wrapper
    with SPARK_Mode
is
    Initialized : Boolean := False;
    -- This is the big one. Once this has been set to false the value is not allowed to change
    -- outside of a restart. Once this is set to false the car will emergency brake
    -- and ignore any other commands until it is reset
    Safe : Boolean := True;

    -- Variable to cache the current speed in.
    -- Should be updated every time the canbus callback is run
    CurrentSpeed : Speed := 0.0;
    -- Variable to cache current position
    CurrentPosition : Pose_Ada;

    LastPerceptionTimestamp : Interfaces.C.double := 0.0;
    LastPositionTimestamp : Interfaces.C.double := 0.0;
    LastSpeedTimestamp : Interfaces.C.double := 0.0;

    -- TODO: Determine these in a proper way
    MaxPerceptionDelay : constant Interfaces.C.double := 1000.0;
    MaxPositionDelay : constant Interfaces.C.double := 1000.0;
    MaxSpeedDelay : constant Interfaces.C.double := 1000.0;

    -- Here should any initialzation code be run
    procedure Init 
    with 
        Global => (Output => Initialized, In_Out => CurrentSpeed, Input => Safe),
        Convention => C,
        Export,
        External_Name => "init_ada";
    -- Simply returns if the init function has been run or not
    pragma Warnings (Off, "return type of ""Is_Initialized"" is an 8-bit Ada Boolean",
                        Reason => "Handeled by the c++ wrapper");
    function Is_Initialized return Boolean
    with
        Global => (Input => Initialized),
        Convention => C,
        Export,
        External_Name => "is_initialized_ada";
    pragma Warnings (On, "return type of ""Is_Initialized"" is an 8-bit Ada Boolean");

    -- This block is the callback functions for the c++ wrapper to attatch to the ROS topics
    procedure Update_Perception(perception_data : in perception_obstacle_ada)
    with
        Global => (Input => (CurrentPosition, CurrentSpeed), In_Out => Safe, Output => LastPerceptionTimestamp),
        Convention => C,
        Export,
        External_Name => "update_perception_ada";
    procedure Update_GPS(localization_estimate : in localization_estimate_ada)
    with
        Global => (In_Out => (Safe, CurrentPosition), Output => LastPositionTimestamp),
        Convention => C,
        Export,
        External_Name => "update_gps_ada";
    procedure Update_Speed(speed : in speed_ada)
    with
        Global => (In_Out => (Safe, CurrentSpeed), Output => LastSpeedTimestamp),
        Convention => C,
        Export,
        External_Name => "update_speed_ada";

    procedure CheckTimestamps(currentTime : in Interfaces.C.double)
    with
        Global => (
            Input => (LastSpeedTimestamp, LastPositionTimestamp, LastPerceptionTimestamp), 
            In_Out => Safe
            );

    -- Returns whether we are safe or not
    -- The result is based on the last run of the callback functions
    -- Once it has switched to unsafe, it will not switch back without resetting
    pragma Warnings (Off, "return type of ""Is_Safe"" is an 8-bit Ada Boolean",
                        Reason => "Handeled by the c++ wrapper");
    function Is_Safe return Boolean 
    with 
        Global => (Input => Safe),
        Convention => C,
        Export,
        External_Name => "is_safe_ada";
    pragma Warnings (On, "return type of ""Is_Safe"" is an 8-bit Ada Boolean");
    
end Wrapper;
