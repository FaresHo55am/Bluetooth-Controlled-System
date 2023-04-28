/*
 * SPI_Interface.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Dell
 */

#ifndef INTERFACE_SPI_INTERFACE_H_
#define INTERFACE_SPI_INTERFACE_H_

#include "../STD_types.h"
#include "../Register/SPI_Register.h"

void SPI_Init_Master();
void SPI_Init_Slave();
u8 SPI_Transceiver(u8 data);
void SPI_Transmit(u8 data);
u8 SPI_Recieve();

#endif /* INTERFACE_SPI_INTERFACE_H_ */
