#ifndef GYRO_H
#define GYRO_H

#include <Arduino.h>
#include<Wire.h>

 /*
  * Code adapted from How2Electronics 
  * URL https://how2electronics.com/measure-tilt-angle-mpu6050-arduino/
  * Modified by Alden Giedraitis
  * 
   */
 
extern const int MPU_addr;
extern int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
extern int minVal;
extern int maxVal;
extern double x;
extern double y;
extern double z;

void offsetAngles();

int determineDirection();

void gyro_setup();


void gyro_loop();


#endif
