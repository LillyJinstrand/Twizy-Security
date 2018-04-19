#ifndef BRAKE_MESSAGE_H
#define BRAKE_MESSAGE_H

#include "ros/ros.h"
#include "modules/control/proto/control_cmd.pb.h"

//Gets the next sequence number, and increments automaticly
int get_sequence_num();

//Generates the header for the break message.
//Since it sets the timestamp and sequnce number it should be 
//called last in the message generation
apollo::common::Header generate_header();

//Returns a command for stopping the car. For the timestamp to remain
//valid the message should be sent immediatly after being generated
apollo::control::ControlCommand generate_brake_command();


#endif
