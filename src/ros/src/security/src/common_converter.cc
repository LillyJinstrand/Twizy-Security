#include "common_converter.h"

bool simple_test(){
    return true;
}

point_enu_ada convert_point_enu(const apollo::common::PointENU& p){
    point_enu_ada out = {}; 
    if((out.valid_x = p.has_x()))
        out.x = p.x();
    if((out.valid_y = p.has_y()))
        out.y = p.y();
    if((out.valid_z = p.has_z()))
        out.z = p.z();
    return out;
}

quaternion_ada convert_quaternion(const apollo::common::Quaternion& q){
    quaternion_ada out = {};
    if((out.valid_qx = q.has_qx()))
        out.qx = q.qx();
    if((out.valid_qy = q.has_qy()))
        out.qy = q.qy();
    if((out.valid_qz = q.has_qz()))
        out.qz = q.qz();
    if((out.valid_qw = q.has_qw()))
        out.qw = q.qw();
    return out;
}

path_point_ada convert_path_point(const apollo::common::PathPoint& p){
    path_point_ada out = {};

    if((out.valid_x = p.has_x()))
        out.x = p.x();
    if((out.valid_y = p.has_y()))
        out.y = p.y();
    if((out.valid_z = p.has_z()))
        out.z = p.z();

    if((out.valid_theta = p.has_theta()))
        out.theta = p.theta();

    if((out.valid_kappa = p.has_kappa()))
        out.kappa = p.kappa();
    if((out.valid_dkappa = p.has_dkappa()))
        out.dkappa = p.dkappa();
    if((out.valid_ddkappa = p.has_ddkappa()))
        out.ddkappa = p.ddkappa();

    if((out.valid_s = p.has_s()))
        out.s = p.s();
    return out;
}

trajectory_point_ada convert_trajectory_point(const apollo::common::TrajectoryPoint& p){
    trajectory_point_ada out = {};
    if((out.valid_point = p.has_path_point()))
        //out.path_point = convert_path_point(p.path_point());
    if((out.valid_v = p.has_v()))
        out.v = p.v();
    if((out.valid_a = p.has_a()))
        out.a = p.a();
    if((out.valid_relative_time = p.has_relative_time()))
        out.relative_time = p.relative_time();
    
}

point_3d convert_point_3d(const apollo::common::Point3D& p){
    point_3d out = {};
    if((out.valid_x = p.has_x()))
        out.x = p.x();
    if((out.valid_y = p.has_y()))
        out.y = p.y();
    if((out.valid_z = p.has_z()))
        out.z = p.z();
    return out;
}
point_3d convert_point(const apollo::perception::Point& p){
    point_3d out = {};
    if((out.valid_x = p.has_x()))
        out.x = p.x();
    if((out.valid_y = p.has_y()))
        out.y = p.y();
    if((out.valid_z = p.has_z()))
        out.z = p.z();
    return out;
}
