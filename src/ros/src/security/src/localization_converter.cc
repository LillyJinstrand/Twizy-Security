#include "localization_converter.h"

pose_ada convert_pose(const apollo::localization::Pose& p){
    pose_ada out = {};

    if((out.valid_position = p.has_position()))
        out.position = convert_point_enu(p.position());
    if((out.valid_orientation = p.has_orientation()))
        out.orientation = convert_quaternion(p.orientation());
    if((out.valid_linear_velocity = p.has_linear_velocity()))
        out.linear_velocity = convert_point_3d(p.linear_velocity());
    if((out.valid_linear_acceleration = p.has_linear_acceleration()))
        out.linear_acceleration = convert_point_3d(p.linear_acceleration());
    if((out.valid_angular_velocity = p.has_angular_velocity()))
        out.angular_velocity = convert_point_3d(p.angular_velocity());
    if((out.valid_heading = p.has_heading()))
        out.heading = p.heading();
    if((out.valid_linear_acceleration_vrf = p.has_linear_acceleration_vrf()))
        out.linear_acceleration_vrf = convert_point_3d(p.linear_acceleration_vrf());
    if((out.valid_angular_velocity_vrf = p.has_angular_velocity_vrf()))
        out.angular_velocity_vrf = convert_point_3d(p.angular_velocity_vrf());
    if((out.valid_euler_angles = p.has_euler_angles()))
        out.euler_angles = convert_point_3d(p.euler_angles());

    return out;
}

MeasureState convert_measure_state(const apollo::localization::MeasureState& m){
    switch (m){
        case apollo::localization::NOT_VALID:
            return NOT_VALID;
            break;
        case apollo::localization::NOT_STABLE:
            return NOT_STABLE;
            break;
        case apollo::localization::OK:
            return OK;
            break;
        case apollo::localization::VALID:
            return VALID;
            break;
    }
}

uncertainty_ada convert_uncertainty(const apollo::localization::Uncertainty& u){
    uncertainty_ada out = {};
    
    if((out.valid_position_std_dev = u.has_position_std_dev()))
        out.position_std_dev = convert_point_3d(u.position_std_dev());
    if((out.valid_orientation_std_dev = u.has_orientation_std_dev()))
        out.orientation_std_dev = convert_point_3d(u.orientation_std_dev());
    if((out.valid_linear_velocity_std_dev = u.has_linear_velocity_std_dev()))
        out.linear_velocity_std_dev = convert_point_3d(u.linear_velocity_std_dev());
    if((out.valid_linear_acceleration_std_dev = u.has_linear_acceleration_std_dev()))
        out.linear_acceleration_std_dev = convert_point_3d(u.linear_acceleration_std_dev());
    if((out.valid_angular_velocity_std_dev = u.has_angular_velocity_std_dev()))
        out.angular_velocity_std_dev = convert_point_3d(u.angular_velocity_std_dev());
   
    return out;
}

localization_estimate_ada convert_localization_estimate(const apollo::localization::LocalizationEstimate& e){
    localization_estimate_ada out = {};

    if((out.valid_pose = e.has_pose()))
        out.pose = convert_pose(e.pose());
    if((out.valid_uncertainty = e.has_uncertainty()))
        out.uncertainty = convert_uncertainty(e.uncertainty());
    if((out.valid_measurement_time = e.has_measurement_time()))
        out.measurement_time = e.measurement_time();

    return out;
}

localization_status_ada convert_localization_status(const apollo::localization::LocalizationStatus& s){
    localization_status_ada out = {};

    if((out.valid_fusion_status = s.has_fusion_status()))
        out.fusion_status = convert_measure_state(s.fusion_status());
    if((out.valid_gnss_status = s.has_gnss_status()))
        out.gnss_status = convert_measure_state(s.gnss_status());
    if((out.valid_lidar_status = s.has_lidar_status()))
        out.lidar_status = convert_measure_state(s.lidar_status());
    if((out.valid_measurement_time = s.has_measurement_time()))
        out.measurement_time = s.measurement_time();

    return out;
}
