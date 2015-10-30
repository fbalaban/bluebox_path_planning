/*
 * camera_model.h



 *
 *  Created on: Aug 25, 2015
 *      Author: Leopoldo Rodríguez Salazar
 */

#ifndef CAMERA_MODEL_H_
#define CAMERA_MODEL_H_

#include <waypoint_planning/fparams.h>

// ----------------------------------------------------------------
// --------------VARIABLES AND STRUCTURES--------------------------

// -- This structure defines the parameter of the camera
struct camera2{
	double xSensor;     // Width of sensor in mm
	double ySensor; 	// Height of sensor in mm
	double focallen; 	// Focal length of sensor in mm
	double xGimbal;     // X-Axis gimbal angle
	double yGimbal;      // Y-Axis gimbal angle
};

struct footprint{
	double fpXlen;    // Height of footprint in m
	double fpYlen;     // Width of footprint in m
	double fpGXdistToCenter;     // Projected X distance from UAV to the center of footprint
	double fpGYdistToCenter;     // Projected Y distance from UAV to the center of footprint
	double fpBdist;     // Ground distance from platform to Bottom picture
	double fpTdist;     // Ground distance from platform to Top picture
	double fpLdist;     // Calculate distance from platform to Left picture
	double fpRdist;      // Calculate distance from platform to Right picture
};


// ----------------------------------------------------------------
// ---------------------------FUNCTIONS----------------------------

camera2 initializeCamera();
footprint initializeFootprint();


footprint calculateFootprint(camera2 finput_camera, flightParams fParams);

#endif /* CAMERA_MODEL_H_ */
