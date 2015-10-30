/*
 * listener.cpp
 *
 *  Created on: Oct 29, 2015
 *      Author: Fotis Balampanis
 */

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "waypoint_planning/Coordinates.h"

#include <waypoint_planning/simulation.h>
//#include <transformationUtilities.h>

using namespace std;

//void chatterCallback(const std_msgs::String::ConstPtr& msg)
void chatterCallback(const waypoint_planning::Coordinates::ConstPtr& msg)
{	
	std::cout << std::setprecision(7); 
	double longitude = (double) msg->longitude;
	double latitude = (double) msg->latitude;
	double altitude = 400.0;

  	ROS_INFO("I heard the longitude: [%3.7f]", longitude);
  	ROS_INFO("I heard the latitude: [%3.7f]", latitude); 
  
  	int a = 0;
  	a = perform_simulation(longitude, latitude, altitude);
    //.c_str()); //data.c_str());
}
// create a listener to the topic "waypoint_planner".
// when a set of lat long has been published to the topic waypoint_planner,
// calculate the waypoint files.
int main(int argc, char **argv)
{

	ros::init(argc, argv, "waypoint_planning_listener");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("waypoint_release_spot", 1000, chatterCallback);

	ros::spin();

	return 0;
	// int a = 0;
	//    a = perform_simulation();

    //testTransformationFunctions();
	//return a;
}

