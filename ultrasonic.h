#define SOUND_SPEED 0.034

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class UltrasonicSensor {
private:
  int trigPin;
  int echoPin;

public:
  UltrasonicSensor(int pTrigPin, int pEchoPin);
  int getDistance();
};
#endif