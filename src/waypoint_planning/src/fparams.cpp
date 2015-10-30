/*
 * fparms.cpp

 *
 *  Created on: Aug 26, 2015
 *      Author: Leopoldo Rodríguez Salazar, Fotis Balampanis
 */

#include <fparams.h>

velocity initializeVelocity(){ //velocity in ECEF (m/s)
	velocity fVelocity;
	fVelocity.vx = 0.0;
	fVelocity.vy = 0.0;
	fVelocity.vz = 0.0;
	return fVelocity;
}

attitude initializeAttitude(){ //radians
	attitude fAttitude;
	fAttitude.pitch_angle = 0.0;
	fAttitude.roll_angle = 0.0;
	fAttitude.yaw_angle = 0.0;
	return fAttitude;
}

position_ecef initializeAbsPos(){ //position in ECEF (m/s)
	position_ecef fAbsPos;
	fAbsPos.px = 0.0;
	fAbsPos.py = 0.0;
	fAbsPos.pz = 0.0;
	return fAbsPos;
}

position_llh initializeLLHPos(){
	position_llh fllHPos;
	fllHPos.h = 0.0;
	fllHPos.lat = 0.0;
	fllHPos.lon = 0.0;
	return fllHPos;
}

flightParams initializeFParams(){
	flightParams fParams;
	fParams.fVelocity = initializeVelocity();
	fParams.fAttitude = initializeAttitude();
	fParams.fAbsPosition = initializeAbsPos();
	fParams.fllhPosition = initializeLLHPos();
	return fParams;
}
