#include <ESP32Servo.h>

// FRONT LEFT
Servo FLHIP;
const int FLHpin = 33;
Servo FLKNEE;
const int FLKpin = 32;

// FRONT RIGHT
Servo FRHIP;
const int FRHpin = 26;
Servo FRKNEE;
const int FRKpin = 25;

// BACK LEFT
Servo BLHIP;
const int BLHpin = 13;
Servo BLKNEE;
const int BLKpin = 27;

// BACK RIGHT
Servo BRHIP;
const int BRHpin = 12;
Servo BRKNEE;
const int BRKpin = 14;

void setup() {
  // Attach servos
  FLHIP.attach(FLHpin);
  FLKNEE.attach(FLKpin);

  FRHIP.attach(FRHpin);
  FRKNEE.attach(FRKpin);

  BLHIP.attach(BLHpin);
  BLKNEE.attach(BLKpin);

  BRHIP.attach(BRHpin);
  BRKNEE.attach(BRKpin);

  // Set every servo to 90 degrees
  FLHIP.write(90);
  FLKNEE.write(90);

  FRHIP.write(90);
  FRKNEE.write(90);

  BLHIP.write(90);
  BLKNEE.write(90);

  BRHIP.write(90);
  BRKNEE.write(90);

  delay(1000);


}

void loop() {
  FLKNEE.write(160);
  BRKNEE.write(160);
  delay(100);
  FLHIP.write(45);
  BRHIP.write(120);
  delay(100);
  FLKNEE.write(90);
  BRKNEE.write(90);
  delay(100);
  FLHIP.write(90);
  BRHIP.write(90);
  delay(100);

  FRKNEE.write(20);
  BLKNEE.write(20);
  delay(100);
  FRHIP.write(120);
  BLHIP.write(45);
  delay(100);
  FRKNEE.write(90);
  BLKNEE.write(90);
  delay(100);
  FRHIP.write(90);
  BLHIP.write(90);
  delay(100);


}