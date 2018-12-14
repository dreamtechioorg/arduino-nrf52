/*
  nRF52_standbyTimer.ino
  
  Written by Chiara Ruggeri (chiara@arduino.org)
  Modified by Frank Wu (frank@dreamtechio.org)
  
  This example for the ELEVEN board shows how to use
  nrf52pwr library to enter in standby mode and save power.
  This mode ensure the fastest response time. If you need
  a deeper power saving mode use powerOFF function instead.
  
  The function nrf52pwr.standby() use an RTC to wake up the
  board after five second and call the function passed as second
  parameter when the count expires. You can choose between two
  different sub power mode. With "constant latency" mode you'll
  get the minimum response time; "nrf52pwr" mode will ensure
  the minimum power consumption.
  
  
  This example code is in the public domain.
  
*/

#include <nrf52pwr.h>

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  Serial.println("Ready to go to bed...");

  //set the RTC to wake up the board after five second and enter in standby mode
  nrf52pwr.standby(5, myFunction); //standby mode - default
  //  nrf52pwr.standby(5, myFunction, CONST_LATENCY);  //constant latency mode

  Serial.println("Good morning to all!");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);	

} 


void myFunction(){
  // pass NULL as second argument of standby function if you
  // don't want to manage the Interrupt Request
}

