/*
 * map.h

 *
 *  Created on: Aug 25, 2015
 *      Author: Leopoldo Rodriguez Salazar
 */

#ifndef MAP_H_
#define MAP_H_

#include <fstream>
#include <waypoint_planning/camera_model.h>
#include <waypoint_planning/fparams.h>

using namespace std;



// As a starting point a rectangular map is defined

struct map{
	double p0[2]; // 1st Corner of map
	double p1[2]; // 2nd Corner of map
	double p2[2]; // 3rd Corner of map
	double p3[2]; // 4th Corner of map
	int Nx; // Number of cells in the x direction
	int Ny; // Number of cells in the y direction
	int NTotal; //Total Number of Cells;
};

struct cell{
	int Number;   // Number of cell
	bool isValid; // Cell is Valid
	double p0[2]; // 1st Corner of cell
    double p1[2]; // 2nd Corner of cell
	double p2[2]; // 3rd Corner of cell
	double p3[2]; // 4th Corner of cell
};

// Defines a position (X,Y,Z) on the map frame.
struct positionMap{
	double px;
	double py;
	double pz;
};


// Initialize Map
map initializeMap();

// Initialize Cell
cell initializeCell();

// This function calculates the number of cells in which the map will be divided
map calculateCells(map iM, footprint iFP);

// This function assign the values to the cells (position values)
int assignCells(cell *inputCell, int size, double effFP, map inputMap, footprint inputFP);

// This function calculates if a given cell is passed
bool cellPassed(map inputMap, flightParams inputfParams, cell inputCells[]);

position_ecef mapToECEF();




#endif /* MAP_H_ */
