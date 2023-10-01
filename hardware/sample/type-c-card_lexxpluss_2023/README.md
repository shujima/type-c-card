![](https://github.com/shujima/type-c-card/blob/master/img/card1.jpg)
![](https://github.com/shujima/type-c-card/blob/master/img/card2.jpg)

# Overview
* 今後追記予定の項目
  * i2cのスペック、アドレス


# KiCAD Project
* This can open with KiCAD 7 or later

# Manufacturing Data
* [Gerber File](https://github.com/shujima/type-c-card/blob/master/hardware/sample/type-c-card_lexxpluss_2023/production/type-c-card_lexxpluss_2023_2023-09-23_17-43-02)
* [BOM](https://github.com/shujima/type-c-card/blob/master/hardware/sample/type-c-card_lexxpluss_2023/production/type-c-card_lexxpluss_2023_2023-09-23_17-43-02/bom.csv)

# Specification

## Functions
* USB Flash Drive
* NFC-Tag
* RISC-V MCU
* 5 x 14 Bi-color LED Display
* USB PD Controller

![](https://github.com/shujima/type-c-card/blob/master/img/BlockDiagram-Current.drawio.svg)

#### Remarks
* USB Flash Driveとマイコンはお互いに接続されておらず、唯一USB Switchの動作によってのみ影響します。よってデータのやりとりはできません。
* NFC TagはEnergy Harvestingに対応しており、電源を接続しなくてもタグとして動作します


## Detail Structure

### Power Connection

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

#### I2C Address

|IC Name|Address|Usage|
|-|-|-|
|CH32V203|-|Master|
|IS31FL3731(LED)|1110100*|Write LED|
|ST25DV(NFC)-1|1010011*||
|ST25DV(NFC)-2|1010111*||
|TPS65987(USB PD)|0100010*|USB PD|

#### GPIO Pin Assign

|Pin|Name|Dir|Usage|
|-|-|-|-|
|PA0|ST25_GPO|INPUT|Interrupt Input from ST25DV|
|PA1|Voltage_FB|AnalogIN|PD Voltage FB (Voltage Divided 1:22)|
|PA2|PowerOut|OUTPUT|PD Output port FET Gate(Low:Off, High:On)|
|PA3|LED_INTB|INPUT|Interrupt Input from IS31FL3731|
|PA4|-|-|-|
|PA5|DEBUG-LED-G|OUTPUT|Debug LED (Green)|
|PA6|SW-Left|INPUT|Switch (Left)|
|PA7|SW-Right|INPUT|Switch (Right)|
|PB0|FT231_RESET|OUTPUT|Reset Pin of FT231 (Active Low)|
|PB1|USB_SWITCH_S|OUTPUT|USB Switch Control Pin (Low:FT231-Serial,High:USB2241-emmc)|
|PB3|USB2241_RESET|OUTPUT|Reset Pin of USB2241 (Active Low)|
|PB4|TPS65987_I2C_IRQ|INPUT|I2C Interrupt Input from TPS65987|
|PB5|DEBUG-LED-B|OUTPUT|Debug LED (Blue)|
|PB6|I2C_SCL|OUTPUT|I2C Bus (Clock)|
|PB7|I2C_SDA|I/O|I2C_Bus (Data)|
|PB8|SW-Select|INPUT|Switch (Select), Boot Select(Low:Boot from Flash, High:Boot from USB)|

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

# Hardware Issues
### <b>LEDmatrixに対し電源が供給されていません（配線ミス）。電源線を追加する必要があります</b>
### Do not populateに指定されている部品類もあやまって実装されています。


# 後悔＆将来やりたいこと
* USBからBootできない
  * 発注直前でマイコンの型番変更が必要になり、そこまでケアできなかった
* 高すぎる
  * emmc載せると基板費用、実装費用含めて価格が倍増する
* 新規コンポーネント
  * スピーカ
  * 加速度センサ
  * スーパーキャパシタ