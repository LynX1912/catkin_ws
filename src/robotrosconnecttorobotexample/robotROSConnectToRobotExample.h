/*
 * robotROSConnectToRobotExample.h
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

#ifndef RTW_HEADER_robotROSConnectToRobotExample_h_
#define RTW_HEADER_robotROSConnectToRobotExample_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "slros_initialize.h"
#include "robotROSConnectToRobotExample_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry In1;/* '<S5>/In1' */
  SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry b_varargout_2;
  real_T X;
  real_T Y;
  real_T TmpSignalConversionAtsfunxyInpo[2];
} B_robotROSConnectToRobotExample_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ros_slroscpp_internal_block_P_T obj; /* '<S2>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_e;/* '<S3>/SourceBlock' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S3>/Enabled Subsystem' */
  boolean_T objisempty;                /* '<S3>/SourceBlock' */
  boolean_T objisempty_c;              /* '<S2>/SinkBlock' */
} DW_robotROSConnectToRobotExample_T;

/* Parameters (default storage) */
struct P_robotROSConnectToRobotExample_T_ {
  SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry Out1_Y0;/* Computed Parameter: Out1_Y0
                                                                  * Referenced by: '<S5>/Out1'
                                                                  */
  SL_Bus_robotROSConnectToRobotExample_nav_msgs_Odometry Constant_Value;/* Computed Parameter: Constant_Value
                                                                      * Referenced by: '<S3>/Constant'
                                                                      */
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist Constant_Value_j;/* Computed Parameter: Constant_Value_j
                                                                      * Referenced by: '<S1>/Constant'
                                                                      */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_robotROSConnectToRobotExample_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern B_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern DW_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void robotROSConnectToRobotExample_initialize(void);
  extern void robotROSConnectToRobotExample_step(void);
  extern void robotROSConnectToRobotExample_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_robotROSConnectToRobotExample_T *const
    robotROSConnectToRobotExample_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'robotROSConnectToRobotExample'
 * '<S1>'   : 'robotROSConnectToRobotExample/Blank Message'
 * '<S2>'   : 'robotROSConnectToRobotExample/Publish1'
 * '<S3>'   : 'robotROSConnectToRobotExample/Subscribe1'
 * '<S4>'   : 'robotROSConnectToRobotExample/XY Graph'
 * '<S5>'   : 'robotROSConnectToRobotExample/Subscribe1/Enabled Subsystem'
 */
#endif                         /* RTW_HEADER_robotROSConnectToRobotExample_h_ */
