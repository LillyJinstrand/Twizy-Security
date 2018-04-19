#ifndef LOCALIZATION_DATA_H
#define LOCALIZATION_DATA_H

#include "common_data.h"

struct pose_ada {
	point_enu_ada position;
	bool valid_position;

	quaternion_ada orientation;
	bool valid_orientation;

	point_3d linear_velocity;
	bool valid_linear_velocity;

	point_3d linear_acceleration;
	bool valid_linear_acceleration;

	point_3d angular_velocity;
	bool valid_angular_velocity;

	double heading;
	bool valid_heading;

	point_3d linear_acceleration_vrf;
	bool valid_linear_acceleration_vrf;

	point_3d angular_velocity_vrf;
	bool valid_angular_velocity_vrf;

	point_3d euler_angles;
	bool valid_euler_angles;
};

enum MeasureState {
	NOT_VALID = 0,
	NOT_STABLE = 1,
	OK = 2,
	VALID = 3,
};

struct uncertainty_ada {
	point_3d position_std_dev;
	bool valid_position_std_dev;

	point_3d orientation_std_dev;
	bool valid_orientation_std_dev;

	point_3d linear_velocity_std_dev;
	bool valid_linear_velocity_std_dev;

	point_3d linear_acceleration_std_dev;
	bool valid_linear_acceleration_std_dev;

	point_3d angular_velocity_std_dev;
	bool valid_angular_velocity_std_dev;
};

struct localization_estimate_ada {
	pose_ada pose;
	bool valid_pose;

	uncertainty_ada uncertainty;
	bool valid_uncertainty;

	double measurement_time;
	bool valid_measurement_time;
};

struct localization_status_ada {
	MeasureState fusion_status;
	bool valid_fusion_status;

	MeasureState gnss_status;
	bool valid_gnss_status;

	MeasureState lidar_status;
	bool valid_lidar_status;

	// time of pose measurement, seconds since GPS epoch (jan 6, 1980)
	double measurement_time;
	bool valid_measurement_time;
};

#endif // LOCALIZATION_DATA_H
