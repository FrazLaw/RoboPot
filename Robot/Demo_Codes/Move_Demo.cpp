#include "Move.h"



Move::Move()
{
}


Move::~Move()
{
}

char Move::Turn_LeftorRight(int Target_Bearing, int Current_Bearing) //Returns whether left or right is shortest distance to target bearing
{

	int a = Target_Bearing - Current_Bearing;
	int b = Target_Bearing - Current_Bearing + 360;
	int c = Target_Bearing - Current_Bearing - 360;

	if (abs(a)>abs(b) && abs(a)>abs(c))
	{
		if (a > 0)
		{
			return 'R';//Turn Right
		}
		else
		{
			return 'L';//Turn Left
		}
	}
	else
		if (abs(b)>abs(a) && abs(b)>abs(c))
		{
			if (b > 0)
			{
				return 'R';//Turn Right
			}
			else
			{
				return 'L';//Turn Left
			}
		}
	if (abs(c)>abs(a) && abs(c)>abs(a))
	{
		if (c > 0)
		{
			return 'R';//Turn Right
		}
		else
		{
			return 'L';//Turn Left
		}
	}
}