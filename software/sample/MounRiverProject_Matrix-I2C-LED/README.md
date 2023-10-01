
![](https://github.com/shujima/type-c-card/blob/master/img/Matrix.jpg)

# Note:
<b> This project effected to the Errata on hardware "type-c-card_lexxpluss_2023", please refer to [the modification guide](https://github.com/shujima/type-c-card/blob/master/hardware/sample/type-c-card_lexxpluss_2023)
 </b>

# Overview 
This is the MounRiver sample project it can works 5 x 14 LED Matrix by IS31FL3731-QFLS2 from CH32V203G6U6.

# I2C_LED_IS31FL3731.c
This program has some general functions for use IS31FL3731 from I2C MCU

### init
IS31FL3731_Init();

# TC_LED_Matrix.c
This program has special fuctions for type-c-card, can display on the matrix by each pixel, ASCII character, string.
This depends on I2C_LED_IS31FL3731

### init
Matrix_init();

### Function
* int Matrix_init();
* int Matrix_setBufPixel(u8 vertical,u16 horizontal,u8 green,u8 blue);
* int Matrix_setBufChar(char chr, u8 green, u8 blue, u16 offset);
* int Matrix_setBufPrint(char *str, u8 green, u8 blue, u16 offset);
* int Matrix_writeBufToMatrix(u16 offset);
* int Matrix_clearBuf();

### LED order
This code was optimized for the matrix on "type-c-card", so the LED order was strange.
```
const u8 matrix_table[5][14] = {
        { 0, 8,16,24,32,40,48,56,64, 5, 6, 7,45,54},
        { 1, 9,17,25,33,41,49,57,65,13,14,15,53,62},
        { 2,10,18,26,34,42,50,58,66,21,22,23,61,47},
        { 3,11,19,27,35,43,51,59,67,29,30,31,69,55},
        { 4,12,20,28,36,44,52,60,68,37,38,39,46,63}
};
```
And also this LED display have 2 colors.