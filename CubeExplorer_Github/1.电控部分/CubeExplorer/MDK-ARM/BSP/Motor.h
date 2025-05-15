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
  ==============================================================================
  @endverbatim
  ****************************(C)SWJTU-Ynfeng****************************
  **/
#ifndef __MOTOR_H
#define __MOTOR_H

void L_shun_90(void);
void L_ni_90(void);
void R_shun_90(void);
void R_ni_90(void);
void L_180(void);
void R_180(void);
void L_shun_90_c(void);
void L_ni_90_c(void);
void R_shun_90_c(void);
void R_ni_90_c(void);
void L_cube(const char *solve_string);
void R_cube(const char *solve_string);
void L_hand_ping(const char *solve_string);
void R_hand_ping(const char *solve_string);
#endif
