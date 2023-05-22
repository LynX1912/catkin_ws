/*
 * robotROSConnectToRobotExample_dt.h
 *
 * Code generation for model "robotROSConnectToRobotExample".
 *
 * Model version              : 1.35
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C++ source code generated on : Thu Jun  2 18:01:15 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3),
  sizeof(SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist),
  sizeof(SL_Bus_robotROSConnectToRobotExample_ros_time_Time),
  sizeof(SL_Bus_ROSVariableLengthArrayInfo),
  sizeof(SL_Bus_robotROSConnectToRobotExample_std_msgs_Header),
  sizeof(SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point),
  sizeof(SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n),
  sizeof(SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose),
  sizeof(SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx),
  sizeof(SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9),
  sizeof(SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry),
  sizeof(ros_slroscpp_internal_block_P_T),
  sizeof(ros_slroscpp_internal_block_S_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3",
  "SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist",
  "SL_Bus_robotROSConnectToRobotExample_ros_time_Time",
  "SL_Bus_ROSVariableLengthArrayInfo",
  "SL_Bus_robotROSConnectToRobotExample_std_msgs_Header",
  "SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point",
  "SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n",
  "SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose",
  "SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx",
  "SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9",
  "SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry",
  "ros_slroscpp_internal_block_P_T",
  "ros_slroscpp_internal_block_S_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&robotROSConnectToRobotExample_B.In1), 24, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_B.X), 0, 0, 4 }
  ,

  { (char_T *)(&robotROSConnectToRobotExample_DW.obj), 25, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_DW.obj_e), 26, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_DW.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_DW.objisempty), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&robotROSConnectToRobotExample_P.Out1_Y0), 24, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_P.Constant_Value), 24, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_P.Constant_Value_j), 15, 0, 1 },

  { (char_T *)(&robotROSConnectToRobotExample_P.Constant_Value_e), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] robotROSConnectToRobotExample_dt.h */
