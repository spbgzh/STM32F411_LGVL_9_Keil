#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#define USE_HORIZONTAL 4

#define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2, GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2, GPIO_PIN_SET)
 		     
#define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_SET)


void LCD_GPIO_Init(void);
void LCD_Writ_Bus(unsigned char *data, unsigned int size);
void LCD_WR_DATA8(unsigned char dat);
void LCD_WR_DATA(unsigned int dat);
void LCD_WR_REG(unsigned char dat);
void LCD_Address_Set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void LCD_Init(void);
#endif
