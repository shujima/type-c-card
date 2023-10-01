/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : shujima
 * Version            : V1.0.0
 * Date               : 2023/10/01
 * Description        : Main program body.
 *********************************************************************************
*/

#include <I2C_LED_IS31FL3731.h>
#include "debug.h"
#include "I2C.h"
#include <stdlib.h>
#include <TC_LED_Matrix.h>

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

    GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);

    Delay_Ms(500);

    I2C_init();



    Matrix_init();



    //Turn on each LED in order ->->->->->->->->->->->
    //i = vertical pos 0:TOP 4:BOTTOM
    //j = horizontal pos 0:left 13:right
    //GREEN
    for(int j = 0; j < 5 ; j ++)
    {
        for(int k = 0; k < 14 ; k ++)
        {
            Matrix_setBufPixel(j,k,50,0);
            Matrix_writePixelsToFrame(1, 0);

            Delay_Ms(1);

            Matrix_setBufPixel(j,k,0,0);
        }
    }

    //BLUE
    for(int k = 0; k < 14 ; k ++)
    {
        for(int j = 0; j < 5 ; j ++)
        {
            Matrix_setBufPixel(j,k,0,50);
            Matrix_writePixelsToFrame(1, 0);

            Delay_Ms(1);
        }
    }

    Matrix_clearBuf();

    //Draw Logo by pixel
    //Logo +
    Matrix_setBufPixel(3,5,50,0);
    Matrix_setBufPixel(2,6,50,0);
    Matrix_setBufPixel(3,6,50,0);
    Matrix_setBufPixel(4,6,50,0);
    Matrix_setBufPixel(3,7,50,0);
    //Logo P
    Matrix_setBufPixel(1,6,40,50);
    Matrix_setBufPixel(1,7,40,50);
    Matrix_setBufPixel(1,8,40,50);
    Matrix_setBufPixel(2,9,40,50);
    Matrix_setBufPixel(3,8,40,50);


    //Draw String
    u16 p;
    p = Matrix_setBufPrint("I2C LED Display DEMO", 100, 0, 14);
    p = Matrix_setBufPrint("   CH32V203 RISC-V MCU", 0, 100, p);
    p = Matrix_setBufPrint(" + IS31FL3731 CharliePlex Matrix ", 50, 50, p);

    Matrix_writePixelsToFrame(1, 0); //Drawing
    Delay_Ms(500);

    for(u16 offset = 0 ; offset < p ; offset ++)
    {
        Matrix_writePixelsToFrame(1, offset);
        Delay_Ms(10);
    }


    while(1)
    {
        Delay_Ms(1000);
        GPIO_WriteBit(GPIOA, GPIO_Pin_5, (i % 4 == 1 || i % 4 == 2) ? Bit_SET : Bit_RESET);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, (i % 4 == 2 || i % 4 == 3) ? Bit_RESET : Bit_SET);
        i++;
    }
}