#include <Arduino.h>
#include "InverseKinimatics.h"
#include <ESP32Servo.h>
#include "config.h"

  //creating object
InverseKinimatics leg;

void setup() {
leg.setupServoPins(hipServoPin, kneeServoPin);

}

double xPot;
double yPot;
double ManualLength;
double xMove = 0;
double yMove = -5;

void loop() {
 leg.walk();
/*

xPot = pot1; //Change!!
yPot = pot2;

map(xPot, 0, 4095, -10, 10);
map(yPot, 0, 4095, 0, -10);

just updated
ManualLength = sqrt( (pow(xx,2)) * (pow(yy,2)) );

if(L<=100){
  xMove = 
leg.moveto
}

*/

}