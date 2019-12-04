/*
 * canFE.h
 *
 *  Created on: Nov 23, 2019
 *      Author: Eric / Brennan
 *      Baud Rate - 500k
 *
 */

#ifndef CANFE_H_
#define CANFE_H_

class canFE {
public:
	canFE();
	virtual ~canFE();

	static void setID(uint_32 id, CAN_TxHeaderTypeDef header){
		header.StdId = id;
		headerInit(header);
	}
	static void setExtID(uint_32 id, CAN_TxHeaderTypeDef header){
		header.ExtId = id;
		headerInit(header);
	}

	static void headerInit(CAN_TxHeaderTypeDef header){
		header.RTR = CAN_RTR_DATA;
		header.IDE = CAN_ID_STD;
		header.DLC = 8;
		header.TransmitGlobalTime = DISABLE;
	}


};

#endif /* CANFE_H_ */
