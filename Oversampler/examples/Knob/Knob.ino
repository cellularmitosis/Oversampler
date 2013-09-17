// Oversampler - A simple library which makes it easier to oversample Arduino
// ADC inputs.  See https://github.com/cellularmitosis/Oversampler
// v0.1 (Sept 16, 2013)
//
// This is a version of the Arduino "Knob" example which has been modified to
// use the Oversampler library.  It demonstrates the use of analogRead16x(),
// and analogRead2x through analogRead64x are also available.
//
// Copyright (c) 2013 Jason Pepas
//
// This sample code is released to the public domain.  The Oversampler library
// is released under the terms of the MIT License.
//
// Original head comment follows:
// ----
//
// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "Oversampler.h"
 
Servo myservo;  // create servo object to control a servo 

OversamplerData *oversampler = NULL;
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  oversampler = createOversamplerData();
} 
 
void loop() 
{
  // here, the original code was:
  //   val = analogRead(potpin);
  // we replace this with the 16x oversampled version below:
  val = analogRead16x(oversampler, potpin);

                                       // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
}

