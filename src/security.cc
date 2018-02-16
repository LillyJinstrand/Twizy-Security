#include "security.h"

bool initialized = false;

extern "C" {
    void init_ada();
    char is_initialized_ada();
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

bool update(){
    char result = update_ada();
    if (result){
        return true;
    } else {
        return false;
    }
}
