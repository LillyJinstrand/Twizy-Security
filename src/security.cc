#include "security.h"

bool initialized = false;

// The chars are ada booleans.
extern "C" {
    void init_ada();
    char is_initialized_ada();

    void update_perception_ada(perception_obstacle_ada);
    void update_gps_ada(localization_estimate_ada);
    void update_speed_ada(speed_ada);

    char is_safe_ada();

    void ckinit();
}

void init(){
    ckinit();
    init_ada();
    initialized = is_initialized_ada();
}

bool isInitialized(){
    return initialized;
}

void update_perception(perception_obstacle_ada in){
    update_perception_ada(in);
}
void update_gps(localization_estimate_ada in){
    update_gps_ada(in);
}
void update_speed(speed_ada in){
    update_speed_ada(in);
}

bool is_safe(){
    char result = is_safe_ada();
    if (result){
        return true;
    } else {
        return false;
    }
}
