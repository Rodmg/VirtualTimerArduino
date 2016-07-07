#ifndef VIRTUAL_TIMER_H
#define VIRTUAL_TIMER_H

#include <Arduino.h>

class VirtualTimer
{
private:
  long startTime, timeout;
public:
  VirtualTimer();
  VirtualTimer(int ms);
  bool expired();
  void countdown_ms(int ms);
  void countdown(int seconds);
  long left_ms();
};

#endif //VIRTUAL_TIMER_H
