#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

double lin = 0, ang = 0 , linout = 0 , angout = 0;

void servocmd(const geometry_msgs::Twist& msg)
{
  lin = msg.linear.x;
  ang = msg.angular.z;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "final");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::Point>("arduino", 100 );
  ros::Subscriber sub = n.subscribe("cmd_vel", 100, servocmd);
  ros::Rate loop_rate(100);


  while (ros::ok())
  { 

    if ( ang == 0 )
	{
	sleep(0.5);
	if(ang == 0)
	angout = 0;
	
	}
    else
	angout = ang;

    geometry_msgs::Point ar;
    ar.x = lin;
    ar.z = angout;  
    pub.publish(ar);    

    ros::spinOnce();
    loop_rate.sleep();   
  }                        
  return 0;
}


