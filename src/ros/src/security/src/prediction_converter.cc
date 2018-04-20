#include "prediction_converter.h"

//IMPORTANT: Needs to respect MAX_NUMBER_POINTS
trajectory_ada convert_trajectory(const apollo::prediction::Trajectory& t){
    trajectory_ada out = {};

    if((out.valid_probability = t.has_probability()))
        out.probability = t.probability();
    out.trajectory_points_size = 0;
    
    for(int i=0; i < t.trajectory_point_size() && i < MAX_NUMBER_POINTS; i++){
        out.trajectory_points[i] = convert_trajectory_point(t.trajectory_point(i));
        out.trajectory_points_size++;
    }
    

    return out;
}

//IMPORTANT: Needs to respect MAX_NUMBER_TRAJECTORIES
prediction_obstacle_ada convert_prediction_obstacle(const apollo::prediction::PredictionObstacle& o){
    prediction_obstacle_ada out = {};

    if((out.valid_perception_obstacle = o.has_perception_obstacle()))
        out.perception_obstacle = convert_obstacle(o.perception_obstacle());
    if((out.valid_timestamp = o.has_timestamp()))
        out.timestamp = o.timestamp();
    if((out.valid_predicted_period = o.has_predicted_period()))
        out.predicted_period = o.predicted_period();
    
    //TODO: Handle the case of more than 10 trajectories more gracefully
    out.trajectory_size = 0;
    for(int i=0; i < o.trajectory_size() && i < MAX_NUMBER_TRAJECTORIES; i++){
        out.trajectory[i] = convert_trajectory(o.trajectory(i));
        out.trajectory_size++;
    }

    return out;
}

