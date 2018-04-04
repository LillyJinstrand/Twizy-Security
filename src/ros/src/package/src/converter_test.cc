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
}

TEST_LIST = {
    {"PointENU" , test_convert_point_enu},
    {"Speed", test_convert_speed},
    {"Perception", test_convert_perception},
    {0}
};
