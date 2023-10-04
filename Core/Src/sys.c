#include "sys.h"

void Stm32_Clock_Init(uint32_t plln,uint32_t pllm,uint32_t pllp,uint32_t pllq)
{
    HAL_StatusTypeDef ret = HAL_OK;
    RCC_OscInitTypeDef RCC_OscInitStructure; 
    RCC_ClkInitTypeDef RCC_ClkInitStructure;
    
	 __HAL_RCC_PWR_CLK_ENABLE(); //Ê¹ÄÜPWRÊ±ÖÓ
	
	//ÏÂÃæÕâ¸öÉèÖÃÓÃÀ´ÉèÖÃµ÷Ñ¹Æ÷Êä³öµçÑ¹¼¶±ð£¬ÒÔ±ãÔÚÆ÷¼þÎ´ÒÔ×î´óÆµÂÊ¹¤×÷
    //Ê±Ê¹ÐÔÄÜÓë¹¦ºÄÊµÏÖÆ½ºâ£¬´Ë¹¦ÄÜÖ»ÓÐSTM32F42xxºÍSTM32F43xxÆ÷¼þÓÐ£¬
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);//ÉèÖÃµ÷Ñ¹Æ÷Êä³öµçÑ¹¼¶±ð1
    
	RCC_OscInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSE; //Ê±ÖÓÔ´ÎªHSE
	RCC_OscInitStructure.HSEState = RCC_HSE_ON;//´ò¿ªHSE
	RCC_OscInitStructure.PLL.PLLState = RCC_PLL_ON;//´ò¿ªPLL
	RCC_OscInitStructure.PLL.PLLSource = RCC_PLLSOURCE_HSE;//PLLÊ±ÖÓÔ´Ñ¡ÔñHSE
	RCC_OscInitStructure.PLL.PLLM = pllm;//Ö÷PLLºÍÒôÆµPLL·ÖÆµÏµÊý(PLLÖ®Ç°µÄ·ÖÆµ),È¡Öµ·¶Î§:2~63.
	RCC_OscInitStructure.PLL.PLLN = plln;//Ö÷PLL±¶ÆµÏµÊý(PLL±¶Æµ),È¡Öµ·¶Î§:50~432. 
	RCC_OscInitStructure.PLL.PLLP = pllp; //ÏµÍ³Ê±ÖÓµÄÖ÷PLL·ÖÆµÏµÊý(PLLÖ®ºóµÄ·ÖÆµ),È¡Öµ·¶Î§:2,4,6,8.(½öÏÞÕâ4¸öÖµ!)
	RCC_OscInitStructure.PLL.PLLQ = pllq; //USB/SDIOµÄÖ÷PLL·ÖÆµÏµÊý(PLLÖ®ºóµÄ·ÖÆµ),È¡Öµ·¶Î§:2~15.
	ret=HAL_RCC_OscConfig(&RCC_OscInitStructure);//³õÊ¼»¯
	
    if(ret!=HAL_OK) while(1);
    
	RCC_ClkInitStructure.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStructure.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;//ÉèÖÃÏµÍ³Ê±ÖÓÊ±ÖÓÔ´ÎªPLL
	RCC_ClkInitStructure.AHBCLKDivider = RCC_SYSCLK_DIV1;//AHB·ÖÆµÏµÊýÎª1
	RCC_ClkInitStructure.APB1CLKDivider = RCC_HCLK_DIV2;//APB1·ÖÆµÏµÊýÎª2
	RCC_ClkInitStructure.APB2CLKDivider = RCC_HCLK_DIV1;//APB2·ÖÆµÏµÊýÎª2
    ret=HAL_RCC_ClockConfig(&RCC_ClkInitStructure, FLASH_LATENCY_3);//Í¬Ê±ÉèÖÃFLASHÑÓÊ±ÖÜÆÚÎª3WS£¬Ò²¾ÍÊÇ4¸öCPUÖÜÆÚ¡£
		
    if(ret!=HAL_OK) while(1);
	
	//³õÊ¼»¯HAL SystickÊ±ÖÓ
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
	
}