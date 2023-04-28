/*
 * SPI_Register.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Dell
 */

#ifndef REGISTER_SPI_REGISTER_H_
#define REGISTER_SPI_REGISTER_H_

#define SPCR_reg 	*((volatile u8*)(0x2D))
#define SPSR_reg 	*((volatile u8*)(0x2E))
#define SPDR_reg 	*((volatile u8*)(0x2F))

#endif /* REGISTER_SPI_REGISTER_H_ */
