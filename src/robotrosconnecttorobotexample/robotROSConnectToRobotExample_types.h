/*
 * robotROSConnectToRobotExample_types.h
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

#ifndef RTW_HEADER_robotROSConnectToRobotExample_types_h_
#define RTW_HEADER_robotROSConnectToRobotExample_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist_

typedef struct {
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3 Linear;
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Vector3 Angular;
} SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_ros_time_Time_

typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_robotROSConnectToRobotExample_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_std_msgs_Header_

typedef struct {
  uint32_T Seq;
  SL_Bus_robotROSConnectToRobotExample_ros_time_Time Stamp;
  uint8_T FrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
} SL_Bus_robotROSConnectToRobotExample_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose_

typedef struct {
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Point Position;
  SL_Bus_robotROSConnectToRobotExa_Quaternion_jly90n Orientation;
} SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx_

typedef struct {
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Pose Pose;
  real_T Covariance[36];
} SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9_

typedef struct {
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist Twist;
  real_T Covariance[36];
} SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry_

typedef struct {
  SL_Bus_robotROSConnectToRobotExample_std_msgs_Header Header;
  uint8_T ChildFrameId[128];
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;
  SL_Bus_robotROSConnectToRobotExa_PoseWithCovariance_xbogsx Pose;
  SL_Bus_robotROSConnectToRobotExa_TwistWithCovariance_33jhu9 Twist;
} SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry;

#endif

#ifndef struct_tag_D6QYIVJDjoKN0blLVEpT8F
#define struct_tag_D6QYIVJDjoKN0blLVEpT8F

struct tag_D6QYIVJDjoKN0blLVEpT8F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_D6QYIVJDjoKN0blLVEpT8F*/

#ifndef typedef_ros_slroscpp_internal_block_P_T
#define typedef_ros_slroscpp_internal_block_P_T

typedef tag_D6QYIVJDjoKN0blLVEpT8F ros_slroscpp_internal_block_P_T;

#endif                               /*typedef_ros_slroscpp_internal_block_P_T*/

#ifndef struct_tag_eFCXAaC7vLdwjksE0MwgOD
#define struct_tag_eFCXAaC7vLdwjksE0MwgOD

struct tag_eFCXAaC7vLdwjksE0MwgOD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_eFCXAaC7vLdwjksE0MwgOD*/

#ifndef typedef_ros_slroscpp_internal_block_S_T
#define typedef_ros_slroscpp_internal_block_S_T

typedef tag_eFCXAaC7vLdwjksE0MwgOD ros_slroscpp_internal_block_S_T;

#endif                               /*typedef_ros_slroscpp_internal_block_S_T*/

/* Parameters (default storage) */
typedef struct P_robotROSConnectToRobotExample_T_
  P_robotROSConnectToRobotExample_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_robotROSConnectToRobotExample_T
  RT_MODEL_robotROSConnectToRobotExample_T;

#endif                   /* RTW_HEADER_robotROSConnectToRobotExample_types_h_ */
