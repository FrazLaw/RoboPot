#include <wiringPi.h>	//RPI headers and functions commented out in laptop version
#include <stdio.h>
#include <fstream>

string cmdfile = "/var/www/html/readme.txt";

int main()
{
	
	int init = Initialise();
	
	while (1)
	{	
		if(Read_cmd(cmdfile) == 'A')//Read GUI
		{
			softPwmWrite(Left_High_Motor, 800);
			softPwmWrite(Right_High_Motor, 800);
			softPwmWrite(Left_Low_Motor, 0);
			softPwmWrite(Right_Low_Motor, 0);	
		}
		if(Read_cmd(cmdfile) == 'B')//Read GUI
		{
			softPwmWrite(Left_High_Motor, 0);
			softPwmWrite(Right_High_Motor, 0);
			softPwmWrite(Left_Low_Motor, 0);
			softPwmWrite(Right_Low_Motor, 0);	
		}
		if(Read_cmd(cmdfile) == 'C')//Read GUI
		{
			softPwmWrite(Left_High_Motor, 0);
			softPwmWrite(Right_High_Motor, 800);
			softPwmWrite(Left_Low_Motor, 0);
			softPwmWrite(Right_Low_Motor, 0);	
		}
		if(Read_cmd(cmdfile) == 'D')//Read GUI
		{
			softPwmWrite(Left_High_Motor, 800);
			softPwmWrite(Right_High_Motor, 0);
			softPwmWrite(Left_Low_Motor, 0);
			softPwmWrite(Right_Low_Motor, 0);	
		}
	//Move Motors	
	}
	
}

char Read_Cmd(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	file.get(cmd);
//	remove(filename.c_str());
	return cmd;
}


int Initialise() 		//Initialises wiringPi
{
	//Initialise Wiring Pi
	if (wiringPiSetup() == -1)
	{
		printf("Wiring Pi Setup Failed \n");
		return -1;
	}
	//Set Motor Pin Configuration
	if (
	softPwmCreate(Left_High_Motor, 0, 1000) != 0 ||
	softPwmCreate(Left_Low_Motor, 0, 1000) != 0 ||
	softPwmCreate(Right_High_Motor, 0, 1000) != 0 ||
	softPwmCreate(Right_Low_Motor, 0, 1000) != 0)
	{
		printf("PWM Pin Creation Failed");
	}

	return 0;

}