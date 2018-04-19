#ifndef COMMON_DATA_H
#define COMMON_DATA_H

// point in the map reference frame
struct point_enu_ada {
	double x; // east from origin, meters
	bool valid_x;

	double y; // north from origin, meters
	bool valid_y;

	double z; // up from WGS-84 ellipsoid, meters
	bool valid_z;
};

struct quaternion_ada {
	double qx;
	bool valid_qx;

	double qy;
	bool valid_qy;

	double qz;
	bool valid_qz;

	double qw;
	bool valid_qw;
};

struct path_point_ada {
	double x;
	bool valid_x;

	double y;
	bool valid_y;

	double z;
	bool valid_z;

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
