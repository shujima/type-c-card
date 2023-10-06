
# `#typeccard`

![](https://github.com/shujima/type-c-card/blob/master/img/card1.jpg)
![](https://github.com/shujima/type-c-card/blob/master/img/card2.jpg)

# Overview

## Hardware info

### USB Type-C Connector Document

* [USB Type-C Connector Library File](https://github.com/shujima/type-c-card/tree/master/hardware/lib_usb-type-c/)

### Hardware Info / Sample Card

ハードウェア関係の情報は以下ページに順次移行しています。

* [LexxPluss_2023](https://github.com/shujima/type-c-card/tree/master/hardware/sample/type-c-card_lexxpluss_2023)
  * This is a first prototype of typeccard to promote the company [LexxPluss](https://lexxpluss.com)

# How To Write Firmware

### Tools
* PC (Windows以外での動作確認はしていません)
* WCH-Link E ( 秋月通販コード M-18065 )

あったほうが良いもの
* ブレッドボードを使用する場合
 * 細ピンヘッダ　１×４０　（黒） ( 秋月通販コード C-06631 )
 * ジャンプワイヤ メス→オス
* ブレッドボードを使用しない場合
 * ジャンプワイヤメス→メス
 * スルーホール用テストワイヤ　ＴＰ－２００　（１０本入）( 秋月通販コード C-09830 )
* 修理に必要なもの
 * スズメッキ線 P-02220

### Connection
![](https://github.com/shujima/type-c-card/blob/master/img/connection.jpg)

* x : None (何もつながない)
* + : 3.3V (シルク印刷の都合上"I"に見えてしまうので注意)
* G : GND
* D : DIO
* C : CLK
（x～Cまでの4ピンが四角で囲まれているが特に意味はないので注意）

### Software Sample

* LED blink sample (Debug LED)
  * [こちらのブログ](https://www.shujima.work/entry/2023/09/17/235534)を参考に[サンプルのプロジェクト](https://github.com/shujima/type-c-card/tree/master/software/sample/MoonRiverProject_L-chika)をビルドし、実行する。
  * LEDが緑→水色→青と点滅すればOK。
* [LED Matrix sample](https://github.com/shujima/type-c-card/tree/master/software/sample/MounRiverProject_Matrix-I2C-LED)
  * On the first hardware, you need to repair the hardware( [type-c-card_lexxpluss_2023](https://github.com/shujima/type-c-card/tree/master/hardware/sample/type-c-card_lexxpluss_2023#ledmatrix%E3%81%AB%E5%AF%BE%E3%81%97%E9%9B%BB%E6%BA%90%E3%81%8C%E4%BE%9B%E7%B5%A6%E3%81%95%E3%82%8C%E3%81%A6%E3%81%84%E3%81%BE%E3%81%9B%E3%82%93%E9%85%8D%E7%B7%9A%E3%83%9F%E3%82%B9%E9%9B%BB%E6%BA%90%E7%B7%9A%E3%82%92%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B%E5%BF%85%E8%A6%81%E3%81%8C%E3%81%82%E3%82%8A%E3%81%BE%E3%81%99) ) before try this.

# License
### Software
* Undefined the detail currently
  * I want to set Apache License, Version 2.0, but I am checking that included code doesn't have GPL etc.

### Hardware
* Undefined the detail currently
  * Published in the spirit based on the "open source".
* Disclaimer
  * Please understand that it's created for hobby purposes. There is no intention to incorporate it into products or for commercial sales.
  * Sufficient verification regarding safety and compatibility has not been conducted.
  * Since it's a hardware product, special consideration is required, especially regarding the potential risk of harming the human body or connected devices.
* Creating a hardware copy
  * On the sample files, "lexxpluss_2023" is included a trademark of LexxPluss Corporation. This was used and published with limited permission. You cannot use it freely without their permission.
  * In particular, when it comes to producing copies within the bounds of common sense, such as for personal hobby use, we have no intention of claiming rights over the board's external shape, component placement, functionality, or any related aspects.
  * Please feel free to add the hashtag #typeccard to your related SNS posts (not obligatory).

# Contact / Feedback
* If you have any positive feedback about this board or software, please feel free to share with hashtag #typeccard or contact to me ( Twitter/X : [@shjma_](https://twitter.com/shjma_) ).
* My day job is a mechanical engineer. Please understand that this was designed and manufactured purely as a horiday hobby and is published only for private use, and please refrain from giving negative feedback.
