#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
//#include "security.h"

void canbusCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from canbus: [%s]", msg->data.c_str());
  /* Filter out speed from canbus data
  update_speed(); 
  */
}

void controlCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from control: [%s]", msg->data.c_str());
  /* This isn't even correct just a suggestion, we should probably 
  if is_safe()
	  vidarebefordra
  */
}

void localizationCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from localization: [%s]", msg->data.c_str());
  /* update_gps(); */
}

void perceptionCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from perception: [%s]", msg->data.c_str());
  /* update_perception(); */
}

void predictionCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard from prediction: [%s]", msg->data.c_str());
  /* update_prediction(); Maybe combine prediction and perception? */
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rosTest");   
  ros::NodeHandle n;   

  ros::Subscriber canbus = n.subscribe("/apollo/canbus", 1000, canbusCallback);
  ros::Subscriber control = n.subscribe("/apollo/control", 1000, controlCallback);
  ros::Subscriber localization = n.subscribe("/apollo/localization", 1000, localizationCallback);
  ros::Subscriber perception = n.subscribe("/apollo/perception", 1000, perceptionCallback);
  ros::Subscriber prediction = n.subscribe("/apollo/prediction", 1000, predictionCallback);
  
  ros::Publisher canbus_pub = n.advertise<std_msgs::String>("/apollo/canbus", 1000);

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
