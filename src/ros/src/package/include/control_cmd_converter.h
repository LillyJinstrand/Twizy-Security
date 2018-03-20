#ifndef CONTROL_CMD_CONVERTER_H
#define CONTROL_CMD_CONVERTER_H

#include "control_cmd_data.h"
#include "modules/control/proto/control_cmd.pb.h"

control_cmd_ada convert_control_cmd(apollo::control::ControlCommand&);

#endif
