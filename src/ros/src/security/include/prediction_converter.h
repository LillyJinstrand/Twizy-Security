#ifndef PREDICTION_CONVERTER_H
#define PREDICTION_CONVERTER_H

#include "common_converter.h"
#include "perception_converter.h"
#include "prediction_data.h"

trajectory_ada convert_trajectory(const apollo::prediction::Trajectory&);

prediction_obstacle_ada convert_prediction_obstacle(const apollo::prediction::PredictionObstacle&);

#endif
