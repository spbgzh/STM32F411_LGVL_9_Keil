#ifndef __LCD_H
#define __LCD_H		
#include <stdint.h>
void EnterSleep(void);
void ExitSleep(void);
void LCD_DisplayWindows(uint32_t w, uint32_t h, uint8_t *s);

#endif





