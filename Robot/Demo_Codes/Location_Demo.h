#ifndef Location_H
#define Location_H

#include <cmath>

#define North_Bearing 0
#define East_Bearing 90
#define West_Bearing 270
#define South_Bearing 180


class Location
{
public:

	int X_Bearing;
	int Y_Bearing;
	int X_PathLength;
	int Y_PathLength;
	int No_X_Turn;
	int No_Y_Turn;
	void Find_Path(char Destination, char Pot_Start_Position);

	Location();
	~Location();

private:

	const char Location_ref[4][4] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P' };

	void Find_coordinates(int ref, int *x, int *y);
};

#endif // !Location