#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/localization/proto/localization.pb.h"

//#include "security.h"

void perceptionCallback(const apollo::perception::PerceptionObstacles& msg)
{
    std::stringstream ss;
    ss << "\n" << msg.perception_obstacle_size() << " Obstacles:\n";
    for(int i=0; i < msg.perception_obstacle_size(); i++){
        //ss << "Id: " << msg.perception_obstacle(i).id() << "\n";
        ss << "Type: ";
        switch(msg.perception_obstacle(i).type()){
           case 0:
               ss << "Unknown";
               break;
           case 1:
               ss << "Unknown Movable";
               break;
           case 2:
               ss << "Unkown Unmovable";
               break;
           case 3:
               ss << "Pedestrian";
               break;
           case 4:
               ss << "Bicycle";
               break;
           case 5:
               ss << "Vehicle";
               break;
       }
       ss << "\n";
       //ss << "Size: " << msg.perception_obstacle(i).length() << " " << msg.perception_obstacle(i).width() << " " << msg.perception_obstacle(i).height() << "\n";
       ss << "Position: x: " << msg.perception_obstacle(i).position().x() << " y: " << msg.perception_obstacle(i).position().y() << " z: " << msg.perception_obstacle(i).position().z() << "\n";
    }
	// ROS_INFO("%s", ss.str().c_str());
  /* update_perception(); */
}

void predictionCallback(const apollo::prediction::PredictionObstacles& msg)
{
    ROS_INFO("Prediction recived");
  /* update_prediction(); Maybe combine prediction and perception? */
}

void controlCallback(const apollo::control::ControlCommand& msg)
{
    std::stringstream ss;
    ss << "\nControl Command:\n";
    ss << "Throttle: " << msg.throttle() << "\n";
    ss << "Brake: " << msg.brake() << "\n";
    ss << "Speed: " << msg.speed() << "\n";
   // ROS_INFO("%s", ss.str().c_str());

  /* This isn't even correct just a suggestion, we should probably 
  if is_safe()
	  vidarebefordra
  */
}

void canbusCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from canbus: [%s]", msg->data.c_str());
  /* Filter out speed from canbus data
  update_speed(); 
  */
}

void localizationCallback(const apollo::localization::LocalizationEstimate& msg)
{
	
    std::stringstream ss;
    ss << "\nLocalization:\n";
	apollo::localization::Pose pose = msg.pose();
	apollo::common::PointENU position = pose.position();
	//ss << "Position of car in map reference frame" << "\n";
	ss << "Heading: " << pose.heading() << "\n";
	/*
	ss << "x: " << position.x();
	ss << " y: " << position.y();
	ss << " z: " << position.z() << "\n";
	*/
	ROS_INFO("%s", ss.str().c_str());
	
	//ROS_INFO("Recived localization callback");
	
  /* update_gps(); */
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rosTest");   
  ros::NodeHandle n;   

  ros::Subscriber perception = n.subscribe("/apollo/perception/obstacles", 1000, perceptionCallback);
  ros::Subscriber prediction = n.subscribe("/apollo/prediction", 1000, predictionCallback);
  ros::Subscriber control = n.subscribe("/apollo/control", 1000, controlCallback);
  ros::Subscriber canbus = n.subscribe("canbus", 1000, canbusCallback);
  ros::Subscriber localization = n.subscribe("/apollo/localization/pose", 1000, localizationCallback);
  
  ros::Publisher canbus_pub = n.advertise<std_msgs::String>("canbus", 1000);

  ros::Rate loop_rate(1000);   

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    //ROS_INFO("%s", msg.data.c_str());

    //canbus_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  ros::spin();

  return 0;
}
