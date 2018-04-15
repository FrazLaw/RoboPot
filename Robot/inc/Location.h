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


class Location
{
public:
	int X_Bearing;
	int Y_Bearing;
	int X_PathLength;
	int Y_PathLength;
	int Final_Proximity;
	
	//Location Functions
	Location();
	~Location();
	char Find_Pot();	//returns character representing location of Pot
	void Find_Path(char Destination, char Pot_Start_Position);
	int Find_Direction(int fd); //Returns present bearing 0-360degrees
	int Find_Proximity(); // Returns distance to front wall

private:
	void Find_coordinates(char ref, int *x, int *y); //converts abcd etc into x and y coordinates
	
	const char Location_ref[4][4] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P' };
	int Round_Proximity(int Proximity, int Multiple);
	//Used for VL53L0X LIDAR API
	VL53L0X_Error WaitMeasurementDataReady(VL53L0X_DEV Dev);
	VL53L0X_Error WaitStopCompleted(VL53L0X_DEV Dev);
	
};

#endif
