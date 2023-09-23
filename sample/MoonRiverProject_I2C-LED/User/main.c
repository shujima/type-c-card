/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *GPIO routine:
 *PA0 push-pull output.
 *
 */

#include "debug.h"
#include "IS31FL3731.h"

/* Global define */

/* I2C Mode Definition */
#define HOST_MODE   0
#define SLAVE_MODE   1

//#define I2C_ADDR 0b1110100

/* I2C Communication Mode Selection */
#define I2C_MODE   HOST_MODE
//#define I2C_MODE   SLAVE_MODE


/* Global Variable */

/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOA.0
 *
 * @return  none
 */
void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructureA = {0};
    GPIO_InitTypeDef GPIO_InitStructureB = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructureA.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructureA.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructureA.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructureA);

    GPIO_InitStructureB.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructureB.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructureB.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructureB);


}

//void IIC_Init(u32 bound, u16 address)
//{
//    GPIO_InitTypeDef GPIO_InitStructure={0};
//    I2C_InitTypeDef I2C_InitTSturcture={0};
//
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );
//    //GPIO_PinRemapConfig(GPIO_Remap_I2C1, ENABLE);
//    RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C1, ENABLE );
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init( GPIOB, &GPIO_InitStructure );
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init( GPIOB, &GPIO_InitStructure );
//
//    I2C_InitTSturcture.I2C_ClockSpeed = bound;
//    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
//    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_16_9;
//    I2C_InitTSturcture.I2C_OwnAddress1 = address;
//    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
//    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
//    I2C_Init( I2C1, &I2C_InitTSturcture );
//
//    I2C_Cmd( I2C1, ENABLE );
//
//#if (I2C_MODE == HOST_MODE)
//    I2C_AcknowledgeConfig( I2C1, ENABLE );
//
//#endif
//}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    u8 i = 0;
    u8 j = 0;
    u8 TxData[6] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("GPIO Toggle TEST\r\n");
    GPIO_Toggle_INIT();

    printf("IIC Host mode\r\n");
    //IS31FL3731_begin( 80000, I2C_ADDR << 1);
    IS31FL3731_begin();

    //I2C_write(I2C_ADDR << 1, 0, 4, TxData );

    IS31FL3731_write1byte(0x0B, 0x0A, 0x00);///
    IS31FL3731_write1byte(0x0B, 0x0A, 0x01);

    //for( j =0; j < 5; j++)
//    {
//        while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
//
//
//
//        I2C_GenerateSTART( I2C1, ENABLE );
//        while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
//        I2C_Send7bitAddress( I2C1, 0b11101000, I2C_Direction_Transmitter );
//
//        while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );
//
//        for( i=0; i< 6;i++ )
//        {
//            if( I2C_GetFlagStatus( I2C1, I2C_FLAG_TXE ) !=  RESET )
//            {
//                //Delay_Ms(100);
//                I2C_SendData( I2C1, TxData[i] );
//            }
//        }
//
//        while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
//        I2C_GenerateSTOP( I2C1, ENABLE );
//        Delay_Ms(1000);
//    }
//
//
//
    while(1)
    {
        Delay_Ms(1000);
        GPIO_WriteBit(GPIOA, GPIO_Pin_5, (i % 4 == 1 || i % 4 == 2) ? Bit_SET : Bit_RESET);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, (i % 4 == 2 || i % 4 == 3) ? Bit_RESET : Bit_SET);
        i++;
    }
}
