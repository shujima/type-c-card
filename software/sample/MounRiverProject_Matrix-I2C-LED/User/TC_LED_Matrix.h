/*
 * LED_Matrix.h
 *
 *  Created on: Oct. 1, 2023
 *      Author: shujima
 */

#include <I2C_LED_IS31FL3731.h>
#include "debug.h"

#ifndef SHUJIMA_LED_MATRIX_H_
#define SHUJIMA_LED_MATRIX_H_

#endif /* SHUJIMA_LED_MATRIX_H_ */

int Matrix_init();
int Matrix_setBufPixel(u8 vertical,u8 horizontal,u8 green,u8 blue);
int Matrix_setBufChar(char chr, u8 green, u8 blue, u16 offset);
int Matrix_setBufPrint(char *str, u8 green, u8 blue, u16 offset);
int Matrix_writePixelsToFrame(u8 frame, u16 offset);
int Matrix_clearBuf();
