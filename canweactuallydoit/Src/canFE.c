/*
 * canFE.c
 *
 *  Created on: Nov 29, 2019
 *      Author: Eric / Brennan
 *
 */
#include "canFE.h"
#include "main.h"
#include "stm32f3xx_hal_can.h"

void CANFE_headerInit(CAN_TxHeaderTypeDef header){
		header.RTR = CAN_RTR_DATA;
		header.IDE = CAN_ID_STD;
		header.DLC = 8;
		header.TransmitGlobalTime = DISABLE;
	}
void CANFE_setID(CAN_TxHeaderTypeDef header, uint16_t id){
		header.StdId = id;
		CANFE_headerInit(header);
	}
void CANFE_setExtID(CAN_TxHeaderTypeDef header, uint32_t id){
		header.ExtId = id;
		CANFE_headerInit(header);
	}
void CANFE_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[8], uint32_t *pTxMailbox){
	HAL_CAN_AddTxMessage(&hcan, &pHeader, aData, &pTxMailbox);
}

//uint8_t CANFE_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]){
//	uint8_t RxData[8];
//	HAL_CAN_GetRxMessage(&hcan, RxFifo, &pHeader, RxData);
//	return RxData;
//}
//void CANFE_setFifoNumber(CAN_RxMsgTypeDef msg)
//{
//	msg.FIFONumber = CAN_RX_FIFO1;
//}
//bytes must be hexadecimal values
void CANFE_setTxData(uint8_t TxData[8], uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4,uint8_t byte5, uint8_t byte6, uint8_t byte7){
	TxData[0]=byte0;
	TxData[1]=byte1;
	TxData[2]=byte2;
	TxData[3]=byte3;
	TxData[4]=byte4;
	TxData[5]=byte5;
	TxData[6]=byte6;
	TxData[7]=byte7;
}
