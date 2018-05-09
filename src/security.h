#ifndef SECURITY_H
#define SECURITY_H

#include "perception_data.h"
#include "localization_data.h"
#include "speed_data.h"

extern bool initialized;
//Sets up internal state. Must be called before any other calls
extern void init();

//Gets if library is initialized
extern bool isInitialized();

//Returns if all checks have passed since last run
extern bool is_safe();

//Updates internal state
extern void update_perception(perception_obstacle_ada);
extern void update_gps(localization_estimate_ada);
extern void update_speed(speed_ada);
extern void check_brake_pedal(bool);
extern void check_timestamps(double);


#endif
