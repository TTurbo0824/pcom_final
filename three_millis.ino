//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int waterPin = 11;
int lightPin = 12;
int fanPin = 13;
int incomingByte;
float humF;
int humI;
float tempF;
int tempI;
unsigned long lightOffAt = 0;
unsigned long waterOffAt = 0;
unsigned long fanOffAt = 0;
unsigned long currentMillis;

void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
  pinMode(waterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  while (!Serial.available()) { // until the server responds,
    Serial.println("hello");    // send a hello message
    delay(500);                 // every half second
  }
  dht.begin();
}

void loop() {
  currentMillis = millis();

  if (currentMillis > lightOffAt) {
    digitalWrite(lightPin, LOW);
  }
  else if (lightOffAt >= currentMillis) {
    digitalWrite(lightPin, HIGH);
  }

  if (currentMillis > waterOffAt) {
    digitalWrite(waterPin, LOW);
  }
  else if (waterOffAt >= currentMillis) {
    digitalWrite(waterPin, HIGH);
  }

  if (currentMillis > fanOffAt) {
    digitalWrite(fanPin, LOW);
  }
  else if (fanOffAt >= currentMillis) {
    digitalWrite(fanPin, HIGH);
  }

  if (Serial.available() > 0) {   // see if there's incoming serial data
    incomingByte = Serial.read();

    if (incomingByte == 1) { //yellow
      lightOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 2) { //ribbon
      lightOffAt = millis() + 5 * 1000;
      waterOffAt = millis() + 1 * 1000;
    }
    else if (incomingByte == 3) { //march
      lightOffAt = millis() + 5 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 4) { //belief
      lightOffAt = millis() + 5 * 1000;
      waterOffAt = millis() + 1 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
   else if (incomingByte == 5) { //gray
      waterOffAt = millis() + 1 * 1000;
    }
   else if (incomingByte == 7) { //data
      fanOffAt = millis() + 5 * 1000;
    }
   else if (incomingByte == 8) { //Korea
      lightOffAt = millis() + 10 * 1000;
    }
  else if (incomingByte == 6) { //apple
      waterOffAt = millis() + 1 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 9) { //side
      lightOffAt = millis() + 10 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
   else if (incomingByte == 10) { //candle
      lightOffAt = millis() + 10 * 1000;
      fanOffAt = millis() + 10 * 1000;
    }
    else if (incomingByte == 11) { //Taiwan
      lightOffAt = millis() + 10 * 1000;
      waterOffAt = millis() + 1 * 1000;
    }
    else if (incomingByte == 12) { //voice
      lightOffAt = millis() + 10 * 1000;
      waterOffAt = millis() + 1 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 13) { //revolution
      lightOffAt = millis() + 10 * 1000;
      waterOffAt = millis() + 1 * 1000;
      fanOffAt = millis() + 10 * 1000;
    }
    else if (incomingByte == 14) { //rainbow
      lightOffAt = millis() + 10 * 1000;
      waterOffAt = millis() + 3 * 1000;
    }
    else if (incomingByte == 15) { // power
      lightOffAt = millis() + 10 * 1000;
      waterOffAt = millis() + 3 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 16) { //support
      waterOffAt = millis() + 3 * 1000;
    }
    else if (incomingByte == 17) { //peace
      waterOffAt = millis() + 3 * 1000;
      fanOffAt = millis() + 5 * 1000;
    }
    else if (incomingByte == 18) { //cold
      waterOffAt = millis() + 3 * 1000;
      fanOffAt = millis() + 10 * 1000;
    }
    else if (incomingByte == 19) { //indifferent
      fanOffAt = millis() + 10 * 1000;
    }

    else if (incomingByte == 20) { //share
      waterOffAt = millis() + 1 * 1000;
      fanOffAt = millis() + 10 * 1000;
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
