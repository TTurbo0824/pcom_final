//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int ledPin = 13;
int incomingByte;
int blinkTime = 500;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

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
    if (incomingByte == 'H'){
    blinkyBlinky(5, blinkTime); // 5 is number of blinks, blinkTime is the milliseconds in each state from above: int blinkTime = 500;
  }
}

  float humF;
  int humI;
  float tempF;
  int tempI;
  humF = dht.readHumidity() * 100;
  humI = (int)humF;
  tempF = dht.readTemperature() * 100;
  tempI = (int)tempF;

  Serial.println(humI);
  Serial.println(",");
  Serial.println(tempI);
  delay(2000); //Delay 2 sec.
}

void blinkyBlinky(int repeats, int time) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(ledPin, HIGH);
    delay(time);
    digitalWrite(ledPin, LOW);
    delay(time);
  }
}
