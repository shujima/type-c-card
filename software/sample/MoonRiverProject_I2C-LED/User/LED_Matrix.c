
#include "LED_Matrix.h"

#define VIRTUAL_MATRIX_WIDTH 600
#define DISPLAY_WIDTH 14
#define MAX_FONT_WIDTH 10


//Matrix Data for display in LED matrix [color][vertical][horizontal]
//The width is by variable by VIRTUAL_MATRIX_WIDTH, very long data
u8 matrix_buf[2][5][VIRTUAL_MATRIX_WIDTH] = {};

//Matrix LED number
const u8 matrix_table[5][14] = {
        { 0, 8,16,24,32,40,48,56,64, 5, 6, 7,45,54},
        { 1, 9,17,25,33,41,49,57,65,13,14,15,53,62},
        { 2,10,18,26,34,42,50,58,66,21,22,23,61,47},
        { 3,11,19,27,35,43,51,59,67,29,30,31,69,55},
        { 4,12,20,28,36,44,52,60,68,37,38,39,46,63}
};

//Font

//Font start position in font_band, when before first use,
//font_ptr should set by font_init() then font_ptr_set_flag = 1
u16 font_ptr[128];
u8 font_ptr_set_flag = 0;

//Font width data on font_band
const u8 font_width[128]={0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        3,1,3,5,5,5,5,1, // SP
        2,2,4,3,2,3,2,3, //(
        3,3,3,3,3,3,3,3, //0
        3,3,1,2,3,3,3,3, //8
        6,4,4,4,4,4,4,4, //@
        4,3,4,4,4,5,4,4, //H
        4,4,4,4,3,4,4,5, //P
        4,5,4,2,5,2,3,3, //X
        2,4,4,4,4,4,4,4, //`
        4,3,3,4,3,5,4,4, //h
        4,4,3,4,4,4,4,5, //p
        4,4,4,3,1,3,4,0, //x
};

//Font data matrix. All of the pixel font data is arranged in ASCII order.
//Each value depict the vertical line of the font by 5-digit binary data. LSB(1) is top, MSB(16) is bottom.
const u8 font_band[512]={0,0,0,23,2,3,1,10,31,10,31,10,22,21,31,21,13,19,11,4,26,25,8,23,21,10,16,3,14,17,17,14,21,14,14,21,4,14,4,16,8,4,4,4,24,24,24,4,3,31,17,31,17,31,16,29,21,23,21,21,10,7,4,31,23,21,29,31,21,29,7,1,31,31,21,31,23,21,31,10,16,10,4,10,17,10,10,10,17,10,4,1,21,6,2,9,21,29,17,14,30,9,9,30,31,21,21,10,14,17,17,10,31,17,17,14,31,21,21,17,31,5,5,1,14,17,21,13,31,4,4,31,17,31,17,8,16,17,15,31,4,10,17,31,16,16,16,31,3,12,3,31,31,2,12,31,14,17,17,14,31,5,5,2,14,17,9,22,31,5,13,18,18,21,21,9,1,31,1,15,16,16,15,15,16,8,7,15,16,14,16,15,27,4,4,27,1,2,28,2,1,17,25,21,19,31,17,9,10,28,10,9,17,31,2,1,2,16,16,16,1,2,12,18,30,16,31,20,20,8,12,18,18,18,8,20,20,31,12,26,26,20,8,28,10,8,16,20,26,12,31,4,4,24,20,29,16,8,16,13,31,8,20,18,1,31,16,30,2,28,2,28,30,2,2,28,12,18,18,12,30,10,10,4,4,10,10,30,28,2,2,20,22,22,10,4,14,20,20,14,16,16,30,14,16,8,6,14,16,12,16,14,18,12,12,18,18,20,8,6,18,26,22,18,4,27,17,27,17,27,4,2,1,2,1,0,0,0,0,0,0
};


/*********************************************************************
 * @fn      font_init (private use)
 *
 * @brief   This function is called by IS31FL3731_setBufChar when first time of using font data
 *
 * @return  none
 */
void font_init() //private
{
    u16 s = 0;
    for (u8 i = 0; i < 128 ; i ++)
    {
        font_ptr[i]=s;
        s += font_width[i];
    }
}

/*********************************************************************
 * @fn      IS31FL3731_setBufPixel
 *
 * @brief   Set the virtual pixel buffer ( array data ) of PWM value (0-255) of each color (green/blue)
 *          The virtual pixels size is 5 (0-4) x 100 (0 - 99), actual one is 5 x 14 so it can flow by offset
 *
 * @return  0 : ok , -1 abend
 */
int IS31FL3731_setBufPixel(u8 vertical,u8 horizontal,u8 green,u8 blue)
{
    if(vertical < 0 || vertical > 4 || horizontal < 0 || horizontal > 99)return -1;
    matrix_buf[0][vertical][horizontal] = green;
    matrix_buf[1][vertical][horizontal] = blue;
    return 0;
}


/*********************************************************************
 * @fn      IS31FL3731_setBufChar
 *
 * @brief   Set the virtual pixel buffer ( array data ) by internal font char of PWM value (0-255) of each color (green/blue)
 *          The virtual pixels size is 5 (0-4) x 100 (0 - 99), actual one is 5 x 14 so it can flow by offset
 *
 * @return  0<= : ok(end position + 1) , -1 abend
 */
int IS31FL3731_setBufChar(char chr, u8 green, u8 blue, u16 offset)
{
    u8 fl = 0;
    if(chr > 127) return -1;

    if(font_ptr_set_flag == 0)font_init(); //Make the font ptr array when only first time.

    for(u8 h = 0; h < font_width[chr]; h ++)
    {
        for(u8 v = 0; v < 5; v ++)
        {
            fl = font_band[font_ptr[chr] + h] & (1 << v);
            if(h + offset >= VIRTUAL_MATRIX_WIDTH) return -1;
            matrix_buf[0][v][h + offset] = fl ? green : 0;
            matrix_buf[1][v][h + offset] = fl ? blue  : 0;
        }
    }
    return offset + font_width[chr];
}

/*********************************************************************
 * @fn      IS31FL3731_setBufPrint
 *
 * @brief   Set the virtual pixel buffer ( array data ) by internal font string of PWM value (0-255) of each color (green/blue)
 *          The virtual pixels size is 5 (0-4) x 100 (0 - 99), actual one is 5 x 14 so it can flow by offset
 *
 * @return  0<= : ok(end position + 1) , -1 abend
 */
int IS31FL3731_setBufPrint(char *str, u8 green, u8 blue, u16 offset)
{
    u8 r = 0;
    u16 p = offset;
    for(int i = 0 ; str[i] != 0 ; i ++)
    {
        //if(r < 0 || offset > VIRTUAL_MATRIX_WIDTH - MAX_FONT_WIDTH)return -1;
        r = IS31FL3731_setBufChar(str[i], green, blue, p);
        p += font_width[str[i]] + 1;
        if(r < 0)return -1;
    }
    return p;
}

/*********************************************************************
 * @fn      IS31FL3731_writePixelsToFrame
 *
 * @brief   Write from virtual pixel buffer (matrix array) to actual pixel frame
 *
 * @return  0 : ok , -1 abend
 */
int IS31FL3731_writePixelsToFrame(u8 frame, u16 offset)
{
    if(frame < 1 || frame > 8 || offset < 0 || offset > VIRTUAL_MATRIX_WIDTH - DISPLAY_WIDTH)return -1;

    u8 buf[144];
    u8 t;
    for(u8 j = 0 ; j < 5 ; j ++)
    {
        for (u8 k = 0 ; k < 14 ; k ++)
        {
            t = matrix_table[j][k];
            buf[(u8)(t / 8) * 16 + t % 8] = matrix_buf[0][j][k+offset]; //green
            buf[(u8)(t / 8) * 16 + t % 8 + 8 ] = matrix_buf[1][j][k+offset]; //blue

        }
    }
    IS31Fl3731_writeFrame(frame, buf);

    return 0;
}


void clearBuf()
{

}
