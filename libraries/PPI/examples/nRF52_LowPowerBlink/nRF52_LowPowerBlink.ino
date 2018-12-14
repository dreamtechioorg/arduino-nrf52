/*
  nRF52_LowPowerBlink.ino
  
  Written by Chiara Ruggeri (chiara@arduino.org)
  Modified by Frank Wu (frank@dreamtechio.org)
  
  This example for the ELEVEN board shows how to use
  PPI library.
  With this library is possible to bind an action to a particular
  event. In this way, when an event occurs, the related peripheral
  can take the specified action without the MCU intervention.
  For a complete list of all events and actions that is possible to
  use, please refer to the library documentation.
 
  This example code is in the public domain.
 
*/

#include <PPI.h>
#include "nrf52pwr.h"

void setup() {
  //bind a timer event to the toggle of the pin
  //set an interval for the timer (in milliseconds)
  PPI.setTimerInterval(1000);
  //select the output pin
  PPI.setOutputPin(LED_BUILTIN);
  //bind TIMER event to PIN_TOGGLE action
  PPI.setShortcut(TIMER, PIN_TOGGLE);
}


void loop() {
  //put the nRF52 in standby mode to save power
  nrf52pwr.standby();
}
