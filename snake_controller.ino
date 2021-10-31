#include "gyro.h"
#include "joystick.h"
#include "serial_controller.h"

/*
 * Alden Giedraitis
 * UML EECE.4520 Lab 2
 * Description: Game controller for snake game in Python. 
 * Using a joystick and gyroscope to control the snake's direction
 * as well as a buzzer to receive game feedback. 
 */

void setup() {

Serial.begin(9600); //Communicate at baud rate of Arduino Nano 

gyro_setup(); //Set up gyro controller  

joy_setup(); //Set up joystick controller

serial_setup(); //Start up serial controller
}

void loop() {

//Get game input

serial_loop();

//Check controller mode

getJoyMode(); 

//Send controller input to game

switch(controlMode){
  case 1:
    send_direction(detectDirection()); //Send off joystick output (up, down, left or right)
  break;

  case 2:
    gyro_loop(); //Calculate gyro values
    send_direction(determineDirection()); //Send off gyro output (up, down, left or right)
  break;
}


  //Serial.print("Control mode is:");

  //Serial.println(controlMode);
  








}
