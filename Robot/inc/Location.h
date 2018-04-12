#ifndef Location_H
#define Location_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "Project_Config.h"
#include "Move.h"
#include "LSM303AGR.h"

//Location Public Variables
extern int X_Bearing;
extern int Y_Bearing;
extern int X_PathLength;
extern int Y_PathLength;

extern int Final_Proximity;

class Location
{
public:
	//Location Functions
	Location();
	~Location();
	int Setup(); //Sets bearings and initial location of pot
	char Find_Pot();	//returns character representing location of Pot
	void Find_Path(char Destination, char Pot_Start_Position);
	int Find_Direction(); //Returns present bearing 0-360degrees
	int Find_Proximity(); // Returns distance to front wall
//	void Initialise_Proximity(); //Initialises Sensor


private:
	void Find_coordinates(char ref, int *x, int *y); //converts abcd etc into x and y coordinates
	
	const char Location_ref[4][4] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P' };
	int Round_Proximity(int Proximity, int Multiple);
	VL53L0X_Error WaitMeasurementDataReady(VL53L0X_DEV Dev);
	VL53L0X_Error WaitStopCompleted(VL53L0X_DEV Dev);
	
};

#endif
