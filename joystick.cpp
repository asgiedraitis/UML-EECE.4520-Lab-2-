#include "joystick.h"


/*
 * Code adapted from Minuka Thesath Yapa
 * URL: https://create.arduino.cc/projecthub/MinukaThesathYapa/arduino-thumb-joystick-to-processing-92c182
 * Modified by Alden Giedraitis
 * 
  */
int xValue = 0;
int yValue = 0; 

int currJoy = 0;

int prevJoy = 0; 

int controlMode = 1; //Assume controller starts in joystick mode by default

void joy_setup()  
{ 
  //Serial.begin(9600) ;
  pinMode(9,INPUT); 
  digitalWrite(9,HIGH); //joystick push button pin 
} 

int detectDirection(){
  xValue = analogRead(A0);  
  yValue = analogRead(A1);

  if(xValue > 1000 && yValue >=300 && yValue <=513){
    //Serial.println("Up");
    return 1;
  }

  else if(xValue < 100 && yValue >=300 && yValue <=513){
    //Serial.println("Down");
    return 2;
  }

  else if(xValue>=380 && xValue <=800 && yValue <= 100){
    //Serial.println("Left");
    return 3;
  }

  else if(xValue>=380 && xValue <=800 && yValue>=800){
    //Serial.println("Right");
    return 4;
  }

  else return 0; //Any other value, return a value of 0 
}

  void getJoyMode(){

    currJoy = digitalRead(9); //Get current push button state

    //Serial.print("Current button output is ");

    //Serial.println(currJoy);

    //See if state has changed or not (falling edge detection for the button)
    
    if (currJoy ==  0 && prevJoy == 1){

      if (controlMode == 2){

        controlMode = 1; //Control mode set to joystick mode

        //Serial.println("Joystick Mode");
        
      }

    else {
  
      controlMode = 2; //Control mode set to gyro mode

      //Serial.println("Gyro Mode");
     }
      
    }

    delay(50);

    prevJoy = currJoy;
    
  }
 

  
  




void joy_loop() 
{ 

  /*
  xValue = analogRead(A0);  
  yValue = analogRead(A1);
  */

  //detectDirection();
  

  
  /*
  Serial.print(xValue,DEC);
  Serial.print(",");
  Serial.print(yValue,DEC);
  Serial.print(",");
  Serial.print(!bValue);
  Serial.print("\n");
  */
  
  //delay(10);  
}
