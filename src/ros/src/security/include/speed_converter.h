#ifndef SPEED_CONVERTER_H
#define SPEED_CONVERTER_H

#include "speed_data.h"
#include "modules/canbus/proto/chassis.pb.h"

speed_ada convert_speed(const apollo::canbus::Chassis&);

#endif
