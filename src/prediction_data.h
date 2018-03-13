#ifndef PREDICTION_DATA_H
#define PERCEPTION_DATA_H

#include "perception_data.h"

struct path_point_ada {
	double x;
	bool valid_x;

	double y;
	bool valid_y;

	double z;
	bool valid_y;

	// direction in x-y plane
	double theta;
	bool valid_theta;

	// curvature in x-y plane
	double kappa;
	bool valid_kappa;

	double dkappa; // first derivative
	bool valid_dkappa;

	double ddkappa; // second derivative
	bool valid_ddkappa;

	// accumulated dist from beginning of path
	double s;
	bool valid_s;
}

struct trajectory_point_ada {
	path_point_ada path_point;
	bool valid_point;

	double v; // velocity
	bool valid_v;

	double a; // acceleration
	bool valid_a;

	double relative_time; // time from beginning of trajectory
	bool valid_relative_time;

}

struct trajectory_ada {
	double probability;
	bool valid_probability;


	trajectory_point_ada trajectory_points[10];
	int trajectory_points_size;
}

struct prediction_obstacle_ada {
	perception_obstacle_ada perception_obstacle;
	bool valid_perception_obstacle;

	double timestamp;
	bool valid_timestamp;

	double predicted_period;
	bool valid_predicted_period;


	trajectory_ada trajectory[10];
	int trajectory_size;
}

#endif // PREDICTION_DATA_H
