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

### Read and write Characters from the GUI- GUI Class

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

### Translate characters into coordinates- Location Class

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


### Return data from VL53L0X Proximity and from LSM303AGR Magnetometer Sensors- Location Class

Reading proximity data from the STM VL53l0X is no trivial task. It requires implementing the use of an API specific to the sensor and compilation of the required libraries in order to make it work. In addition use of the API is itself is a challenge as many of the settings of the sensor must be set up correctly in order for any meaningfull data to be returned. As of yet there is no publication of the registers and register functions of the sensor.</br>

The LSM303AGR was used by programming the required registers over I2C using the WiringPi library. This, in addition to performing a mathematical operation on the sensor as described [here.](https://github.com/FrazLaw/RoboPot/tree/master/Sensors/Magnetometer)

### Determine Path to reach destination- Location Class

The code has an initial location of robopot already stored.
