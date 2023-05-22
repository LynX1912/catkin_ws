#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block robotROSConnectToRobotExample/Subscribe1
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry> Sub_robotROSConnectToRobotExample_33;

// For Block robotROSConnectToRobotExample/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist> Pub_robotROSConnectToRobotExample_32;

void slros_node_init(int argc, char** argv);

#endif
