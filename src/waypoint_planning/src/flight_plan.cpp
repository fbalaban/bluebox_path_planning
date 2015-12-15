/*
 * flightPlan.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: Fotis Balampanis, Leopoldo Rodriguez Salazar
 *
 *      The flight plan library allows the creation of a Flight plan based on
 *      cells and waypoints. It contains different functions and utilities to
 *      create flight plans at a local level (based on input map) and then
 *      transform it to a global level.
 *
 *      TODO: clean code, extend
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <waypoint_planning/flight_plan.h>
#include <waypoint_planning/map.h>
#include <waypoint_planning/transformation_utilities.h>

using namespace std;

ofstream fPlanData("flightPlan.csv");
ofstream fPlanDataCoordinates("flightPlanCoordinates.csv");

void LocalWaypoint::createLocalWpt(cell inputCell) {

	double P0x = inputCell.p0[0];
	double P0y = inputCell.p0[1];

	double P1x = inputCell.p1[0];
	double P3y = inputCell.p3[1];

	localWpt.IDNumber = 0;
	localWpt.SEQNumber = 0;
	localWpt.isOnMap = true;
	localWpt.isValid = true;
	localWpt.PosType = local;
	localWpt.Type = flyOver;
	localWpt.Status = notinFP;
	localWpt.xPosition = (P1x - P0x) / 2 + P0x;
	localWpt.yPosition = (P3y - P0y) / 2 + P0y;

}

waypoint LocalFlightPlan::detLocStartingWpt(map inputMap, flightPlan inputFPln,
			positionMap initPos){

}

// This function creates a local flight plan (map frame)
// by determining the center of each cell.
 // the method has been changed. no swipe direction in this version //
void LocalFlightPlan::createLocalFP(map inputMap,
		int initWPT, cell *inputCell, double lat, double lon, bool forSingleUAV, int for_uav_id) { // remove lat,lon to go back to previous implementation..

	 // Define the size of the array
	int size = inputMap.Nx * inputMap.Ny;

	// Define the array (dynamic allocation)
	localFP.wptList = new waypoint[size];

	// create a LocalWaypoint object
	LocalWaypoint locWPT;

	fPlanData << "'UAVID', 'WptID', 'Py_map', 'Px_map',"<< endl;
	fPlanDataCoordinates << "'UAVID', 'WptID', 'Lat', 'Lon',"<< endl;

	int times;

	if (forSingleUAV){
		times = 2;	
	} else {
		times = 5;
	}

	// Creates an array of waypoints;
	for (int i(1); i < times; i++){

		stringstream filename;
		
		if (forSingleUAV){
			filename << "wpPlanUAV" << for_uav_id << ".txt";
		} else {
			filename << "wpPlanUAV" << i << ".txt";
		}
		// see http://stackoverflow.com/questions/1374468/stringstream-string-and-char-conversion-confusion
		const std::string& tmp = filename.str();
  		const char* cstr = tmp.c_str();

		ofstream fWPPlan(cstr); //.str()
		//fWPPlan << "QGC WPL 110" << endl;

		for (int j(0); j < size; j++) {

			double newLongitude;
			double newLatitude;
			double newLonPosition;
			double newLatPosition;

			locWPT.createLocalWpt(inputCell[j]);
			localFP.wptList[j] = locWPT.localWpt;
			localFP.wptList[j].IDNumber = j;

			if (forSingleUAV){
				fPlanData << for_uav_id << ", ";
				fPlanDataCoordinates << for_uav_id << ", ";
			} else {
				fPlanData << i << ", ";
				fPlanDataCoordinates << i << ", ";
			}

			fPlanData << localFP.wptList[j].IDNumber << ", ";
			fPlanDataCoordinates << localFP.wptList[j].IDNumber << ", ";

			newLatPosition = localFP.wptList[j].yPosition;
			newLonPosition = localFP.wptList[j].xPosition;

			if (i==2 || i==3){
				newLatPosition = -newLatPosition;
			}

			if (i > 2){
				newLonPosition = -newLonPosition;
			}

			newLatitude = latitudeDisplacement(lat, newLatPosition);
			newLongitude = longitudeDisplacement(lon, newLatitude, newLonPosition);

			fPlanData << newLatPosition <<", ";
			fPlanDataCoordinates << fixed << setprecision(7) << newLatitude << ", ";

			fPlanData << newLonPosition <<"," << endl;
			fPlanDataCoordinates << fixed << setprecision(7) << newLongitude <<"," << endl;

			// creation of wp file for mavLink waypoint file format:
			if (j<1){
				// this is the initial position (the x spot). For now is the default location
				// of the ardupilot simulation tests in Australia.
				// The altitude variable is in the final parameter.
				fWPPlan << "0\t1\t0\t16\t0\t0\t0\t0\t" << fixed << setprecision(7) << lat << "\t"
						<< fixed <<  setprecision(7) << lon << "\t585\t1" << endl;
				// TODO: IN REPLANNING (THERE SHOULD NOT BE A TAKE OFF COMMAND - OR IT SHOULD BE PARAMETERIZATION)
				// and here is the first waypoint to takeoff to. when the UAVs are airborn,
				// only waypoint commands like the following will be there are the plane doesn't
				// need to take off.
				fWPPlan << "1\t0\t3\t22\t15\t0\t0\t0\t" << fixed << setprecision(7) << newLatitude << "\t"
						<< fixed << setprecision(7) << newLongitude << "\t100\t1" << endl;
			} else {
				fWPPlan << j+1 << "\t0\t3\t16\t0\t0\t0\t0\t" << fixed << setprecision(7) << newLatitude << "\t"
						<< fixed << setprecision(7) << newLongitude << "\t100\t1" << endl;
			}

			// for small distances, some kilometers, the displacement can be performed
			// by applying a simplistic calculation:
			// new latitude = latitude (initial position) + (dy / r_earth) * (180/pi);
			// new longitude = longitude (initial position) + (dx / r_earth) * (180/pi) / cos(latitude * pi/180);
			// since our flight path is in meters and dy and dx are in km, dx,dy is
			// actually the xPostition, yPosition divided by 1000.
//			fPlanDataCoordinates << i << ", ";
//			fPlanDataCoordinates << localFP.wptList[j].IDNumber << ", ";
//			double newLatitude = latitudeDisplacement(lat, localFP.wptList[j].yPosition);
//			fPlanDataCoordinates << fixed << newLatitude << ", ";
//			fPlanDataCoordinates << fixed << longitudeDisplacement(lon, newLatitude, localFP.wptList[j].xPosition) <<"," << endl;
			}
		// fWPPlan << size+1 << "\t0\t3\t20\t0\t0\t0\t0\t0\t0\t0\t1" << endl;
		fWPPlan << size+2 << "\t0\t3\t21\t480\t0\t0\t25\t" << fixed << setprecision(7) << lat << "\t"
				<< fixed << setprecision(7) << lon << "\t580\t1" << endl;
		fWPPlan.close();
	}
	// Define the sequence of waypoints;

	fPlanData.close();
	fPlanDataCoordinates.close();
}

positionMap selectStartMapCoord(double h) {
	positionMap startcoord;
	cout << "Enter initial position x coordinate on map" << endl;
	cin >> startcoord.px;
	cout << "Enter initial position y coordinate on map" << endl;
	cin >> startcoord.py;
	startcoord.pz = h;
	return startcoord;
}

