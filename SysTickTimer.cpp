#include "SysTickTimer.h"

uint32_t SysTickTimer::tick = 0;

SysTickTimer::SysTickTimer() {
}

void SysTickTimer::start() {
  SysTick_Config(SystemCoreClock / 1000); // 1ms per interrupt
}

void SysTickTimer::stop() {
  SysTick->CTRL = 0;
}

uint32_t SysTickTimer::getTick() {
  return tick;
}

extern "C" void SysTick_Handler() {
  SysTickTimer::tick++;
  HAL_IncTick();
}
