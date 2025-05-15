/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Motor.c
  * @brief      �����Ǳջ����������Դ�ļ�
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2025-2-1       	 LYF               1. done
  *
  @verbatim
  ==============================================================================
  ���а����˼򵥵���Ч�ķ������㷨�����ñ�־λ���ж��Ƿ��ת��˳������90����һ��270
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
// ����תΪshun������תΪni�����������������������������������
/**
  * ��    ����˳ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void L_shun_90()
{
	uint32_t i = 0;
	static uint16_t flag_shun_90; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_L();//���צ�ɿ�
	// clamp_R();//�Ҽ�צ�н�
	if (flag_shun_90 < 3)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
		// 1600����תһȦ��8ϸ��
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
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // ��ת
		// 1600����תһȦ��8ϸ��
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
  * ��    ������ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void L_ni_90()
{
	uint32_t i = 0;
	static uint16_t flag_ni_90; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//ʹ��
	// release_L();//���צ�ɿ�
	// clamp_R();//�Ҽ�צ�н�
	if (flag_ni_90 < 3)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // ��ת
		// 1600����תһȦ��8ϸ��
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
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
		// 1600����תһȦ��8ϸ��
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
  * ��    ����˳ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void R_shun_90()
{
	uint32_t i = 0;
	static uint16_t flag_shun_90; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_R();//�Ҽ�צ�ɿ�
	// clamp_L();//���צ�н�
	if (flag_shun_90 < 3)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
		// 1600����תһȦ��8ϸ��
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
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // ��ת
		// 1600����תһȦ��8ϸ��
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
  * ��    ������ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void R_ni_90()
{
	uint32_t i = 0;
	static uint16_t flag_ni_90; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//ʹ��
	// release_R();//�Ҽ�צ�ɿ�
	// clamp_L();//���צ�н�
	if (flag_ni_90 < 3)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // ��ת
		// 1600����תһȦ��8ϸ��
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
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
		// 1600����תһȦ��8ϸ��
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
  * ��    ����˳ʱ��ת180�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void L_180()
{
	uint32_t i = 0;
	static uint16_t flag_180 = 0; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_L();//���צ�ɿ�
	// clamp_R();//�Ҽ�צ�н�
	// 1600����תһȦ��8ϸ��
	if (flag_180)
	{
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
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
		HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // ��ת
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
  * ��    ������ʱ��ת180�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void R_180()
{
	uint32_t i = 0;
	static uint16_t flag_180 = 0; // �򵥵ķ������㷨
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_R();//�Ҽ�צ�ɿ�
	// clamp_L();//���צ�н�
	if (flag_180)
	{
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
		// 1600����תһȦ��8ϸ��
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
		HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // ��ת
		// 1600����תһȦ��8ϸ��
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
  * ��    ����˳ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void L_shun_90_c()
{
	uint32_t i = 0;

	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_L();//���צ�ɿ�
	// clamp_R();//�Ҽ�צ�н�
	HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
	// 1600����תһȦ��8ϸ��
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * ��    ������ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void L_ni_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//ʹ��
	// release_L();//���צ�ɿ�
	// clamp_R();//�Ҽ�צ�н�
	HAL_GPIO_WritePin(L_motor_dir_GPIO_Port, L_motor_dir_Pin, GPIO_PIN_SET); // ��ת
	// 1600����תһȦ��8ϸ��
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(L_motor_stp_GPIO_Port, L_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * ��    ����˳ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void R_shun_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,L_DIR,1);//ʹ��
	// release_R();//�Ҽ�צ�ɿ�
	// clamp_L();//���צ�н�
	HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_RESET); // ��ת
	// 1600����תһȦ��8ϸ��
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * ��    ������ʱ��ת90�Ⱥ���
  * ��    ������
  * �� �� ֵ����
  */
void R_ni_90_c()
{
	uint32_t i = 0;
	// HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);//ʹ��
	// release_R();//�Ҽ�צ�ɿ�
	// clamp_L();//���צ�н�
	HAL_GPIO_WritePin(R_motor_dir_GPIO_Port, R_motor_dir_Pin, GPIO_PIN_SET); // ��ת
	// 1600����תһȦ��8ϸ��
	for (i = 0; i < 400; i++)
	{
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_SET);
		Delay_us(speed_zhuan);
		HAL_GPIO_WritePin(R_motor_stp_GPIO_Port, R_motor_stp_Pin, GPIO_PIN_RESET);
		Delay_us(speed_zhuan);
	}
}
/**
  * ��    �������е�ۻ�ԭ����
  * ��    ������
  * �� �� ֵ����
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
  * ��    �����һ�е�ۻ�ԭ����
  * ��    ������
  * �� �� ֵ����
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
  * ��    �������е�ۻ�������
  * ��    ����solve_string:��Ҫ��ԭ���ַ���
  * �� �� ֵ����
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
  * ��    �����һ�е�ۻ�������
  * ��    ����solve_string:��Ҫ��ԭ���ַ���
  * �� �� ֵ����
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
