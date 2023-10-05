#include "lcd.h"
#include "lcd_init.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

extern SPI_HandleTypeDef hspi1;

void EnterSleep(void)
{
	LCD_WR_REG(0x28);
	LCD_WR_REG(0x10);
	HAL_Delay(120);
}

void ExitSleep(void)
{
	LCD_WR_REG(0x11);
	HAL_Delay(120);
	LCD_WR_REG(0x29);
	HAL_Delay(10);
}

static void ConvHL(uint8_t *s, int32_t l)
{
	uint8_t v;
	while (l > 0) {
		v = *(s+1);
		*(s+1) = *s;
		*s = v;
		s += 2;
		l -= 2;
	}
}

void LCD_DisplayWindows(uint32_t w, uint32_t h, uint8_t *s)
{
	ConvHL(s, w*h*2);
	HAL_SPI_Transmit_DMA(&hspi1, (uint8_t*)s, w * h *2);
}
