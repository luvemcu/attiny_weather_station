# ATtiny Weather Station
Small but accurate device to collect environmental temperature and relative humidity which is sent through RF 433.92mhz. It uses the protocol of Alecto WS-1700 weather stations, since that is recognized by a great domotica solution: [Pilight] (http://www.pilight.org).
Compared to my other weather station running on Arduino Nano (328P) it is a power saving device, consumes only a few milliamps!
Therefore it can run off a single AAA battery for months now. Everything is detailed below to build yourself one, but in case you have questions, i'm glad to answer! The project is yet far from complete, there can be still issues and mistypes so watch out.

## Parts-list:
 - Atmel ATtiny85 microchip
 - DHT22/AM2302 sensor
 - RF 433 transmitter module
 - 4.7µH inductor
 - MCP1640 step-up converter
 - battery holder (1xAAA)
 - 2 pin switch
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
Lately i've switched to [Arduino IDE 1.6.5] (http://arduino.cc) on every of my computer, so i would suggest to use the same version.
Then get the ATtiny support (http://code.google.com/archive/p/arduino-tiny/) for the IDE. This one is tested to compile fine.
Installation goes by the instructions in the archive, but there is additional step before it's going to compile. Navigate into the freshly created `~/Arduino/hardware/tiny/avr/` and create a folder named `libraries`. From your Arduino installation folder `../Arduino/hardware/arduino/avr/libraries` copy the `EEPROM` directory to the `~/Arduino/hardware/tiny/avr/libraries`.
The path structure have changed in the IDE 1.6+ and maybe there is also needed to edit the compiler path in the Tiny's `platform.txt`.
Something like this: `compiler.path={runtime.ide.path}/hardware/tools/avr/bin/`

To compile there is DHTlib v0.1.13 (by Rob Tillaart) needed. It is possible to work with newer versions, but this one is tested to work with.
Get it here: http://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib

Tested to compile fine on Arduino 1.6.5 and work with ATtiny85.

*** There is still room to improve this code i believe, if you have any thoughts regarding then pls let me know.

## Troubleshooting
In case you did everything as described, but still experiencing issues then you can try debugging via serial interface.
The code file begins with a commented line `SERTER` which you need to uncomment and upload to the ATtiny. Then you can connect a USB TTL's rx pin on the tiny's PB3 pin. Though this way there is no sending from the terminal, but you can see some texts confirming status of the program.

## Reference
More details on the protocol can be found here:
http://wiki.pilight.org/doku.php/alecto_ws1700_v7_0#protocol
and at the forum thread from the wiki page.
