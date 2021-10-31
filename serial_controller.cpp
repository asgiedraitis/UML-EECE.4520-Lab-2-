#include "serial_controller.h"


/*
 * Code adapted from ansh2919
 * URL: https://create.arduino.cc/projecthub/ansh2919/serial-communication-between-python-and-arduino-e7cce0
 * Modified by Alden Giedraitis
 * 
  */

int line_in = 0;

int buzz = 3; //PWM pin on Arduino nano 

void serial_setup(){

  pinMode(buzz,OUTPUT);
  
  Serial.setTimeout(1);
}

void serial_loop(){

  //If python sends apple alert over, buzz speaker
  if (Serial.available() > 0){
    line_in = Serial.readString().toInt();
  }

    
    apple_detection();

    line_in = 0; //Reset apple detector
    

}

  /*Determine if a value of 1,2,3 or 4 is returned, then send the appropriate
   * key down the line for the python game 
   */

  
void send_direction(int val){

  switch(val){
    case 1:
      Serial.println('w'); //up
    break;

    case 2:
      Serial.println('s'); //down
    break;

    case 3:
      Serial.println('a'); //left
    break;

    case 4:
      Serial.println('d'); //right
    break; 
  }
}


/*If Python sends a 1 through the line, meaning an apple is found, buzz the speaker*/
void apple_detection(){
  
if (line_in == 1){
  //Sound the buzzer
  tone(buzz,1000);
  delay(20);
  noTone(buzz);
  delay(20); 
}
}
  
