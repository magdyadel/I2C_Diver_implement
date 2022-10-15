/*
 * I2C_int.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Magdy Adel
 */

#ifndef COTS_MCAL_AVR_I2C_I2C_INT_H_
#define COTS_MCAL_AVR_I2C_I2C_INT_H_


void I2C_vInit(void);
u8 I2C_u8SendStartCondition(void);
u8 I2C_u8SendSlaveAddress(u8 A_u8Sla, u8 A_Rw);
u8 I2C_u8SendByte(u8 A_u8Byte);
u8 I2C_u8SendSlaveAddress(u8 A_u8Sla, u8 A_Rw);
u8 I2C_u8SendStopCondition(void);
u8 I2C_u8SendRepeatedStartCondition(void);
u8 I2C_u8GetStatusCode(void);



#endif /* COTS_MCAL_AVR_I2C_I2C_INT_H_ */
