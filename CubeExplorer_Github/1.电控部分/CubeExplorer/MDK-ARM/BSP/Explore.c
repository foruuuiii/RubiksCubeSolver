/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Motor.h
  * @brief      �����Ǳջ����������ͷ�ļ�
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2025-2-1       	 LYF               1. done
  *
  @verbatim
  ==============================================================================
  ����Ҫ����ת���㷨
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

#define speed 300 // �൱��delay��λΪms

// F=����=��ɫ��  B=����=��ɫ�� U=����=��ɫ�� D=����=��ɫ�� 	R=����=��ɫ�� L=����=��ɫ��
int8_t yellow = 1, green = 2, white = 3, blue = 4, orange = 10, red = 0;

/**
  * ��    ������ѧ�任���������ھ������λ�ã�
  * ��    ����x:��Ҫ�任������
  * �� �� ֵ���任�������
  */
int8_t math(int8_t x) // ���ֱ任����������ÿһ�����λ�á�
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
  * ��    ����ħ����ԭ����
  * ��    ����solve_string:��Ҫ��ԭ���ַ���
  * �� �� ֵ����
  */
void change(const char *solve_string) // ��ԭħ��
{
	if (solve_string[0] == 'U') // ȥת��ɫ
	{
		// example
		if (yellow - 3 == -2) // ��ɫ��1��λ
		{
			clamp_R(); // �Ҽ�צת��������תħ��
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			yellow = 3; // ��ɫ����
			green = green + 2;
			green = math(green);
			blue = blue + 2;
			blue = math(blue);
			white = white + 2;
			white = math(white);

			Delay_ms(speed); // ���צת����š��ħ��
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (yellow - 3 == -1) // ��ɫ��2��λ
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			yellow = 3; // ��ɫ����
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
		else if (yellow - 3 == 0) // ��ɫ��3��λ
		{
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(50);
		}
		else if (yellow - 3 == 1) // ��ɫ��4��λ
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_ni_90();

			yellow = 3; // ��ɫ����
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

	if (solve_string[0] == 'F') // �Ҽ�צֱ��š													ȥת��ɫ
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

			red = 0; // ��ɫ����
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

	if (solve_string[0] == 'B') // ȥת��ɫ
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

			orange = 0; // ��ɫ����
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

	if (solve_string[0] == 'D') // ȥת��ɫ
	{
		if (white - 3 == -2) // ��ɫ��1��λ
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_180();

			white = 3; // ��ɫ����
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
		else if (white - 3 == -1) // ��ɫ��2��λ
		{
			clamp_R();
			Delay_ms(speed);
			release_L();
			Delay_ms(speed);
			R_shun_90();

			white = 3; // ��ɫ����
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
		else if (white - 3 == 0) // ��ɫ��3��λ
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (white - 3 == 1) // ��ɫ��4��λ
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
	else if (solve_string[0] == 'L') // ȥת��ɫ
	{
		if (blue - 3 == -2) // ��ɫ��1��λ
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
		else if (blue - 3 == -1) // ��ɫ��2��λ
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
		else if (blue - 3 == 0) // ��ɫ��3��λ
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (blue - 3 == 1) // ��ɫ��4��λ
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

	else if (solve_string[0] == 'R') // ȥת��ɫ
	{
		if (green - 3 == -2) // ��ɫ��1��λ
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
		else if (green - 3 == -1) // ��ɫ��2��λ
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
		else if (green - 3 == 0) // ��ɫ��3��λ
		{
			clamp_R();
			clamp_L();
			Delay_ms(speed);
			L_cube(solve_string);
			Delay_ms(speed);
			L_hand_ping(solve_string);
			// Delay_ms(80);
		}
		else if (green - 3 == 1) // ��ɫ��4��λ
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
  * ��    ����ħ�����ƺ���
  * ��    ����solve_string:��Ҫ��ԭ���ַ���
  * �� �� ֵ����
  */
void magic_cube(char *solve_string) // �ȴ��ַ�����Ϊ�գ��Զ���ʼ�����յ����ַ���ʼת��ħ����
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
  * ��    �����������պ���
  * ��    ������
  * �� �� ֵ����
  */
void control_cube() // ������ת
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
