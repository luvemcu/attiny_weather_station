/* ATtiny Weather Station
 * with Alecto WS1700 protocol.
 * 
 * Tiny,low power device designed to collect and send
 * environmental temperature and relative humidity.
 *
 * GregNau      2016
 */

// Serial terminal(you need USB TTL rx pin connected to PB3)
//#define SERTER    // to be removed soon!

// Set pins where modules connected
#define TX_PIN 0  // Transmitter pin
#define DHT_PIN 1 // DHT Sensor pin

// Alecto WS1700 protocol settings
#define ID 1334  // Set an ID between 1280 and 1535
#define BAT 1    // Battery status to send in signal (0:Depleted, 1:Charged)
#define TXMOD 0  // Sending mode (0:Auto,1:Forced)
#define CHAN 0   // Set channel (0:1 or 1:2 or 2:3)
#define REP 6    // Signal repeats

// Alecto WS1700 protocol timings (!do not change this,unless...!)
#define LONG 3780    // LONG is approx 3780 uS
#define SHORT 1890   // SHORT is approx 1890 uS
#define SEP 540      // SEParator is approx 540 uS
#define SYNC 9180    // SYNC signal length is 9180 uS

#include <dht.h>  // initialize DHT Library
dht DHT;

byte message[36]; // array to hold the whole message

void setup() {
  pinMode(4, OUTPUT);   // status led
  pinMode(TX_PIN, OUTPUT);  // initialize TX_PIN for sending
  
  digitalWrite(4, HIGH);  // turn on status led on startup
  delay(3000);    // and break code running for 3 sec
  
  #if defined(SERTER)
    serialStart();  // start serial and print some text
  #endif
}

void loop() {
  // Fill the message array
  convertId(ID);
  message[12] = BAT;
  message[13] = TXMOD;
  message[14-15] = CHAN;
  
  convertTemp(readTemp());
  convertHum(readHum());
  
  #if defined(SERTER)
    serialPrintMessage(); // print the message bits on terminal if enabled
    parseMessage(); // print the data in decimal and detailed
  #endif
  
  digitalWrite(4, HIGH);  // turn led on during send

  
  for (byte r=0; r<REP; r++) { sendMessage(); }  // repeat the signal for above defined times

  digitalWrite(4, LOW); // turn status led off when sent
  
  #if defined(SERTER)
    Serial.println("SENT");
    Serial.flush();
  #endif
  
  delay(180000);  // delay resend with 180s = 3minutes
  // this is not yet battery friendly, to be solved soon
}

void serialStart() {
    Serial.begin(9600);  // Initialize serial communication
    Serial.println("SERiAL ENABLED AT 9600 BPS");
    Serial.print("TX PiN ");Serial.print(TX_PIN);Serial.println(" SET");
    Serial.print("DHT PiN");Serial.print(DHT_PIN);Serial.println(" SET");
    Serial.println();
    Serial.flush();
}

// Convert the ID to bits and write to message array
void convertId(int decValue) {
    int binIndex = 0;
    for (int i = 11; i >= 0; i--) {
      int binValue = decValue >> i; 
      if (binValue & 1) {
        message[binIndex] = 1;
        binIndex += 1;
      }
      else {
        message[binIndex] = 0;
        binIndex += 1;
      }
    }
}

// Read DHT22 Sensor
int readTemp() {
  DHT.read22(DHT_PIN);
  int temp = DHT.temperature * 10;
  return temp;
}

int readHum() {
  DHT.read22(DHT_PIN);
  int hum = DHT.humidity;
  return hum;
}

// Convert temp to bits and fill to message array
void convertTemp(int decValue) {
  int binIndex = 16;
  for (int i = 11; i >= 0; i--) {
    int binValue = decValue >> i; 
    if (binValue & 1) {
      message[binIndex] = 1;
      binIndex += 1;
    }
    else {
      message[binIndex] = 0;
      binIndex += 1;
    }
  }
}

// Convert hum to bits and fill to message array
void convertHum(int decValue) {
  int binIndex = 28;
  for (int i = 7; i >= 0; i--) {
    int binValue = decValue >> i; 
    if (binValue & 1) {
      message[binIndex] = 1;
      binIndex += 1;
    }
    else {
      message[binIndex] = 0;
      binIndex += 1;
    }
  }
}

#if defined(SERTER)
  // Parse the message
  void parseMessage() {
    unsigned int id = 0;
    for(byte i = 0; i < 12; i++) { id = (id << 1) + message[i]; }
    Serial.print("ID = ");
    Serial.print(id);
    Serial.flush();
  
    unsigned short int ch = 0;
    for(byte i = 15; i < 17; i++) { ch = (ch << 1) + message[i]; }
    Serial.print(" CH = ");
    Serial.print(ch);
    Serial.flush();
  
    unsigned int temp = 0;
    for(byte i = 17; i < 28; i++) { temp = (temp << 1) + message[i]; }
    Serial.print(" TEMP = ");
    Serial.print(temp);
    Serial.flush();
  
    unsigned int hum = 0;
    for(byte i = 28; i < 36; i++) { hum = (hum << 1) + message[i]; }
    Serial.print(" HUM = ");
    Serial.println(hum);
    Serial.flush();
  }
  
  // Print the whole message bit by bit
  void serialPrintMessage() {
    Serial.print("MESSAGE: ");
    for (byte i=0; i<36; i++) {
      Serial.print(message[i]);
      Serial.flush();
    }
    Serial.println(" SYNC");
    Serial.flush();
  }
#endif

// Signal
void sendBit(byte b) {
  if (b == 0) {               // LOW
    digitalWrite(TX_PIN, HIGH);
    delayMicroseconds(SHORT);
    digitalWrite(TX_PIN, LOW);
  }
  else if (b == 1) {          // HIGH
    digitalWrite(TX_PIN, HIGH);
    delayMicroseconds(LONG);
    digitalWrite(TX_PIN, LOW);
  }
  delayMicroseconds(SEP);
}

// SYNC Signal
void sendSync() {
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(SYNC);
  digitalWrite(TX_PIN,LOW);
  delayMicroseconds(SEP);
}

// Send the 'message' by bits
void sendMessage() {
  for (byte i = 0; i < 36; i++) {
    sendBit(message[i]);
  }
  sendSync();    // Send the SYNC signal at the end
}
