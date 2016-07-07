#include "VirtualTimer.h"

VirtualTimer::VirtualTimer()
{
  VirtualTimer(1000);
}

VirtualTimer::VirtualTimer(int ms)
{
  startTime = 0;
  timeout = 0;
  countdown_ms(ms);
}

bool VirtualTimer::expired()
{
  return (left_ms() <= 0);
}

void VirtualTimer::countdown_ms(int ms)
{
  long now = millis();
  startTime = now;
  timeout = ms;
}

void VirtualTimer::countdown(int seconds)
{
  long now = millis();
  startTime = now;
  timeout = (seconds * 1000);
}

long VirtualTimer::left_ms()
{
  yield();
  long now = millis();
  long left = timeout - (now - startTime);
  return (left < 0) ? 0 : left;
}
