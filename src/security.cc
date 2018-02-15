#include "security.h"

extern "C" {
    void init_ada();
    char update_ada();
    void ckinit();
}

void init(){
    ckinit();
    init_ada();
    initialized = true;
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
