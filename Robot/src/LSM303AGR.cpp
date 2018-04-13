#include "Location.h"

	LSM303AGR::LSM303AGR()
	{
//	fd = wiringPiI2CSetup(MAG_ADDR);
//	return fd;
	}

	int LSM303AGR::setup()
	{
	fd = wiringPiI2CSetup(MAG_ADDR);
	return fd;
	}
	//int fd;
//	int fd = wiringPiI2CSetup(MAG_ADDR);

	int LSM303AGR::configure(){
		alastair = wiringPiI2CWriteReg8(fd, CFG_REG_A_M, 0x00);//configure with default settings
	}

	int LSM303AGR::readCh1(int fd){
		msbX = wiringPiI2CReadReg8(fd, OUTX_H_REG_M);//68h and 69h for X output registers, 69 is MSB(?)
		lsbX = wiringPiI2CReadReg8(fd, OUTX_L_REG_M);
		xresult = (msbX<<8 | lsbX);//the value is a 16-bit signed integer. Therefore, shift the 8 bits read before (msbX) and input the latter 8 bits on the end.
		return xresult;
	}

	int LSM303AGR::readCh2(int fd){
		msbY = wiringPiI2CReadReg8(fd, OUTY_H_REG_M);//6Ah and 6Bh for y output registers,
		lsbY = wiringPiI2CReadReg8(fd, OUTY_L_REG_M);
		yresult = (msbY << 8) | (lsbY);
		return yresult;
	}
