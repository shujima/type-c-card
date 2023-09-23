
![](https://github.com/shujima/type-c-card/blob/master/img/USBType-C.png)

# How to use
* This library is for KiCAD

## PCB Specification / Manufacture

* The PCB thickness should design with 0.6 - 0.8mm
* This library complies with JLCPCB's manufacturing rules as of August 2023.

## Connection

### Minimum connection for as of power source of your PCB
* VBUS (5V)
  * Normally, voltage is not supplied to VBUS until a device connection is detected via the pull-down of the CC pins.
  * In cases where a USB A to C cable is used or when power is supplied from a traditional connector, 5V is provided without checking the CC pins.
* GND
* CC x2
  * Both CC pins should be pulled down with a 5.1k ohm resistor each (2 resistors required).
  * The available current can vary significantly depending on the connected device. While USB PD supports a maximum of 5A, simply pulling down the CC pins will limit it to a maximum of 3A. Additionally, when connected to a bus-powered USB 2.0 device, you can only draw a maximum of 500mA or even lower.
  * With the exception of cases where you are using an appropriate USB PD Controller IC, it is recommended not to omit the pull-down resistors on the CC pins in any situation.


# Disclaimer
* This is not compliant with USB standards.
* There is a risk of damaging cables, connected devices, and potentially causing serious disasters such as overheating or fire due to short circuits.
* We do not guarantee any damages resulting from the use or redistribution of this product.