/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

RTC_HandleTypeDef hrtc;

void MX_RTC_Init(void){
//	RTC_TimeTypeDef sTime;
//	RTC_DateTypeDef sDate;
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
	if (HAL_RTC_Init(&hrtc) != HAL_OK){
		_Error_Handler(__FILE__, __LINE__);
	}

//	sTime.Hours = 18;
//	sTime.Minutes = 27;
//	sTime.Seconds = 45;
//	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
//	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
//
//	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK){
//		_Error_Handler(__FILE__, __LINE__);
//	}
//
//	sDate.WeekDay = RTC_WEEKDAY_FRIDAY;
//	sDate.Month = RTC_MONTH_DECEMBER;
//	sDate.Date = 13;
//	sDate.Year = 19;
//
//	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK){
//		_Error_Handler(__FILE__, __LINE__);
//	}
}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle){
	if(rtcHandle->Instance==RTC){
		__HAL_RCC_RTC_ENABLE();
	}
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle){
	if(rtcHandle->Instance==RTC){
		__HAL_RCC_RTC_DISABLE();
	}
} 
