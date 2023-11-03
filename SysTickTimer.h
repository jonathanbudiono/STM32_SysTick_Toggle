#pragma once
#include "main.h"

class SysTickTimer {
public:
  SysTickTimer();
  void start();
  void stop();
  uint32_t getTick();

private:
  static uint32_t tick;
};

extern SysTickTimer systickTimer;

