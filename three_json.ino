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
  //  delay(2000);
  if (Serial.available() > 0) {   // see if there's incoming serial data
    incomingByte = Serial.read();
    if (incomingByte = 1) {
      lightBlinky(5);
    }
    if (incomingByte = 2) {
      lightBlinky(5);
      fanBlinky(5);
    }
    if (incomingByte = 3) {
      lightBlinky(5);
      waterBlinky(5);
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

void lightBlinky(int time) {
  digitalWrite(lightPin, HIGH);
  delay(time * 1000);
  digitalWrite(lightPin, LOW);
}

void waterBlinky(int time) {
  digitalWrite(waterPin, HIGH);
  delay(time * 1000);
  digitalWrite(waterPin, LOW);
}

void fanBlinky(int time) {
  digitalWrite(fanPin, HIGH);
  delay(time * 1000);
  digitalWrite(fanPin, LOW);
}
