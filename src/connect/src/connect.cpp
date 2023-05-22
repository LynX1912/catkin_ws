#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

float mode = 0,manual1 = 0, manual2 = 0, on = 0 , velvl = 0, linvl = 0;


void changemode(const geometry_msgs::Point& msg)
{
  mode = msg.x;
}
void controlmanual1(const geometry_msgs::Point& msg)
{
  manual1 = msg.x;
}
void controlmanual2(const geometry_msgs::Point& msg)
{
  manual2 = msg.x;
}

void veltran(const geometry_msgs::Twist& msg)
{
  velvl = msg.linear.x;
  linvl = msg.angular.z;
}
void reboot(const geometry_msgs::Point& msg)
{
  on = msg.x;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "manual");

  ros::NodeHandle n;
  ros::Publisher pub1 = n.advertise<geometry_msgs::Point>("modear", 100 );
  ros::Publisher pub2 = n.advertise<geometry_msgs::Point>("manualar1", 100 );
  ros::Publisher pub3 = n.advertise<geometry_msgs::Point>("manualar2", 100 );
  ros::Publisher pub4 = n.advertise<geometry_msgs::Point>("velml", 100 );
  ros::Subscriber sub1 = n.subscribe("modeml", 100, changemode);
  ros::Subscriber sub2 = n.subscribe("manualml1", 100, controlmanual1);
  ros::Subscriber sub3 = n.subscribe("manualml2", 100, controlmanual2);
  ros::Subscriber sub4 = n.subscribe("cmd_vel", 100, veltran);
  ros::Subscriber sub5 = n.subscribe("reset", 100, reboot);
  
  ros::Rate loop_rate(100);


  while (ros::ok())
  {
    geometry_msgs::Point mode_msg;
    mode_msg.x = mode;
    pub1.publish(mode_msg);	
    
    geometry_msgs::Point manual1_msg;
    manual1_msg.x = manual1;
    pub2.publish(manual1_msg);

    geometry_msgs::Point manual2_msg;
    manual2_msg.x = manual2;
    pub3.publish(manual2_msg);
	
    geometry_msgs::Point vel_msg;
    vel_msg.x = velvl;
    vel_msg.z = linvl;
    pub4.publish(vel_msg);

    if(on == 1)
	{
	system("rosrun reset111 reset111.sh"); 
	}
    else if(on == 2)
	{
	system("rosrun reset111 reset112.sh"); 
	}
    ros::spinOnce();
    loop_rate.sleep();   
  }						
  return 0;
}

