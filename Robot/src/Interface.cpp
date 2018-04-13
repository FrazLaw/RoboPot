#include <curses.h>
#include <string>
#include <unistd.h>
//#include <stdio.h>
#include <Location.h>

//Reads Robot Sensor Data and Displays
//Reads Motor Status and Displays

//recieves commands and uses to control motors

LSM303AGR lsm;
int fd = lsm.setup();
int x = lsm.configure();

void Interface()
{
	char input;
	//Setup curses.h
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	Location dis;
//	dis.Magno_Init();
	while(1)
	{

		input = getch();
		erase();	//clears screen

		printw("------------Robopot-Display------------\n"
		"------------Sensor-Display------------\n"
//		"Proximity Sensor Data: %i\n"
		"Magnemometer Sensor Data: %i\n"
		//"GUI Input: %c\n",
		//"------------Motor-Display------------\n"
		//"Motor 1: %i\n"
		//"Motor 2: %i\n", 
//		      , dis.Find_Proximity()
			,dis.Find_Direction(fd)
		);

	}
}
