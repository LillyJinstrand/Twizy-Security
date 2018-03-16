#ifndef PREDICTION_DATA_H
#define PREDICTION_DATA_H

#include "common_data.h"
#include "perception_data.h"

#define MAX_NUMBER_TRAJECTORIES 10
#define MAX_NUMBER_POINTS 10


struct trajectory_ada {
	double probability;
	bool valid_probability;

    //No good way of passing dynamic arrays, so a fixed size is used
    //Should be plenty, but if not later points in the list are dropped
	trajectory_point_ada trajectory_points[MAX_NUMBER_POINTS];
	int trajectory_points_size;
};

struct prediction_obstacle_ada {
	perception_obstacle_ada perception_obstacle;
	bool valid_perception_obstacle;

	double timestamp;
	bool valid_timestamp;

	double predicted_period;
	bool valid_predicted_period;

    //Since we have no good way of passing dynamic arrays between c++ and ada
    //this is a predifined size.  
    //In case there are more then the max trajectories will be prioritised based on probability
	trajectory_ada trajectory[MAX_NUMBER_TRAJECTORIES];
	int trajectory_size;
};

#endif // PREDICTION_DATA_H
