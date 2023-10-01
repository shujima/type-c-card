#include "I2C.h"


/*********************************************************************
 * @fn      IS31FL3731_I2C_init
 *
 * @brief   Init I2C communication
 *
 * @return  none
 */
void I2C_init()
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    I2C_InitTypeDef I2C_InitTSturcture={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );
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

/*********************************************************************
 * @fn      IS31FL3731_selectRegPage
 *
 * @brief   Send I2C Data
 *
 * @return  none
 */
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
