/*
 * I2C_prg.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Magdy Adel
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"

#include "I2C_int.h"
#include "I2C_pvt.h"
#include "I2C_cfg.h"

void I2C_vInit(void)
{
	/* 1- Bit rate (TWBR) */
	TWBR = 10;
	TWSR |= (0<<0) | (0<<1); // TWPS prescaler bits
	/* 2- Own slave Address */
	TWAR = I2C_OWN_SLA ;

}

u8 I2C_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); // Send START condition
	while ( !( TWCR & (1<<TWINT) ) ); /*Wait for TWINT Flag set. This indicates
										that the START condition has been
										transmitted */
	return (TWSR & 0xF8);
}

u8 I2C_u8SendSlaveAddress(u8 A_u8Sla, u8 A_Rw)
{
	TWDR = (A_u8Sla<<1) | A_Rw;
	CLR_BIT(TWCR,TWSTA);
	TWCR = (1<<TWINT) | (1<<TWEN);  //	Load SLA_W into TWDR Register. Clear
									//	TWINT bit in TWCR to start transmission
									//	of address
	while (!(TWCR & (1<<TWINT)));   //	Wait for TWINT Flag set. This indicates
									//	that the SLA+W has been transmitted,
									//	and ACK/NACK has been received.

	return (TWSR & 0xF8);

}

u8 I2C_u8SendByte(u8 A_u8Byte)
{
	TWDR = DATA;
	TWCR = (1<<TWINT) | (1<<TWEN);	//	Load DATA into TWDR Register. Clear
									//	TWINT bit in TWCR to start transmission
									//	of data
	while (!(TWCR & (1<<TWINT)));	//	Wait for TWINT Flag set. This indicates
									//	that the DATA has been transmitted, and
									//	ACK/NACK has been received.
	return (TWSR & 0xF8);
}

u8 I2C_u8SendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);	//	Transmit STOP condition
	return (TWSR & 0xF8);
}

u8 I2C_u8SendRepeatedStartCondition(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); // Send START condition
	while ( !( TWCR & (1<<TWINT) ) ); /*Wait for TWINT Flag set. This indicates
										that the START condition has been
										transmitted */
	return (TWSR & 0xF8);
}
u8 I2C_u8GetStatusCode(void)
{
	return (TWSR & 0xF8);
}
