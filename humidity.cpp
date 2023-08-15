#include "humidity.h"

HumiditySensor::HumiditySensor(int pPin) {
  pin = pPin;
}

int HumiditySensor::getHumidity() {
  return map(analogRead(pin), 0, 1023, 100, 0);
}