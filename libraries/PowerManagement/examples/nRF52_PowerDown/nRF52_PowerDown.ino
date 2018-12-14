/*
  nRF52_PowerDown.ino
  
  Written by Chiara Ruggeri (chiara@arduino.org)
  Modified by Frank Wu (frank@dreamtechio.org)
  
  This example for the ELEVEN board shows how to use
  nrf52pwr library to enter in power off mode and save power.
  This mode ensure the deepest power saving mode. If you need
  a faster response from the board use standby function instead.
  
  The functions wakeUpBy.. set the signals that will wake up 
  the board. Comment out this functions if you don't want to
  use one of them in order to get the minimum power consumption.
  The board will be reset when it wakes up from power off.
  You can use whoIs() function to find out what signals woke up
  the board if you use more than one wakeUpBy.. function.
  
  This example code is in the public domain.
  
*/

#include <nrf52pwr.h>

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  //look for what peripheral woke up the board
  //reason is 0 at the first execution
  resetReason reason=nrf52pwr.whoIs();
  if(reason==GPIOReset) //GPIO caused the wake up
    doMyStuff();
  else
    if(reason==NFCReset) //NFC caused the wake up
      doMyStuffWithNFC();
  else
    if(reason==CompReset) //Comparator caused the wake up
      doOtherStuff();

  Serial.println("Hi all, I return to sleep");

  //set digital button to wake up the board when LOW level is detected
  nrf52pwr.wakeUpByGPIO(BUTTON_BUILTIN, LOW);
  //let the board be woken up by any NFC field
  nrf52pwr.wakeUpByNFC();
  //wake up the board when the voltage on pin A0 goes below the voltage on pin AREF
  nrf52pwr.wakeUpByComp(A0, AREF, DOWN);
  //go in power OFF mode
  nrf52pwr.powerOFF();
}


void loop() {}

void doMyStuff(){
  //insert your code here
}

void doMyStuffWithNFC(){
  //insert your code here
}

void doOtherStuff(){
  //insert your code here
}