/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : shujima
 * Version            : V1.0.0
 * Date               : 2023/10/01
 * Description        : Main program body.
 *********************************************************************************
*/

#include "debug.h"
#include <stdlib.h>

/* Global define */

/* Global Variable */

/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIO of Debug LEDs
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

    GPIO_InitStructureA.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructureA.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructureA.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructureA);

    GPIO_InitStructureA.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructureA.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructureA.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructureA);

    GPIO_InitStructureB.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructureB.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructureB.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructureB);
}





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

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("LED Matrix on I2C IS31FL3731 Demo\r\n");
    GPIO_Toggle_INIT();

    Delay_Ms(500);

    //Debug LED
    while(1)
    {
        Delay_Ms(10);
        GPIO_WriteBit(GPIOA, GPIO_Pin_5, GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) );
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7) );
        i++;
    }
}
