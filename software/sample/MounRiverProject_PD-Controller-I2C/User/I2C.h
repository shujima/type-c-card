/*
 * IS31FL3731.h
 *
 *  Created on: Sep 24, 2023
 *      Author: shujima
 */

#include "debug.h"

#ifndef SHUJIMA_I2C_H_
#define SHUJIMA_I2C_H_


#define I2C_PORT I2C1
#define I2C_BOUD 80000

#endif /* SHUJIMA_I2C_H_ */


void I2C_init();
void I2C_write(u16 address, u8 reg, u8 buf_max_length, u8 *data );
u8 I2C_read(u16 address, u8 reg, u8 buf_max_length, u8 *data );
