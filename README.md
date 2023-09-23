
`#typeccard`

![](https://github.com/shujima/type-c-card/blob/master/img/card1.jpg)
![](https://github.com/shujima/type-c-card/blob/master/img/card2.jpg)



# Overview

## Hardware info

### USB Type-C Connector Document

* [USB Type-C Connector Library File](https://github.com/shujima/type-c-card/tree/master/hardware/lib_usb-type-c/)

### Hardware Info / Sample Card

* [LexxPluss_2023]((https://github.com/shujima/type-c-card/tree/master/hardware/sample/type-c-card_lexxpluss_2023)
  * This is a first prototype of typeccard to promote the company [LexxPluss](https://lexxpluss.com)

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

# License
* Undefined the detail currently
  * "Infinitely open source"
* Disclaimer
  * Please understand that it's created for hobby purposes. There is no intention to incorporate it into products or for commercial sales.
  * Sufficient verification regarding safety and compatibility has not been conducted.
  * Since it's a hardware product, special consideration is required, especially regarding the potential risk of harming the human body or connected devices.
* Creating a hardware copy
  * On the sample files, "lexxpluss_2023" is included a trademark of LexxPluss Corporation, and you cannot use it freely without their permission.
  * In particular, when it comes to producing copies within the bounds of common sense, such as for personal hobby use, we have no intention of claiming rights over the board's external shape, component placement, functionality, or any related aspects.
  * Please feel free to add the hashtag #typeccard to your related posts (not obligatory).
