#include "control_cmd_converter.h"

control_cmd_ada convert_control_cmd(apollo::control::ControlCommand& c){
    control_cmd_ada out = {};

    if((out.valid_throttle = c.has_throttle()))
        out.throttle = c.throttle();
    if((out.valid_brake = c.has_brake()))
        out.brake = c.brake();
    if((out.valid_steering_rate = c.has_steering_rate()))
        out.steering_rate = c.steering_rate();
    if((out.valid_steering_target = c.has_steering_target()))
        out.steering_target = c.steering_target();
    if((out.valid_parking_brake = c.has_parking_brake()))
        out.parking_brake = c.parking_brake();
    if((out.valid_speed = c.has_speed()))
        out.speed = c.speed();
    if((out.valid_acceleration = c.has_acceleration()))
        out.acceleration = c.acceleration();

    return out;
}
