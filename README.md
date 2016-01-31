# ATtiny Weather Station
(I mean another one, but this is based on Alecto protocol)

The purpose of this code is to periodically read temperature and humidity from an attached DHT22 sensor and transmit using regular 433mhz transmitter. The signal is in Alecto protocol, it can fool their devices also. Besides it is compatible with a great domotica solution: Pilight (http://www.pilight.org).

# Wiring:
![ATtiny Weather Station](/wiring.jpg?raw=true "Wiring")

# Schematics:
![ATtiny Weather Station](/schematics.jpg?raw=true "Schematics")

# Compile
To compile there is DHTlib v0.1.13 needed. It is possible to work with newer versions, but this one is tested to work with.
Get it here: http://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib

Tested to compile fine on Arduino 1.6 from 1.0.5 and work with ATtiny85.

*** There is still room to improve this code i believe, if you have any thoughts regarding then pls let me know.

# Reference
More details on the protocol can be found here:
http://wiki.pilight.org/doku.php/alecto_ws1700_v7_0#protocol
and at the forum thread from the wiki page.
