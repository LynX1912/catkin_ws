#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "robotROSConnectToRobotExample";

// For Block robotROSConnectToRobotExample/Subscribe1
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry> Sub_robotROSConnectToRobotExample_33;

// For Block robotROSConnectToRobotExample/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist> Pub_robotROSConnectToRobotExample_32;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

