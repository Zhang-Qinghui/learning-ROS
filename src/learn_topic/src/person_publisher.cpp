#include  <ros/ros.h>
#include "learn_topic/Person.h"

int main(int argc,char **argv)
{
	ros::init(argc,argv,"person_publisher");
	ros::NodeHandle n;
	ros::Publisher person_info_pub =n.advertise<learn_topic::Person>("/Person_info",10);
	ros::Rate loop_rate(1);

	int count=0;
	while(ros::ok())
	{
		learn_topic::Person person_msg;
		person_msg.name="tom";
		person_msg.age=18;
		person_msg.sex=learn_topic::Person::male;
		
		person_info_pub.publish(person_msg);
		ROS_INFO("pubish person info:name:%s age:%d sex:%d",person_msg.name.c_str(),person_msg.age,person_msg.sex);
		loop_rate.sleep();
	}
	return 0;
}
