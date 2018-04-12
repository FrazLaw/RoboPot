

Location::Location()
{
}


Location::~Location()
{
}

int Location::Setup()
{

}

char Location::Find_Pot()
{
	
	int x,y;
	int Proximity_North;
	int Proximity_East;
	int Proximity_South;
	int Proximity_West;
	
	Move Navigate;
	Location Check;
	
	Navigate.Turn(North_Bearing);
	Proximity_North= Check.Find_Proximity()/Unit_Length;
	
	Navigate.Turn(East_Bearing);
	Proximity_East= Check.Find_Proximity()/Unit_Length;
	
	Navigate.Turn(South_Bearing);
	Proximity_South= Check.Find_Proximity()/Unit_Length;
	
	Navigate.Turn(West_Bearing);
	Proximity_West= Check.Find_Proximity()/Unit_Length;
	
	//Confirm x coordinate using East and West Proximity Measurements
	if((Proximity_East + Proximity_West) == 3*Unit_Length)
	{
		x = Proximity_East;		
	}
	
	//Confirm y coordinate using North and South Proximity Measurements
	if((Proximity_North + Proximity_South) == 3*Unit_Length)
	{
		y = Proximity_North;		
	}
	
	
	return Location_ref[x][y];
	
}

int Location::Find_Direction()
{

	//using namespace std;

	int LSM303AGR::getFileDescriptor()
	{
		//cout << fd << endl;
		return fd;

	}

	int LSM303AGR::configure(){
		alastair = wiringPiI2CWriteReg8(fd, CFG_REG_A_M, 0x00);//configure with default settings
	}

	int LSM303AGR::readCh1(){
		msbX = wiringPiI2CReadReg8(fd, OUTX_H_REG_M);//68h and 69h for X output registers, 69 is MSB(?)
		lsbX = wiringPiI2CReadReg8(fd, OUTX_L_REG_M);
		xresult = (msbX<<8 | lsbX);//the value is a 16-bit signed integer. Therefore, shift the 8 bits read before (msbX) and input the latter 8 bits on the end.
		return xresult;
	}

	int LSM303AGR::readCh2(){
		msbY = wiringPiI2CReadReg8(fd, OUTY_H_REG_M);//6Ah and 6Bh for y output registers,
		lsbY = wiringPiI2CReadReg8(fd, OUTY_L_REG_M);
		yresult = (msbY << 8) | (lsbY);
		return yresult;
	}

	//int main(){

	LSM303AGR lsm;
	ofstream magneto;

	lsm.configure();

		for (int i = 0; i<100000; i++){//number of output checks

			int sum = 0;
			float average = 0;
			float compass[10];
			float direction; //compass coordingate

			for (int j = 0; j < 10; j++){//number of averages, 10 seems to be max

				float x = lsm.readCh1()-307;//to centre the plot around 0. It performs as expected with few errors

				float y = lsm.readCh2();


				float coord = x/y;

				if (y > 0){
					direction = 90 - atan(coord)*(180/PI);
					compass[j] = direction;
				} else if (y < 0){
					direction = 270 - atan(coord)*(180/PI);
					compass[j] = direction;
				} else if (y == 0 && x < 0){
					direction = 180;
					compass[j] = direction;
				} else if (y == 0 && x > 0){
					direction = 0;
					compass[j] = direction;
				} else {
					printf("Direction = error\n");
				}
			sum += compass[j];
			}
		average = sum/10;
		cout << "average direction = " << average << endl;
		magneto.open("magneto.txt");
		magneto << average;
		magneto.close();
		}

	//}

}

int Location::Find_Proximity()
{
	int i;
	int divisor=5;
	int proximity_measurements=0;
	VL53L0X_Error Status = VL53L0X_ERROR_NONE;
	VL53L0X_Dev_t MyDevice;
	VL53L0X_Dev_t *pMyDevice = &MyDevice;
	VL53L0X_RangingMeasurementData_t RangingMeasurementData;

	printf("VL53L0X API Simple Ranging example FMenzies mod\n\n");

	pMyDevice->I2cDevAddr = 0x29;

	pMyDevice->fd = VL53L0X_i2c_init((char*)"/dev/i2c-1", pMyDevice->I2cDevAddr);//choose between i2c-0 and i2c-1; On the raspberry pi zero, i2c-1 are pins 2 and 3


	if (Status == VL53L0X_ERROR_NONE)
	{
		for (i = 0;i<divisor;i++)
		{
			printf("Call of VL53L0X_PerformSingleRangingMeasurement\n");
			Status = VL53L0X_PerformSingleRangingMeasurement(pMyDevice,&RangingMeasurementData);
			//printf("Measured distance: %i\n\n", RangingMeasurementData.RangeMilliMeter);
			proximity_measurements += RangingMeasurementData.RangeMilliMeter;
		}
		return Round_Proximity((proximity_measurements /divisor), 50);
	}
}

void Location::Find_Path(char Destination, char Pot_Start_Position)
{
	int Dest_x, Dest_y; //Destination coordinates
	int Loc_x, Loc_y;	//Present Location Coordinates
	Find_coordinates(Destination, &Dest_x, &Dest_y);
	Find_coordinates(Pot_Start_Position, &Loc_x, &Loc_y);

	int X_PathLength = Dest_x - Loc_x;
	int Y_PathLength = Dest_y - Loc_y;
	
	if (X_PathLength > 0)
	{
		int X_Bearing = East_Bearing;
	}
	else if (X_PathLength < 0)
	{
		int X_Bearing = West_Bearing;
	}
	else
	{
		int X_Bearing = 0;
	}

	if (Y_PathLength > 0)
	{
		int Y_Bearing = South_Bearing;
	}
	else if (Y_PathLength < 0)
	{
		int Y_Bearing = North_Bearing;
	}
	else
	{
		int Y_Bearing = 0;
	}
}

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

int Location::Round_Proximity(int Proximity, int Multiple)
{	
	return ((Proximity+Multiple/2)/Multiple)*Multiple;
}
