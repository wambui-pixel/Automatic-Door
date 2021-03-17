#include <SR04.h>
#include <Servo.h>

//limz 2020
#include "SR04.h"
#define TRIG_PIN 34
#define ECHO_PIN 40

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
Servo door;
int pos = 0;    // variable to store the servo position
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
   door.attach(26);  // attaches the servo on pin 26 to the servo object
}

void loop() {
  a=sr04.Distance();
  
  if (a <= 50.0)
      { door.write(180); }
  else { door.write(0); }

  Serial.print(a) ;
  Serial.println("cm");

}
