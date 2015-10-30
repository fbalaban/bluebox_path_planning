/*
 * map.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: Leopoldo Rodríguez Salazar, Fotis Balampanis
 */

// LIBRARIES
#include <fstream>
#include <iostream>
// HEADER FILES
#include <camera_model.h>
#include <constants.h>
#include <fparams.h>
#include <map.h>
#include <math.h>

using namespace std;

ofstream mapCoord("mapCoordinates.csv");

// Initialize a rectangle of 2000M X 2000M
/*
 * y
 * ^
 * |____________________________
 * | P3(x,y)            P2(x,y) |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |                            |
 * |____________________________|------>x
 *  P0(x,y)                P1(x,y)
 */
map initializeMap() {
	map input_map;
	input_map.NTotal = 1;
	input_map.Nx = 1;
	input_map.Ny = 1;
	input_map.p0[0] = 0.0;
	input_map.p0[1] = 0.0;
	input_map.p1[0] = 2000.0;
	input_map.p1[1] = 0.0;
	input_map.p2[0] = 2000.0;
	input_map.p2[1] = 2000.0;
	input_map.p3[0] = 0.0;
	input_map.p3[1] = 2000.0;
	return input_map;
}
;

/*
 * Initialize the cells as follows:
 *
 * y
 * ^
 * |__________________
 * | P3(x,y)   P2(x,y)|
 * |                  |
 * |                  |
 * |                  |
 * |__________________|-----> x
 *  P0(x,y)    P1(x,y)
 */

cell initializeCell() {
	cell input_cell;
	input_cell.Number = 0;
	input_cell.isValid = true;
	input_cell.p0[0] = 0.0;
	input_cell.p0[1] = 0.0;
	input_cell.p1[0] = 0.0;
	input_cell.p1[1] = 0.0;
	input_cell.p2[0] = 0.0;
	input_cell.p2[1] = 0.0;
	input_cell.p3[0] = 0.0;
	input_cell.p3[1] = 0.0;
	return input_cell;
}
;

// This function calculates the number of cells in the x and y direction of
// the map.
map calculateCells(map iM, footprint iFP) {

	double mapLength, mapWidth;
	// once again, the efficiency of the footprint. was 0.8, for testing is 1.
	double effFP = 1;
	// Calculation of vector
	mapLength = iM.p1[0] - iM.p0[0];
	mapWidth = iM.p3[1] - iM.p0[1];

	// At first we consider the 80% of the footprint to be effective, this
	// ensures that map will be covered, this number may be optimized.

	iM.Nx = int(ceil(mapLength / (effFP * iFP.fpXlen)));
	iM.Ny = int(ceil(mapWidth / (effFP * iFP.fpYlen)));
	return iM;
}
;

// This function assigns the coordinates of the cells utilizing the input of
// the map and the footprint. This will allow the creation of waypoint in the
// trajectory
int assignCells(cell *inputCell, int size, double effFP, map inputMap,
		footprint inputFP) {
	int k = 0;
	const int x = 0;
	const int y = 1;

	mapCoord << "'Number'; 'POx'; 'P0y';'P1x';'P1y';'P2x';'P2y';'P3x';'P3y'"
			<< endl;

	inputCell[0].p0[x] = 0.0;
	inputCell[0].p0[y] = 0.0;
	inputCell[0].p1[x] = inputCell[0].p0[x] + effFP * inputFP.fpXlen;
	inputCell[0].p1[y] = inputCell[0].p0[y];
	inputCell[0].p2[x] = inputCell[0].p0[x] + effFP * inputFP.fpXlen;
	inputCell[0].p2[y] = inputCell[0].p0[y] + effFP * inputFP.fpYlen;
	inputCell[0].p3[x] = inputCell[0].p0[x];
	inputCell[0].p3[y] = inputCell[0].p0[y] + effFP * inputFP.fpYlen;
	inputCell[0].Number = 0;

	mapCoord << inputCell[0].Number << ", ";
	mapCoord << inputCell[0].p0[x] << ", ";
	mapCoord << inputCell[0].p0[y] << ", ";
	mapCoord << inputCell[0].p1[x] << ", ";
	mapCoord << inputCell[0].p1[y] << ", ";
	mapCoord << inputCell[0].p2[x] << ", ";
	mapCoord << inputCell[0].p2[y] << ", ";
	mapCoord << inputCell[0].p3[x] << ", ";
	mapCoord << inputCell[0].p3[y] << "," << endl;

	int reverse = 1;
	int j = 0;

	for (int i(1); i < size; i++) {
		k++;
		j++;

		// This portion of the algorithm determines when the x coordinate shall
		// reset to 0.

		if (k % inputMap.Nx <= SMALL) {
			reverse = reverse * (-1);
			k = 0;
			//inputCell[i].p0[x] = 0.0;
			inputCell[i].p0[x] = inputCell[i - 1].p0[x];
			inputCell[i].p0[y] = inputCell[i - 1].p0[y] + effFP * inputFP.fpYlen;
		} else {
			inputCell[i].p0[x] = inputCell[i - 1].p0[x] + (reverse *(effFP * inputFP.fpXlen));
			inputCell[i].p0[y] = inputCell[i - 1].p0[y];
		}

		// Calculate X - Coordinates of Cells

		inputCell[i].p1[x] = inputCell[i].p0[x] + effFP * inputFP.fpXlen;
		inputCell[i].p2[x] = inputCell[i].p1[x];
		inputCell[i].p3[x] = inputCell[i].p0[x];

		// Calculate Y coordinates of cells (reset when the cell has been
		//calculated)

		inputCell[i].p1[y] = inputCell[i].p0[y];
		inputCell[i].p2[y] = inputCell[i].p0[y] + effFP * inputFP.fpYlen;
		inputCell[i].p3[y] = inputCell[i].p2[y];
		inputCell[i].Number = j;
		mapCoord << inputCell[i].Number << ", ";
		mapCoord << inputCell[i].p0[x] << ", ";
		mapCoord << inputCell[i].p0[y] << ", ";
		mapCoord << inputCell[i].p1[x] << ", ";
		mapCoord << inputCell[i].p1[y] << ", ";
		mapCoord << inputCell[i].p2[x] << ", ";
		mapCoord << inputCell[i].p2[y] << ", ";
		mapCoord << inputCell[i].p3[x] << ", ";
		mapCoord << inputCell[i].p3[y] << "," << endl;

	};

	mapCoord.close();

	return k;

}
;

