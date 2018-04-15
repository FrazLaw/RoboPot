#include <curses.h>
#include <string>
#include <unistd.h>
#include <Location.h>

//Reads Robot Sensor Data and Displays

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

	Location dis; //Display location
	while(1)
	{
		erase();	//clears screen

		printw("------------Robopot-Display------------\n"
		"------------Sensor-Display------------\n"
		"Proximity Sensor Data: %i\n"
		"Magnemometer Sensor Data: %i\n" 
		      , dis.Find_Proximity()
			,dis.Find_Direction(fd)
		);

	}
}
