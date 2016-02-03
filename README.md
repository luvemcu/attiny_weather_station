# ATtiny Weather Station
Small but accurate device to collect environmental temperature and relative humidity which is sent through RF 433/315mhz. It uses the protocol of [Alecto WS-1700](http://www.alecto.nl/weerstation-1700) weather stations, since that is recognized by a great domotica solution: [Pilight] (http://www.pilight.org).
Compared to my other weather station running on Arduino Nano (328P) it is a power saving device, consumes only a few milliamps!
Therefore it can run off a single 9v battery for almost a month. Everything is detailed below to build yourself one, but in case you have questions, i'm glad to answer! The project is yet not complete, there can be still issues and mistypes so watch out.

## Parts-list:
<<<<<<< HEAD
 - [Atmel ATtiny85 microchip](http://www.atmel.com/images/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf)
 - [DHT22/AM2302 sensor](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
 - [RF 433 transmitter module (3.3v)](http://www.dx.com/nl/p/mini-3-3v-rf-transmitter-receiver-module-433mhz-wireless-link-kit-for-arduino-3-3v-mcu-414004#.VrDg8Hko-Uk)
 - [LT1763-3.3v micropower reg.](http://cds.linear.com/docs/en/datasheet/1763fh.pdf)
 - [battery holder or adapter (9v)](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR0.TRC0.H0.X9v+battery+arduino.TRS0&_nkw=9v+battery+arduino&_sacat=0)
 - [Tactile SPST switch](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR10.TRC2.A0.H0.Xspst+switch+smd.TRS0&_nkw=spst+switch+smd&_sacat=0) (momentary pushbutton)
 - [few different resistors](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR12.TRC2.A0.H0.Xresistor+pack.TRS0&_nkw=resistor+pack&_sacat=0) (see the [Schematic](#schematic))
 - [two capacitors](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR12.TRC2.A0.H0.Xcapacitor+pack.TRS0&_nkw=capacitor+pack&_sacat=0) (see the [Schematic](#schematic))
 - [a 3mm led](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR12.TRC2.A0.H0.Xled+3mm.TRS0&_nkw=led+3mm&_sacat=0)
 - [some wires](http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR12.TRC2.A0.H0.Xjumper+wire+arduino.TRS0&_nkw=jumper+wire+arduino&_sacat=0)

Most of these are easily available anywhere online, but some of the links above are pointing directly to products.
=======
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
>>>>>>> origin/master

## Wiring:
Please take the time to study properly the wiring below. Also pay attention for the connection points, some places just cable crossings but not connected! If something still not clear you find a [schematic](#schematic) further down.

![ATtiny Weather Station](/wiring.jpg?raw=true "Wiring")

*The length of the antenna is very important for a decent range on the radio. 1/4 wave antenna lengths are 433MHz - 17.28 cm, 315MHz - 23.81 cm.

## Schematic:
Hopefully this clarifies the above picture!

![ATtiny Weather Station](/schematics.jpg?raw=true "Schematics")

## Configuration
There are some options available on top of the code:

	// Set pins where modules connected
	#define TX_PIN 0  // Transmitter pin
	#define DHT_PIN 1  // DHT Sensor pin

	// Alecto WS1700 protocol settings
	#define ID 1334  // Set an ID between 1280 and 1535
	#define BAT 1  // Battery status to send in signal (0:Depleted, 1:Charged)
	#define TXMOD 0  // Sending mode (0:Auto,1:Forced)
	#define CHAN 0  // Set channel (0:1 or 1:2 or 2:3)
	#define REP 6  // Signal repeats

	// Serial terminal(you need USB TTL rx pin connected to PB3)
	//#define SERTER    // Un-comment this line to enable serial debug
Pretty much self-explanatory, though it is not necessary to change any of these for basic operation. More information on the `SERTER` is described in the [Troubleshooting](#troubleshooting) section below.

## Compile
<<<<<<< HEAD
Lately i've switched to [Arduino IDE 1.6.5](http://arduino.cc) on every of my computer, so i would suggest to use the same version.
Then get the [ATtiny support](http://code.google.com/archive/p/arduino-tiny/) for the IDE. This one is tested to compile fine.
Installation goes by the instructions in the archive, but there is additional step before it's going to compile. Navigate into the freshly created `~/Arduino/hardware/tiny/avr/` and create a folder named `libraries`. From your Arduino installation folder `../Arduino/hardware/arduino/avr/libraries` copy the `EEPROM` directory to the `~/Arduino/hardware/tiny/avr/libraries`.
The path structure have changed in the IDE 1.6+ and maybe there is also needed to edit the compiler path in the Tiny's `platform.txt`.
Something like this: `compiler.path={runtime.ide.path}/hardware/tools/avr/bin/`

To compile there is [DHTlib v0.1.13 (by Rob Tillaart)](http://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) needed. It is possible to work with newer versions, but this one is tested to work with.

![Build | Passing](https://img.shields.io/badge/build-passing-brightgreen.svg)
=======
Lately i've switched to [Arduino IDE 1.6.5] (https://www.arduino.cc/en/Main/OldSoftwareReleases#previous) on every of my computer, so i would suggest to use the same version. It is compiling fine on this version, though you need to get and edit some files to support the ATtiny family.
There is an archived library on Google Code named [Arduino-Tiny] (http://code.google.com/archive/p/arduino-tiny/) and you need the latest version for Arduino 1.5.
Installation goes by the instructions in the archive, but there is additional step before it's going to work. Navigate into the freshly created `~/Arduino/hardware/tiny/avr/` and create a folder named `libraries`. From your Arduino installation folder `../Arduino/hardware/arduino/avr/libraries` copy the `EEPROM` directory to the `~/Arduino/hardware/tiny/avr/libraries`.
The path structure have changed in the IDE 1.6+ and maybe there is also needed to edit the compiler path in the Tiny's `platform.txt`.
Something like this: `compiler.path={runtime.ide.path}/hardware/tools/avr/bin/`

In addition the [DHTlib v0.1.13 (by Rob Tillaart)] (http://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) is needed. It is possible to work with newer versions, but this one is tested to work with.
>>>>>>> origin/master

## Troubleshooting
In case you did everything as described, but still experiencing issues then you can try debugging via serial interface.
The code file begins with a commented line `SERTER` which you need to uncomment and upload to the ATtiny.

	// Serial terminal(you need USB TTL rx pin connected to PB3)
	//#define SERTER    // Un-comment this line to enable serial debug
Then you can connect a USB TTL's rx pin on the tiny's PB3 pin. Though this way there is no sending from the terminal, but you can see some texts confirming status of the program. Baud rate must be set to 9600bps or if you prefer faster speeds than look for the function `serialStart();` and change it.

Then you should see something like this printing in the terminal window of the:

	ATtiny Weather Station v1.0
	SERIAL TERMINAL - ENABLED
	TX PIN - D3
	DHT PIN - D2
	
	MESSAGE 0101111100111000000011001011001010111 SYNC
			ID = 1334	CH = 1	TEMP = 20.1	  HUM = 56
	SENT
If it displays everything like above, then you should take a look on the wiring.


## Reference
More details on the protocol can be found in the [Pilight Wiki - Alecto WS1700 section](http://wiki.pilight.org/doku.php/alecto_ws1700_v7_0#protocol) and at the forum thread from the wiki page.