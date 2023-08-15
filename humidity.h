#ifndef HUMIDITY_H
#define HUMIDITY_H
#include <Arduino.h>

class HumiditySensor {
private:
  int pin;

public:
  HumiditySensor(int pPin);
  int getHumidity();
};

#endif