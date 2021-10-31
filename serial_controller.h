#ifndef SERIAL_CONTROLLER_H
#define SERIAL_CONTROLLER_H

#include <Arduino.h>

/*Code adapted from ansh2919
 * URL: https://create.arduino.cc/projecthub/ansh2919/serial-communication-between-python-and-arduino-e7cce0
 * Modified by Alden Giedraitis
 * 
  */

extern int line_in; 

extern int buzz; 

void serial_setup();

void serial_loop();

void send_direction(int val);

void apple_detection();


#endif
