#include "security.h"

bool initialized = false;

// The chars are ada booleans.
extern "C" {
    void init_ada();
    char is_initialized_ada();

    void update_perception_ada();
    void update_gps_ada();
    void update_speed_ada();

    char update_ada();

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

void update_perception(){
    update_perception_ada();
}
void update_gps(){
    update_gps_ada();
}
void update_speed(){
    update_speed_ada();
}

bool update(){
    char result = update_ada();
    if (result){
        return true;
    } else {
        return false;
    }
}
