//This is an Arduino pro micro based linear force-sensing handbrake for sim-racing
//you can get the 3D designs, photos and the BOM here: https://www.thingiverse.com/thing:2766811

//Lib HX711 is from
//https://github.com/bogde/HX711
#include "HX711.h"

//Lib Joystick is from
//https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-2.0
//with version 2.0
#include "Joystick.h"

//filter size
#define FILTER_LEN 10

HX711 scale;
// Create Joystick
Joystick_ Joystick;
long offset;
long filter[FILTER_LEN];
int pointer;

void setup() {
  long sum = 0;

  //// Serial for debugging
  //Serial.begin(38400);
  // set the device as Z axis
  Joystick.setZAxisRange(0, 255);
  Joystick.begin();
  pointer = 0;
  //gain: 128/64,DOUT - pin #A1, HX711.PD_SCK	- pin #A0
  scale.begin(A1, A0, 128);
  for(int i=0;i < FILTER_LEN;i++)
  {
    filter[i] = scale.read();
    sum += filter[i];
  }
  offset  = sum/FILTER_LEN;
}

void loop() {
  filter[pointer] = scale.read();
  long sum = 0;
  for(int i = 0; i < FILTER_LEN; i++)
  {
    sum += filter[i];
  }
  long force = sum/FILTER_LEN-offset;
  pointer = (pointer+1)%FILTER_LEN;
  // adjust the deadzone for your device here
  force -= 100000;
  if(force < 0)
  {
    force = 0;
  }
  // adjust the deadzone here as well
  long zaxis = map(force, 0, 1100000, 0, 255);
  //// Serial for debugging
  //Serial.println(zaxis);
  //Serial.println(force);
  Joystick.setZAxis(zaxis);
}
