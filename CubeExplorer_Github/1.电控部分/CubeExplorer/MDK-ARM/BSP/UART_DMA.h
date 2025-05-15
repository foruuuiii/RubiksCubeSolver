/**
  ******************************************************************************
  * @file    UART_DMA.c
  * @author  Vofa
  * @version V1.0
  * @date    2023-10-01
  * @brief   串口DMA接收函数
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef UART_DMA_H
#define UART_DMA_H

#include "main.h"
#include "usart.h"

#define buffer_receive_length_1 50
#define buffer_receive_length_2 50
#define buffer_receive_length_3 50
#define buffer_receive_length_4 50
#define buffer_receive_length_5 50
#define buffer_receive_length_6 50

extern uint8_t buffer_receive_1[buffer_receive_length_1];//缓存数组全局定义
extern uint8_t buffer_receive_2[buffer_receive_length_2];//缓存数组全局定义
extern uint8_t buffer_receive_3[buffer_receive_length_3];//缓存数组全局定义
extern uint8_t buffer_receive_4[buffer_receive_length_4];//缓存数组全局定义
extern uint8_t buffer_receive_5[buffer_receive_length_5];//缓存数组全局定义
extern uint8_t buffer_receive_6[buffer_receive_length_6];//缓存数组全局定义
/**
  * @brief          初始化串口DMA接收
  * @param[in]      UART接口
  * @param[in]      缓存数组->推荐使用已定义数组
  * @param[in]      长度  【1-128】
  * @retval         none
  */
extern void UART_DMA_Receive_init(UART_HandleTypeDef *usart, uint8_t *buffer, uint8_t length);
/**
  * @brief          串口DMA接收中断函数->放入《USER CODE BEGIN USARTX_IRQn 1》 中
  * @param[in]      UART接口
  * @param[in]      UART DMA接口
  * @param[in]      缓存数组->推荐使用已定义数组
  * @param[in]      长度  【1-128】
  * @retval         none
  */
extern void UART_DMA_Receive_IT(UART_HandleTypeDef *usart, DMA_HandleTypeDef *DMA, uint8_t *buffer, uint8_t length);
#endif
