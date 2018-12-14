/*
  nRF52_standbyGPIO.ino
  
  Written by Chiara Ruggeri (chiara@arduino.org)
  Modified by Frank Wu (frank@dreamtechio.org)
  
  This example for the ELEVEN board shows how to use
  nrf52pwr library to enter in standby mode and save power.
  This mode ensure the fastest response time. If you need
  a deeper power saving mode use powerOFF function instead.
  
  By calling nrf52pwr.standby() function, the board will enter
  in standby mode waiting for any interrupt. Every kind of
  interrupt will wake up the board and you can use more than
  an interrupt source at the same time.
  If you want to exit from standby mode you have to call 
  nrf52pwr.wakeUpNow() function inside the interrupt callback.
  
  This example code is in the public domain.
  
*/

#include <nrf52pwr.h>

void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_BUILTIN, INPUT);
  //attach an interrupt on button to wake up the board when a low level is detected
  attachInterrupt(BUTTON_BUILTIN, myFunction, LOW); 

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

  //enter in standby mode
  nrf52pwr.standby();
	
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
  // for interrupt external to nrf52pwr library you need
  // to call wakeUpNow function in order to exit from
  // standby mode
  nrf52pwr.wakeUpNow();
}
