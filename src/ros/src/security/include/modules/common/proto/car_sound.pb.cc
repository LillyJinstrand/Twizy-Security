// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: modules/common/proto/car_sound.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "modules/common/proto/car_sound.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace apollo {
namespace common {
namespace sound {
class SoundRequestDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<SoundRequest> {
} _SoundRequest_default_instance_;

namespace protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, header_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, priority_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, mode_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SoundRequest, words_),
  1,
  2,
  3,
  0,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 9, sizeof(SoundRequest)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_SoundRequest_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "modules/common/proto/car_sound.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _SoundRequest_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::apollo::common::protobuf_modules_2fcommon_2fproto_2fheader_2eproto::InitDefaults();
  _SoundRequest_default_instance_.DefaultConstruct();
  _SoundRequest_default_instance_.get_mutable()->header_ = const_cast< ::apollo::common::Header*>(
      ::apollo::common::Header::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n$modules/common/proto/car_sound.proto\022\023"
      "apollo.common.sound\032!modules/common/prot"
      "o/header.proto\"\210\002\n\014SoundRequest\022%\n\006heade"
      "r\030\001 \001(\0132\025.apollo.common.Header\022A\n\010priori"
      "ty\030\002 \001(\0162/.apollo.common.sound.SoundRequ"
      "est.PriorityLevel\0224\n\004mode\030\003 \001(\0162&.apollo"
      ".common.sound.SoundRequest.Mode\022\r\n\005words"
      "\030\004 \001(\t\".\n\rPriorityLevel\022\007\n\003LOW\020\000\022\n\n\006MEDI"
      "UM\020\001\022\010\n\004HIGH\020\002\"\031\n\004Mode\022\007\n\003SAY\020\000\022\010\n\004BEEP\020"
      "\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 361);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "modules/common/proto/car_sound.proto", &protobuf_RegisterTypes);
  ::apollo::common::protobuf_modules_2fcommon_2fproto_2fheader_2eproto::AddDescriptors();
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto

const ::google::protobuf::EnumDescriptor* SoundRequest_PriorityLevel_descriptor() {
  protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::file_level_enum_descriptors[0];
}
bool SoundRequest_PriorityLevel_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const SoundRequest_PriorityLevel SoundRequest::LOW;
const SoundRequest_PriorityLevel SoundRequest::MEDIUM;
const SoundRequest_PriorityLevel SoundRequest::HIGH;
const SoundRequest_PriorityLevel SoundRequest::PriorityLevel_MIN;
const SoundRequest_PriorityLevel SoundRequest::PriorityLevel_MAX;
const int SoundRequest::PriorityLevel_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
const ::google::protobuf::EnumDescriptor* SoundRequest_Mode_descriptor() {
  protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::file_level_enum_descriptors[1];
}
bool SoundRequest_Mode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const SoundRequest_Mode SoundRequest::SAY;
const SoundRequest_Mode SoundRequest::BEEP;
const SoundRequest_Mode SoundRequest::Mode_MIN;
const SoundRequest_Mode SoundRequest::Mode_MAX;
const int SoundRequest::Mode_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SoundRequest::kHeaderFieldNumber;
const int SoundRequest::kPriorityFieldNumber;
const int SoundRequest::kModeFieldNumber;
const int SoundRequest::kWordsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SoundRequest::SoundRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:apollo.common.sound.SoundRequest)
}
SoundRequest::SoundRequest(const SoundRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  words_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_words()) {
    words_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.words_);
  }
  if (from.has_header()) {
    header_ = new ::apollo::common::Header(*from.header_);
  } else {
    header_ = NULL;
  }
  ::memcpy(&priority_, &from.priority_,
    reinterpret_cast<char*>(&mode_) -
    reinterpret_cast<char*>(&priority_) + sizeof(mode_));
  // @@protoc_insertion_point(copy_constructor:apollo.common.sound.SoundRequest)
}

void SoundRequest::SharedCtor() {
  _cached_size_ = 0;
  words_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&header_, 0, reinterpret_cast<char*>(&mode_) -
    reinterpret_cast<char*>(&header_) + sizeof(mode_));
}

SoundRequest::~SoundRequest() {
  // @@protoc_insertion_point(destructor:apollo.common.sound.SoundRequest)
  SharedDtor();
}

void SoundRequest::SharedDtor() {
  words_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) {
    delete header_;
  }
}

void SoundRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SoundRequest::descriptor() {
  protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SoundRequest& SoundRequest::default_instance() {
  protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::InitDefaults();
  return *internal_default_instance();
}

SoundRequest* SoundRequest::New(::google::protobuf::Arena* arena) const {
  SoundRequest* n = new SoundRequest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SoundRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:apollo.common.sound.SoundRequest)
  if (_has_bits_[0 / 32] & 3u) {
    if (has_words()) {
      GOOGLE_DCHECK(!words_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*words_.UnsafeRawStringPointer())->clear();
    }
    if (has_header()) {
      GOOGLE_DCHECK(header_ != NULL);
      header_->::apollo::common::Header::Clear();
    }
  }
  if (_has_bits_[0 / 32] & 12u) {
    ::memset(&priority_, 0, reinterpret_cast<char*>(&mode_) -
      reinterpret_cast<char*>(&priority_) + sizeof(mode_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool SoundRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:apollo.common.sound.SoundRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .apollo.common.Header header = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_header()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .apollo.common.sound.SoundRequest.PriorityLevel priority = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::apollo::common::sound::SoundRequest_PriorityLevel_IsValid(value)) {
            set_priority(static_cast< ::apollo::common::sound::SoundRequest_PriorityLevel >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .apollo.common.sound.SoundRequest.Mode mode = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::apollo::common::sound::SoundRequest_Mode_IsValid(value)) {
            set_mode(static_cast< ::apollo::common::sound::SoundRequest_Mode >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string words = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_words()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->words().data(), this->words().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "apollo.common.sound.SoundRequest.words");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:apollo.common.sound.SoundRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:apollo.common.sound.SoundRequest)
  return false;
#undef DO_
}

void SoundRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:apollo.common.sound.SoundRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .apollo.common.Header header = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->header_, output);
  }

  // optional .apollo.common.sound.SoundRequest.PriorityLevel priority = 2;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->priority(), output);
  }

  // optional .apollo.common.sound.SoundRequest.Mode mode = 3;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->mode(), output);
  }

  // optional string words = 4;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->words().data(), this->words().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "apollo.common.sound.SoundRequest.words");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->words(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:apollo.common.sound.SoundRequest)
}

::google::protobuf::uint8* SoundRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:apollo.common.sound.SoundRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .apollo.common.Header header = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->header_, deterministic, target);
  }

  // optional .apollo.common.sound.SoundRequest.PriorityLevel priority = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->priority(), target);
  }

  // optional .apollo.common.sound.SoundRequest.Mode mode = 3;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->mode(), target);
  }

  // optional string words = 4;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->words().data(), this->words().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "apollo.common.sound.SoundRequest.words");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->words(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:apollo.common.sound.SoundRequest)
  return target;
}

size_t SoundRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:apollo.common.sound.SoundRequest)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string words = 4;
    if (has_words()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->words());
    }

    // optional .apollo.common.Header header = 1;
    if (has_header()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          *this->header_);
    }

    // optional .apollo.common.sound.SoundRequest.PriorityLevel priority = 2;
    if (has_priority()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->priority());
    }

    // optional .apollo.common.sound.SoundRequest.Mode mode = 3;
    if (has_mode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->mode());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SoundRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:apollo.common.sound.SoundRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const SoundRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SoundRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:apollo.common.sound.SoundRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:apollo.common.sound.SoundRequest)
    MergeFrom(*source);
  }
}

void SoundRequest::MergeFrom(const SoundRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:apollo.common.sound.SoundRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_words();
      words_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.words_);
    }
    if (cached_has_bits & 0x00000002u) {
      mutable_header()->::apollo::common::Header::MergeFrom(from.header());
    }
    if (cached_has_bits & 0x00000004u) {
      priority_ = from.priority_;
    }
    if (cached_has_bits & 0x00000008u) {
      mode_ = from.mode_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void SoundRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:apollo.common.sound.SoundRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SoundRequest::CopyFrom(const SoundRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:apollo.common.sound.SoundRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SoundRequest::IsInitialized() const {
  return true;
}

void SoundRequest::Swap(SoundRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SoundRequest::InternalSwap(SoundRequest* other) {
  words_.Swap(&other->words_);
  std::swap(header_, other->header_);
  std::swap(priority_, other->priority_);
  std::swap(mode_, other->mode_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SoundRequest::GetMetadata() const {
  protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_modules_2fcommon_2fproto_2fcar_5fsound_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SoundRequest

// optional .apollo.common.Header header = 1;
bool SoundRequest::has_header() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void SoundRequest::set_has_header() {
  _has_bits_[0] |= 0x00000002u;
}
void SoundRequest::clear_has_header() {
  _has_bits_[0] &= ~0x00000002u;
}
void SoundRequest::clear_header() {
  if (header_ != NULL) header_->::apollo::common::Header::Clear();
  clear_has_header();
}
const ::apollo::common::Header& SoundRequest::header() const {
  // @@protoc_insertion_point(field_get:apollo.common.sound.SoundRequest.header)
  return header_ != NULL ? *header_
                         : *::apollo::common::Header::internal_default_instance();
}
::apollo::common::Header* SoundRequest::mutable_header() {
  set_has_header();
  if (header_ == NULL) {
    header_ = new ::apollo::common::Header;
  }
  // @@protoc_insertion_point(field_mutable:apollo.common.sound.SoundRequest.header)
  return header_;
}
::apollo::common::Header* SoundRequest::release_header() {
  // @@protoc_insertion_point(field_release:apollo.common.sound.SoundRequest.header)
  clear_has_header();
  ::apollo::common::Header* temp = header_;
  header_ = NULL;
  return temp;
}
void SoundRequest::set_allocated_header(::apollo::common::Header* header) {
  delete header_;
  header_ = header;
  if (header) {
    set_has_header();
  } else {
    clear_has_header();
  }
  // @@protoc_insertion_point(field_set_allocated:apollo.common.sound.SoundRequest.header)
}

// optional .apollo.common.sound.SoundRequest.PriorityLevel priority = 2;
bool SoundRequest::has_priority() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void SoundRequest::set_has_priority() {
  _has_bits_[0] |= 0x00000004u;
}
void SoundRequest::clear_has_priority() {
  _has_bits_[0] &= ~0x00000004u;
}
void SoundRequest::clear_priority() {
  priority_ = 0;
  clear_has_priority();
}
::apollo::common::sound::SoundRequest_PriorityLevel SoundRequest::priority() const {
  // @@protoc_insertion_point(field_get:apollo.common.sound.SoundRequest.priority)
  return static_cast< ::apollo::common::sound::SoundRequest_PriorityLevel >(priority_);
}
void SoundRequest::set_priority(::apollo::common::sound::SoundRequest_PriorityLevel value) {
  assert(::apollo::common::sound::SoundRequest_PriorityLevel_IsValid(value));
  set_has_priority();
  priority_ = value;
  // @@protoc_insertion_point(field_set:apollo.common.sound.SoundRequest.priority)
}

// optional .apollo.common.sound.SoundRequest.Mode mode = 3;
bool SoundRequest::has_mode() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void SoundRequest::set_has_mode() {
  _has_bits_[0] |= 0x00000008u;
}
void SoundRequest::clear_has_mode() {
  _has_bits_[0] &= ~0x00000008u;
}
void SoundRequest::clear_mode() {
  mode_ = 0;
  clear_has_mode();
}
::apollo::common::sound::SoundRequest_Mode SoundRequest::mode() const {
  // @@protoc_insertion_point(field_get:apollo.common.sound.SoundRequest.mode)
  return static_cast< ::apollo::common::sound::SoundRequest_Mode >(mode_);
}
void SoundRequest::set_mode(::apollo::common::sound::SoundRequest_Mode value) {
  assert(::apollo::common::sound::SoundRequest_Mode_IsValid(value));
  set_has_mode();
  mode_ = value;
  // @@protoc_insertion_point(field_set:apollo.common.sound.SoundRequest.mode)
}

// optional string words = 4;
bool SoundRequest::has_words() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void SoundRequest::set_has_words() {
  _has_bits_[0] |= 0x00000001u;
}
void SoundRequest::clear_has_words() {
  _has_bits_[0] &= ~0x00000001u;
}
void SoundRequest::clear_words() {
  words_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_words();
}
const ::std::string& SoundRequest::words() const {
  // @@protoc_insertion_point(field_get:apollo.common.sound.SoundRequest.words)
  return words_.GetNoArena();
}
void SoundRequest::set_words(const ::std::string& value) {
  set_has_words();
  words_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:apollo.common.sound.SoundRequest.words)
}
#if LANG_CXX11
void SoundRequest::set_words(::std::string&& value) {
  set_has_words();
  words_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:apollo.common.sound.SoundRequest.words)
}
#endif
void SoundRequest::set_words(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_words();
  words_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:apollo.common.sound.SoundRequest.words)
}
void SoundRequest::set_words(const char* value, size_t size) {
  set_has_words();
  words_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:apollo.common.sound.SoundRequest.words)
}
::std::string* SoundRequest::mutable_words() {
  set_has_words();
  // @@protoc_insertion_point(field_mutable:apollo.common.sound.SoundRequest.words)
  return words_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* SoundRequest::release_words() {
  // @@protoc_insertion_point(field_release:apollo.common.sound.SoundRequest.words)
  clear_has_words();
  return words_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SoundRequest::set_allocated_words(::std::string* words) {
  if (words != NULL) {
    set_has_words();
  } else {
    clear_has_words();
  }
  words_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), words);
  // @@protoc_insertion_point(field_set_allocated:apollo.common.sound.SoundRequest.words)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace sound
}  // namespace common
}  // namespace apollo

// @@protoc_insertion_point(global_scope)