/*
 * earth_model.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: Fotis Balampanis
 */

#include <fparams.h>
#include <iostream>
#include <earth_model.h>

using namespace std;

position_llh startllhCoord(double h){
	position_llh startCoord;
	cout << "Enter initial latitude coordinate on map" << endl;
	cin >> startCoord.lat;
	cout << "Enter initial longitude coordinate on map" << endl;
	cin >> startCoord.lon;
	startCoord.h = h;
	return startCoord;

}



