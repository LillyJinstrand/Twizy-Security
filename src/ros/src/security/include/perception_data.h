#ifndef PERCEPTION_DATA_H
#define PERCEPTION_DATA_H

#include "common_data.h"

enum Type {
  UNKNOWN = 0,
  UNKNOWN_MOVABLE = 1,
  UNKNOWN_UNMOVABLE = 2,
  PEDESTRIAN = 3,  // Pedestrian, usually determined by moving behaviour.
  BICYCLE = 4,  // bike, motor bike
  VEHICLE = 5,  // Passenger car or truck.
};

struct perception_obstacle_ada {
    int id;
    bool valid_id;

    point_3d position;
    bool valid_position;

    double theta;
    bool valid_theta;
    point_3d velocity;
    bool valid_velocity;

    double length;
    bool valid_length;
    double width;
    bool valid_width;
    double height;
    bool valid_height;

    double tracking_time;
    bool valid_tracking_time;


    Type type;
    bool valid_type;
    double timestamp;
    bool valid_timestamp;
};

#endif
