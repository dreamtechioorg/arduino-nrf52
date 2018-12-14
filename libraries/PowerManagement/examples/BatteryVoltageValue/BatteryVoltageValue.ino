/*
  BatteryVoltageValue.ino
  Written by Jeff Wu (jeff@arduino.org)
  Modified : Frank Wu (frank@dreamtechio.org)
  This example for the ELEVEN board shows how to use bat library.

  This example allows you to get Battery Voltage Value of ELEVEN
  board.
  disabling STM32 enter to standby mode to avoid ELEVEN board enter to
  standby mode when ELEVEN board is powered only by battery.
  ELEVEN board is able to send voltage value over serial port or BLE serial, 
  Create UART service compatible with Nordic's *nRF Toolbox* and Adafruit's 
  *Bluefruit LE* iOS/Android apps. You can also use another board with 
  serial_client example in File->Examples->BLE->Central menu to set up
  a BLE serial connection between two different boards.

  This example code is in the public domain.
*/

#include <BLEPeripheral.h>
#include <BLESerial.h>
#include <Wire.h>
#include <bat.h>
#include <stm32pwr.h>


// create ble serial instance
BLESerial bleSerial = BLESerial();

bat eleven_bat;
double bat_voltage;

void setup() {
  // custom services and characteristics can be added as well
  bleSerial.setLocalName("ELEVEN");
  // start serial port at 115200 bps:
  Serial.begin(115200);
  // start BLE serial
  bleSerial.begin();  
  // disable STM32 enter to standby mode
  stm32pwr.disableStandbyMode();
  // initialize the LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(300);
  // turn LED on
  digitalWrite(LED_BUILTIN, HIGH);
  // get battery voltage value
  bat_voltage = eleven_bat.analogRead();
  // print battery voltage vaule on serial port
  Serial.print("Battery Voltage:" );
  Serial.println(bat_voltage,3);
  // print battery voltage vaule on BLE serial
  bleSerial.print("Battery Voltage:" );
  bleSerial.println(bat_voltage,3);
  delay(300);
  // turn LED off
  digitalWrite(LED_BUILTIN, LOW);
}