#include "acutest/acutest.h"
#include "common_converter.h"
#include "common_data.h"
#include "speed_converter.h"

#include "perception_converter.h"

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
    o2.id = 1;

    o2.valid_theta = true;
    o2.theta = 6.0;

    o2.velocity.x = 2.5;
    o2.velocity.y = 3.5;
    o2.velocity.z = 4.5;
}

TEST_LIST = {
    {"PointENU" , test_convert_point_enu},
    {"Speed", test_convert_speed},
    {"Perception", test_convert_perception},
    {0}
};
