/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Servo.c
  * @brief      这里是舵机的源文件
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2025-2-1       	 LYF               1. done
  *
  @verbatim
  ==============================================================================
  ==============================================================================
  @endverbatim
  ****************************(C)SWJTU-Ynfeng****************************
  **/
#include "tim.h"
#include "gpio.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "oled.h"
#include "Servo.h"
#include "Delay.h"
float angle_test[2];
uint16_t AD_Buf[2]={0};
/**
  * 函    数：舵机初始化
  * 参    数：无
  * 返 回 值：无
  */
void Servo_Init(void)
{
	//MX_GPIO_Init();
	//MX_TIM2_Init();									//初始化舵机的底层PWM
	__HAL_TIM_CLEAR_IT(&htim1,TIM_IT_UPDATE);
	__HAL_TIM_CLEAR_IT(&htim2,TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
}

/**
  * 函    数：左舵机设置角度
  * 参    数：Angle 要设置的舵机角度，范围：0~180  //0-500   180-2500  all-20000
  * 返 回 值：无
  */
void Servo_SetAngle_L(float Angle)
{
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,Angle/180*2000+500);//设置占空比
												
}
/**
  * 函    数：右舵机设置角度
  * 参    数：Angle 要设置的舵机角度，范围：0~180  //0-500   180-2500  all-20000
  * 返 回 值：无
  */
void Servo_SetAngle_R(float Angle)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,Angle/180*2000+500);//设置占空比
												
}
/**
  * 函    数：左舵机夹取函数
  * 参    数：无
  * 返 回 值：无
  */
void clamp_L(void)
{
	Servo_SetAngle_L(85);
}
/**
  * 函    数：左舵机小角度释放函数
  * 参    数：无
  * 返 回 值：无
  */
void release_L_wei(void)
{
	Servo_SetAngle_L(117);
}
/**
  * 函    数：左舵机释放函数
  * 参    数：无
  * 返 回 值：无
  */
void release_L(void)
{
	Servo_SetAngle_L(165);
}
/**
  * 函    数：右舵机夹取函数
  * 参    数：无
  * 返 回 值：无
  */
void clamp_R(void)
{
	Servo_SetAngle_R(85);
}
/**
  * 函    数：右舵机小角度释放函数
  * 参    数：无
  * 返 回 值：无
  */
void release_R_wei(void)
{
	Servo_SetAngle_R(117);
}
/**
  * 函    数：右舵机释放函数
  * 参    数：无
  * 返 回 值：无
  */
void release_R(void)
{
	Servo_SetAngle_R(165);
}
/**
  * 函    数：舵机测试函数
  * 参    数：无
  * 返 回 值：无
  */
void Servo_Test(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)AD_Buf, 2);
	angle_test[0] = (float)AD_Buf[0] / 4096.0 * 180.0+1;
	angle_test[1] = (float)AD_Buf[1] / 4096.0 * 180.0+1;
	Servo_SetAngle_L(angle_test[0]);
	Servo_SetAngle_R(angle_test[1]);
	OLED_ShowNum(1,9,angle_test[0],3);
	OLED_ShowNum(2,9,angle_test[1],3);
}
