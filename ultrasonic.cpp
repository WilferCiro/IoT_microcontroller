#include "ultrasonic.h"

UltrasonicSensor::UltrasonicSensor(int pTrigPin, int pEchoPin) {  
  trigPin = pTrigPin;
  echoPin = pEchoPin;
}
int UltrasonicSensor::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  int distanceCm = duration * SOUND_SPEED / 2;
  return distanceCm;
}