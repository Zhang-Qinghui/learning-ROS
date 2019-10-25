#include <ros/ros.h>
#include "learn_topic/Person.h"

void personInfoCallback(const learn_topic::Person::ConstPtr& msg)
{
	ROS_INFO("subscriber person info:name:%s age:%d sex:%d",msg->name.c_str(),msg->age,msg->sex);
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"person_subscriber");
	ros::NodeHandle n;
	ros::Subscriber person_info_sub = n.subscribe("/Person_info",10,personInfoCallback);
	ros::spin();
	return 0;
}
