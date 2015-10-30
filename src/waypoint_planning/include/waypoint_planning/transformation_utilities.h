/*
 * transformation_utilities.h
 *
 *  Created on: Sep 7, 2015
 *      Author: fotis balampanis
 *
 *      Utility class for performing various transformations.
 *      ECEF2LLH, LLH2ECEF
 */

#ifndef TRANSFORMATION_UTILITIES_H_
#define TRANSFORMATION_UTILITIES_H_

#include <cmath>

// ----Variables and structures ----

// WGS84 Parameters
const static double r_earth = 6378.137; // in kilometers
const static double f = 1/298.257224;
const static double b = r_earth*(1-f);
const static double e = sqrt(pow(r_earth, 2) - pow(b, 2)) / pow(r_earth, 2);
const static double e2 = sqrt(pow(r_earth, 2) - pow(b, 2)) / pow(b, 2);

// the latitude, longitude, height structure
struct llh {

	double longitude;
	double latitude;
	double height;

};

// the earth-centered, earth-fixed coordinate structure
struct ecef {

	double x;
	double y;
	double z;
};

// --------- Functions ---------//

double* ecef2llh(double x, double y, double z);
double* llh2ecef(double longitude, double latitude, double height);

// transform coordinates, by a given displacement in meters
double latitudeDisplacement(double initialLatitude, double meters);
double longitudeDisplacement(double initialLongitude, double displacedLatitude, double meters);


void testTransformationFunctions();

#endif /* TRANSFORMATION_UTILITIES_H_ */
