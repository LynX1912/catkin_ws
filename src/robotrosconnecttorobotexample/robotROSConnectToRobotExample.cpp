/*
 * robotROSConnectToRobotExample.cpp
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

#include "robotROSConnectToRobotExample.h"
#include "robotROSConnectToRobotExample_private.h"
#include "robotROSConnectToRobotExample_dt.h"

/* Block signals (default storage) */
B_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_B;

/* Block states (default storage) */
DW_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_DW;

/* Real-time model */
RT_MODEL_robotROSConnectToRobotExample_T robotROSConnectToRobotExample_M_ =
  RT_MODEL_robotROSConnectToRobotExample_T();
RT_MODEL_robotROSConnectToRobotExample_T *const robotROSConnectToRobotExample_M =
  &robotROSConnectToRobotExample_M_;

/* Model step function */
void robotROSConnectToRobotExample_step(void)
{
  SL_Bus_robotROSConnectToRobotExample_geometry_msgs_Twist rtb_BusAssignment;
  boolean_T b_varargout_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(robotROSConnectToRobotExample_DW.EnabledSubsystem_SubsysRanBC);

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant'
   */
  rtb_BusAssignment = robotROSConnectToRobotExample_P.Constant_Value_j;
  rtb_BusAssignment.Linear.X = robotROSConnectToRobotExample_P.Constant_Value_e;

  /* Outputs for Atomic SubSystem: '<Root>/Publish1' */
  /* MATLABSystem: '<S2>/SinkBlock' */
  Pub_robotROSConnectToRobotExample_32.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish1' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
  /* MATLABSystem: '<S3>/SourceBlock' incorporates:
   *  Inport: '<S5>/In1'
   */
  b_varargout_1 = Sub_robotROSConnectToRobotExample_33.getLatestMessage
    (&robotROSConnectToRobotExample_B.b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (b_varargout_1) {
    robotROSConnectToRobotExample_B.In1 =
      robotROSConnectToRobotExample_B.b_varargout_2;
    srUpdateBC(robotROSConnectToRobotExample_DW.EnabledSubsystem_SubsysRanBC);
  }

  /* End of MATLABSystem: '<S3>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  robotROSConnectToRobotExample_B.X =
    robotROSConnectToRobotExample_B.In1.Pose.Pose.Position.X;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  robotROSConnectToRobotExample_B.Y =
    robotROSConnectToRobotExample_B.In1.Pose.Pose.Position.Y;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)robotROSConnectToRobotExample_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(robotROSConnectToRobotExample_M)!=-1) &&
        !((rtmGetTFinal(robotROSConnectToRobotExample_M)-
           robotROSConnectToRobotExample_M->Timing.taskTime0) >
          robotROSConnectToRobotExample_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(robotROSConnectToRobotExample_M, "Simulation finished");
    }

    if (rtmGetStopRequested(robotROSConnectToRobotExample_M)) {
      rtmSetErrorStatus(robotROSConnectToRobotExample_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++robotROSConnectToRobotExample_M->Timing.clockTick0)) {
    ++robotROSConnectToRobotExample_M->Timing.clockTickH0;
  }

  robotROSConnectToRobotExample_M->Timing.taskTime0 =
    robotROSConnectToRobotExample_M->Timing.clockTick0 *
    robotROSConnectToRobotExample_M->Timing.stepSize0 +
    robotROSConnectToRobotExample_M->Timing.clockTickH0 *
    robotROSConnectToRobotExample_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void robotROSConnectToRobotExample_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(robotROSConnectToRobotExample_M, 10.0);
  robotROSConnectToRobotExample_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  robotROSConnectToRobotExample_M->Sizes.checksums[0] = (2877376557U);
  robotROSConnectToRobotExample_M->Sizes.checksums[1] = (3561141347U);
  robotROSConnectToRobotExample_M->Sizes.checksums[2] = (3845458653U);
  robotROSConnectToRobotExample_M->Sizes.checksums[3] = (3215792925U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    robotROSConnectToRobotExample_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &robotROSConnectToRobotExample_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(robotROSConnectToRobotExample_M->extModeInfo,
      &robotROSConnectToRobotExample_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(robotROSConnectToRobotExample_M->extModeInfo,
                        robotROSConnectToRobotExample_M->Sizes.checksums);
    rteiSetTPtr(robotROSConnectToRobotExample_M->extModeInfo, rtmGetTPtr
                (robotROSConnectToRobotExample_M));
  }

  /* block I/O */
  (void) memset((static_cast<void *>(&robotROSConnectToRobotExample_B)), 0,
                sizeof(B_robotROSConnectToRobotExample_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&robotROSConnectToRobotExample_DW), 0,
                sizeof(DW_robotROSConnectToRobotExample_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    robotROSConnectToRobotExample_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 27;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    static const char_T tmp[8] = { '/', 'a', 'r', 'd', 'u', 'i', 'n', 'o' };

    static const char_T tmp_0[5] = { '/', 'o', 'd', 'o', 'm' };

    int32_T i;
    char_T b_zeroDelimTopic[9];
    char_T b_zeroDelimTopic_0[6];

    /* Start for Atomic SubSystem: '<Root>/Publish1' */
    /* Start for MATLABSystem: '<S2>/SinkBlock' */
    robotROSConnectToRobotExample_DW.obj.matlabCodegenIsDeleted = false;
    robotROSConnectToRobotExample_DW.objisempty_c = true;
    robotROSConnectToRobotExample_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[8] = '\x00';
    Pub_robotROSConnectToRobotExample_32.createPublisher(&b_zeroDelimTopic[0], 1);
    robotROSConnectToRobotExample_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    robotROSConnectToRobotExample_DW.obj_e.matlabCodegenIsDeleted = false;
    robotROSConnectToRobotExample_DW.objisempty = true;
    robotROSConnectToRobotExample_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[5] = '\x00';
    Sub_robotROSConnectToRobotExample_33.createSubscriber(&b_zeroDelimTopic_0[0],
      51);
    robotROSConnectToRobotExample_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S5>/Out1' incorporates:
   *  Inport: '<S5>/In1'
   */
  robotROSConnectToRobotExample_B.In1 = robotROSConnectToRobotExample_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */
}

/* Model terminate function */
void robotROSConnectToRobotExample_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Publish1' */
  /* Terminate for MATLABSystem: '<S2>/SinkBlock' */
  if (!robotROSConnectToRobotExample_DW.obj.matlabCodegenIsDeleted) {
    robotROSConnectToRobotExample_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish1' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  if (!robotROSConnectToRobotExample_DW.obj_e.matlabCodegenIsDeleted) {
    robotROSConnectToRobotExample_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */
}
