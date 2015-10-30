/*
 * flightPlan.h


 *
 *  Created on: Sep 2, 2015
 *      Author: Leopoldo Rodríguez Salazar
 *      The flight plan management utility works with the creation of waypoints
 *		EDIT: ALL ENUM TYPES WERE CLASSES. changed for compliance with c++03. ROS 
 *				before Jade had problems when compiling in c++11.
 *
 */

#ifndef FLIGHT_PLAN_H_
#define FLIGHT_PLAN_H_

#include <waypoint_planning/map.h>
#include <waypoint_planning/fparams.h>

// define the type of waypoint either fly-over, fly-by.
enum WptType {
	flyOver, flyBy
};

// define waypoint position type: local (map frame) or global (ecef/llh frame)
enum WptPosType {
	local, global
};

// Define swipe direction positive x/y or negative x/y considering
// the map definition on map.h
enum SwipeDirection {
	posx, posy, negx, negy
};

// Define the direction of turning
enum TurnDirection {
	clckwise, ctrclckwise
};

enum WptStatus {
	inCurrentFP, sequenced, passed, deleted, notinFP
};

struct waypoint {
	int IDNumber;
	int SEQNumber;
	double xPosition;
	double yPosition;
	WptPosType PosType;
	WptType Type;
	WptStatus Status;
	bool isValid;
	bool isOnMap;

};

struct flightPlan {
	waypoint *wptList;
	bool isValid;

};

class LocalWaypoint {
public:
	waypoint localWpt;
	void createLocalWpt(cell inputCell);
	waypoint nextLocalWpt(flightPlan inputFlightPlan, positionMap inputPos);
};

class GlobalWaypoint {
public:
	waypoint globalWpt;

};

class LocalFlightPlan {
public:
	flightPlan localFP;
	SwipeDirection swipeDir;
	void defineSwpDirection(map inputMap, positionMap initPos);
	waypoint detLocStartingWpt(map inputMap, flightPlan inputFPln,
			positionMap initPos);
	void createLocalFP(map inputMap, SwipeDirection SwpDir,
			int initWPT,  cell *inputCell);
	void createLocalFP(map inputMap, 
			int initWPT,  cell *inputCell, double lat, double lon);
	waypoint sequenceWpt(flightPlan inputFPln, positionMap initPos);
};

class GlobalFlightPlan {
public:
	flightPlan globalFP;
	void createGlobalFP(flightPlan inputFPln);
};

positionMap selectStartMapCoord(double h);
waypoint detRemainingWpt(flightPlan inputFPln, waypoint currentWpt);
waypoint nextWaypoint(waypoint *inWPTList, waypoint currentWpt,
		flightParams inputFParams);
#endif /* FLIGHT_PLAN_H_ */
