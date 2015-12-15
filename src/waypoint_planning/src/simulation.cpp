/*
 * simulation.cpp

 *
 *  Created on: Aug 31, 2015
 *      Author: Leopoldo Rodríguez Salazar, Fotis Balampanis
 */

// LIBRARIES
#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

// HEADER FILES
#include <waypoint_planning/atmos.h>
#include <waypoint_planning/camera_model.h>
#include <waypoint_planning/fparams.h>
#include <waypoint_planning/flight_plan.h>
#include <waypoint_planning/map.h>

using namespace std;

int perform_simulation(double longitude, double latitude, double altitude, bool forSingleUav, int for_uav_id) {

	// Variable initialization
	camera2 simCamera;
	flightParams fParams;
	map sampleMap;
	footprint inputFP;
	flightPlan inputFPln;

	int nCells;
	int arrSize = 0;
	cell *iC;
	time_t now = time(0);
	char* dt = ctime(&now);
	// the following is the efficiency of the footprint. was 0.8, for now is 1
	double effFP = 1.0;

	// Text input initialization
	ofstream LogFile("LOG.txt");
	ofstream FPLog("flightPlan.csv");

	LogFile << "Log from " << dt << endl;

	// cout << "Welcome to the simulation, press any key to continue..." << endl;
	// cin.get();

	cout << "Performing initializations..." << endl;

	simCamera = initializeCamera();
	LogFile << "Camera initialized successfully" << endl;

	fParams = initializeFParams();
	LogFile << "Flight parameters initialized successfully" << endl;

	sampleMap = initializeMap();
	LogFile << "Map initialized successfully" << endl;
	LogFile << "Map length is" << sampleMap.p1[0] - sampleMap.p0[0] << endl;
	LogFile << "Map width is" << sampleMap.p3[1] - sampleMap.p0[1] << endl;

	inputFP = initializeFootprint();
	LogFile << "footprint initialized successfully" << endl;

	cout << "SUCCESS" << endl;

	// cout << "Please enter a desired altitude:" << endl;
	// cin >> fParams.fllhPosition.h;
	fParams.fllhPosition.h = altitude;
	LogFile << "Selected altitude is " << fixed << fParams.fllhPosition.h
			<< endl;

	// cout << "Enter longitude:" << endl;
	// cin >> fParams.fllhPosition.lon;
	fParams.fllhPosition.lon = longitude;
	LogFile << "Selected longitude is " << fixed << fParams.fllhPosition.lon
			<< endl;

	// cout << "Enter latitude:" << endl;
	// cin >> fParams.fllhPosition.lat;
	fParams.fllhPosition.lat = latitude;
	LogFile << "Selected latitude is " << fixed << fParams.fllhPosition.lat
			<< endl;

	cout << "Simulation started" << endl;

	LogFile << "Calculating Footprint..." << endl;
	inputFP = calculateFootprint(simCamera, fParams);

	LogFile << "Footprint X Distance is " << fixed << inputFP.fpXlen << endl;
	LogFile << "Footprint Y Distance is " << fixed << inputFP.fpYlen << endl;

	sampleMap = calculateCells(sampleMap, inputFP);

	LogFile << "Cells in the X Direction " << sampleMap.Nx << endl;
	LogFile << "Cells in the Y Direction " << sampleMap.Ny << endl;

	// Create the dynamic array
	arrSize = (sampleMap.Nx * sampleMap.Ny);
	iC = new cell[arrSize];

	// call the assign cell function in order to
	// determine the position of the cells.
	nCells = assignCells(iC, arrSize, effFP, sampleMap, inputFP);

	// It will be defined once the cells and waypoints are created.
	// The following has been changed.
	// SwipeDirection stub = SwipeDirection::posx;

	// Create an object of the class LocalFlightPlan
	LocalFlightPlan locFP;

	// Create the local flight plan (waypoint list)
	// locFP.createLocalFP(sampleMap, stub, 0, iC);

	// Create the local flight plan (waypoint list) along with a second
	// flight plan transforming the coordinates (testing purposes)
	// should be done by using the GlobalFlightPlan made by Leo in the future.
	// CHANGED: removed the flight direction (stub)
	// CHANGED: added last bool parameter when we produce the files for a single UAV only
	// (as it was in the first place actually...). TRUE for one UAV, FALSE for 4.
	locFP.createLocalFP(sampleMap, 0, iC, fParams.fllhPosition.lat,
			fParams.fllhPosition.lon, forSingleUav, for_uav_id);

	// Assign the actual Flight Plan to a FP Variable
	inputFPln = locFP.localFP;

	LogFile << "Flight Plan created" << endl;

	// ***********************************************************************
	// ***********************************************************************

	cout << "DONE!! :)" << endl;
	cout << nCells;

	return 1;

}

