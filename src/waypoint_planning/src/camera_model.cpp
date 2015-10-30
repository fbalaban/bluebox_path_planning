/*
 * camera_model.cpp

 *
 *  Created on: Aug 25, 2015
 *      Author: Leopoldo Rodríguez Salazar
 *
 *      Model for front-mounted vision camera
 */

#include <cmath>
#include <string>
#include "constants.h"
#include <camera_model.h>
#include <fparams.h>

using namespace std;


// This function initializes the camera variables
camera2 initializeCamera(){

	camera2 finput_camera;
	finput_camera.xSensor  = 36*PI/180;
	finput_camera.ySensor  = 24*PI/180;
	finput_camera.focallen = 50*PI/180;
	finput_camera.xGimbal  = 30*PI/180;
	finput_camera.yGimbal  = 0*PI/180;


	return finput_camera;
};

// This function initializes the footprint values.
footprint initializeFootprint(){
	footprint fp_Camera;

	fp_Camera.fpBdist = 0.0;
	fp_Camera.fpXlen = 0.0;
	fp_Camera.fpLdist = 0.0;
	fp_Camera.fpRdist = 0.0;
	fp_Camera.fpTdist = 0.0;
	fp_Camera.fpYlen = 0.0;
	fp_Camera.fpGXdistToCenter = 0.0;
	fp_Camera.fpGYdistToCenter = 0.0;

	return fp_Camera;
};

// This function calculates the footprint of the camera utilizing inputs
// of the flight parameters. Initially the attitude is ignored (assuming
// that the gimbal can compensate the aircraft movement.

footprint calculateFootprint(camera2 finput_camera, flightParams fParams){

	double fovW, fovT;
	footprint fp_Camera;

	// Calculate field of view wide
	fovW = 2*atan(finput_camera.xSensor/(2*finput_camera.focallen));

	// Calculate field of view tall
	fovT = 2*atan(finput_camera.ySensor/(2*finput_camera.focallen));

	// Calculate distance from platform to bottom picture
	fp_Camera.fpBdist = fParams.fllhPosition.h * tan(finput_camera.xGimbal - 0.5*fovW);

	// Calculate distance from platform to top of picture
	fp_Camera.fpTdist = fParams.fllhPosition.h * tan(finput_camera.xGimbal + 0.5*fovW);

	// Calculate distance from platform to left of picture
	fp_Camera.fpLdist = fParams.fllhPosition.h * tan(finput_camera.yGimbal - 0.5*fovT);

	// Calculate distance from platform to right of picture
	fp_Camera.fpRdist = fParams.fllhPosition.h * tan(finput_camera.yGimbal + 0.5*fovT);

    // 	Calculate the length among the X-Axis of the footprint
	// 	for testing purposes, the footprint is now static (20m footprint)
	// 	fp_Camera.fpXlen = fp_Camera.fpTdist  - fp_Camera.fpBdist;
		fp_Camera.fpXlen = staticFootprintSize;

	// 	Calculate the length among the Y-Axis of the footprint
	//	the same goes for y value (testing - 20m footprint)
	//	fp_Camera.fpYlen = fp_Camera.fpRdist - fp_Camera.fpLdist;
		fp_Camera.fpYlen = staticFootprintSize;

	// Calculate the ground distance from platform to center of footprint.
	fp_Camera.fpGXdistToCenter = fParams.fllhPosition.h * tan(finput_camera.xGimbal);


	fp_Camera.fpGYdistToCenter = fParams.fllhPosition.h * tan(finput_camera.yGimbal);

	return fp_Camera;

};



