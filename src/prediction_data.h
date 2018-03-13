#ifndef PREDICTION_DATA_H
#define PERCEPTION_DATA_H

#include "perception_data.h"
#include "common_data.h"


struct trajectory_ada {
	double probability;
	bool valid_probability;


	trajectory_point_ada trajectory_points[10];
	int trajectory_points_size;
};

struct prediction_obstacle_ada {
	perception_obstacle_ada perception_obstacle;
	bool valid_perception_obstacle;

	double timestamp;
	bool valid_timestamp;

	double predicted_period;
	bool valid_predicted_period;


	trajectory_ada trajectory[10];
	int trajectory_size;
};

#endif // PREDICTION_DATA_H
