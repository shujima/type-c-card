/*
 * IS31FL3731.h
 *
 *  Created on: Sep 24, 2023
 *      Author: shujima
 */

#include "debug.h"

#ifndef SHUJIMA_IS31FL3731_H_
#define SHUJIMA_IS31FL3731_H_

#define ISSI_ADDR_DEFAULT 0x74

#define ISSI_REG_CONFIG 0x00
#define ISSI_REG_CONFIG_PICTUREMODE 0x00
#define ISSI_REG_CONFIG_AUTOPLAYMODE 0x08
#define ISSI_REG_CONFIG_AUDIOPLAYMODE 0x18

#define ISSI_CONF_PICTUREMODE 0x00
#define ISSI_CONF_AUTOFRAMEMODE 0x04
#define ISSI_CONF_AUDIOMODE 0x08

#define ISSI_REG_PICTUREFRAME 0x01

#define ISSI_REG_SHUTDOWN 0x0A
#define ISSI_REG_AUDIOSYNC 0x06

#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_BANK_FUNCTIONREG 0x0B

#endif /* SHUJIMA_IS31FL3731_H_ */



void IS31FL3731_begin();
void I2C_write(u16 address, u8 reg, u8 length, u8 *data );
void IS31FL3731_selectBank(u8 bank);
void IS31FL3731_write1byte(u8 bank, u8 reg, u8 data);
