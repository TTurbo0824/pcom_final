//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int pumpPin = 11;
int lampPin = 12;
int fanPin = 13;
int incomingByte;
int humI; float humF;

float tempF;
int tempI;

void setup() {
  Serial.begin(115200);
  pinMode(pumpPin, OUTPUT);
  pinMode(lampPin, OUTPUT);
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
    incomingByte = Serial.read(); // read it
    if (incomingByte > 20) {
      blinkyBlinky(5, 500, 500); // 5 is number of blinks, blinkTime is the milliseconds in each state from above: int blinkTime = 500;
    } else if (incomingByte > 30) {
      blinkyBlinky(1, 5000, 0);
    }
  }
  humF = dht.readHumidity() * 100;
  humI = (int)humF;
  tempF = dht.readTemperature() * 100;
  tempI = (int)tempF;

  Serial.print(humI);
  Serial.print(",");
  Serial.println(tempI);
  delay(30); //Delay 2 sec.
}

void fanBlinky(int repeats, int time, int time2) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(fanPin, HIGH);
    delay(time);
    digitalWrite(fanPin, LOW);
    delay(time2);
  }
}

void lampBlinky(int repeats, int time, int time2) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(lampPin, HIGH);
    delay(time);
    digitalWrite(lampPin, LOW);
    delay(time2);
  }
}

void pumpBlinky(int repeats, int time, int time2) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(pumpPin, HIGH);
    delay(time);
    digitalWrite(pumpPin, LOW);
    delay(time2);
  }
}
