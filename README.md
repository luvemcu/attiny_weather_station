# ATtiny Weather Station
Small but accurate device to collect environmental temperature and relative humidity which is sent through RF 433.92mhz. It uses the protocol of Alecto WS-1700 weather stations, since that is recognized by a great domotica solution: [Pilight] (http://www.pilight.org).
Compared to my other weather station running on Arduino Nano (328P) it is a power saving device, consumes only a few milliamps!
Therefore it can run off a single AAA battery for months now. Everything is detailed below to build yourself one, but in case you have questions, i'm glad to answer! The project is yet far from complete, there can be still issues and mistypes so watch out.

## Parts-list:
 - [Atmel ATtiny85 microchip] (http://www.atmel.com/images/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf)
 - [DHT22/AM2302 sensor] (https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
 - [RF 433 transmitter module] (http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR0.TRC0.H0.Xrf+433+arduino.TRS0&_nkw=rf+433+arduino&_sacat=0)
 - [4.7µH inductor] (http://www.ebay.com/sch/i.html?_odkw=4.7uh+-smd&_osacat=0&_from=R40&_trksid=p2045573.m570.l1313.TR0.TRC0.H0.X4.7uh+axial.TRS0&_nkw=4.7uh+axial&_sacat=0)
 - [MCP1640 step-up converter] (http://ww1.microchip.com/downloads/en/DeviceDoc/22234B.pdf)
 - [battery holder (1xAAA)] (http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR0.TRC0.H0.X1+aaa+battery+holder.TRS0&_nkw=1+aaa+battery+holder&_sacat=0)
 - [2 pin SPST switch] (http://www.ebay.com/sch/i.html?_odkw=spst+switch&_osacat=0&_from=R40&_trksid=p2045573.m570.l1313.TR10.TRC2.A0.H0.Xspst+switch+smd.TRS0&_nkw=spst+switch+smd&_sacat=0)
 - few different resistors (see the schematics)
 - two capacitors (see the schematics)
 - a 3mm led
 - some wires

Most of these are easily available anywhere, but i've had a hard time finding MCP1640 and inductor. Try to google these in addition to the `buy` word on your native language to find the nearest shop or webshop. At least i did it and this brought some results.

## Wiring:
Please take the time to study properly the wiring below. Also pay attention for the connection points, some places just cable crossings but not connected! If something still not clear you find a schematic further down.

![ATtiny Weather Station](/wiring.jpg?raw=true "Wiring")

## Schematic:
Hopefully this clarifies the above picture!

![ATtiny Weather Station](/schematics.jpg?raw=true "Schematics")

## Compile
Lately i've switched to [Arduino IDE 1.6.5] (https://www.arduino.cc/en/Main/OldSoftwareReleases#previous) on every of my computer, so i would suggest to use the same version. It is compiling fine on this version, though you need to get and edit some files to support the ATtiny family.
There is an archived library on Google Code named [Arduino-Tiny] (http://code.google.com/archive/p/arduino-tiny/) and you need the latest version for Arduino 1.5.
Installation goes by the instructions in the archive, but there is additional step before it's going to work. Navigate into the freshly created `~/Arduino/hardware/tiny/avr/` and create a folder named `libraries`. From your Arduino installation folder `../Arduino/hardware/arduino/avr/libraries` copy the `EEPROM` directory to the `~/Arduino/hardware/tiny/avr/libraries`.
The path structure have changed in the IDE 1.6+ and maybe there is also needed to edit the compiler path in the Tiny's `platform.txt`.
Something like this: `compiler.path={runtime.ide.path}/hardware/tools/avr/bin/`

In addition the [DHTlib v0.1.13 (by Rob Tillaart)] (http://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) is needed. It is possible to work with newer versions, but this one is tested to work with.

## Troubleshooting
In case you did everything as described, but still experiencing issues then you can try debugging via serial interface.
The code file begins with a commented line `SERTER` which you need to uncomment and upload to the ATtiny. Then you can connect a USB TTL's rx pin on the tiny's PB3 pin. Though this way there is no sending from the terminal, but you can see some texts confirming status of the program.

## Reference
More details on the protocol can be found here:
http://wiki.pilight.org/doku.php/alecto_ws1700_v7_0#protocol
and at the forum thread from the wiki page.
