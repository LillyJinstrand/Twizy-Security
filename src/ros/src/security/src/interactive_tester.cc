#include "ros/ros.h"
#include <iostream>

#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/canbus/proto/chassis.pb.h"

int sequence_number = 1;
int get_sequence_num(){
    return sequence_number++;
}

apollo::common::Header generate_header(){
    apollo::common::Header msg;

    msg.set_module_name("Interactive_tester");
    msg.set_sequence_num(get_sequence_num());
    apollo::common::ErrorCode err = apollo::common::OK;
    msg.mutable_status()->set_error_code(err);
    msg.set_timestamp_sec(ros::Time::now().toSec());
    std::cout << ros::Time::now().toSec() << "s" << std::endl;

    return msg;
}

void control_cmd(ros::Publisher& pub){
    apollo::control::ControlCommand msg;

    msg.mutable_header()->CopyFrom(generate_header());
    double speed;
    std::cout << "Enter speed" << std::endl;
    std::cin >> speed;
    msg.set_speed(speed);
    pub.publish(msg);
}
void speed_msg(ros::Publisher& pub){
    apollo::canbus::Chassis msg;

    msg.mutable_header()->CopyFrom(generate_header());
    double speed;
    std::cout << "Enter speed" << std::endl;
    std::cin >> speed;
    msg.set_speed_mps(speed);
    int pedal;
    std::cout << "Pedal status, 1 for pressed, 0 for not" << std::endl;
    std::cin >> pedal;
    msg.set_parking_brake((bool) pedal);
    pub.publish(msg);
}

void perception_msg(ros::Publisher& pub){
    apollo::perception::PerceptionObstacles msg;

    msg.mutable_header()->CopyFrom(generate_header());

    apollo::perception::PerceptionObstacle o1;
    o1.set_id(1);
    o1.mutable_position()->set_x(6.0);
    o1.mutable_position()->set_y(20.0);
    o1.mutable_position()->set_z(0.0);

    o1.mutable_velocity()->set_x(0.0101980390272);
    o1.mutable_velocity()->set_y(0.0101980390272);
    o1.mutable_velocity()->set_z(0.0);

	//o1.set_theta(3.14/4.0);;
	o1.set_theta(0.0);;

    o1.set_length(0.5);
    o1.set_width(1.0);
    o1.set_height(1.0);

    apollo::perception::PerceptionObstacle::Type type = apollo::perception::PerceptionObstacle::VEHICLE;
    o1.set_type(type);

    msg.add_perception_obstacle();
    msg.mutable_perception_obstacle(0)->CopyFrom(o1);

    pub.publish(msg);
}

void localization_msg(ros::Publisher& pub) {
    apollo::localization::LocalizationEstimate msg;

    msg.mutable_header()->CopyFrom(generate_header());

	apollo::localization::Pose pose;
	pose.mutable_position()->set_x(-6.0);
	pose.mutable_position()->set_y(-6.0);
	pose.mutable_position()->set_z(0.0);

	//pose.set_heading(0.0);
	pose.set_heading(-3.14/2.0);

	msg.mutable_pose()->CopyFrom(pose);

	pub.publish(msg);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "interactiveTester");
    ros::NodeHandle nh;

    ros::Publisher control_publisher = nh.advertise<apollo::control::ControlCommand>("CONTROL_COMMAND", 1000);
    ros::Publisher localization_publisher = nh.advertise<apollo::localization::LocalizationEstimate>("/apollo/localization/pose", 1000);
    ros::Publisher canbus_publisher = nh.advertise<apollo::canbus::Chassis>("/apollo/canbus/chassis", 1000);
    ros::Publisher perception_publisher = nh.advertise<apollo::perception::PerceptionObstacles>("/apollo/perception/obstacles", 1000);

    int count = 0;
    while(ros::ok()){
        std::cout << "Interactive tester:" << std::endl
            << "1: Send Control command" << std::endl
            << "2: Send Canbus input" << std::endl
            << "3: Send Localization data" << std::endl
            << "4: Send Perception data" << std::endl
            << "0: Exit" << std::endl;
        int n;
        std::cin >> n;
        switch(n){
            case 0:
                return 0;
                break;
            case 1:
                control_cmd(control_publisher);
                break;
            case 2:
                speed_msg(canbus_publisher);
                break;
            case 3:
				localization_msg(localization_publisher);
                break;
            case 4:
                perception_msg(perception_publisher);
                break;
        }


        ros::spinOnce();
        count++;
    }
}
