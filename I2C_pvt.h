/*
 * I2C_pvt.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Magdy Adel
 */

#ifndef COTS_MCAL_AVR_I2C_I2C_PVT_H_
#define COTS_MCAL_AVR_I2C_I2C_PVT_H_

#define TWDR	*((volatile u8*)(0x23))
#define TWAR	*((volatile u8*)(0x22))
#define TWSR	*((volatile u8*)(0x21))
#define TWBR	*((volatile u8*)(0x20))


#define TWINT  		7
#define TWEA  		6
#define TWSTA		5
#define TWSTO		4
#define TWWC		3
#define TWEN 		2
////RESERVED////	1
#define TWIE		0




#define PS_1   0x00
#define PS_4   0x01
#define PS_16  0x02
#define PS_64  0x03


#endif /* COTS_MCAL_AVR_I2C_I2C_PVT_H_ */
