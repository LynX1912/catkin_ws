// Copyright 2019-2020 The MathWorks, Inc.
// Generated 02-Jun-2022 18:01:18

#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma comment(lib, "Ws2_32.lib")

#else

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"

#endif                                 //_MSC_VER

#include "robotROSConnectToRobotExample.h"
#include "rosnodeinterface.h"
#include <thread>
#include <chrono>
#include <utility>

//
// Forward declare the ROS Time stepping and notification related
// functions and global flags/variables
//
// Flag to determine that model should continue to run
static volatile bool modelRuns;
static uint32_t _clock_msg_sec;
static uint32_t _clock_msg_nsec;

// Counter to determine the number of overruns
static int numOverruns;
namespace ros
{
  namespace matlab
  {
    NodeInterface::NodeInterface()
      : mNode()
      , mBaseRateSem()
      , mBaseRateThread()
      , mSchedulerThread()
      , mExtModeThread()
      , mStopSem()
      , mRunModel(true)
    {
    }

    NodeInterface::~NodeInterface()
    {
      terminate();
    }

    void NodeInterface::initialize(int argc, char ** argv)
    {
      try {
        mNode = std::make_shared<ros::NodeHandle>();
        ROS_INFO("** Starting the model \"robotROSConnectToRobotExample\" **\n");

        {
          char* extmodeArg[] = { "-port", "17725", "-blocking", "1", "-verbose",
            "0" };

          rtExtModeParseArgs(6, (const char_T **)extmodeArg, NULL);
        }

        // initialize the model which will initialize the publishers and subscribers
        rtmSetErrorStatus(robotROSConnectToRobotExample_M, (NULL));
        robotROSConnectToRobotExample_initialize();

        /* External mode */
        rtSetTFinalForExtMode(&rtmGetTFinal(robotROSConnectToRobotExample_M));
        rtExtModeCheckInit(1);

        {
          boolean_T rtmStopReq = false;
          rtExtModeWaitForStartPkt(robotROSConnectToRobotExample_M->extModeInfo,
            1,
            &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(robotROSConnectToRobotExample_M, true);
          }
        }

        rtERTExtModeStartMsg();
        mExtModeThread = std::make_shared<std::thread>(&NodeInterface::
          extmodeBackgroundTask, this);

        // create the threads for the rates in the Model
        mBaseRateThread = std::make_shared<std::thread>(&NodeInterface::
          baseRateTask, this);

        // create scheduler thread
        mSchedulerThread = std::make_shared<std::thread>(&NodeInterface::
          schedulerThread, this);
      } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
      }
    }

    int NodeInterface::run()
    {
      // Wait for ROSTime scheduler to finish
      mStopSem.wait();
      mRunModel = false;
      return 0;
    }

    boolean_T NodeInterface::getStopRequestedFlag(void)
    {

#ifndef rtmGetStopRequested

      return (!(rtmGetErrorStatus(robotROSConnectToRobotExample_M)
                == (NULL)));

#else

      return (!(rtmGetErrorStatus(robotROSConnectToRobotExample_M)
                == (NULL)) || rtmGetStopRequested
              (robotROSConnectToRobotExample_M));

#endif

    }

    void NodeInterface::terminate(void)
    {
      if (mBaseRateThread.get()) {
        mBaseRateSem.notify();
        mBaseRateThread->join();
        mRunModel = false;
        mBaseRateThread.reset();
        if (mSchedulerThread.get()) {
          mSchedulerThread->join();
          mSchedulerThread.reset();
        }

        robotROSConnectToRobotExample_terminate();
        rtExtModeShutdown(1);
        mNode.reset();
      }
    }

    //
    // ROS Clock topic subscriber callback to run the base rate task
    //
    void NodeInterface::rosClockSubscriberCallback(const rosgraph_msgs::Clock &
      msg)
    {
      static bool termFlag = false;
      static bool waitingFlag = false;
      static int stateFlag = 1;
      const uint64_t baseRateNanoSec = 10000000;
      static uint64_t nextTimeSlot = baseRateNanoSec;
      uint64_t longTime;
      if ((1 == stateFlag) && (0U != msg.clock.nsec) ) {
        ROS_INFO("Waiting for time synchronization at time %u.000000000",
                 msg.clock.sec + 1U);
      }

      if (false != termFlag) {
        return;
      }

      longTime = ((uint64_t)msg.clock.sec * 1000000000ULL) + (uint64_t)
        msg.clock.nsec;

      // Check if time fits into model steps
      if ((0 == stateFlag) && (true == waitingFlag) ) {
        if (longTime > nextTimeSlot) {
          fflush(stdout);
          ROS_FATAL("The clock missed time slot at %f for the model step. Actual clock = %.6f\n",
                    nextTimeSlot/1E9, (double)longTime/1E9);
          fflush(stderr);
          mRunModel = false;
          mBaseRateSem.notify();
          termFlag = true;
          return;
        }
      }

      // Store into global variable published by clock topic
      _clock_msg_sec = msg.clock.sec;
      _clock_msg_nsec = msg.clock.nsec;

      // Starting the model code at time of "nsec" at 0ns
      if (false == waitingFlag) {
        if (0U == msg.clock.nsec) {
          waitingFlag = true;
          ROS_INFO("** Unblocking base-rate at %.6f", (double)longTime/1E9);
          modelRuns = true;
          mBaseRateSem.notify();       // Launch for first time
          nextTimeSlot = longTime + baseRateNanoSec;
        } else {
          // Check if there was no termination in the meantime
          mRunModel = (rtmGetErrorStatus(robotROSConnectToRobotExample_M) ==
                       (NULL));
          if (mRunModel == false) {
            termFlag = true;
          }
        }
      } else {
        if ((msg.clock.nsec % baseRateNanoSec) == 0U) {
          // Overrun check
          if (false != modelRuns) {
            numOverruns++;
            ROS_ERROR("Overrun %d", numOverruns);
          }

          modelRuns = true;
          mBaseRateSem.notify();
          nextTimeSlot += baseRateNanoSec;
        }
      }

      if (stateFlag > 0) {
        stateFlag--;
      }
    }

    //
    // Scheduler Task using ROS Time published by "/clock" topic to run base-rate
    //
    void NodeInterface::schedulerThread(void)
    {

#ifdef MW_DEBUG_LOG

      ROS_INFO("ROS schedulerTask entered\n");

#endif

      std::string sClockTopic = "/clock";
      ros::NodeHandle n;
      ros::Subscriber sub = n.subscribe(sClockTopic, 10, &ros::matlab::
        NodeInterface::rosClockSubscriberCallback, this);
      if (sub == NULL) {
        ROS_INFO("Error: cannot subscribe the '%s'", sClockTopic.c_str());
        return;
      }

      ros::spin();

      // Unblock main thread and terminate
      mStopSem.notify();
      return;
    }

    // Base-rate task
    void NodeInterface::baseRateTask(void)
    {
      mRunModel = (rtmGetErrorStatus(robotROSConnectToRobotExample_M) ==
                   (NULL));
      while (mRunModel) {
        mBaseRateSem.wait();

#ifdef MW_DEBUG_LOG

        ROS_INFO("** Base rate task semaphore received\n");

#endif

        if (!mRunModel)
          break;

        /* External mode */
        {
          boolean_T rtmStopReq = false;
          rtExtModePauseIfNeeded(robotROSConnectToRobotExample_M->extModeInfo, 1,
            &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(robotROSConnectToRobotExample_M, true);
          }

          if (rtmGetStopRequested(robotROSConnectToRobotExample_M) == true) {
            rtmSetErrorStatus(robotROSConnectToRobotExample_M,
                              "Simulation finished");
            mRunModel = false;
            break;
          }
        }

        robotROSConnectToRobotExample_step();
        rtExtModeCheckEndTrigger();
        mRunModel = !NodeInterface::getStopRequestedFlag();
      }

      // Shutdown the ROS node
      ros::shutdown();
    }

    void NodeInterface::extmodeBackgroundTask(void)
    {
      while (mRunModel) {
        /* External mode */
        {
          boolean_T rtmStopReq = false;
          rtExtModeOneStep(robotROSConnectToRobotExample_M->extModeInfo, 1,
                           &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(robotROSConnectToRobotExample_M, true);
          }
        }
      }
    }
  }                                    //namespace matlab
}                                      //namespace ros

#ifdef _MSC_VER

#pragma warning(pop)

#else

#pragma GCC diagnostic pop

#endif                                 //_MSC_VER
