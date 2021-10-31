#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <Arduino.h>

/*
 * Code adapted from Minuka Thesath Yapa
 * URL: https://create.arduino.cc/projecthub/MinukaThesathYapa/arduino-thumb-joystick-to-processing-92c182
 * Modified by Alden Giedraitis
 * 
  */


extern int xValue;
extern int yValue; 


extern int currJoy;

extern int prevJoy;

extern int controlMode; 

void joy_setup(); 

int detectDirection();

void getJoyMode();

//void joy_loop();


#endif
