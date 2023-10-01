/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : shujima
 * Version            : V1.0.0
 * Date               : 2023/10/01
 * Description        : Main program body.
 *********************************************************************************
*/

#include <LED_IS31FL3731.h>
#include "LED_Matrix.h"
#include "debug.h"
#include "I2C.h"
#include <stdlib.h>

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

    GPIO_InitStructureA.GPIO_Pin = GPIO_Pin_4;
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
//    u8 j = 0;
//    u8 TxData[6] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("GPIO Toggle TEST\r\n");
    GPIO_Toggle_INIT();

    GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);

    Delay_Ms(1000);


    printf("IIC Host mode\r\n");
    I2C_init();

    IS31FL3731_Init();

    IS31FL3731_changeDisplayFrame(1);
    IS31FL3731_clearFrame(1);

    //Turn on each LED in order ->->->->->->->->->->->
    //i = vertical pos 0:TOP 4:BOTTOM
    //j = horizontal pos 0:left 13:right
    //GREEN
    for(int j = 0; j < 5 ; j ++)
    {
        for(int k = 0; k < 14 ; k ++)
        {
            IS31FL3731_setBufPixel(j,k,50,0);
            IS31FL3731_writePixelsToFrame(1, 0);

            Delay_Ms(1);

            IS31FL3731_setBufPixel(j,k,0,0);
        }
    }

    //BLUE
    for(int k = 0; k < 14 ; k ++)
    {
        for(int j = 0; j < 5 ; j ++)
        {
            IS31FL3731_setBufPixel(j,k,0,50);
            IS31FL3731_writePixelsToFrame(1, 0);

            Delay_Ms(1);

            //IS31FL3731_setBufPixel(j,k,0,0);
        }
    }



    //Draw Logo by pixel
    //Logo +
    IS31FL3731_setBufPixel(3,5,50,0);
    IS31FL3731_setBufPixel(2,6,50,0);
    IS31FL3731_setBufPixel(3,6,50,0);
    IS31FL3731_setBufPixel(4,6,50,0);
    IS31FL3731_setBufPixel(3,7,50,0);
    //Logo P
    IS31FL3731_setBufPixel(1,6,40,50);
    IS31FL3731_setBufPixel(1,7,40,50);
    IS31FL3731_setBufPixel(1,8,40,50);
    IS31FL3731_setBufPixel(2,9,40,50);
    IS31FL3731_setBufPixel(3,8,40,50);


    //Draw String
    u16 p;
    p = IS31FL3731_setBufPrint("I2C LED Display DEMO", 100, 0, 14);
    p = IS31FL3731_setBufPrint("   CH32V203 RISC-V MCU", 0, 100, p);
    p = IS31FL3731_setBufPrint(" + IS31FL3731 CharliePlex Matrix ", 50, 50, p);

    IS31FL3731_writePixelsToFrame(1, 0); //Drawing
    Delay_Ms(500);

    for(u16 offset = 0 ; offset < p ; offset ++)
    {
        IS31FL3731_writePixelsToFrame(1, offset);
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
