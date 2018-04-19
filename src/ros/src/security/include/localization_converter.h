#ifndef LOCALIZATION_CONVERTER_H
#define LOCALIZATION_CONVERTER_H

#include "localization_data.h"
#include "common_converter.h"

#include "modules/localization/proto/pose.pb.h"
#include "modules/localization/proto/measure.pb.h"
#include "modules/localization/proto/localization.pb.h"

pose_ada convert_pose(const apollo::localization::Pose&);

MeasureState convert_measure_state(const apollo::localization::MeasureState&);

uncertainty_ada convert_uncertainty(const apollo::localization::Uncertainty&);

localization_estimate_ada convert_localization_estimate(const apollo::localization::LocalizationEstimate&);

localization_status_ada convert_localization_status(const apollo::localization::LocalizationStatus&);

#endif
