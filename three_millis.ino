//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int waterPin = A0;
int lightPin = 12;
int fanPin = 13;
int incomingByte;
float humF;
int humI;
float tempF;
int tempI;
unsigned long lightMillis = 0;
unsigned long waterMillis = 0;
unsigned long fanMillis = 0;
unsigned long currentMillis;
bool isLignt;
bool isWater;
bool isFan;

void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
  pinMode(waterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  isLight = false;
  isWater = false;
  isFan = false;
  
  while (!Serial.available()) { // until the server responds,
    Serial.println("hello");    // send a hello message
    delay(500);                 // every half second
  }
  dht.begin();
}

void loop() {
  currentMillis = millis();

  if (Serial.available() > 0) {   // see if there's incoming serial data
    incomingByte = Serial.read();

    if (incomingByte == 1) { //yellow
     
      isLight = true;
      
      lightBlinky(5);
    }
    if (incomingByte == 2) { //ribbon
      lightBlinky(5);
      waterBlinky(5);
    }
    if (incomingByte == 3) { //march
      lightBlinky(5);
      fanBlinky(5);
    }
    if (incomingByte == 4) { //belief
      
      lightBlinky(5);
      waterBlinky(5);
      fanBlinky(5);
    }
    if (incomingByte == 5) { //gray
      waterBlinky(5);
    }
    if (incomingByte == 6) { //apple
      waterBlinky(5);
      fanBlinky(5);
    }
    if (incomingByte == 7) { //data
      fanBlinky(5);
    }
    if (incomingByte == 8) { //escape
      lightBlinky(10);
    }
    if (incomingByte == 9) { //side
      lightBlinky(10);
      fanBlinky(5);
    }
    if (incomingByte == 10) { //candle
      lightBlinky(10);
      fanBlinky(10);
    }
    if (incomingByte == 11) { //taiwan
      lightBlinky(10);
      waterBlinky(5);
    }
    if (incomingByte == 12) { //voice
      lightBlinky(10);
      waterBlinky(5);
      fanBlinky(5);
    }
    if (incomingByte == 13) { //revolution
      lightBlinky(10);
      waterBlinky(5);
      fanBlinky(10);
    }
    if (incomingByte == 14) { //rainbow
      lightBlinky(10);
      waterBlinky(10);
    }
    if (incomingByte == 15) { //power
      lightBlinky(10);
      waterBlinky(10);
      fanBlinky(5);
    }
    if (incomingByte == 16) { //support
      waterBlinky(10);
    }
    if (incomingByte == 17) { //peace
      waterBlinky(10);
      fanBlinky(5);
    }
    if (incomingByte == 18) { //cold
      waterBlinky(10);
      fanBlinky(10);
    }
    if (incomingByte == 19) { //indifferent
      fanBlinky(10);
    }

    if (incomingByte == 20) { //share
      waterBlinky(5);
      fanBlinky(10);
    }
    if (incomingByte == 21) {
      if (digitalRead(lightPin)) {
        digitalWrite(lightPin, LOW);
      }
      if (digitalRead(waterPin)) {
        digitalWrite(waterPin, LOW);
      }
      if (digitalRead(fanPin)) {
        digitalWrite(fanPin, LOW);
      }
    }

    humF = dht.readHumidity() * 100;
    humI = (int)humF;
    tempF = dht.readTemperature() * 100;
    tempI = (int)tempF;

    Serial.print(humI);
    Serial.print(",");
    Serial.println(tempI);
    delay(30);
  }
}

void lightBlinky(int timeOn) {
  if (currentMillis - lightMillis > timeOn * 1000) {
      digitalWrite(lightPin, LOW);
    } else {
      digitalWrite(lightPin, HIGH);
      lightMillis = currentMillis;
    }
  }
}

void waterBlinky(int timeOn) {
  if (currentMillis > waterMillis) {
    if (isWater) {
      digitalWrite(waterPin, LOW);
      waterMillis = currentMillis + (15 - timeOn) * 1000;
    } else {
      digitalWrite(waterPin, HIGH);
      waterMillis = currentMillis + timeOn * 1000;
    }
  }
}

void fanBlinky(int timeOn) {
  if (currentMillis > fanMillis) {
    if (isFan) {
      digitalWrite(fanPin, LOW);
      fanMillis = currentMillis + (15 - timeOn) * 1000;
    } else {
      digitalWrite(fanPin, HIGH);
      fanMillis = currentMillis + timeOn * 1000;
    }
  }
}

/*
  void loop() {
  unsigned long currentTime = millis();
  if (currentTime > nextTime) {
   if (digitalRead(PIN)) {
     digitalWrite(PIN, LOW);
     nextTime = currentTime + OFF_INTERVAL;
   } else {
     digitalWrite(PIN, HIGH);
     nextTime = currentTime + ON_INTERVAL;
   }
  }
  }
*/
