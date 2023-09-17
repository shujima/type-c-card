# Overview

## Functions
* USB Flash Drive
* NFC-Tag
* RISC-V MCU
* 5 x 14 Bi-color LED Display
* USB PD Controller

![](https://github.com/shujima/type-c-card/blob/master/img/BlockDiagram-Current.drawio.svg)

## Detail Structure



### Signal Connection
* I2C
  * MCU CH32V203G6U6
  * LED Driver IS31FL3731
  * NFC Tag ST25DV04K
  * TPS65987DDHRSHR
* CAN
  * MCU CAN Control
* USB 2.0
  * USB Switch TS3USB221RSER
    * USB-Serial FT231XQ-R
      * MCU Serial Port
  * USB Card Reader USB2241I-AEZG-06
    * eMMC Flash Chip THGBMNG5D1LBAIL
      * USB Flash Drive

### Power 

* USB VBUS (5-20V)
  * DC-DC Converter 4.5V AP63357DV-7
    * USB-Serial
    * LED Display
    * CAN Driver
  * DC-DC Converter 3.3V AP63357DV-7
    * Flash Drive
    * RiSC-V MCU
* Energy Harvesting
  * NFC Tag


# How To Write Firmware

### Tools
* PC (Windows以外での動作確認はしていません)
* WCH-Link E (秋月で750円)

### Connection
![](https://github.com/shujima/type-c-card/blob/master/img/connection.jpg)


* x : None (何もつながない)
* + : 3.3V (シルク印刷の都合上"I"に見えてしまうので注意)
* G : GND
* D : DIO
* C : CLK
（x～Cまでの4ピンが四角で囲まれているが特に意味はないので注意）

### LED blink sample

[こちらのブログ](https://www.shujima.work/entry/2023/09/17/235534)を参考に[サンプルのプロジェクト](https://github.com/shujima/type-c-card/tree/master/sample/MoonRiverProject_L-chika)をビルドし、実行する。

LEDが緑→水色→青と点滅すればOK。

# Erratta
## Jumpers