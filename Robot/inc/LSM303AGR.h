#ifndef LSM303AGR_H
#define LSM303AGR_H

//#include "Location.h"
//#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <linux/i2c.h>
//#include "LSM303AGR.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
//#include <fstream>

#define PI 3.14159265 //used for calculations
#define ACC_ADDR 0x19 //not used
#define MAG_ADDR 0x1E
//default addresses
#define STATUS_REG_M 0x67
#define OUTX_L_REG_M 0x68 //lsb
#define OUTX_H_REG_M 0x69 //msb to shift << 8
#define OUTY_L_REG_M 0x6A //lsb
#define OUTY_H_REG_M 0x6B //msb to shift
#define OUTZ_L_REG_M 0x6C //lsb
#define OUTZ_H_REG_M 0x6D //msb to shift
#define WHO_AM_I_M  0x4F // device ID
#define CFG_REG_A_M 0x60 //configure address

class LSM303AGR
{
	int msbX;
	int lsbX;
	int msbY;
	int lsbY;
	int msbZ;
	int lsbZ;
	int fd;
	int alastair;
	int16_t xresult;
	int16_t yresult;
	int16_t zresult;
public:
	LSM303AGR();
	int setup();
	int configure();
	int getFileDescriptor();
	int dataAvailable();
	int readCh1(int fd);
	int readCh2(int fd);
	int readCh3();
	int startSeq();
	int sadW();
	int sak();
	int sub();
	int sadR();
};

#endif
