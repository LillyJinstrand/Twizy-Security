#include "acutest/acutest.h"
#include "common_converter.h"
#include "common_data.h"
#include "speed_converter.h"
#include "localization_data.h"
#include "control_cmd_converter.h"
#include "perception_converter.h"
#include "localization_converter.h"

void test_convert_point_enu(){
    apollo::common::PointENU p1;
    p1.Clear();
    convert_point_enu(p1);
    simple_test();
    p1.set_x(1.0);
    p1.set_y(2.0);
    p1.set_z(3.0);

    point_enu_ada p2= {
        1.0,
        true,
        2.0,
        true,
        3.0,
        true
    };

    
    TEST_CHECK(p2.x == convert_point_enu(p1).x);
    TEST_CHECK(p2.y == convert_point_enu(p1).y);
    TEST_CHECK(p2.z == convert_point_enu(p1).z);

    TEST_CHECK(p2.valid_x == convert_point_enu(p1).valid_x);
    TEST_CHECK(p2.valid_y == convert_point_enu(p1).valid_y);
    TEST_CHECK(p2.valid_z == convert_point_enu(p1).valid_z);
   
    TEST_CHECK(true);
}

void test_convert_speed(){
    apollo::canbus::Chassis c;
    c.Clear();
    c.set_speed_mps(5.0f);
    speed_ada tmp = {};
    tmp.speed = 5.0f;
    TEST_CHECK(tmp.speed == convert_speed(c).speed);
}

void test_convert_perception(){
    apollo::perception::PerceptionObstacle o1;
    o1.Clear();

    o1.set_id(1);

    o1.set_theta(6.0);

    o1.mutable_position()->set_x(1.5);
    o1.mutable_position()->set_y(2.5);
    o1.mutable_position()->set_z(3.5);

    o1.mutable_velocity()->set_x(2.5);
    o1.mutable_velocity()->set_y(3.5);
    o1.mutable_velocity()->set_z(4.5);

    o1.set_length(10.0);
    o1.set_width(20.0);
    o1.set_height(30.0);

    o1.set_type(apollo::perception::PerceptionObstacle::PEDESTRIAN);

    o1.set_timestamp(100.0);
    o1.set_tracking_time(3.3);

    perception_obstacle_ada o2 = {};

    o2.valid_id = true;
    TEST_CHECK(o2.valid_id == convert_obstacle(o1).valid_id);
    o2.id = 1;
    TEST_CHECK(o2.id == convert_obstacle(o1).id);

    o2.valid_theta = true;
    TEST_CHECK(o2.valid_theta == convert_obstacle(o1).valid_theta);
    o2.theta = 6.0;
    TEST_CHECK(o2.theta == convert_obstacle(o1).theta);

    o2.velocity.x = 2.5;
    o2.velocity.valid_x = true;
    o2.velocity.y = 3.5;
    o2.velocity.valid_y = true;
    o2.velocity.z = 4.5;
    o2.velocity.valid_z = true;
    TEST_CHECK(o2.velocity.valid_x == convert_obstacle(o1).velocity.valid_x);
    TEST_CHECK(o2.velocity.x == convert_obstacle(o1).velocity.x);

    TEST_CHECK(o2.velocity.valid_y == convert_obstacle(o1).velocity.valid_y);
    TEST_CHECK(o2.velocity.y == convert_obstacle(o1).velocity.y);
    
    TEST_CHECK(o2.velocity.valid_z == convert_obstacle(o1).velocity.valid_z);
    TEST_CHECK(o2.velocity.z == convert_obstacle(o1).velocity.z);

    o2.position.x = 1.5;
    o2.position.valid_x = true;
    o2.position.y = 2.5;
    o2.position.valid_y = true;
    o2.position.z = 3.5;
    o2.position.valid_z = true;

    TEST_CHECK(o2.position.valid_x == convert_obstacle(o1).position.valid_x);
    TEST_CHECK(o2.position.x == convert_obstacle(o1).position.x);
    TEST_CHECK(o2.position.valid_y == convert_obstacle(o1).position.valid_y);
    TEST_CHECK(o2.position.y == convert_obstacle(o1).position.y);
    TEST_CHECK(o2.position.valid_z == convert_obstacle(o1).position.valid_z);
    TEST_CHECK(o2.position.z == convert_obstacle(o1).position.z);


    o2.length = 10.0;
    o2.valid_length = true;
    o2.width = 20.0;
    o2.valid_width = true;
    o2.height = 30.0;
    o2.valid_height = true;

    TEST_CHECK(o2.valid_length == convert_obstacle(o1).valid_length);
    TEST_CHECK(o2.length == convert_obstacle(o1).length);
    TEST_CHECK(o2.valid_width == convert_obstacle(o1).valid_width);
    TEST_CHECK(o2.width == convert_obstacle(o1).width);
    TEST_CHECK(o2.valid_height == convert_obstacle(o1).valid_height);
    TEST_CHECK(o2.height == convert_obstacle(o1).height);

    o2.tracking_time = 3.3;
    o2.valid_tracking_time = true;

    TEST_CHECK(o2.valid_tracking_time == convert_obstacle(o1).valid_tracking_time);
    TEST_CHECK(o2.tracking_time == convert_obstacle(o1).tracking_time);

    o2.type = PEDESTRIAN;
    o2.valid_type = true;

    TEST_CHECK(o2.valid_type == convert_obstacle(o1).valid_type);
    TEST_CHECK(o2.type == convert_obstacle(o1).type);

    o2.timestamp = 100.0;
    o2.valid_timestamp = true;

    TEST_CHECK(o2.valid_timestamp == convert_obstacle(o1).valid_timestamp);
    TEST_CHECK(o2.timestamp == convert_obstacle(o1).timestamp);
}

void test_convert_control_cmd(){
    apollo::control::ControlCommand c1;
    control_cmd_ada c2 = {};

    c2.valid_throttle = false;
    TEST_CHECK(c2.valid_throttle == convert_control_cmd(c1).valid_throttle);

    c1.set_throttle(6.6);
    c2.valid_throttle = true;
    c2.throttle = 6.6;
    TEST_CHECK(c2.valid_throttle == convert_control_cmd(c1).valid_throttle);
    TEST_CHECK(c2.throttle == convert_control_cmd(c1).throttle);

    c1.set_brake(7.7);
    c2.valid_brake = true;
    c2.brake = 7.7;
    TEST_CHECK(c2.valid_brake == convert_control_cmd(c1).valid_brake);
    TEST_CHECK(c2.brake == convert_control_cmd(c1).brake);

    c1.set_steering_rate(8.8);
    c2.valid_steering_rate = true;
    c2.steering_rate = 8.8;
    TEST_CHECK(c2.valid_steering_rate == convert_control_cmd(c1).valid_steering_rate);
    TEST_CHECK(c2.steering_rate == convert_control_cmd(c1).steering_rate);

    c1.set_steering_target(9.9);
    c2.valid_steering_target = true;
    c2.steering_target = 9.9;
    TEST_CHECK(c2.valid_steering_target == convert_control_cmd(c1).valid_steering_target);
    TEST_CHECK(c2.steering_target == convert_control_cmd(c1).steering_target);

    c1.set_parking_brake(true);
    c2.valid_parking_brake = true;
    c2.parking_brake = true;
    TEST_CHECK(c2.valid_parking_brake == convert_control_cmd(c1).valid_parking_brake);
    TEST_CHECK(c2.parking_brake == convert_control_cmd(c1).parking_brake);
}

void test_convert_pose(){
    apollo::localization::Pose p1;
    pose_ada p2;

    p1.mutable_position()->set_x(11.1);
    p1.mutable_position()->set_y(22.2);
    p1.mutable_position()->set_z(33.3);
    p2.valid_position = true;
    p2.position.x = 11.1;
    p2.position.y = 22.2;
    p2.position.z = 33.3;
    TEST_CHECK(p2.valid_position == convert_pose(p1).valid_position);
    TEST_CHECK(p2.position.x == convert_pose(p1).position.x);
    TEST_CHECK(p2.position.y == convert_pose(p1).position.y);
    TEST_CHECK(p2.position.z == convert_pose(p1).position.z);

    p1.mutable_orientation()->set_qx(1.1);
    p1.mutable_orientation()->set_qy(2.2);
    p1.mutable_orientation()->set_qz(3.3);
    p1.mutable_orientation()->set_qw(4.4);
    p2.orientation.qx = 1.1;
    p2.orientation.valid_qx = true;
    p2.orientation.qy = 2.2;
    p2.orientation.valid_qy = true;
    p2.orientation.qz = 3.3;
    p2.orientation.valid_qz = true;
    p2.orientation.qw = 4.4;
    p2.orientation.valid_qw = true;
    p2.valid_orientation = true;
    TEST_CHECK(p2.valid_orientation == convert_pose(p1).valid_orientation);
    TEST_CHECK(p2.orientation.qx == convert_pose(p1).orientation.qx);
    TEST_CHECK(p2.orientation.valid_qx = convert_pose(p1).orientation.valid_qx);
    TEST_CHECK(p2.orientation.qy == convert_pose(p1).orientation.qy);
    TEST_CHECK(p2.orientation.valid_qy = convert_pose(p1).orientation.valid_qy);
    TEST_CHECK(p2.orientation.qz == convert_pose(p1).orientation.qz);
    TEST_CHECK(p2.orientation.valid_qz = convert_pose(p1).orientation.valid_qz);
    TEST_CHECK(p2.orientation.qw == convert_pose(p1).orientation.qw);
    TEST_CHECK(p2.orientation.valid_qw = convert_pose(p1).orientation.valid_qw);

    p1.mutable_linear_velocity()->set_x(11);
    p1.mutable_linear_velocity()->set_y(22);
    p1.mutable_linear_velocity()->set_z(33);
    p2.valid_linear_velocity = true;
    p2.linear_velocity.x = 11;
    p2.linear_velocity.valid_x = true;
    p2.linear_velocity.y = 22;
    p2.linear_velocity.valid_y = true;
    p2.linear_velocity.z = 33;
    p2.linear_velocity.valid_z = true;
    TEST_CHECK(p2.valid_linear_velocity == convert_pose(p1).valid_linear_velocity);
    TEST_CHECK(p2.linear_velocity.x == convert_pose(p1).linear_velocity.x);
    TEST_CHECK(p2.linear_velocity.valid_x == convert_pose(p1).linear_velocity.valid_x);
    TEST_CHECK(p2.linear_velocity.y == convert_pose(p1).linear_velocity.y);
    TEST_CHECK(p2.linear_velocity.valid_y == convert_pose(p1).linear_velocity.valid_y);
    TEST_CHECK(p2.linear_velocity.z == convert_pose(p1).linear_velocity.z);
    TEST_CHECK(p2.linear_velocity.valid_z == convert_pose(p1).linear_velocity.valid_z);

    p1.mutable_linear_acceleration()->set_x(11);
    p1.mutable_linear_acceleration()->set_y(22);
    p1.mutable_linear_acceleration()->set_z(33);
    p2.valid_linear_acceleration = true;
    p2.linear_acceleration.x = 11;
    p2.linear_acceleration.valid_x = true;
    p2.linear_acceleration.y = 22;
    p2.linear_acceleration.valid_y = true;
    p2.linear_acceleration.z = 33;
    p2.linear_acceleration.valid_z = true;
    TEST_CHECK(p2.valid_linear_acceleration == convert_pose(p1).valid_linear_acceleration);
    TEST_CHECK(p2.linear_acceleration.x == convert_pose(p1).linear_acceleration.x);
    TEST_CHECK(p2.linear_acceleration.valid_x == convert_pose(p1).linear_acceleration.valid_x);
    TEST_CHECK(p2.linear_acceleration.y == convert_pose(p1).linear_acceleration.y);
    TEST_CHECK(p2.linear_acceleration.valid_y == convert_pose(p1).linear_acceleration.valid_y);
    TEST_CHECK(p2.linear_acceleration.z == convert_pose(p1).linear_acceleration.z);
    TEST_CHECK(p2.linear_acceleration.valid_z == convert_pose(p1).linear_acceleration.valid_z);

    p1.mutable_angular_velocity()->set_x(11);
    p1.mutable_angular_velocity()->set_y(22);
    p1.mutable_angular_velocity()->set_z(33);
    p2.valid_angular_velocity = true;
    p2.angular_velocity.x = 11;
    p2.angular_velocity.valid_x = true;
    p2.angular_velocity.y = 22;
    p2.angular_velocity.valid_y = true;
    p2.angular_velocity.z = 33;
    p2.angular_velocity.valid_z = true;
    TEST_CHECK(p2.valid_angular_velocity == convert_pose(p1).valid_angular_velocity);
    TEST_CHECK(p2.angular_velocity.x == convert_pose(p1).angular_velocity.x);
    TEST_CHECK(p2.angular_velocity.valid_x == convert_pose(p1).angular_velocity.valid_x);
    TEST_CHECK(p2.angular_velocity.y == convert_pose(p1).angular_velocity.y);
    TEST_CHECK(p2.angular_velocity.valid_y == convert_pose(p1).angular_velocity.valid_y);
    TEST_CHECK(p2.angular_velocity.z == convert_pose(p1).angular_velocity.z);
    TEST_CHECK(p2.angular_velocity.valid_z == convert_pose(p1).angular_velocity.valid_z);

    p1.mutable_linear_acceleration_vrf()->set_x(12);
    p1.mutable_linear_acceleration_vrf()->set_y(23);
    p1.mutable_linear_acceleration_vrf()->set_z(34);
    p2.valid_linear_acceleration_vrf = true;
    p2.linear_acceleration_vrf.x = 12;
    p2.linear_acceleration_vrf.valid_x = true;
    p2.linear_acceleration_vrf.y = 23;
    p2.linear_acceleration_vrf.valid_y = true;
    p2.linear_acceleration_vrf.z = 34;
    p2.linear_acceleration_vrf.valid_z = true;
    TEST_CHECK(p2.valid_linear_acceleration_vrf == convert_pose(p1).valid_linear_acceleration_vrf);
    TEST_CHECK(p2.linear_acceleration_vrf.x == convert_pose(p1).linear_acceleration_vrf.x);
    TEST_CHECK(p2.linear_acceleration_vrf.valid_x == convert_pose(p1).linear_acceleration_vrf.valid_x);
    TEST_CHECK(p2.linear_acceleration_vrf.y == convert_pose(p1).linear_acceleration_vrf.y);
    TEST_CHECK(p2.linear_acceleration_vrf.valid_y == convert_pose(p1).linear_acceleration_vrf.valid_y);
    TEST_CHECK(p2.linear_acceleration_vrf.z == convert_pose(p1).linear_acceleration_vrf.z);
    TEST_CHECK(p2.linear_acceleration_vrf.valid_z == convert_pose(p1).linear_acceleration_vrf.valid_z);

    p1.mutable_angular_velocity_vrf()->set_x(12);
    p1.mutable_angular_velocity_vrf()->set_y(23);
    p1.mutable_angular_velocity_vrf()->set_z(34);
    p2.valid_angular_velocity_vrf = true;
    p2.angular_velocity_vrf.x = 12;
    p2.angular_velocity_vrf.valid_x = true;
    p2.angular_velocity_vrf.y = 23;
    p2.angular_velocity_vrf.valid_y = true;
    p2.angular_velocity_vrf.z = 34;
    p2.angular_velocity_vrf.valid_z = true;
    TEST_CHECK(p2.valid_angular_velocity_vrf == convert_pose(p1).valid_angular_velocity_vrf);
    TEST_CHECK(p2.angular_velocity_vrf.x == convert_pose(p1).angular_velocity_vrf.x);
    TEST_CHECK(p2.angular_velocity_vrf.valid_x == convert_pose(p1).angular_velocity_vrf.valid_x);
    TEST_CHECK(p2.angular_velocity_vrf.y == convert_pose(p1).angular_velocity_vrf.y);
    TEST_CHECK(p2.angular_velocity_vrf.valid_y == convert_pose(p1).angular_velocity_vrf.valid_y);
    TEST_CHECK(p2.angular_velocity_vrf.z == convert_pose(p1).angular_velocity_vrf.z);
    TEST_CHECK(p2.angular_velocity_vrf.valid_z == convert_pose(p1).angular_velocity_vrf.valid_z);

    p1.mutable_euler_angles()->set_x(12);
    p1.mutable_euler_angles()->set_y(23);
    p1.mutable_euler_angles()->set_z(34);
    p2.valid_euler_angles = true;
    p2.euler_angles.x = 12;
    p2.euler_angles.valid_x = true;
    p2.euler_angles.y = 23;
    p2.euler_angles.valid_y = true;
    p2.euler_angles.z = 34;
    p2.euler_angles.valid_z = true;
    TEST_CHECK(p2.valid_euler_angles == convert_pose(p1).valid_euler_angles);
    TEST_CHECK(p2.euler_angles.x == convert_pose(p1).euler_angles.x);
    TEST_CHECK(p2.euler_angles.valid_x == convert_pose(p1).euler_angles.valid_x);
    TEST_CHECK(p2.euler_angles.y == convert_pose(p1).euler_angles.y);
    TEST_CHECK(p2.euler_angles.valid_y == convert_pose(p1).euler_angles.valid_y);
    TEST_CHECK(p2.euler_angles.z == convert_pose(p1).euler_angles.z);
    TEST_CHECK(p2.euler_angles.valid_z == convert_pose(p1).euler_angles.valid_z);
}

void test_localization_status(){
    apollo::localization::LocalizationStatus s1;
    localization_status_ada s2 = {};

    s1.set_fusion_status(apollo::localization::OK);
    s2.valid_fusion_status = true;
    s2.fusion_status = OK;
    TEST_CHECK(s2.valid_fusion_status == convert_localization_status(s1).valid_fusion_status);
    TEST_CHECK(s2.fusion_status == convert_localization_status(s1).fusion_status);

    s1.set_gnss_status(apollo::localization::OK);
    s2.valid_gnss_status = true;
    s2.gnss_status = OK;
    TEST_CHECK(s2.valid_gnss_status == convert_localization_status(s1).valid_gnss_status);
    TEST_CHECK(s2.gnss_status == convert_localization_status(s1).gnss_status);

    s1.set_lidar_status(apollo::localization::OK);
    s2.valid_lidar_status = true;
    s2.lidar_status = OK;
    TEST_CHECK(s2.valid_lidar_status == convert_localization_status(s1).valid_lidar_status);
    TEST_CHECK(s2.lidar_status == convert_localization_status(s1).lidar_status);

    s1.set_measurement_time(123);
    s2.valid_measurement_time = true;
    s2.measurement_time = 123;
    TEST_CHECK(s2.valid_measurement_time == convert_localization_status(s1).valid_measurement_time);
    TEST_CHECK(s2.measurement_time == convert_localization_status(s1).measurement_time);
}

void test_uncertainty(){
    apollo::localization::Uncertainty u1;
    uncertainty_ada u2 = {};

    //Position std dev
    u2.valid_position_std_dev = true;
    u1.mutable_position_std_dev()->set_x(1);
    u1.mutable_position_std_dev()->set_y(2);
    u1.mutable_position_std_dev()->set_z(3);
    u2.position_std_dev.x = 1;
    u2.position_std_dev.valid_x = true;
    u2.position_std_dev.y = 2;
    u2.position_std_dev.valid_y = true;
    u2.position_std_dev.z = 3;
    u2.position_std_dev.valid_z = true;
    TEST_CHECK(u2.valid_position_std_dev == convert_uncertainty(u1).valid_position_std_dev);
    TEST_CHECK(u2.position_std_dev.valid_x == convert_uncertainty(u1).position_std_dev.valid_x);
    TEST_CHECK(u2.position_std_dev.x == convert_uncertainty(u1).position_std_dev.x);
    TEST_CHECK(u2.position_std_dev.valid_y == convert_uncertainty(u1).position_std_dev.valid_y);
    TEST_CHECK(u2.position_std_dev.y == convert_uncertainty(u1).position_std_dev.y);
    TEST_CHECK(u2.position_std_dev.valid_z == convert_uncertainty(u1).position_std_dev.valid_z);
    TEST_CHECK(u2.position_std_dev.z == convert_uncertainty(u1).position_std_dev.z);

    //Orientation std dev
    u2.valid_orientation_std_dev = true;
    u1.mutable_orientation_std_dev()->set_x(2);
    u1.mutable_orientation_std_dev()->set_y(3);
    u1.mutable_orientation_std_dev()->set_z(4);
    u2.orientation_std_dev.x = 2;
    u2.orientation_std_dev.valid_x = true;
    u2.orientation_std_dev.y = 3;
    u2.orientation_std_dev.valid_y = true;
    u2.orientation_std_dev.z = 4;
    u2.orientation_std_dev.valid_z = true;
    TEST_CHECK(u2.valid_orientation_std_dev == convert_uncertainty(u1).valid_orientation_std_dev);
    TEST_CHECK(u2.orientation_std_dev.valid_x == convert_uncertainty(u1).orientation_std_dev.valid_x);
    TEST_CHECK(u2.orientation_std_dev.x == convert_uncertainty(u1).orientation_std_dev.x);
    TEST_CHECK(u2.orientation_std_dev.valid_y == convert_uncertainty(u1).orientation_std_dev.valid_y);
    TEST_CHECK(u2.orientation_std_dev.y == convert_uncertainty(u1).orientation_std_dev.y);
    TEST_CHECK(u2.orientation_std_dev.valid_z == convert_uncertainty(u1).orientation_std_dev.valid_z);
    TEST_CHECK(u2.orientation_std_dev.z == convert_uncertainty(u1).orientation_std_dev.z);
    
    //Linear velocity std dev
    u2.valid_linear_velocity_std_dev = true;
    u1.mutable_linear_velocity_std_dev()->set_x(4);
    u1.mutable_linear_velocity_std_dev()->set_y(5);
    u1.mutable_linear_velocity_std_dev()->set_z(6);
    u2.linear_velocity_std_dev.x = 4;
    u2.linear_velocity_std_dev.valid_x = true;
    u2.linear_velocity_std_dev.y = 5;
    u2.linear_velocity_std_dev.valid_y = true;
    u2.linear_velocity_std_dev.z = 6;
    u2.linear_velocity_std_dev.valid_z = true;
    TEST_CHECK(u2.valid_linear_velocity_std_dev == convert_uncertainty(u1).valid_linear_velocity_std_dev);
    TEST_CHECK(u2.linear_velocity_std_dev.valid_x == convert_uncertainty(u1).linear_velocity_std_dev.valid_x);
    TEST_CHECK(u2.linear_velocity_std_dev.x == convert_uncertainty(u1).linear_velocity_std_dev.x);
    TEST_CHECK(u2.linear_velocity_std_dev.valid_y == convert_uncertainty(u1).linear_velocity_std_dev.valid_y);
    TEST_CHECK(u2.linear_velocity_std_dev.y == convert_uncertainty(u1).linear_velocity_std_dev.y);
    TEST_CHECK(u2.linear_velocity_std_dev.valid_z == convert_uncertainty(u1).linear_velocity_std_dev.valid_z);
    TEST_CHECK(u2.linear_velocity_std_dev.z == convert_uncertainty(u1).linear_velocity_std_dev.z);

    //Linear acceleration std dev
    u2.valid_linear_acceleration_std_dev = true;
    u1.mutable_linear_acceleration_std_dev()->set_x(4);
    u1.mutable_linear_acceleration_std_dev()->set_y(5);
    u1.mutable_linear_acceleration_std_dev()->set_z(6);
    u2.linear_acceleration_std_dev.x = 4;
    u2.linear_acceleration_std_dev.valid_x = true;
    u2.linear_acceleration_std_dev.y = 5;
    u2.linear_acceleration_std_dev.valid_y = true;
    u2.linear_acceleration_std_dev.z = 6;
    u2.linear_acceleration_std_dev.valid_z = true;
    TEST_CHECK(u2.valid_linear_acceleration_std_dev == convert_uncertainty(u1).valid_linear_acceleration_std_dev);
    TEST_CHECK(u2.linear_acceleration_std_dev.valid_x == convert_uncertainty(u1).linear_acceleration_std_dev.valid_x);
    TEST_CHECK(u2.linear_acceleration_std_dev.x == convert_uncertainty(u1).linear_acceleration_std_dev.x);
    TEST_CHECK(u2.linear_acceleration_std_dev.valid_y == convert_uncertainty(u1).linear_acceleration_std_dev.valid_y);
    TEST_CHECK(u2.linear_acceleration_std_dev.y == convert_uncertainty(u1).linear_acceleration_std_dev.y);
    TEST_CHECK(u2.linear_acceleration_std_dev.valid_z == convert_uncertainty(u1).linear_acceleration_std_dev.valid_z);
    TEST_CHECK(u2.linear_acceleration_std_dev.z == convert_uncertainty(u1).linear_acceleration_std_dev.z);

    //angular velocity std dev
    u2.valid_angular_velocity_std_dev = true;
    u1.mutable_angular_velocity_std_dev()->set_x(4);
    u1.mutable_angular_velocity_std_dev()->set_y(5);
    u1.mutable_angular_velocity_std_dev()->set_z(6);
    u2.angular_velocity_std_dev.x = 4;
    u2.angular_velocity_std_dev.valid_x = true;
    u2.angular_velocity_std_dev.y = 5;
    u2.angular_velocity_std_dev.valid_y = true;
    u2.angular_velocity_std_dev.z = 6;
    u2.angular_velocity_std_dev.valid_z = true;
    TEST_CHECK(u2.valid_angular_velocity_std_dev == convert_uncertainty(u1).valid_angular_velocity_std_dev);
    TEST_CHECK(u2.angular_velocity_std_dev.valid_x == convert_uncertainty(u1).angular_velocity_std_dev.valid_x);
    TEST_CHECK(u2.angular_velocity_std_dev.x == convert_uncertainty(u1).angular_velocity_std_dev.x);
    TEST_CHECK(u2.angular_velocity_std_dev.valid_y == convert_uncertainty(u1).angular_velocity_std_dev.valid_y);
    TEST_CHECK(u2.angular_velocity_std_dev.y == convert_uncertainty(u1).angular_velocity_std_dev.y);
    TEST_CHECK(u2.angular_velocity_std_dev.valid_z == convert_uncertainty(u1).angular_velocity_std_dev.valid_z);
    TEST_CHECK(u2.angular_velocity_std_dev.z == convert_uncertainty(u1).angular_velocity_std_dev.z);
}

void test_localization_estimate(){
    apollo::localization::LocalizationEstimate l1;
    localization_estimate_ada l2 = {};

    l1.set_measurement_time(152);
    l2.valid_measurement_time = true;
    l2.measurement_time = 152;
    TEST_CHECK(l2.measurement_time == convert_localization_estimate(l1).measurement_time);
}

TEST_LIST = {
    {"PointENU" , test_convert_point_enu},
    {"Speed", test_convert_speed},
    {"Perception", test_convert_perception},
    {"Control Cmd", test_convert_control_cmd},
    {"Pose", test_convert_pose},
    {"Localization status", test_localization_status},
    {"Uncertainty", test_uncertainty},
    {"Localization estimate", test_localization_estimate},
    {0}
};
