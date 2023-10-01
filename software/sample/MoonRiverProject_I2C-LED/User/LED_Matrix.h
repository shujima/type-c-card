/*
 * LED_Matrix.h
 *
 *  Created on: Oct. 1, 2023
 *      Author: shujima
 */

#include "debug.h"
#include "LED_IS31FL3731.h"

#ifndef SHUJIMA_LED_MATRIX_H_
#define SHUJIMA_LED_MATRIX_H_

#endif /* SHUJIMA_LED_MATRIX_H_ */

int IS31FL3731_setBufPixel(u8 vertical,u8 horizontal,u8 green,u8 blue);
int IS31FL3731_setBufChar(char chr, u8 green, u8 blue, u16 offset);
int IS31FL3731_setBufPrint(char *str, u8 green, u8 blue, u16 offset);
int IS31FL3731_writePixelsToFrame(u8 frame, u16 offset);
