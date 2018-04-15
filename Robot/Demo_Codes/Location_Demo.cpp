#include "Location.h"



Location::Location()
{
}


Location::~Location()
{
}

void Location::Find_coordinates(int ref, int *x, int *y)
{
	int i, j;

	for (i = 0;i<4;i++)
	{
		for (j = 0;j<4;j++)
		{
			if (ref == Location_ref[i][j])
			{
				*y = i;
				*x = j;
			}
		}
	}
}

void Location::Find_Path(char Destination, char Pot_Start_Position)
{
	int Dest_x, Dest_y; //Destination coordinates
	int Start_x, Start_y;	//Present Location Coordinates

	No_X_Turn = 0;
	No_Y_Turn = 0;
	Find_coordinates(Destination, &Dest_x, &Dest_y);
	Find_coordinates(Pot_Start_Position, &Start_x, &Start_y);

	X_PathLength = Dest_x - Start_x;
	Y_PathLength = Dest_y - Start_y;

	if (X_PathLength > 0)
	{
		X_Bearing = East_Bearing;
	}
	else if (X_PathLength < 0)
	{
		X_Bearing = West_Bearing;
		X_PathLength = abs(Dest_x - Start_x);
	}
	else
	{
		No_X_Turn = 1;
	}

	if (Y_PathLength > 0)
	{
		Y_Bearing = South_Bearing;
	}
	else if (Y_PathLength < 0)
	{
		Y_Bearing = North_Bearing;
		Y_PathLength = abs(Dest_y - Start_y);
	}
	else
	{
		No_Y_Turn = 1;
	}
}