#ifndef VIRTUAL_TIMER_H
#define VIRTUAL_TIMER_H

#include <Arduino.h>

class VirtualTimer
{
private:
  unsigned long startTime, timeout;
public:
  VirtualTimer();
  VirtualTimer(unsigned long ms);
  bool expired();
  void countdown_ms(unsigned long ms);
  void countdown(unsigned long seconds);
  unsigned long left_ms();
};

#endif //VIRTUAL_TIMER_H
