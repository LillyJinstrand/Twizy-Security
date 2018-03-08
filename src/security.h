#ifndef SECURITY_H
#define SECURITY_H

#include "perception_data.h"

extern bool initialized;
//Sets up internal state. Must be called before any other calls
extern void init();

//Gets if library is initialized
extern bool isInitialized();

//Returns if all checks have passed since last run
extern bool is_safe();

//Updates internal state
extern void update_perception(perception_obstacle_ada);
extern void update_gps();
extern void update_speed();


#endif
