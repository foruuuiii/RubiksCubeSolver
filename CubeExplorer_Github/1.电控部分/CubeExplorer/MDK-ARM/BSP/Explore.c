/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Motor.h
  * @brief      这里是闭环步进电机的头文件
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2025-2-1       	 LYF               1. done
  *
  @verbatim
  ==============================================================================
  最重要的六转二算法
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
#include "string.h"

#define speed 300 // 相当于delay单位为ms

// F=右下=红色面  B=左上=橘色面 U=右上=黄色面 D=左下=白色面 	R=后面=绿色面 L=正面=蓝色面
int8_t yellow = 1, green = 2, white = 3, blue = 4, orange = 10, red = 0;

/**
  * 函    数：数学变换函数（用于纠正面的位置）
  * 参    数：x:需要变换的数字
  * 返 回 值：变换后的数字
  */
int8_t math(int8_t x) // 数字变换，用来纠正每一个面的位置。
{
	if (x == 1)
		x = 1;
	else if (x == 2)
		x = 2;
	else if (x == 3)
		x = 3;
	else if (x == 4)
		x = 4;
	else if (x == 0)
		x = 4;
	else if (x == 5)
		x = 1;
	else if (x == 6)
		x = 2;
	return x;
}
/**
  * 函    数：魔方复原函数
  * 参    数：solve_string:需要复原的字符串
  * 返 回 值：无
  */
void change(const char *solve_string) // 复原魔方
{
	if (solve_string[0] == 'U') // 去转黄色
	{
		// example
		if (yellow - 3 == -2) // 黄色在1号位
		{
			clamp_R(); // 右夹爪转，进行旋转魔方
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			yellow = 3; // 颜色处理
			green = green + 2;
			green = math(green);
			blue = blue + 2;
			blue = math(blue);
			white = white + 2;
			white = math(white);

			Delay_ms(speed); // 左夹爪转进行拧动魔方
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (yellow - 3 == -1) // 黄色在2号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			yellow = 3; // 颜色处理
			green = green + 1;
			green = math(green);
			blue = blue + 1;
			blue = math(blue);
			white = white + 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(50);
		}
		else if (yellow - 3 == 0) // 黄色在3号位
		{
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(50);
		}
		else if (yellow - 3 == 1) // 黄色在4号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_ni_90();

			yellow = 3; // 颜色处理
			green = green - 1;
			green = math(green);
			blue = blue - 1;
			blue = math(blue);
			white = white - 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R(); ////////////////
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}

	if (solve_string[0] == 'F') // 右夹爪直接拧													去转红色
	{
		if (red == 0)
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			R_cube(solve_string);
			Delay_ms(speed);
			R_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (red == 10)
		{
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			L_180();

			red = 0; // 颜色处理
			orange = 10;
			if (yellow == 1 || yellow == 3)
			{
				green = green + 2;
				green = math(green);
				blue = blue + 2;
				blue = math(blue);
			}
			if (blue == 1 || blue == 3)
			{
				yellow = yellow + 2;
				yellow = math(yellow);
				white = white + 2;
				white = math(white);
			}

			Delay_ms(speed);
			R_cube(solve_string);
			Delay_ms(speed);
			R_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}

	if (solve_string[0] == 'B') // 去转橘色
	{
		if (orange == 0)
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			R_cube(solve_string);
			Delay_ms(speed);
			R_hand_ping(solve_string);
			//	Delay_ms(80);
		}
		else if (orange == 10)
		{
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			L_180();

			orange = 0; // 颜色处理
			red = 10;
			if (yellow == 1 || yellow == 3)
			{
				green = green + 2;
				green = math(green);
				blue = blue + 2;
				blue = math(blue);
			}
			if (blue == 1 || blue == 3)
			{
				yellow = yellow + 2;
				yellow = math(yellow);
				white = white + 2;
				white = math(white);
			}

			Delay_ms(speed);
			R_cube(solve_string);
			Delay_ms(speed);
			R_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}

	if (solve_string[0] == 'D') // 去转白色
	{
		if (white - 3 == -2) // 白色在1号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			white = 3; // 颜色处理
			yellow = yellow + 2;
			yellow = math(yellow);
			green = green + 2;
			green = math(green);
			blue = blue + 2;
			blue = math(blue);

			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (white - 3 == -1) // 白色在2号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			white = 3; // 颜色处理
			green = green + 1;
			green = math(green);
			yellow = yellow + 1;
			yellow = math(yellow);
			blue = blue + 1;
			blue = math(blue);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (white - 3 == 0) // 白色在3号位
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (white - 3 == 1) // 白色在4号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_ni_90();

			white = 3;
			green = green - 1;
			green = math(green);
			yellow = yellow - 1;
			yellow = math(yellow);
			blue = blue - 1;
			blue = math(blue);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}
	else if (solve_string[0] == 'L') // 去转蓝色
	{
		if (blue - 3 == -2) // 蓝色在1号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			blue = 3;
			yellow = yellow + 2;
			yellow = math(yellow);
			green = green + 2;
			green = math(green);
			white = white + 2;
			white = math(white);

			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (blue - 3 == -1) // 蓝色在2号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			blue = 3;
			green = green + 1;
			green = math(green);
			yellow = yellow + 1;
			yellow = math(yellow);
			white = white + 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			Delay_ms(speed);
			clamp_L();
			// Delay_ms(80);
		}
		else if (blue - 3 == 0) // 蓝色在3号位
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (blue - 3 == 1) // 蓝色在4号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_ni_90();

			blue = 3;
			green = green - 1;
			green = math(green);
			yellow = yellow - 1;
			yellow = math(yellow);
			white = white - 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}

	else if (solve_string[0] == 'R') // 去转绿色
	{
		if (green - 3 == -2) // 绿色在1号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			green = 3;
			yellow = yellow + 2;
			yellow = math(yellow);
			blue = blue + 2;
			blue = math(blue);
			white = white + 2;
			white = math(white);

			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (green - 3 == -1) // 绿色在2号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			green = 3;
			blue = blue + 1;
			blue = math(blue);
			yellow = yellow + 1;
			yellow = math(yellow);
			white = white + 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (green - 3 == 0) // 绿色在3号位
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (green - 3 == 1) // 绿色在4号位
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_ni_90();

			green = 3;
			blue = blue - 1;
			blue = math(blue);
			yellow = yellow - 1;
			yellow = math(yellow);
			white = white - 1;
			white = math(white);

			Delay_ms(speed);
			clamp_L();
			Delay_ms(speed);
			release_R();
			Delay_ms(speed);
			R_shun_90();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
	}
}
/**
  * 函    数：魔方控制函数
  * 参    数：solve_string:需要复原的字符串
  * 返 回 值：无
  */
void magic_cube(char *solve_string) // 等待字符串不为空，自动开始根据收到的字符开始转动魔方。
{
	while (solve_string[0] != '\0')
	{
		change(solve_string);
		strcpy(solve_string, solve_string + 2);
	}
	release_L_wei();
	release_R_wei();
}
/**
  * 函    数：控制拍照函数
  * 参    数：无
  * 返 回 值：无
  */
void control_cube() // 控制旋转
{
	clamp_R();
	Delay_ms(speed);
	release_L();
	Delay_ms(speed);
	R_shun_90_c();
	Delay_ms(speed);
	clamp_L();
	Delay_ms(speed);
	release_R();
	Delay_ms(speed);
	R_ni_90_c();
	Delay_ms(speed);
	L_ni_90_c();
	Delay_ms(speed);
	clamp_R();
	Delay_ms(speed);
	release_L();
	Delay_ms(speed);
	L_shun_90_c();
	Delay_ms(speed);
	clamp_L();
	Delay_ms(speed);
	release_R_wei();
	release_L_wei();
}
