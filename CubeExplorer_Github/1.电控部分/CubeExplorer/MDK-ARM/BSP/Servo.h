/**
  ****************************(C)SWJTU-Ynfeng****************************
  * @file       Servo.h
  * @brief      这里是舵机的头文件
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
#ifndef __SERVO_H
#define __SERVO_H


void Servo_Init(void);
void Servo_SetAngle_L(float Angle);
void Servo_SetAngle_R(float Angle);
void clamp_L(void);
void release_L(void);
void clamp_R(void);
void release_R(void);
void Servo_Test(void);
void release_L_wei(void);
void release_R_wei(void);
#endif
