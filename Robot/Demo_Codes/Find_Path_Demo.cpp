#include <iostream>
#include "Location.h"
#include "Move.h"

int main()
{
	char ref;
	char Destination, Pot_Start_Position;
	int start_Bearing;
	char FirstLorR, SecondLorR;
	char Stop = 'A';
	Location loc;
	Move Motors;

	while (Stop != 'x')
	{
		std::cout << "Enter a start square from 'A' to 'P'" << std::endl;
		std::cin >> Pot_Start_Position;
		std::cout << "Enter a start bearing from 0 to 360" << std::endl;
		std::cin >> start_Bearing;
		std::cout << "Enter an end square from 'A' to 'P'" << std::endl;
		std::cin >> Destination;

		loc.Find_Path(Destination, Pot_Start_Position);
		if (loc.No_X_Turn == 0)
		{
			FirstLorR = Motors.Turn_LeftorRight(loc.X_Bearing, start_Bearing);
		}
		else
		{
			FirstLorR = 'X';
		}
		if (loc.No_Y_Turn == 0)
		{
			SecondLorR = Motors.Turn_LeftorRight(loc.Y_Bearing, loc.X_Bearing);
		}
		else
		{
			SecondLorR = 'X';
		}


		std::cout << "You will start at " << Pot_Start_Position << std::endl;
		if (FirstLorR == 'X')
		{
		}
		else
		{
			std::cout << "You will turn to the " << FirstLorR << " to face " << loc.X_Bearing << " degrees" << std::endl;
			std::cout << "You will move forward by " << loc.X_PathLength << " squares" << std::endl;
		}
		if (SecondLorR == 'X')
		{
		}
		else
		{
			std::cout << "You will turn to the " << SecondLorR << " to face " << loc.Y_Bearing << " degrees" << std::endl;
			std::cout << "You will move forward by " << loc.Y_PathLength << " squares " << std::endl;
		}
		std::cout << "You will end at " << Destination << std::endl;

		std::cout << "Enter x to end " << std::endl;

		std::cin >> Stop;
	}

	return 0;
}
