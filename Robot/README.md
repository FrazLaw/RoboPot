# Robot Control Code - Team RoboPot

The Robot Control Code was required to fullfill the requirements outlined in the readme on the [front page of this Github repository!](https://github.com/FrazLaw/RoboPot)

The code can be built using the Makefile. To work on your own Raspberry Pi the Makefile must be edited by changing the Proj_Dir variable to whatever file you are building your project from. For example in the Makefile at present the directory in which the code is located is **/home/pi/Robopot/Robot** .

All C++ files are stored in src and all headers are stored in inc. The VL53L0X API is stored in a seperate directory called Proximity_Sensor.</br>

# Code Functionality
### Code Structure

The main code calls three c++ classes and sets up one thread. The classes are Location, Move and GUI and the thread handles displaying sensor data to a screen.</br>

**GUI Class**</br>
-Read characters from the GUI</br>
-Send characters to the GUI</br>
**Location Class**</br>
-Translate these characters into coordinates</br>
-Read data from magnetometer and proximity sensor</br>
-Determine the path to reach destination</br>
**Move Class**</br>
-Actuate motors</br>
**Interface Thread**</br>
-Display sensor data for debugging</br>
## GUI Class
### Read and write Characters from the GUI

This task is easily accomplished by and writing data to specific text files stored on the apache server which hosts the GUI interface. The C++ <fstream> standard library was used to accomplish this. <\br>
```c++
char GUI::Read_Cmd(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	file.get(cmd);
	return cmd;
}
//Writes to file to inform GUI of present location
void GUI::Send(const std::string& filename, const std::string& message)
{
	std::ifstream file;
	file.open(filename.c_str());
}
```
## Location Class
### Translate characters into coordinates

This function will translate the input character **ref** into the required x and y coordinates required to calculate the path to robopots destination. For example 'A' corresponds to x =0, y=0 and P corresponds to x=3, y=3;
```c++

const char Location_ref[4][4] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P' };

void Location::Find_coordinates(char ref, int *x, int *y)
{
	int i, j;

	for (i = 0;i<4;i++)
	{
		for (j = 0;j<4;j++)
		{
			if (ref == Location_ref[i][j])
			{
				*x = i;
				*y = j;
			}
		}
	}
}

```


### Return data from VL53L0X Proximity and from LSM303AGR Magnetometer Sensors

Reading proximity data from the STM VL53l0X is no trivial task. It requires implementing the use of an API specific to the sensor and compilation of the required libraries in order to make it work. In addition use of the API is itself is a challenge as many of the settings of the sensor must be set up correctly in order for any meaningfull data to be returned. As of yet there is no publication of the registers and register functions of the sensor.</br>

The LSM303AGR was used by programming the required registers over I2C using the WiringPi library. This, in addition to performing a mathematical operation on the sensor as described [here.](https://github.com/FrazLaw/RoboPot/tree/master/Sensors/Magnetometer)

### Determine Path to reach destination

The code has an initial location of robopot already stored. The robot then calculates the required path for the robot to travel in using the Find_Path() function.

```c++

void Location::Find_Path(char Destination, char Pot_Start_Position)
{
	int Dest_x, Dest_y; //Destination coordinates
	int Start_x, Start_y;	//Start Location Coordinates
	Find_coordinates(Destination, &Dest_x, &Dest_y);
	Find_coordinates(Pot_Start_Position, &Start_x, &Start_y);
	
	No_X_Turn = 0;
	No_Y_Turn = 0;
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
```

This is further illustrated in this video. https://youtu.be/BEZmMBXUMUo using the code from [here.](https://github.com/FrazLaw/RoboPot/tree/master/Robot/Demo_Codes)

##Motor Class
### Actuate Motors

The motors can be used in conjunction with the magnetometer and proximity sensor to move around the garden by a known length or angle.

To drive by a single unit length the following code is used.
```c++
void Move::Drive()
{
	//Move one unit space 2m/4units= 0.5m=500mm
	Location unit;	
	int start_Distance = unit.Find_Proximity();		//Using LIDAR to determine forward drive distance

	while ((unit.Find_Proximity() - start_Distance) < Unit_Length) {
		softPwmWrite(Left_High_Motor, PWM_Set_Fast);
		softPwmWrite(Right_High_Motor, PWM_Set_Fast);
		softPwmWrite(Left_Low_Motor, 0);
		softPwmWrite(Right_Low_Motor, 0);
	}

	softPwmWrite(Left_High_Motor, PWM_Set_Stop);
	softPwmWrite(Right_High_Motor, PWM_Set_Stop);
	softPwmWrite(Left_Low_Motor, 0);
	softPwmWrite(Right_Low_Motor, 0);
}
```
To turn to within 5 degrees of the target bearing the following code is used.

```c++
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
		while (abs(Facing.Find_Direction(fd)-Target_Bearing)>5)
		{
			softPwmWrite(Left_High_Motor, PWM_Set_Medium);
			softPwmWrite(Left_Low_Motor, 0);
		}
		softPwmWrite(Left_High_Motor, PWM_Set_Stop);
		softPwmWrite(Left_Low_Motor, 0);
	}else	
	if (Turn_Direction == 'L')
	{
		while (abs(Facing.Find_Direction(fd)-Target_Bearing)>5)
		{
			softPwmWrite(Right_High_Motor, PWM_Set_Medium);
			softPwmWrite(Right_Low_Motor, 0);
		}
		softPwmWrite(Right_High_Motor, PWM_Set_Stop);
		softPwmWrite(Right_Low_Motor, 0);
	}

}
```

