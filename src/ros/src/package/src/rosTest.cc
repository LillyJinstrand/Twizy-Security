#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "modules/perception/proto/perception_obstacle.pb.h"
//#include "security.h"

void perceptionCallback(const apollo::perception::PerceptionObstacles& msg)
{
    std::stringstream ss;
    ss << "\nObstacles:\n";
    for(int i=0; i < msg.perception_obstacle_size(); i++){
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
    }
    ROS_INFO("%s", ss.str().c_str());
  /* update_perception(); */
}

void predictionCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from prediction: [%s]", msg->data.c_str());
  /* update_prediction(); Maybe combine prediction and perception? */
}

void controlCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from control: [%s]", msg->data.c_str());
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

void localizationCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from localization: [%s]", msg->data.c_str());
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
