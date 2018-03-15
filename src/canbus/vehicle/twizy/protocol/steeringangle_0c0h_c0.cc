/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/twizy/protocol/steeringangle_0c0h_c0.h"


#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace twizy {

Steeringangle0c0hc0::Steeringangle0c0hc0() {}
const int32_t Steeringangle0c0hc0::ID = 0xC0;

void Steeringangle0c0hc0::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_twizy()->mutable_steeringangle_0c0h_c0()->set_sas_chcksum(sas_chcksum(bytes, length));
  chassis->mutable_twizy()->mutable_steeringangle_0c0h_c0()->set_msg_count(msg_count(bytes, length));
  chassis->mutable_twizy()->mutable_steeringangle_0c0h_c0()->set_lws_stat(lws_stat(bytes, length));
  chassis->mutable_twizy()->mutable_steeringangle_0c0h_c0()->set_lws_speed(lws_speed(bytes, length));
  chassis->mutable_twizy()->mutable_steeringangle_0c0h_c0()->set_lws(lws(bytes, length));
}

// config detail: {'name': 'sas_chcksum', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 36, 'type': 'int', 'order': 'intel', 'physical_unit': ''}
int Steeringangle0c0hc0::sas_chcksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'name': 'msg_count', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 32, 'type': 'int', 'order': 'intel', 'physical_unit': ''}
int Steeringangle0c0hc0::msg_count(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'name': 'lws_stat', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 24, 'type': 'int', 'order': 'intel', 'physical_unit': ''}
int Steeringangle0c0hc0::lws_stat(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'name': 'lws_speed', 'offset': 0.0, 'precision': 4.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 16, 'type': 'double', 'order': 'intel', 'physical_unit': '\xb0/s'}
double Steeringangle0c0hc0::lws_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 4.000000;
  return ret;
}

// config detail: {'name': 'lws', 'offset': 0.0, 'precision': 0.1, 'len': 16, 'is_signed_var': True, 'physical_range': '[-40|40]', 'bit': 0, 'type': 'double', 'order': 'intel', 'physical_unit': '\xb0'}
double Steeringangle0c0hc0::lws(const std::uint8_t* bytes, double angle) const {
  angle = ProtocolData::BoundedValue(-40.0, 40.0, angle);

  Byte frame_high(bytes + 1);
  // TODO: ask steering if + is left or right!!!!§
  // for now assume that left(+) and right(-). write 255 for -, 0 for +.
  if (angle < 0)
    frame_high.set_value(0xFF);
  else
    frame_high.set_value(0x00);

  // 
  int32_t a = angle / 0.100000;
  if (a < 0)
    a += 0x10000;
   
  std::uint8_t t = 0;
  t = a & 0xFF;
  Byte frame_low(bytes + 0);
  frame_low.set_value(t, 0, 8);
  
  a <<= 16;
  a >>= 16;

  double ret = a * 0.100000;
  return ret;
}

Steeringangle0c0hc0 *Steeringangle0c0hc0::set_steering_angle(double angle) {
	steering_angle_ = angle;
	return this;
}

// TODO: Add additional setter functions for what we need.
void Steeringangle0c0hc0::UpdateData(uint8_t *data) {
	set_steering_angle(data, steering_angle_)
}

// TODO: add additional variables.
void Steeringangle0c0hc0::Reset() {
	steering_angle_ = 0.0;
}
}  // namespace twizy
}  // namespace canbus
}  // namespace apollo
