#include "brake_message.h"

int sequence_number = 1;

int get_sequence_num(){
    //Returns the value, and then increments
    return sequence_number++;
}

apollo::common::Header generate_header(){
    apollo::common::Header msg;

    //Name of the sending module
    msg.set_module_name("Security");
    
    //Set sequence number
    msg.set_sequence_num(get_sequence_num());

    //Status objects
    apollo::common::ErrorCode err = apollo::common::OK;
    msg.mutable_status()->set_error_code(err);
    msg.mutable_status()->set_msg("Emergency break triggered, ignoring further commands");

    //Set the timestamp
    msg.set_timestamp_sec(ros::Time::now().toSec());

    return msg;
}

apollo::control::ControlCommand generate_brake_command(){
    apollo::control::ControlCommand msg;

    //Stop the car
    msg.set_throttle(0);
    msg.set_brake(0);
    msg.set_speed(0);

    msg.mutable_header()->CopyFrom(generate_header());

    return msg;
}
