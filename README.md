# BSP
Board Support Package 


When making a new project you have to do the following things to make CAN work

1.Make new Project
2.Take CAN and drag it to pins PB8 and PB9
3.Set Quanta parameter to 6
4.Set clock pll to 8 x6
5.click build to generate code
6.Import canFE to your project
7.Declare txheader using the "CAN_TxHeaderTypeDef" object
8.Declare rxheader using the "CAN_RxHeaderTypeDef" object
9.declare a uint8_t array for the data with a size of 8
10.declare a uint32_t for the txmailbox
11.in user code begin 2 type canFE.setID(id, txheader)
12.in user code begin 2 type canFE.setExtID(id,txheader)
13.to set data, use the data[0]="byte 1"
						data[1]="byte 2"
						data[2]="byte 3"
						data[3]="byte 4"
						data[4]="byte 5"
						data[5]="byte 6"
						data[6]="byte 7"
						data[7]="byte 8"
14.to send a CAN Message, in the while loop type HAL_CAN_AddTxMessage(&hcan, &TxHeader, "data", &TxMailBox);
15.right click project
				properties
				c/c++ build
				settings
				Tool settings
				MCU Post Build outputs
				click convert to binary
				apply and close
16.click the arrow next to the hammer
								release
17. head to the project in file explorer
18. go to release
19. drag the project.bin to the board
20. unplug and replug the board after the light goes green
