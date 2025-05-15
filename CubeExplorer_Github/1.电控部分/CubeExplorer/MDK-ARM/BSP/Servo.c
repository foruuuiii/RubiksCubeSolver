/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Servo.c
  * @brief      �����Ƕ����Դ�ļ�
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
  * ��    ���������ʼ��
  * ��    ������
  * �� �� ֵ����
  */
void Servo_Init(void)
{
	//MX_GPIO_Init();
	//MX_TIM2_Init();									//��ʼ������ĵײ�PWM
	__HAL_TIM_CLEAR_IT(&htim1,TIM_IT_UPDATE);
	__HAL_TIM_CLEAR_IT(&htim2,TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
}

/**
  * ��    �����������ýǶ�
  * ��    ����Angle Ҫ���õĶ���Ƕȣ���Χ��0~180  //0-500   180-2500  all-20000
  * �� �� ֵ����
  */
void Servo_SetAngle_L(float Angle)
{
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,Angle/180*2000+500);//����ռ�ձ�
												
}
/**
  * ��    �����Ҷ�����ýǶ�
  * ��    ����Angle Ҫ���õĶ���Ƕȣ���Χ��0~180  //0-500   180-2500  all-20000
  * �� �� ֵ����
  */
void Servo_SetAngle_R(float Angle)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,Angle/180*2000+500);//����ռ�ձ�
												
}
/**
  * ��    ����������ȡ����
  * ��    ������
  * �� �� ֵ����
  */
void clamp_L(void)
{
	Servo_SetAngle_L(85);
}
/**
  * ��    ��������С�Ƕ��ͷź���
  * ��    ������
  * �� �� ֵ����
  */
void release_L_wei(void)
{
	Servo_SetAngle_L(117);
}
/**
  * ��    ���������ͷź���
  * ��    ������
  * �� �� ֵ����
  */
void release_L(void)
{
	Servo_SetAngle_L(165);
}
/**
  * ��    �����Ҷ����ȡ����
  * ��    ������
  * �� �� ֵ����
  */
void clamp_R(void)
{
	Servo_SetAngle_R(85);
}
/**
  * ��    �����Ҷ��С�Ƕ��ͷź���
  * ��    ������
  * �� �� ֵ����
  */
void release_R_wei(void)
{
	Servo_SetAngle_R(117);
}
/**
  * ��    �����Ҷ���ͷź���
  * ��    ������
  * �� �� ֵ����
  */
void release_R(void)
{
	Servo_SetAngle_R(165);
}
/**
  * ��    ����������Ժ���
  * ��    ������
  * �� �� ֵ����
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
