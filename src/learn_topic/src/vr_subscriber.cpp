#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

void vrCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	ROS_INFO("%f,%f,%f,%f,%f,%f", msg->linear,msg->angular);
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"vr_subscriber");
	ros::NodeHandle n;
	ros::Subscriber vr_sub=n.subscribe ("/turtle1/cmd_vel",10,vrCallback);
	ros::spin();
	return 0;
}
