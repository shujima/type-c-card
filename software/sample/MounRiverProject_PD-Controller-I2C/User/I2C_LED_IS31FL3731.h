/*
 * IS31FL3731.h
 *
 *  Created on: Sep 24, 2023
 *      Author: shujima
 */

#include "debug.h"
#include "I2C.h"

#ifndef SHUJIMA_IS31FL3731_H_
#define SHUJIMA_IS31FL3731_H_

#define I2C_ADDR 0b1110100

#endif /* SHUJIMA_IS31FL3731_H_ */


void font_init();
void IS31FL3731_selectRegPage(u8 page);
void IS31FL3731_writeFuncReg(u8 reg, u8 data);
void IS31FL3731_changeDisplayFrame(u8 frame);
void IS31FL3731_clearFrame(u8 frame);
void IS31Fl3731_writeFrame(u8 frame, u8 * buf);
