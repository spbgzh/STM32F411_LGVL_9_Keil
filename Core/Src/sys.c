#include "sys.h"

void Stm32F411_Clock_Init(uint32_t plln,uint32_t pllm,uint32_t pllp,uint32_t pllq)
{
    HAL_StatusTypeDef ret = HAL_OK;
    RCC_OscInitTypeDef RCC_OscInitStructure; 
    RCC_ClkInitTypeDef RCC_ClkInitStructure;
    
	 __HAL_RCC_PWR_CLK_ENABLE();

	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    
	RCC_OscInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSE; 
	RCC_OscInitStructure.HSEState = RCC_HSE_ON;
	RCC_OscInitStructure.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStructure.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStructure.PLL.PLLM = pllm;
	RCC_OscInitStructure.PLL.PLLN = plln;
	RCC_OscInitStructure.PLL.PLLP = pllp;
	RCC_OscInitStructure.PLL.PLLQ = pllq; 
	ret=HAL_RCC_OscConfig(&RCC_OscInitStructure);
	
    if(ret!=HAL_OK) while(1);
    
	RCC_ClkInitStructure.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStructure.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStructure.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStructure.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStructure.APB2CLKDivider = RCC_HCLK_DIV1;
    ret=HAL_RCC_ClockConfig(&RCC_ClkInitStructure, FLASH_LATENCY_3);
		
    if(ret!=HAL_OK) while(1);

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}
