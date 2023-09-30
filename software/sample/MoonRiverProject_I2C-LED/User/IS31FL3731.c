#include "IS31FL3731.h"

//#include "debug.h"

// Author : shujima


#define VIRTUAL_MATRIX_WIDTH 600
#define DISPLAY_WIDTH 14
#define MAX_FONT_WIDTH 10


u8 page_now = 9;

u8 matrix_buf[2][5][VIRTUAL_MATRIX_WIDTH] = {}; // ±Ì æ§∑§ø§§•«©`•ø°¢PWM§Œèä§µ [æv/«‡][øk][∫·]

const u8 matrix_table[5][14] = {
        { 0, 8,16,24,32,40,48,56,64, 5, 6, 7,45,54},
        { 1, 9,17,25,33,41,49,57,65,13,14,15,53,62},
        { 2,10,18,26,34,42,50,58,66,21,22,23,61,47},
        { 3,11,19,27,35,43,51,59,67,29,30,31,69,55},
        { 4,12,20,28,36,44,52,60,68,37,38,39,46,63}
};

u16 font_ptr[128];
u8 font_ptr_set_flag = 0;
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
const u8 font_band[512]={0,0,0,23,2,3,1,10,31,10,31,10,22,21,31,21,13,19,11,4,26,25,8,23,21,10,16,3,14,17,17,14,21,14,14,21,4,14,4,16,8,4,4,4,24,24,24,4,3,31,17,31,17,31,16,29,21,23,21,21,10,7,4,31,23,21,29,31,21,29,7,1,31,31,21,31,23,21,31,10,16,10,4,10,17,10,10,10,17,10,4,1,21,6,2,9,21,29,17,14,30,9,9,30,31,21,21,10,14,17,17,10,31,17,17,14,31,21,21,17,31,5,5,1,14,17,21,13,31,4,4,31,17,31,17,8,16,17,15,31,4,10,17,31,16,16,16,31,3,12,3,31,31,2,12,31,14,17,17,14,31,5,5,2,14,17,9,22,31,5,13,18,18,21,21,9,1,31,1,15,16,16,15,15,16,8,7,15,16,14,16,15,27,4,4,27,1,2,28,2,1,17,25,21,19,31,17,9,10,28,10,9,17,31,2,1,2,16,16,16,1,2,12,18,30,16,31,20,20,8,12,18,18,18,8,20,20,31,12,26,26,20,8,28,10,8,16,20,26,12,31,4,4,24,20,29,16,8,16,13,31,8,20,18,1,31,16,30,2,28,2,28,30,2,2,28,12,18,18,12,30,10,10,4,4,10,10,30,28,2,2,20,22,22,10,4,14,20,20,14,16,16,30,14,16,8,6,14,16,12,16,14,18,12,12,18,18,20,8,6,18,26,22,18,4,27,17,27,17,27,4,2,1,2,1,0,0,0,0,0,0
};


void font_init()
{
    u16 s = 0;
    for (u8 i = 0; i < 128 ; i ++)
    {
        font_ptr[i]=s;
        s += font_width[i];
    }
}


void IS31FL3731_begin()
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    I2C_InitTypeDef I2C_InitTSturcture={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );
    //GPIO_PinRemapConfig(GPIO_Remap_I2C1, ENABLE);
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C1, ENABLE );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOB, &GPIO_InitStructure );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOB, &GPIO_InitStructure );

    I2C_InitTSturcture.I2C_ClockSpeed = I2C_BOUD;
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_16_9;
    I2C_InitTSturcture.I2C_OwnAddress1 = 0x02;
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init( I2C1, &I2C_InitTSturcture );

    I2C_Cmd( I2C1, ENABLE );
    I2C_AcknowledgeConfig( I2C1, ENABLE );
}

void I2C_write(u16 address, u8 reg, u8 length, u8 *data )
{
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, address<<1, I2C_Direction_Transmitter );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    int b = 0;
    while(1)
    {
        if(b == 0)
        {
            I2C_SendData( I2C1, reg );
            b++;
        }
        else if(b > 0)
        {
            if( I2C_GetFlagStatus( I2C1, I2C_FLAG_TXE ) !=  RESET )
            {
                I2C_SendData( I2C1, data[b - 1] );
                b++;
            }
            else {
                Delay_Us(10);
            }
        }
        if(b > length) break;
    }


    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );
}


/*********************************************************************
 * @fn      IS31FL3731_selectRegPage
 *
 * @brief   Select "Page" of IS31FL3731, we have to set the page by this func before set any related register
 *
 * @return  none
 */
void IS31FL3731_selectRegPage(u8 page)
{
    u8 d = 0x0B;
    if(page >= 1 && page <= 8)
    {
        d = page - 1;
    }
    else if(page == 9)
    {
        d = 0x0B;
    }

    I2C_write(I2C_ADDR, 0xFD,1,&d);
    page_now = page;

}

/*********************************************************************
 * @fn      IS31FL3731_writeFuncReg
 *
 * @brief   Write to Function Registers
 *
 * @return  none
 */
void IS31FL3731_writeFuncReg(u8 reg, u8 data)
{
    if(page_now != 9)
    {
        IS31FL3731_selectRegPage(9);
    }

    I2C_write(I2C_ADDR, reg, 1, &data);
}


/*********************************************************************
 * @fn      IS31FL3731_changeDisplayFrame(u8 frame)
 *
 * @brief   Change "Frame" to display (from frame1 to frame8);
 *
 * @return  none
 */
void IS31FL3731_changeDisplayFrame(u8 frame)
{
    if(frame <= 0 || frame >= 9)return;
    IS31FL3731_writeFuncReg(ISSI_REG_PICTUREFRAME, frame - 1);
    page_now=frame;
}

/*********************************************************************
 * @fn      IS31FL3731_clearFrame(u8 frame)
 *
 * @brief   Clear "Frame", set 0 pwm of all of pixels
 *
 * @return  none
 */
void IS31FL3731_clearFrame(u8 frame)
{
    u8 buf[8] = {255,255,255,255,255,255,255,255}; // 0

    //PWM Register
    if(page_now != frame)
    {
        IS31FL3731_selectRegPage(frame);
    }
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8,buf);
    }

    u8 i255 = 255;

    //LED Control Register
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, i, 1,&i255);
    }

    //Blink Control Register
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x12 + i, 1,&i255);
    }

    IS31FL3731_selectRegPage(page_now);
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
 * @return  0 : ok , -1 abend
 */
int IS31FL3731_setBufChar(char chr, u8 green, u8 blue, u16 offset)
{
    u8 fl = 0;
    if(offset > 240 || chr > 127) return -1;

    if(font_ptr_set_flag == 0)font_init(); //Make the font ptr array when only first time.

    for(u8 h = 0; h < font_width[chr]; h ++)
    {
        for(u8 v = 0; v < 5; v ++)
        {
            fl = font_band[font_ptr[chr] + h] & (1 << v);
            matrix_buf[0][v][h + offset] = fl ? green : 0;
            matrix_buf[1][v][h + offset] = fl ? blue  : 0;

            //IS31FL3731_writePixelsToFrame(1,0); //temporary debug
        }
    }
    return 0;
}

/*********************************************************************
 * @fn      IS31FL3731_setBufPrint
 *
 * @brief   Set the virtual pixel buffer ( array data ) by internal font string of PWM value (0-255) of each color (green/blue)
 *          The virtual pixels size is 5 (0-4) x 100 (0 - 99), actual one is 5 x 14 so it can flow by offset
 *
 * @return  0 : ok , -1 abend
 */
int IS31FL3731_setBufPrint(char *str, u8 green, u8 blue, u16 offset)
{
    u8 r = 0;
    u16 p = offset;
    for(int i = 0 ; str[i] != 0 ; i ++)
    {
        if(r != 0 || offset > VIRTUAL_MATRIX_WIDTH - MAX_FONT_WIDTH)return -1;
        r = IS31FL3731_setBufChar(str[i], green, blue, p);
        p += font_width[str[i]] + 1;
    }
    return 0;
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
    if(page_now != frame)
    {
        IS31FL3731_selectRegPage(frame);
    }
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8,buf + i * 8);
    }

    IS31FL3731_selectRegPage(page_now);
    return 0;
}

