#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"
#include "modules/localization/proto/localization.pb.h"

#include "perception_data.h"
#include "security.h"


int max_polygons = 0;

void perceptionCallback(const apollo::perception::PerceptionObstacles& msg)
{

    std::stringstream ss;
    ss << "\n" << msg.perception_obstacle_size() << " Obstacles:\n";
    for(int i=0; i < msg.perception_obstacle_size(); i++){
        const apollo::perception::PerceptionObstacle& obs = msg.perception_obstacle(i);

        perception_obstacle_ada ada_obs = {};

        ada_obs.id = obs.id();

        ada_obs.velocity.x = obs.velocity().x();
        ada_obs.velocity.y = obs.velocity().y();
        ada_obs.velocity.z = obs.velocity().z();

        ada_obs.length = obs.length();
        ada_obs.width = obs.width();
        ada_obs.height = obs.height();

        ada_obs.tracking_time = obs.tracking_time();

        switch(obs.type()){
           case 0:
               ada_obs.type = UNKNOWN;
               break;
           case 1:
               ada_obs.type = UNKNOWN_MOVABLE;
               break;
           case 2:
               ada_obs.type = UNKNOWN_UNMOVABLE;
               break;
           case 3:
               ada_obs.type = PEDESTRIAN;
               break;
           case 4:
               ada_obs.type = BICYCLE;
               break;
           case 5:
               ada_obs.type = VEHICLE;
               break;
        }
        ada_obs.timestamp = obs.timestamp();
        ada_obs.tracking_time = obs.tracking_time();



        ss << "Id: " << obs.id() << "\n";
        ss << "Type: ";
        switch(obs.type()){
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
       ss << "Size: " << obs.length() << " " << obs.width() << " " << obs.height() << "\n";
       ss << "Position: x: " << obs.position().x() << " y: " << obs.position().y() << " z: " << obs.position().z() << "\n";
       ss << "Number of polygons: " << obs.polygon_point_size() << "\n";
       
       
       update_perception(ada_obs);

    }
    ROS_INFO("%s", ss.str().c_str());
}

void predictionCallback(const apollo::prediction::PredictionObstacles& msg)
{
    //ROS_INFO("Prediction recived");
    //update_prediction(); //Maybe combine prediction and perception? */
}

void controlCallback(const apollo::control::ControlCommand& msg)
{
    std::stringstream ss;
    ss << "\nControl Command:\n";
    ss << "Throttle: " << msg.throttle() << "\n";
    ss << "Brake: " << msg.brake() << "\n";
    ss << "Speed: " << msg.speed() << "\n";
    //ROS_INFO("%s", ss.str().c_str());

  /* This isn't even correct just a suggestion, we should probably 
  if is_safe()
	  vidarebefordra
  */
}

void canbusCallback(const std_msgs::String::ConstPtr& msg)
{
  //ROS_INFO("I heard from canbus: [%s]", msg->data.c_str());
  /* Filter out speed from canbus data
  update_speed(); 
  */
}

void localizationCallback(const apollo::localization::LocalizationEstimate& msg)
{
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

  ROS_INFO("RosTest started");

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
