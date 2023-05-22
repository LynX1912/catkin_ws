#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

float mode = 0,manual1 = 0, manual2 = 0, on = 0 , linvl = 0, angvl = 0;
double lvel = 0, avel = 0;

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
  linvl = msg.linear.x;
  angvl = msg.angular.z;
}
void reboot(const geometry_msgs::Point& msg)
{
  on = msg.x;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "final");

  ros::NodeHandle n;
  ros::Publisher pub1 = n.advertise<geometry_msgs::Twist>("arduino", 100 );
  ros::Publisher pub2 = n.advertise<geometry_msgs::Point>("vel", 100 );
  ros::Subscriber sub1 = n.subscribe("modeml", 100, changemode);
  ros::Subscriber sub2 = n.subscribe("manualml1", 100, controlmanual1);
  ros::Subscriber sub3 = n.subscribe("manualml2", 100, controlmanual2);
  ros::Subscriber sub4 = n.subscribe("cmd_vel", 100, veltran);
  ros::Subscriber sub5 = n.subscribe("reset", 100, reboot);
  
  ros::Rate loop_rate(100);


  while (ros::ok())
  { 
    lvel = 270 * linvl;
    if(linvl != 0)
    {
    avel = 180/PI * atan((angvl/linvl)*car_length)*4 + 90;
    }
    else
    {
    avel = 90;
    }
    if (lvel > 0)
    {
    if (lvel > 120)
    lvel = 120;
    else if (lvel < 40)
    lvel = 40;
    }
    if (avel > 130)
    avel = 130;
    else if (avel < 50)
    avel = 50;

    geometry_msgs::Twist armsg;
    armsg.linear.x = lvel;
    armsg.linear.y = avel;
    armsg.linear.z = manual1;
    armsg.angular.x = manual2;
    armsg.angular.y = mode;   
    pub1.publish(armsg);	

    geometry_msgs::Point vel_msg;
    vel_msg.x = lvel;
    vel_msg.z = avel;
    pub2.publish(vel_msg);

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

