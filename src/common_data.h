#ifndef COMMON_DATA_H
#define COMMON_DATA_H

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
};

struct trajectory_point_ada {
	path_point_ada path_point;
	bool valid_point;

	double v; // velocity
	bool valid_v;

	double a; // acceleration
	bool valid_a;

	double relative_time; // time from beginning of trajectory
	bool valid_relative_time;
};

struct point_3d {
    double x;
    bool valid_x;
    double y;
    bool valid_y;
    double z;
    bool valid_z;
};

#endif // COMMON_DATA_H
