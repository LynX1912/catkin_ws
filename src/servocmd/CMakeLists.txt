# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(servocmd)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs geometry_msgs)



## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(servocmd src/servocmd.cpp)
target_link_libraries(servocmd ${catkin_LIBRARIES})


# %EndTag(FULLTEXT)%
