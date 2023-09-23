#include "IS31FL3731.h"

//#include "debug.h"

//bool IS31FL3731_begin(u8 addr, )

#define I2C_PORT I2C1
#define I2C_ADDR 0b1110100
#define I2C_BOUD 80000

u8 page_now = 9;

u8 matrix_data[2][5][100] = {}; // 表示したいデータ、PWMの強さ [緑/青][縦][横]

u8 matrix_table[5][14] = {
                  {0,1,2,3,4,5,6,7,8,9,10,11,12,13},
        {14,15,16,17,18,19,20,21,22,23,24,25,26,27},
        {28,29,30,31,32,33,34,35,36,37,38,39,40,41},
        {42,43,44,45,46,47,48,49,50,51,52,53,54,55},
        {56,57,58,59,60,61,62,63,64,65,66,67,68,69}
};


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

//    I2C_SendData( I2C1, reg );
//
//    for(int i = 0 ; i < length ; i ++)
//    {
//        //I2C_SendData( I2C1, data[i] );
//        if( I2C_GetFlagStatus( I2C1, I2C_FLAG_TXE ) !=  RESET )
//        {
//            I2C_SendData( I2C1, data[i] );
//        }
//        else {
//            Delay_Us(10);
//        }
//    }

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );
}

void IS31FL3731_selectPage(u8 page)
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

void IS31FL3731_write1byte(u8 page, u8 reg, u8 data)
{
    IS31FL3731_selectPage(page);
    I2C_write(I2C_ADDR, reg,1,&data);
}

// Write to function regulator (setting)
void IS31FL3731_writeFuncReg(u8 reg, u8 data)
{
    if(page_now != 9)
    {
        IS31FL3731_selectPage(9);
    }

    I2C_write(I2C_ADDR, reg, 1, &data);
}


void IS31FL3731_selectFrame(u8 frame)
{
    IS31FL3731_writeFuncReg(ISSI_REG_PICTUREFRAME, frame - 1);
    page_now=frame;
}

void IS31FL3731_clearFrame(u8 frame)
{
    u8 buf[8] = {0,0,0,0,0,0,0,0}; // 0
    //u8 buf[8] = {255,255,255,255,255,255,255,255}; // 0


    if(page_now != frame)
    {
        IS31FL3731_selectPage(frame);
    }
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8,buf);
    }

    u8 i255 = 255;

    //LED Control Register (関係ないので他の関数に分けるべきかも)
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, i, 1,&i255);
    }
    //Blink Control Register (関係ないので他の関数)
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x12 + i, 1,&i255);
    }


    IS31FL3731_selectPage(page_now);
}

//vertical 0-4, hor:0-13
void IS31FL3731_setPixel(u8 vertical,u8 horizontal,u8 green,u8 blue)
{
    matrix_data[0][vertical][horizontal] = green;
    matrix_data[1][vertical][horizontal] = blue;
}

void IS31FL3731_writePixelsToFrame(u8 frame, u8 offset)
{

    //u8 buf2[8] = {255,255,255,255,255,255,255,255};
    u8 buf[144];
    //u8 buf2[144] = {3};
    u8 t;


    for(u8 j = 0 ; j < 5 ; j ++)
    {
        for (u8 k = 0 ; k < 14 ; k ++)
        {
            t = matrix_table[j][k];
            //8byteずつ、緑と青が交互に記録されるので、
            buf[(u8)(t / 8) * 16 + t % 8] = matrix_data[0][j][k+offset]; //green
            buf[(u8)(t / 8) * 16 + t % 8 + 8 ] = matrix_data[1][j][k+offset]; //blue

        }
    }

    if(page_now != frame)
    {
        IS31FL3731_selectPage(frame);
    }
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8,buf);
    }

//    I2C_write(I2C_ADDR, 0x24, 8, buf2);
//    I2C_write(I2C_ADDR, 0x2C, 8, buf2);
//    for(int i = 0 ; i < 18 ; i ++)
//    {
//        I2C_write(I2C_ADDR, 0x24 + i * 8, 8,buf2);
//    }
    IS31FL3731_selectPage(page_now);

}


//進捗メモ。なぜか1つのLEDを操作したつもりがいくつものLEDが付いてしまう。配列がおかしいのかICの操作方法がおかしいのかよくわからない。シリアルなどのデバッグ機能を使えるようにしたりするほうが早道ではないか。
