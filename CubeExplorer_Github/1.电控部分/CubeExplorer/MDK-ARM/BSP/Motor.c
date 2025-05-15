/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Motor.c
  * @brief      这里是闭环步进电机的源文件
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2025-2-1       	 LYF               1. done
  *
  @verbatim
  ==============================================================================
  其中包含了简单但高效的防缠绕算法，利用标志位来判断是否多转，顺了三次90就逆一次270
  ==============================================================================
  @endverbatim
  ****************************(C)SWJTU-Ynfeng****************************
  **/
#include "Delay.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "Servo.h"
#include "Motor.h"

#define speed_zhuan 200
#define speed_ning 100
// 向内转为shun，向外转为ni（由右手螺旋定则和左手螺旋定则来看）
/**
  * 函    数：顺时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void L_shun_90()
{
	uint32_t i = 0;
	static uint16_t flag_shun_90; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_L();//左夹爪松开
	// clamp_R();//右夹爪夹紧
	if (flag_shun_90 < 3)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 400; i++)
		{
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_shun_90++;
	}
	else
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // 反转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 1200; i++)
		{
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_shun_90 = 0;
	}
}
/**
  * 函    数：逆时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void L_ni_90()
{
	uint32_t i = 0;
	static uint16_t flag_ni_90; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//使能
	// release_L();//左夹爪松开
	// clamp_R();//右夹爪夹紧
	if (flag_ni_90 < 3)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // 反转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 400; i++)
		{
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_ni_90 ++;
	}
	else
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 1200; i++)
		{
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_ni_90 = 0;
	}
}
/**
  * 函    数：顺时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void R_shun_90()
{
	uint32_t i = 0;
	static uint16_t flag_shun_90; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_R();//右夹爪松开
	// clamp_L();//左夹爪夹紧
	if (flag_shun_90 < 3)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 400; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_shun_90++;
	}
	else
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // 反转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 1200; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_shun_90 = 0;
	}
}
/**
  * 函    数：逆时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void R_ni_90()
{
	uint32_t i = 0;
	static uint16_t flag_ni_90; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//使能
	// release_R();//右夹爪松开
	// clamp_L();//左夹爪夹紧
	if (flag_ni_90 < 3)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // 反转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 400; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_ni_90++;
	}
	else
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 1200; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_ni_90 = 0;
	}
}
/**
  * 函    数：顺时针转180度函数
  * 参    数：无
  * 返 回 值：无
  */
void L_180()
{
	uint32_t i = 0;
	static uint16_t flag_180 = 0; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_L();//左夹爪松开
	// clamp_R();//右夹爪夹紧
	// 1600脉冲转一圈，8细分
	if (flag_180)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		for (i = 0; i < 800; i++)
		{

			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_180 = 0;
	}
	else
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // 反转
		for (i = 0; i < 800; i++)
		{
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_180 = 1;
	}
}
/**
  * 函    数：逆时针转180度函数
  * 参    数：无
  * 返 回 值：无
  */
void R_180()
{
	uint32_t i = 0;
	static uint16_t flag_180 = 0; // 简单的防缠绕算法
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_R();//右夹爪松开
	// clamp_L();//左夹爪夹紧
	if (flag_180)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // 正转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 800; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_180 = 0;
	}
	else
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // 反转
		// 1600脉冲转一圈，8细分
		for (i = 0; i < 800; i++)
		{
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
			Delay_us(speed_zhuan);
			HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
			Delay_us(speed_zhuan);
		}
		flag_180 = 1;
	}
}
/**
  * 函    数：顺时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void L_shun_90_c()
{
	uint32_t i = 0;

	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_L();//左夹爪松开
	// clamp_R();//右夹爪夹紧
	HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // 正转
	// 1600脉冲转一圈，8细分
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * 函    数：逆时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void L_ni_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//使能
	// release_L();//左夹爪松开
	// clamp_R();//右夹爪夹紧
	HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // 反转
	// 1600脉冲转一圈，8细分
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * 函    数：顺时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void R_shun_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//使能
	// release_R();//右夹爪松开
	// clamp_L();//左夹爪夹紧
	HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // 正转
	// 1600脉冲转一圈，8细分
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * 函    数：逆时针转90度函数
  * 参    数：无
  * 返 回 值：无
  */
void R_ni_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//使能
	// release_R();//右夹爪松开
	// clamp_L();//左夹爪夹紧
	HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // 反转
	// 1600脉冲转一圈，8细分
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * 函    数：左机械臂还原函数
  * 参    数：无
  * 返 回 值：无
  */
void L_cube(const char *solve_string)
{
	clamp_L();
	clamp_R();
	Delay_ms(200);
	if (solve_string[1] == '1')
	{
		L_shun_90();
	}
	else if (solve_string[1] == '2')
	{
		L_180();
	}
	else if (solve_string[1] == '3')
	{
		L_ni_90();
	}
}
/**
  * 函    数：右机械臂还原函数
  * 参    数：无
  * 返 回 值：无
  */
void R_cube(const char *solve_string)
{
	clamp_L();
	clamp_R();
	Delay_ms(200);
	if (solve_string[1] == '1')
	{
		R_shun_90();
	}
	else if (solve_string[1] == '2')
	{
		R_180();
	}
	else if (solve_string[1] == '3')
	{
		R_ni_90();
	}
}
/**
  * 函    数：左机械臂回正函数
  * 参    数：solve_string:需要复原的字符串
  * 返 回 值：无
  */
void L_hand_ping(const char *solve_string)
{
	if (solve_string[1] == '1' || solve_string[1] == '3')
	{
		clamp_R();
		release_L();
		Delay_ms(100);
		L_shun_90();
		Delay_ms(100);
	}
}
/**
  * 函    数：右机械臂回正函数
  * 参    数：solve_string:需要复原的字符串
  * 返 回 值：无
  */
void R_hand_ping(const char *solve_string)
{
	if (solve_string[1] == '1' || solve_string[1] == '3')
	{
		clamp_L();
		release_R();
		Delay_ms(100);
		R_shun_90();
		Delay_ms(100);
	}
}
