#include <curses.h>
#include <string>
#include <unistd.h>

//Reads Robot Sensor Data and Displays
//Reads Motor Status and Displays

//recieves commands and uses to control motors

void Interface()
{
	char input;
	//Setup curses.h
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	
	while(1)
	{
		input = getch();
		erase();	//clears screen
		
		printw("------------Robopot-Display------------\n"
		"input: %c\n",
		input
		/*"------------Sensor-Display------------\n"
		"Proximity Sensor Data: %i\n"
		"Magnemometer Sensor Data: %i\n"
		"GUI Input: %c\n"
		"------------Motor-Display------------\n"
		"Motor 1: %i\n"
		"Motor 2: %i\n"*/		
		);
	}
	
	
}