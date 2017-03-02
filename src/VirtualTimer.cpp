#include "VirtualTimer.h"

VirtualTimer::VirtualTimer()
{
  VirtualTimer(1000);
}

VirtualTimer::VirtualTimer(unsigned long ms)
{
  startTime = 0;
  timeout = 0;
  countdown_ms(ms);
}

bool VirtualTimer::expired()
{
  return (left_ms() <= 0);
}

void VirtualTimer::countdown_ms(unsigned long ms)
{
  unsigned long now = millis();
  startTime = now;
  timeout = ms;
}

void VirtualTimer::countdown(unsigned long seconds)
{
  unsigned long now = millis();
  startTime = now;
  timeout = (seconds * 1000);
}

unsigned long VirtualTimer::left_ms()
{
  //yield();
  unsigned long now = millis();
  if((unsigned long)(now - startTime) >= timeout) return 0;
  unsigned long left = timeout - (unsigned long)(now - startTime);
  return left;
}
