#ifndef COMMON_CONVERTER_H
#define COMMON_CONVERTER_H

#include "common_data.h"

#include "modules/common/proto/geometry.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"

bool simple_test();

point_enu_ada convert_point_enu(const apollo::common::PointENU&);

quaternion_ada convert_quaternion(const apollo::common::Quaternion&);

path_point_ada convert_path_point(const apollo::common::PathPoint&);

trajectory_point_ada convert_trajectory_point(const apollo::common::TrajectoryPoint&);

//These functions are identiacal except for the types.
//Needed since apollo is inconsistant with their types for points
point_3d convert_point_3d(const apollo::common::Point3D&);
point_3d convert_point(const apollo::perception::Point&);
#endif
