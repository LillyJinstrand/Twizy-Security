cmake_minimum_required(VERSION 2.8.3)
project(security)

## Compile as C++11, supported in ROS Kinetic and newer
#add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

find_package(Protobuf REQUIRED)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Num.msg  
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES package
  CATKIN_DEPENDS roscpp 
#  DEPENDS system_lib
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PROTOBUF_INCLUDE_DIRS}
)

file(GLOB_RECURSE ProtoSource "include/*.pb.cc")
file(GLOB_RECURSE ProtoHeader "include/*.pb.h")

add_library(apollo
    STATIC ${ProtoSource} ${ProtoHeader}
)

file(GLOB_RECURSE ConverterSource "src/*_converter.cc")
file(GLOB_RECURSE ConverterHeader "include/*_converter.h")
add_library(converters
    STATIC ${ConverterSource} ${ConverterHeader}
)

add_library(breakMsg
    STATIC "src/brake_message.cc" "include/brake_message.h"
)

add_executable(twizySecurity src/twizy_security.cc)
target_link_libraries(twizySecurity 
    ${catkin_LIBRARIES}
    apollo
    converters
    breakMsg
    ${CMAKE_CURRENT_LIST_DIR}/lib/security.a
    ${PROTOBUF_LIBRARIES}
    
)
add_executable(interactiveTester src/interactive_tester.cc)
target_link_libraries(interactiveTester
    ${catkin_LIBRARIES}
    apollo
    converters
    breakMsg
    ${CMAKE_CURRENT_LIST_DIR}/lib/security.a
    ${PROTOBUF_LIBRARIES}
)
add_executable(converterTest src/converter_test.cc)
target_link_libraries(converterTest
    ${catkin_LIBRARIES}
    apollo
    converters
    ${CMAKE_CURRENT_LIST_DIR}/lib/security.a
    ${PROTOBUF_LIBRARIES}
)

add_dependencies(twizySecurity package_generate_message_cpp)
add_dependencies(converterTest twizySecurity)
add_dependencies(interactiveTester twizySecurity)
