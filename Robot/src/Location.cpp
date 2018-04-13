#include "Location.h"

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
	

	return 'a';
}

int Location::Find_Direction(int fd)
{

	LSM303AGR lsm;
//	lsm.configure();
//	lsm.setup();
			int sum = 0;
			float average = 0;
			float compass[10];
			float direction; //compass coordingate

			for (int j = 0; j < 10; j++){//number of averages, 10 seems to be max

				float x = lsm.readCh1(fd)-307;//to centre the plot around 0. It performs as expected with few errors
				float y = lsm.readCh2(fd);
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
//					printf("Direction = error\n");
				}
				sum += compass[j];
			}
		average = sum/10;

		return average;

}

//Returns Proximity Data 
int Location::Find_Proximity()
{
	int Final_Proximity;
/*	VL53L0X_Error Status = VL53L0X_ERROR_NONE;
	VL53L0X_Dev_t MyDevice;
	VL53L0X_Dev_t *pMyDevice = &MyDevice;
//	printf("VL53L0X API Simple Ranging example FMenzies mod\n\n");

	pMyDevice->I2cDevAddr = 0x29;

	pMyDevice->fd = VL53L0X_i2c_init((char*)"/dev/i2c-1", pMyDevice->I2cDevAddr);//choose between i2c-0 and i2c-1; On the raspberry pi zero, i2c-1 are pins 2 and 3

	if(Status == VL53L0X_ERROR_NONE)
    {
        Status = VL53L0X_DataInit(&MyDevice); // Data initialization
    }

	
    VL53L0X_RangingMeasurementData_t    RangingMeasurementData;
    VL53L0X_RangingMeasurementData_t   *pRangingMeasurementData    = &RangingMeasurementData;

    uint32_t refSpadCount;
    uint8_t isApertureSpads;
    uint8_t VhvSettings;
    uint8_t PhaseCal;
	
	if(Status == VL53L0X_ERROR_NONE)
    {
//        printf ("Call of VL53L0X_StaticInit\n");
        Status = VL53L0X_StaticInit(pMyDevice); // Device Initialization
        // StaticInit will set interrupt by default
    }
    if(Status == VL53L0X_ERROR_NONE)
    {
//        printf ("Call of VL53L0X_PerformRefCalibration\n");
        Status = VL53L0X_PerformRefCalibration(pMyDevice,
        		&VhvSettings, &PhaseCal); // Device Initialization
    }

    if(Status == VL53L0X_ERROR_NONE)
    {
//        printf ("Call of VL53L0X_PerformRefSpadManagement\n");
        Status = VL53L0X_PerformRefSpadManagement(pMyDevice,
        		&refSpadCount, &isApertureSpads); // Device Initialization
    }

    if(Status == VL53L0X_ERROR_NONE)
    {

//        printf ("Call of VL53L0X_SetDeviceMode\n");
        Status = VL53L0X_SetDeviceMode(pMyDevice, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING); // Setup in single ranging mode
    }

    if(Status == VL53L0X_ERROR_NONE)
    {
//		printf ("Call of VL53L0X_StartMeasurement\n");
		Status = VL53L0X_StartMeasurement(pMyDevice);
    }

	if(Status == VL53L0X_ERROR_NONE)
    {
	int Proximity=0, sumProximity=0;
        uint32_t measurement;
        uint32_t no_of_measurements = 50;

        uint16_t* pResults = (uint16_t*)malloc(sizeof(uint16_t) * no_of_measurements);

        for(measurement=0; measurement<no_of_measurements; measurement++)
        {

            Status = WaitMeasurementDataReady(pMyDevice);

            if(Status == VL53L0X_ERROR_NONE)
            {
                Status = VL53L0X_GetRangingMeasurementData(pMyDevice, pRangingMeasurementData);

                *(pResults + measurement) = pRangingMeasurementData->RangeMilliMeter;
		 Proximity = pRangingMeasurementData->RangeMilliMeter;
//               printf("In loop measurement %d: %d\n", measurement, pRangingMeasurementData->RangeMilliMeter);

                // Clear the interrupt
                VL53L0X_ClearInterruptMask(pMyDevice, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
                VL53L0X_PollingDelay(pMyDevice);
		sumProximity=sumProximity + Proximity;
            } else {
                break;
            }
        }
	Final_Proximity = sumProximity/50;
	return sumProximity/50;

        if(Status == VL53L0X_ERROR_NONE)
        {
            for(measurement=0; measurement<no_of_measurements; measurement++)
            {
               printf("measurement %d: %d\n", measurement, *(pResults + measurement));
            }
        }

        free(pResults);
    }

    
    if(Status == VL53L0X_ERROR_NONE)
    {
//        printf ("Call of VL53L0X_StopMeasurement\n");
        Status = VL53L0X_StopMeasurement(pMyDevice);
    }

    if(Status == VL53L0X_ERROR_NONE)
    {
//        printf ("Wait Stop to be competed\n");
        Status = WaitStopCompleted(pMyDevice);
    }

    if(Status == VL53L0X_ERROR_NONE)
	Status = VL53L0X_ClearInterruptMask(pMyDevice,
		VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
*/
//    return Status;

	return 5;
}

//  Used for Sensor API
VL53L0X_Error Location::WaitStopCompleted(VL53L0X_DEV Dev) {
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    uint32_t StopCompleted=0;
    uint32_t LoopNb;

    // Wait until it finished
    // use timeout to avoid deadlock
    if (Status == VL53L0X_ERROR_NONE) {
        LoopNb = 0;
        do {
            Status = VL53L0X_GetStopCompletedStatus(Dev, &StopCompleted);
            if ((StopCompleted == 0x00) || Status != VL53L0X_ERROR_NONE) {
                break;
            }
            LoopNb = LoopNb + 1;
            VL53L0X_PollingDelay(Dev);
        } while (LoopNb < VL53L0X_DEFAULT_MAX_LOOP);

        if (LoopNb >= VL53L0X_DEFAULT_MAX_LOOP) {
            Status = VL53L0X_ERROR_TIME_OUT;
        }
	
    }

    return Status;
}

// Used for Sensor API
VL53L0X_Error Location::WaitMeasurementDataReady(VL53L0X_DEV Dev) {
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    uint8_t NewDatReady=0;
    uint32_t LoopNb;

    // Wait until it finished
    // use timeout to avoid deadlock
    if (Status == VL53L0X_ERROR_NONE) {
        LoopNb = 0;
        do {
            Status = VL53L0X_GetMeasurementDataReady(Dev, &NewDatReady);
            if ((NewDatReady == 0x01) || Status != VL53L0X_ERROR_NONE) {
                break;
            }
            LoopNb = LoopNb + 1;
            VL53L0X_PollingDelay(Dev);
        } while (LoopNb < VL53L0X_DEFAULT_MAX_LOOP);

        if (LoopNb >= VL53L0X_DEFAULT_MAX_LOOP) {
            Status = VL53L0X_ERROR_TIME_OUT;
        }
    }

    return Status;
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
