/*
 * tranformation_utilities.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Fotis Balampanis
 */

#include <iostream>
#include <cmath>
#include <constants.h>
#include <transformation_utilities.h>

using namespace std;

// as of "http://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm" ,
// you should use it like so (and the same for the llh2ecef function:

// double *llh;
// llh = ecef2llh(x,y,z);

double* ecef2llh (double x, double y, double z){

	static double llh[3];
	double longitude, latitude, height, radiusOfCurvature, p, theta;
	p = sqrt(pow(x, 2) + pow(y, 2));
	theta = atan((z * r_earth) / (p * b));

	longitude = atan(y / x);

	latitude = atan(((z + pow(e2, 2) * b * pow(sin(theta), 3)) / ((p - pow(e, 2) * r_earth * pow(cos(theta), 3)))));

	radiusOfCurvature = r_earth / (sqrt(1 - (pow(e, 2) * pow(sin(latitude), 2))));
	height = (p / cos(theta)) - radiusOfCurvature;

	longitude = (longitude*180)/PI;
	latitude = (latitude*180)/PI;

	llh[0] = longitude;
	llh[1] = latitude;
	llh[2] = height;

	return llh;
}

double* llh2ecef(double longitude, double latitude, double height){

	static double ecef[3];

	double x, y, z, radiusOfCurvature;

	radiusOfCurvature = r_earth / (sqrt(1 - (pow(e, 2) * pow(sin(latitude), 2))));

	x = (radiusOfCurvature+height) * cos(latitude) * cos(longitude);
	y = (radiusOfCurvature+height) * cos(latitude) * sin(longitude);

	z = (((pow(b, 2) / pow(r_earth, 2)) * radiusOfCurvature) + height) * sin(latitude);

	ecef[0] = x;
	ecef[1] = y;
	ecef[2] = z;

	return ecef;

}

// for small distances (some kilometers) the displacement can be performed
// by applying a simplistic calculation:
// new latitude = latitude (initial position) + (dy / r_earth) * (180/pi);
// new longitude = longitude (initial position) + (dx / r_earth) * (180/pi) / cos(latitude * pi/180);
// since our flight path is in meters and dy and dx are in km, dx,dy is
// actually the xPostition, yPosition divided by 1000.
double latitudeDisplacement(double initialLatitude, double meters){

	double newLatitude = 0.0;
	newLatitude = initialLatitude + ((meters/1000) / r_earth) * (180/PI);
	return newLatitude;

}

double longitudeDisplacement(double initialLongitude, double displacedLatitude, double meters){

	double newLongitude = 0.0;
	newLongitude = initialLongitude + ((((meters/1000) / r_earth) * (180/PI)) / cos(displacedLatitude * (PI/180)));
	return newLongitude;

}

void testTransformationFunctions(){

	double longitude = -5.994072;
	double latitude = 37.411437;
	double height = 35.3; // in meters

	// in kilometers.. please be aware that the above and below values
	//are the correct transformed values
	// according to http://www.oc.nps.edu/oc2902w/coord/llhxyz.htm

	double x = 5044.678;
	double y = -529.689;
	double z = 3853.783;

	double *llhToEcefResult;
	double *ecefToLlhResult;

	llhToEcefResult = llh2ecef(longitude, latitude, height);
	ecefToLlhResult = ecef2llh(x, y, z);

	cout << "Testing transformation functions.." << endl;

	cout << "llhToEcefResult: x should be  close to '5044.678' and it's: " << llhToEcefResult[0] << endl;
	cout << "llhToEcefResult: y should be  close to '-529.689' and it's: " << llhToEcefResult[1] << endl;
	cout << "llhToEcefResult: z should be  close to '3853.783' and it's: " << llhToEcefResult[2] << endl;

	cout << "ecefToLlhResult: longitude should be  close to '-5.994072' and it's: " << ecefToLlhResult[0] << endl;
	cout << "ecefToLlhResult: latitude should be  close to '37.411437' and it's: " << ecefToLlhResult[1] << endl;
	cout << "ecefToLlhResult: height should be  close to '35.3' and it's: " << ecefToLlhResult[2] << endl;
}



