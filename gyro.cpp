/*
 * Code adapted from How2Electronics 
 * URL https://how2electronics.com/measure-tilt-angle-mpu6050-arduino/
 * Modified by Alden Giedraitis
 * 
  */


#include "gyro.h"

 
const int MPU_addr = 0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int minVal = 265;
int maxVal = 402;
double x;
double y;
double z;


//If gyro values are non-zero when flat, adjust based on these constants
void offsetAngles(){
  
  x-= 359.4;

  y-=4;

  z-=350;

}

//Check angular position of gyro and choose a direction
int determineDirection(){

  if (y >=30 && y <=80 /*&& x > -1 && x < 1*/){
    //Serial.println("UP");

    return 1;
  }

  else if( y >=260 && y<=330 /*&& x >-1 && x < 1*/){
    //Serial.println("DOWN");

    return 2;
  }

  else if (x >=-340 && x<=-290 /*&& y >-1 && y < 1*/){
    //Serial.println("LEFT");

    return 3;
  }

  else if(x >=-90 && x <= -30 /*&& y > -1 && y < 1*/){
    //Serial.println("RIGHT");

    return 4;
  }

  else return 0; //Any other value, return a value of 0 
  
}

//Set up line transmission for data
void gyro_setup(){
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
//Serial.begin(9600);
}


void gyro_loop(){

//Read in data from MPU6050 gyro and get angular values

Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,-90,90);
int yAng = map(AcY,minVal,maxVal,-90,90);
int zAng = map(AcZ,minVal,maxVal,-90,90);
 
x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

offsetAngles(); //Adjust angles accordingly

delay(100); //Add delay to give time for python to process direction sent: data from gyro comes in fast

/*
Serial.print("AngleX= ");
Serial.println(x);
 
Serial.print("AngleY= ");
Serial.println(y);
 
Serial.print("AngleZ= ");
Serial.println(z);
Serial.println("-----------------------------------------");
*/


//determineDirection();

//delay(20);


/*
Serial.write(27);       // ESC command
Serial.print("[2J");    // clear screen command
Serial.write(27);
Serial.print("[H");     // cursor to home command
*/  
  
}
