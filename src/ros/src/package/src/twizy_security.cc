#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/localization/proto/localization.pb.h"

#include "perception_data.h"
#include "perception_converter.h"
#include "localization_converter.h"
#include "speed_converter.h"

#include "security.h"
#include "brake_message.h"

double max_heading = 0;
double min_heading = 0;

ros::Publisher control_publisher;
void send_brake_command(){
    control_publisher.publish(generate_brake_command());
}

void perceptionCallback(const apollo::perception::PerceptionObstacles& msg)
{
    if(!is_safe()){
        //If the car is in a unsafe state already there is point in calling the check
        return;
    }
    for(int i=0; i < msg.perception_obstacle_size(); i++){
        const apollo::perception::PerceptionObstacle& obs = msg.perception_obstacle(i);
        update_perception(convert_obstacle(obs));
    }
    if(!is_safe()){
        send_brake_command();
        ROS_INFO("Perception module reports not safe! Sending brake command");
    }
}

void predictionCallback(const apollo::prediction::PredictionObstacles& msg)
{
    //ROS_INFO("Prediction recived");
    //update_prediction(); //Maybe combine prediction and perception? */
}

void controlCallback(const apollo::control::ControlCommand& msg)
{
    if (is_safe()){
        ROS_INFO("Everything reports safe, forwarding command");
        control_publisher.publish(msg);
        return;
    }
    send_brake_command();
    ROS_INFO("Car state is NOT SAFE: Blocking message and sending brake command");
}

void canbusCallback(const apollo::canbus::Chassis& msg)
{
    if(!is_safe()){
        //If the car is in a unsafe state already there is point in calling the check
        return;
    }
    update_speed(convert_speed(msg)); 

    if(!is_safe()){
        send_brake_command();
        ROS_INFO("Speed module reports not safe! Sending brake command");
    }
}

void localizationCallback(const apollo::localization::LocalizationEstimate& msg)
{
    if(!is_safe()){
        //If the car is in a unsafe state already there is point in calling the check
        return;
    }
    update_gps(convert_localization_estimate(msg));
    if(!is_safe()){
        send_brake_command();
        ROS_INFO("Localization reports not safe! Sending brake command");
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "twizySecurity");   
  ros::NodeHandle n;   

  control_publisher = n.advertise<apollo::control::ControlCommand>("/apollo/control", 1000);

  ros::Subscriber perception = n.subscribe("/apollo/perception/obstacles", 1000, perceptionCallback);
  ros::Subscriber prediction = n.subscribe("/apollo/prediction", 1000, predictionCallback);
  ros::Subscriber control = n.subscribe("CONTROL_COMMAND", 1000, controlCallback);
  ros::Subscriber canbus = n.subscribe("/apollo/canbus/chassis", 1000, canbusCallback);
  ros::Subscriber localization = n.subscribe("/apollo/localization/pose", 1000, localizationCallback);

  ros::Rate loop_rate(1000);

  ROS_INFO("twizySecurity started");

  int count = 0;
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  ros::spin();

  return 0;
}
