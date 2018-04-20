#ifndef PERCEPTION_CONVERTER_H
#define PERCEPTION_CONVERTER_H

#include "modules/perception/proto/perception_obstacle.pb.h"
#include "common_converter.h"
#include "perception_data.h"

perception_obstacle_ada convert_obstacle(const apollo::perception::PerceptionObstacle&);

#endif
