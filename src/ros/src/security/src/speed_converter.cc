#include "speed_converter.h"

speed_ada convert_speed(const apollo::canbus::Chassis& in){
    speed_ada out = {};
    if((out.valid_speed = in.has_speed_mps()))
        out.speed = in.speed_mps();
    return out;
}
