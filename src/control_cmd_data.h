#ifndef CONTROL_CMD_DATA_H
#define CONTROL_CMD_DATA_H

// add latency stats?

struct control_cmd_ada {
	// header thing

	double throttle;
	bool valid_throttle;

	double brake;
	bool valid_brake;

	double steering_rate;
	bool valid_steering_rate;

	double steering_target;
	bool valid_steering_target;


	bool parking_brake;
	bool valid_parking_brake;


	// target speed and acc
	double speed; // km/h
	bool valid_speed;

	double acceleration; // m/s^2
	bool valid_acceleration;

};

#endif // CONTROL_CMD_DATA_H
