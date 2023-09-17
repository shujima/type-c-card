# Overview
![](https://github.com/shujima/member_card/blob/master/MemberCard2023/BlockDiagram-Current.drawio.svg)



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
