# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(connect)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs geometry_msgs)



## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(connect src/connect.cpp)
target_link_libraries(connect ${catkin_LIBRARIES})


# %EndTag(FULLTEXT)%
