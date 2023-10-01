// Author : shujima in 2023
#include <I2C_LED_IS31FL3731.h>

// Page setting of IS31FL3731/
// This value is changed the range between 1-9 (1-8:each frame, 9:config)
u8 page_now = 0;

/*********************************************************************
 * @fn      IS31FL3731_selectRegPage (private use)
 *
 * @brief   Select "Page" of IS31FL3731 command register, we have to set the page by this func before set any related register
 *
 * @return  none
 */
void IS31FL3731_selectRegPage(u8 page) //private
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
    IS31FL3731_writeFuncReg(0x01, frame - 1); // Picture Frame setting
}

/*********************************************************************
 * @fn      IS31FL3731_clearFrame(u8 frame)
 *
 * @brief   Clear "Frame", set 0 pwm of all of pixels
 *          This function should call before use each frames.
 *
 * @return  none
 */
void IS31FL3731_clearFrame(u8 frame)
{
    u8 buf[8] = {0,0,0,0,0,0,0,0}; // 0
    u8 i255 = 255;
    u8 i0 = 0;

    IS31FL3731_selectRegPage(frame);

    //PWM Register
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8, buf);
    }

    //LED Control Register
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, i, 1,&i255);
    }

    //Blink Control Register
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x12 + i, 1,&i0);
    }

    if(page_now != 0) IS31FL3731_selectRegPage(page_now);
}


/*********************************************************************
 * @fn      IS31FL3731_writeFrame(u8 frame,u8 * buf)
 *
 * @brief   Write (set) frame by buffer
 *
 * @return  none
 */
void IS31Fl3731_writeFrame(u8 frame, u8 * buf)
{
    if(page_now != frame)
    {
        IS31FL3731_selectRegPage(frame);
    }
    for(int i = 0 ; i < 18 ; i ++)
    {
        I2C_write(I2C_ADDR, 0x24 + i * 8, 8, buf + i * 8);
    }
    if(page_now != frame)
    {
        IS31FL3731_selectRegPage(page_now);
    }
}
