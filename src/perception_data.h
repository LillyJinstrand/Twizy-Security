#ifndef PERCEPTION_DATA_H
#define PERCEPTION_DATA_H

struct point_3d {
    double x;
    double y;
    double z;
};
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
    point_3d position;

    double theta;
    point_3d velocity;

    double length;
    double width;
    double height;

    double tracking_time;


    Type type;
    double timestamp;
};

#endif
