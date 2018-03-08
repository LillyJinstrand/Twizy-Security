#ifndef PERCEPTION_DATA_H
#define PERCEPTION_DATA_H

struct point_3d {
    double x;
    double y;
    double z;
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

    enum Type {
      UNKNOWN = 0,
      UNKNOWN_MOVABLE = 1,
      UNKNOWN_UNMOVABLE = 2,
      PEDESTRIAN = 3,  // Pedestrian, usually determined by moving behaviour.
      BICYCLE = 4,  // bike, motor bike
      VEHICLE = 5,  // Passenger car or truck.
    };

    Type type;
    double timestamp;

    double confidence;
    
    enum ConfidenceType {
        CONFIDENCE_UNKNOWN = 0,
        CONFIDENCE_CNN = 1,
        CONFIDENCE_RADAR = 2,
    };

    ConfidenceType confidence_type;
     
};

#endif
