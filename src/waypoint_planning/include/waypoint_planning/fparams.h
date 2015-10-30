/*
 * fparams.h
 *
 *  Created on: Aug 26, 2015
 *      Author: Leopoldo Rodríguez Salazar
 *
 *  This header files defines y structures, variables and functions utilized
 *  to calculate the flight parameters such as:
 *  Velocity, Attitude, Position (ECEF/LLH)
 *
 *
 */

#ifndef FPARAMS_H_
#define FPARAMS_H_

// ----------------------------------------------------------------
// --------------VARIABLES AND STRUCTURES--------------------------

// Structure that defines the velocity in the earth frame (ECEF).
struct velocity {
	double vx;
	double vy;
	double vz;
};

// Structure that defines the attitude in the local frame (body frame)
struct attitude {
	double pitch_angle;
	double roll_angle;
	double yaw_angle;
};

// Structure that defines the position in the ECEF frame
struct position_ecef {
	double px;
	double py;
	double pz;

};

// Structure that defines the position expressed in terms of latitude,
// longitude and altitude.
struct position_llh {
	double lat;
	double lon;
	double h;
};

// Structure that defines the flight parameters.
struct flightParams {

	velocity fVelocity;
	attitude fAttitude;
	position_ecef fAbsPosition;
	position_llh fllhPosition;

};

// ----------------------------------------------------------------
// ---------------------------FUNCTIONS----------------------------

velocity initializeVelocity();            // Initialize velocity
attitude initializeAttitude();            // Initialize attitude
position_ecef initializeAbsPosition(); // Initialize position (ECEF)
position_llh initializeLLHPosition();   // Initialize position (LLH)
flightParams initializeFParams();       // Initilize flight paramenters.

#endif /* FPARAMS_H_ */
