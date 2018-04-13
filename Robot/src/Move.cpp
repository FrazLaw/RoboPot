#include "Move.h"



Move::Move()
{
}


Move::~Move()
{
}
//Dependencies Proximity Sensor
void Move::Drive()
{
	//Move one unit space 2m/4units= 0.5m=500mm
	Location unit;	
	int start_Distance = unit.Find_Proximity();		//Using LIDAR to determine forward drive distance
	while ((unit.Find_Proximity()-start_Distance )< 50) {
		softPwmWrite(Left_High_Motor, PWM_Set_Slow);
		softPwmWrite(Right_High_Motor, PWM_Set_Slow);
		softPwmWrite(Left_Low_Motor, 0);
		softPwmWrite(Right_Low_Motor, 0);
	}

	while ((unit.Find_Proximity() - start_Distance) < 100) {
		softPwmWrite(Left_High_Motor, PWM_Set_Medium);
		softPwmWrite(Right_High_Motor, PWM_Set_Medium);
		softPwmWrite(Left_Low_Motor, 0);
		softPwmWrite(Right_Low_Motor, 0);
	}

	while ((unit.Find_Proximity() - start_Distance) < 400) {
		softPwmWrite(Left_High_Motor, PWM_Set_Fast);
		softPwmWrite(Right_High_Motor, PWM_Set_Fast);
		softPwmWrite(Left_Low_Motor, 0);
		softPwmWrite(Right_Low_Motor, 0);
	}

	while ((unit.Find_Proximity() - start_Distance) < 450) {
		softPwmWrite(Left_High_Motor, PWM_Set_Medium);
		softPwmWrite(Right_High_Motor, PWM_Set_Medium);
		softPwmWrite(Left_Low_Motor, 0);
		softPwmWrite(Right_Low_Motor, 0);
	}

	while ((unit.Find_Proximity() - start_Distance) < 500) {
		pwmWrite(Left_High_Motor, PWM_Set_Slow);
		pwmWrite(Right_High_Motor, PWM_Set_Slow);
		digitalWrite(Left_Low_Motor, 0);
		digitalWrite(Right_Low_Motor, 0);
	}

	softPwmWrite(Left_High_Motor, PWM_Set_Stop);
	softPwmWrite(Right_High_Motor, PWM_Set_Stop);
	softPwmWrite(Left_Low_Motor, 0);
	softPwmWrite(Right_Low_Motor, 0);
}

//Dependencies Magnemometer
void Move::Turn(int Target_Bearing) //Turns the Robot to the Target Bearing
{
	Location Facing;
	LSM303AGR lsm;
	int fd = lsm.setup();
	int x = lsm.configure();
	
	int Current_Bearing = Facing.Find_Direction(fd);	//Using Magnemometer to determine turning angle
	
	char Turn_Direction = Turn_LeftorRight(Target_Bearing, Current_Bearing);
	
	if (Turn_Direction == 'R')
	{
		while (abs(Facing.Find_Direction()-Target_Bearing)>5)
		{
			softPwmWrite(Left_High_Motor, PWM_Set_Medium);
			softPwmWrite(Left_Low_Motor, 0);
		}
		softPwmWrite(Left_High_Motor, PWM_Set_Stop);
		softPwmWrite(Left_Low_Motor, 0);
	}else	
	if (Turn_Direction == 'L')
	{
		while (abs(Facing.Find_Direction()-Target_Bearing)>5)
		{
			softPwmWrite(Right_High_Motor, PWM_Set_Medium);
			softPwmWrite(Right_Low_Motor, 0);
		}
		softPwmWrite(Right_High_Motor, PWM_Set_Stop);
		softPwmWrite(Right_Low_Motor, 0);
	}

}

int Move::Initialise() 		//Initialises wiringPi
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

char Move::Turn_LeftorRight(int Target_Bearing, int Current_Bearing)
{
	
	int a = Target_Bearing-Current_Bearing;
	int b = Target_Bearing-Current_Bearing + 360;
	int c = Target_Bearing-Current_Bearing - 360;
	
	if(abs(a)>abs(b)&& abs(a)>abs(c))
	{
		if(a > 0)
		{
			return 'R';//Turn Right
		}else
		{
			return 'L';//Turn Left
		}
	}else
	if(abs(b)>abs(a)&& abs(b)>abs(c))
	{
		if(b > 0)
		{
			return 'R';//Turn Right
		}else
		{
			return 'L';//Turn Left
		}
	}
	if(abs(c)>abs(a)&& abs(c)>abs(a))
	{
		if(c > 0)
		{
			return 'R';//Turn Right
		}else
		{
			return 'L';//Turn Left
		}
	}
}
