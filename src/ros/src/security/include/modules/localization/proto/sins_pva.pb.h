// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: modules/localization/proto/sins_pva.proto

#ifndef PROTOBUF_modules_2flocalization_2fproto_2fsins_5fpva_2eproto__INCLUDED
#define PROTOBUF_modules_2flocalization_2fproto_2fsins_5fpva_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
// @@protoc_insertion_point(includes)
namespace apollo {
namespace common {
class Header;
class HeaderDefaultTypeInternal;
extern HeaderDefaultTypeInternal _Header_default_instance_;
class Point2D;
class Point2DDefaultTypeInternal;
extern Point2DDefaultTypeInternal _Point2D_default_instance_;
class Point3D;
class Point3DDefaultTypeInternal;
extern Point3DDefaultTypeInternal _Point3D_default_instance_;
class PointENU;
class PointENUDefaultTypeInternal;
extern PointENUDefaultTypeInternal _PointENU_default_instance_;
class PointLLH;
class PointLLHDefaultTypeInternal;
extern PointLLHDefaultTypeInternal _PointLLH_default_instance_;
class Quaternion;
class QuaternionDefaultTypeInternal;
extern QuaternionDefaultTypeInternal _Quaternion_default_instance_;
}  // namespace common
namespace localization {
class IntegSinsPva;
class IntegSinsPvaDefaultTypeInternal;
extern IntegSinsPvaDefaultTypeInternal _IntegSinsPva_default_instance_;
}  // namespace localization
}  // namespace apollo

namespace apollo {
namespace localization {

namespace protobuf_modules_2flocalization_2fproto_2fsins_5fpva_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_modules_2flocalization_2fproto_2fsins_5fpva_2eproto

// ===================================================================

class IntegSinsPva : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:apollo.localization.IntegSinsPva) */ {
 public:
  IntegSinsPva();
  virtual ~IntegSinsPva();

  IntegSinsPva(const IntegSinsPva& from);

  inline IntegSinsPva& operator=(const IntegSinsPva& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const IntegSinsPva& default_instance();

  static inline const IntegSinsPva* internal_default_instance() {
    return reinterpret_cast<const IntegSinsPva*>(
               &_IntegSinsPva_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(IntegSinsPva* other);

  // implements Message ----------------------------------------------

  inline IntegSinsPva* New() const PROTOBUF_FINAL { return New(NULL); }

  IntegSinsPva* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const IntegSinsPva& from);
  void MergeFrom(const IntegSinsPva& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(IntegSinsPva* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated double pva_covar = 5 [packed = true];
  int pva_covar_size() const;
  void clear_pva_covar();
  static const int kPvaCovarFieldNumber = 5;
  double pva_covar(int index) const;
  void set_pva_covar(int index, double value);
  void add_pva_covar(double value);
  const ::google::protobuf::RepeatedField< double >&
      pva_covar() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_pva_covar();

  // optional .apollo.common.Header header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  const ::apollo::common::Header& header() const;
  ::apollo::common::Header* mutable_header();
  ::apollo::common::Header* release_header();
  void set_allocated_header(::apollo::common::Header* header);

  // optional .apollo.common.PointLLH position = 2;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 2;
  const ::apollo::common::PointLLH& position() const;
  ::apollo::common::PointLLH* mutable_position();
  ::apollo::common::PointLLH* release_position();
  void set_allocated_position(::apollo::common::PointLLH* position);

  // optional .apollo.common.Point3D velocity = 3;
  bool has_velocity() const;
  void clear_velocity();
  static const int kVelocityFieldNumber = 3;
  const ::apollo::common::Point3D& velocity() const;
  ::apollo::common::Point3D* mutable_velocity();
  ::apollo::common::Point3D* release_velocity();
  void set_allocated_velocity(::apollo::common::Point3D* velocity);

  // optional .apollo.common.Point3D attitude = 4;
  bool has_attitude() const;
  void clear_attitude();
  static const int kAttitudeFieldNumber = 4;
  const ::apollo::common::Point3D& attitude() const;
  ::apollo::common::Point3D* mutable_attitude();
  ::apollo::common::Point3D* release_attitude();
  void set_allocated_attitude(::apollo::common::Point3D* attitude);

  // optional bool init_and_alignment = 6;
  bool has_init_and_alignment() const;
  void clear_init_and_alignment();
  static const int kInitAndAlignmentFieldNumber = 6;
  bool init_and_alignment() const;
  void set_init_and_alignment(bool value);

  // @@protoc_insertion_point(class_scope:apollo.localization.IntegSinsPva)
 private:
  void set_has_header();
  void clear_has_header();
  void set_has_position();
  void clear_has_position();
  void set_has_velocity();
  void clear_has_velocity();
  void set_has_attitude();
  void clear_has_attitude();
  void set_has_init_and_alignment();
  void clear_has_init_and_alignment();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< double > pva_covar_;
  mutable int _pva_covar_cached_byte_size_;
  ::apollo::common::Header* header_;
  ::apollo::common::PointLLH* position_;
  ::apollo::common::Point3D* velocity_;
  ::apollo::common::Point3D* attitude_;
  bool init_and_alignment_;
  friend struct protobuf_modules_2flocalization_2fproto_2fsins_5fpva_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// IntegSinsPva

// optional .apollo.common.Header header = 1;
inline bool IntegSinsPva::has_header() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void IntegSinsPva::set_has_header() {
  _has_bits_[0] |= 0x00000001u;
}
inline void IntegSinsPva::clear_has_header() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void IntegSinsPva::clear_header() {
  if (header_ != NULL) header_->::apollo::common::Header::Clear();
  clear_has_header();
}
inline const ::apollo::common::Header& IntegSinsPva::header() const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.header)
  return header_ != NULL ? *header_
                         : *::apollo::common::Header::internal_default_instance();
}
inline ::apollo::common::Header* IntegSinsPva::mutable_header() {
  set_has_header();
  if (header_ == NULL) {
    header_ = new ::apollo::common::Header;
  }
  // @@protoc_insertion_point(field_mutable:apollo.localization.IntegSinsPva.header)
  return header_;
}
inline ::apollo::common::Header* IntegSinsPva::release_header() {
  // @@protoc_insertion_point(field_release:apollo.localization.IntegSinsPva.header)
  clear_has_header();
  ::apollo::common::Header* temp = header_;
  header_ = NULL;
  return temp;
}
inline void IntegSinsPva::set_allocated_header(::apollo::common::Header* header) {
  delete header_;
  header_ = header;
  if (header) {
    set_has_header();
  } else {
    clear_has_header();
  }
  // @@protoc_insertion_point(field_set_allocated:apollo.localization.IntegSinsPva.header)
}

// optional .apollo.common.PointLLH position = 2;
inline bool IntegSinsPva::has_position() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void IntegSinsPva::set_has_position() {
  _has_bits_[0] |= 0x00000002u;
}
inline void IntegSinsPva::clear_has_position() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void IntegSinsPva::clear_position() {
  if (position_ != NULL) position_->::apollo::common::PointLLH::Clear();
  clear_has_position();
}
inline const ::apollo::common::PointLLH& IntegSinsPva::position() const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.position)
  return position_ != NULL ? *position_
                         : *::apollo::common::PointLLH::internal_default_instance();
}
inline ::apollo::common::PointLLH* IntegSinsPva::mutable_position() {
  set_has_position();
  if (position_ == NULL) {
    position_ = new ::apollo::common::PointLLH;
  }
  // @@protoc_insertion_point(field_mutable:apollo.localization.IntegSinsPva.position)
  return position_;
}
inline ::apollo::common::PointLLH* IntegSinsPva::release_position() {
  // @@protoc_insertion_point(field_release:apollo.localization.IntegSinsPva.position)
  clear_has_position();
  ::apollo::common::PointLLH* temp = position_;
  position_ = NULL;
  return temp;
}
inline void IntegSinsPva::set_allocated_position(::apollo::common::PointLLH* position) {
  delete position_;
  position_ = position;
  if (position) {
    set_has_position();
  } else {
    clear_has_position();
  }
  // @@protoc_insertion_point(field_set_allocated:apollo.localization.IntegSinsPva.position)
}

// optional .apollo.common.Point3D velocity = 3;
inline bool IntegSinsPva::has_velocity() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void IntegSinsPva::set_has_velocity() {
  _has_bits_[0] |= 0x00000004u;
}
inline void IntegSinsPva::clear_has_velocity() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void IntegSinsPva::clear_velocity() {
  if (velocity_ != NULL) velocity_->::apollo::common::Point3D::Clear();
  clear_has_velocity();
}
inline const ::apollo::common::Point3D& IntegSinsPva::velocity() const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.velocity)
  return velocity_ != NULL ? *velocity_
                         : *::apollo::common::Point3D::internal_default_instance();
}
inline ::apollo::common::Point3D* IntegSinsPva::mutable_velocity() {
  set_has_velocity();
  if (velocity_ == NULL) {
    velocity_ = new ::apollo::common::Point3D;
  }
  // @@protoc_insertion_point(field_mutable:apollo.localization.IntegSinsPva.velocity)
  return velocity_;
}
inline ::apollo::common::Point3D* IntegSinsPva::release_velocity() {
  // @@protoc_insertion_point(field_release:apollo.localization.IntegSinsPva.velocity)
  clear_has_velocity();
  ::apollo::common::Point3D* temp = velocity_;
  velocity_ = NULL;
  return temp;
}
inline void IntegSinsPva::set_allocated_velocity(::apollo::common::Point3D* velocity) {
  delete velocity_;
  velocity_ = velocity;
  if (velocity) {
    set_has_velocity();
  } else {
    clear_has_velocity();
  }
  // @@protoc_insertion_point(field_set_allocated:apollo.localization.IntegSinsPva.velocity)
}

// optional .apollo.common.Point3D attitude = 4;
inline bool IntegSinsPva::has_attitude() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void IntegSinsPva::set_has_attitude() {
  _has_bits_[0] |= 0x00000008u;
}
inline void IntegSinsPva::clear_has_attitude() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void IntegSinsPva::clear_attitude() {
  if (attitude_ != NULL) attitude_->::apollo::common::Point3D::Clear();
  clear_has_attitude();
}
inline const ::apollo::common::Point3D& IntegSinsPva::attitude() const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.attitude)
  return attitude_ != NULL ? *attitude_
                         : *::apollo::common::Point3D::internal_default_instance();
}
inline ::apollo::common::Point3D* IntegSinsPva::mutable_attitude() {
  set_has_attitude();
  if (attitude_ == NULL) {
    attitude_ = new ::apollo::common::Point3D;
  }
  // @@protoc_insertion_point(field_mutable:apollo.localization.IntegSinsPva.attitude)
  return attitude_;
}
inline ::apollo::common::Point3D* IntegSinsPva::release_attitude() {
  // @@protoc_insertion_point(field_release:apollo.localization.IntegSinsPva.attitude)
  clear_has_attitude();
  ::apollo::common::Point3D* temp = attitude_;
  attitude_ = NULL;
  return temp;
}
inline void IntegSinsPva::set_allocated_attitude(::apollo::common::Point3D* attitude) {
  delete attitude_;
  attitude_ = attitude;
  if (attitude) {
    set_has_attitude();
  } else {
    clear_has_attitude();
  }
  // @@protoc_insertion_point(field_set_allocated:apollo.localization.IntegSinsPva.attitude)
}

// repeated double pva_covar = 5 [packed = true];
inline int IntegSinsPva::pva_covar_size() const {
  return pva_covar_.size();
}
inline void IntegSinsPva::clear_pva_covar() {
  pva_covar_.Clear();
}
inline double IntegSinsPva::pva_covar(int index) const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.pva_covar)
  return pva_covar_.Get(index);
}
inline void IntegSinsPva::set_pva_covar(int index, double value) {
  pva_covar_.Set(index, value);
  // @@protoc_insertion_point(field_set:apollo.localization.IntegSinsPva.pva_covar)
}
inline void IntegSinsPva::add_pva_covar(double value) {
  pva_covar_.Add(value);
  // @@protoc_insertion_point(field_add:apollo.localization.IntegSinsPva.pva_covar)
}
inline const ::google::protobuf::RepeatedField< double >&
IntegSinsPva::pva_covar() const {
  // @@protoc_insertion_point(field_list:apollo.localization.IntegSinsPva.pva_covar)
  return pva_covar_;
}
inline ::google::protobuf::RepeatedField< double >*
IntegSinsPva::mutable_pva_covar() {
  // @@protoc_insertion_point(field_mutable_list:apollo.localization.IntegSinsPva.pva_covar)
  return &pva_covar_;
}

// optional bool init_and_alignment = 6;
inline bool IntegSinsPva::has_init_and_alignment() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void IntegSinsPva::set_has_init_and_alignment() {
  _has_bits_[0] |= 0x00000010u;
}
inline void IntegSinsPva::clear_has_init_and_alignment() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void IntegSinsPva::clear_init_and_alignment() {
  init_and_alignment_ = false;
  clear_has_init_and_alignment();
}
inline bool IntegSinsPva::init_and_alignment() const {
  // @@protoc_insertion_point(field_get:apollo.localization.IntegSinsPva.init_and_alignment)
  return init_and_alignment_;
}
inline void IntegSinsPva::set_init_and_alignment(bool value) {
  set_has_init_and_alignment();
  init_and_alignment_ = value;
  // @@protoc_insertion_point(field_set:apollo.localization.IntegSinsPva.init_and_alignment)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace localization
}  // namespace apollo

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_modules_2flocalization_2fproto_2fsins_5fpva_2eproto__INCLUDED