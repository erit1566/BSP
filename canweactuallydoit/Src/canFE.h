/*
 * canFE.h
 *
 *  Created on: Nov 23, 2019
 *      Author: Eric / Brennan
 *      Baud Rate - 500k
 *
 */
#include "stm32f3xx_hal.h"

//void CANFE_setFifoNumber(CAN_RxMsgTypeDef header);
void CANFE_setID(CAN_TxHeaderTypeDef header, uint16_t id);
void CANFE_setExtID(CAN_TxHeaderTypeDef header, uint32_t id);
//uint8_t CANFE_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
void CANFE_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
void CANFE_setTxData(uint8_t TxData[8], uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4,uint8_t byte5, uint8_t byte6, uint8_t byte7);
