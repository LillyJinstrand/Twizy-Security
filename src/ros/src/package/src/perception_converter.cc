#include "perception_converter.h"

perception_obstacle_ada convert_obstacle(const apollo::perception::PerceptionObstacle& obs){
    perception_obstacle_ada ada_obs = {};

    if((ada_obs.valid_id = obs.has_id())){
        ada_obs.id = obs.id();
    }

    if((ada_obs.valid_theta = obs.has_theta()))
        ada_obs.theta = obs.theta();

    if((ada_obs.valid_velocity = obs.has_velocity()))
        ada_obs.velocity = convert_point(obs.velocity());
    

    if((ada_obs.valid_position = obs.has_position())){
        ada_obs.position = convert_point(obs.position());
    }

    if((ada_obs.valid_length = obs.has_length()))
        ada_obs.length = obs.length();
    if((ada_obs.valid_width = obs.has_width()))
        ada_obs.width = obs.width();
    if((ada_obs.valid_height = obs.has_height()))
        ada_obs.height = obs.height();

    if((ada_obs.valid_tracking_time = obs.has_tracking_time()))
        ada_obs.tracking_time = obs.tracking_time();

    if((ada_obs.valid_type = obs.has_type())){
        switch(obs.type()){
           case 0:
               ada_obs.type = UNKNOWN;
               break;
           case 1:
               ada_obs.type = UNKNOWN_MOVABLE;
               break;
           case 2:
               ada_obs.type = UNKNOWN_UNMOVABLE;
               break;
           case 3:
               ada_obs.type = PEDESTRIAN;
               break;
           case 4:
               ada_obs.type = BICYCLE;
               break;
           case 5:
               ada_obs.type = VEHICLE;
               break;
        }
    }
    if((ada_obs.valid_timestamp = obs.has_timestamp()))
        ada_obs.timestamp = obs.timestamp();
    if((ada_obs.valid_tracking_time = obs.has_tracking_time()))
        ada_obs.tracking_time = obs.tracking_time();
    return ada_obs;
}
