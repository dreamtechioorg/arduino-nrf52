/*
  STM32_SleepMode.ino
  
  Written by Jeff Wu (jeff@arduino.org)
  Modified : Frank Wu (frank@dreamtechio.org)
  
  This example for the ELEVEN board shows how to use
  stm32pwr library.
  The STM32 has two functions for power savings. One is sleep mode, 
  and the other is standby mode. The BUTTON allows you setup 
  as an interrupt to trigger STM32 enter to sleep mode or wake up 
  from sleep mode. When the ELEVEN board is powered by USB cable and 
  battery, and then disconnect the USB cable, the STM32 will enter 
  to standby mode or the ELEVEN board is only powered by battery. 
  Waiting for ELEVEN board reconnect to USB cable to wake up from 
  standby mode. The disableStandbyMode() function allows you to 
  disable STM32 enter to standby mode when the ELEVEN disconnect 
  the USB cable.

  This example code is in the public domain.
  
*/

#include <stm32pwr.h>

void setup() {
  // start serial port at 9600 bps
  Serial.begin(9600);
  // setup BUTTON as an interrupt to trigger STM32 
  // enter to sleep mode or wake up from sleep mode
  stm32pwr.enableSleepMode();
  // disable STM32 enter to standby mode
  stm32pwr.disableStandbyMode() ;
}

void loop() {
  //Waiting for BUTTON press trigger STM32 enter to sleep mode
  Serial.println("Waiting for BUTTON press");
  delay(5000);
}