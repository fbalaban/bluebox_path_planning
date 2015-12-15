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
#include "boost/ref.hpp"
#include "std_msgs/String.h"
#include "waypoint_planning/Coordinates.h"
#include "waypoint_planning/Replan_Msg.h"

#include <waypoint_planning/simulation.h>
//#include <transformationUtilities.h>

using namespace std;

// creates waypoint files for 4 UAVs, in an area 2km by 2km (for each UAV) around the central
// drop spot, defined by the Coordinates message.
void chatterCallback(const waypoint_planning::Coordinates::ConstPtr& msg)
{	
	std::cout << std::setprecision(7); 
	double longitude = (double) msg->longitude;
	double latitude = (double) msg->latitude;
	double altitude = 400.0;

  	ROS_INFO("I heard the longitude: [%3.7f]", longitude);
  	ROS_INFO("I heard the latitude: [%3.7f]", latitude); 
  
  	int a = 0;

  	// bool argument (false) is given when we perform the calculations for one UAV only, instead of 4.
  	a = perform_simulation(longitude, latitude, altitude, false, 0);
    //.c_str()); //data.c_str());
}

// Creates one waypoint file for UAV $uav_id (of Replan_Msg).
// Coordinates given of the bottom left corner of an 2km x 2km area for coverage. 
void replannerCallback(const waypoint_planning::Replan_Msg::ConstPtr& msg)
{	
	std::cout << std::setprecision(7); 
	int uav_id = (int) msg->uav_id;
	double longitude = (double) msg->coordinates.longitude;
	double latitude = (double) msg->coordinates.latitude;
	double altitude = 400.0;

  	ROS_INFO("I heard UAV id: [%i]", uav_id);
  	ROS_INFO("I heard the longitude: [%3.7f]", longitude);
  	ROS_INFO("I heard the latitude: [%3.7f]", latitude); 
  
  	int a = 0;
  	// bool argument (true) is given when we perform the calculations for one UAV only.
  	a = perform_simulation(longitude, latitude, altitude, true, uav_id);
    //.c_str()); //data.c_str());
}

// create a listener to the topic "waypoint_planner".
// when a set of lat long has been published to the topic waypoint_planner,
// calculate the waypoint files.
int main(int argc, char **argv)
{

	int number_of_uav;

	ros::init(argc, argv, "waypoint_planning_listener");

	ros::NodeHandle n;

	ros::Subscriber multiple_sub = n.subscribe("waypoint_release_spot", 1000, chatterCallback);

	ros::Subscriber single_sub = n.subscribe("waypoint_replanner", 1000, replannerCallback);
	
	ros::spin();

	return 0;
	// int a = 0;
	//    a = perform_simulation();

    //testTransformationFunctions();
	//return a;
}

