/**
  ******************************************************************************
  * @file    UART_DMA.c
  * @author  Vofa
  * @version V1.0
  * @date    2023-10-01
  * @brief   ����DMA���պ���
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

extern uint8_t buffer_receive_1[buffer_receive_length_1];//��������ȫ�ֶ���
extern uint8_t buffer_receive_2[buffer_receive_length_2];//��������ȫ�ֶ���
extern uint8_t buffer_receive_3[buffer_receive_length_3];//��������ȫ�ֶ���
extern uint8_t buffer_receive_4[buffer_receive_length_4];//��������ȫ�ֶ���
extern uint8_t buffer_receive_5[buffer_receive_length_5];//��������ȫ�ֶ���
extern uint8_t buffer_receive_6[buffer_receive_length_6];//��������ȫ�ֶ���
/**
  * @brief          ��ʼ������DMA����
  * @param[in]      UART�ӿ�
  * @param[in]      ��������->�Ƽ�ʹ���Ѷ�������
  * @param[in]      ����  ��1-128��
  * @retval         none
  */
extern void UART_DMA_Receive_init(UART_HandleTypeDef *usart, uint8_t *buffer, uint8_t length);
/**
  * @brief          ����DMA�����жϺ���->���롶USER CODE BEGIN USARTX_IRQn 1�� ��
  * @param[in]      UART�ӿ�
  * @param[in]      UART DMA�ӿ�
  * @param[in]      ��������->�Ƽ�ʹ���Ѷ�������
  * @param[in]      ����  ��1-128��
  * @retval         none
  */
extern void UART_DMA_Receive_IT(UART_HandleTypeDef *usart, DMA_HandleTypeDef *DMA, uint8_t *buffer, uint8_t length);
#endif
