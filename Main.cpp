#include "main.h"
#include "SysTickTimer.h"

SysTickTimer systickTimer;

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  systickTimer.start();

  uint32_t lastTick = 0;

  while (1) {
    uint32_t currentTick = systickTimer.getTick();
    if (currentTick - lastTick >= 1500) { // 1.5 detik
      lastTick = currentTick;
      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    }
  }
}
