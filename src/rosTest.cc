#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");   
  ros::NodeHandle n;   

  ros::Subscriber perception = n.subscribe("perception", 1000, chatterCallback);
  ros::Subscriber prediction = n.subscribe("prediction", 1000, chatterCallback);
  ros::Subscriber control = n.subscribe("control", 1000, chatterCallback);
  ros::Subscriber canbus = n.subscribe("canbus", 1000, chatterCallback);

  ros::Publisher canbus_pub = n.advertise<std_msgs::String>("canbus", 1000);

  ros::Rate loop_rate(1000);   

  int count = 0;
  while (ros::ok())
  {

    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    canbus_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  ros::spin();

  return 0;
}
