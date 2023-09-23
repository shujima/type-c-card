#include "IS31FL3731.h"

//#include "debug.h"

//bool IS31FL3731_begin(u8 addr, )

#define I2C_PORT I2C1
#define I2C_ADDR 0b1110100
#define I2C_BOUD 80000

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

void IS31FL3731_selectBank(u8 bank)
{
    I2C_write(I2C_ADDR, 0xFD,1,&bank);
}

void IS31FL3731_write1byte(u8 bank, u8 reg, u8 data)
{
    IS31FL3731_selectBank(bank);
    I2C_write(I2C_ADDR, reg,1,&data);
}
