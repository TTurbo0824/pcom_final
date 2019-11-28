/* 
Step before sending sensor values (humidity/temperature) from DHT-22 sensor to p5.js sketch
Converting float to int to enable serial communication
*/


//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

float humF;
int humI;
float tempF;
int tempI;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
   
  humF = dht.readHumidity()*100;
  humI = (int)humF;
  tempF = dht.readTemperature()* 100;
  tempI = (int)tempF;

  Serial.println(humI);
  Serial.println(",");
  Serial.println(tempI);
  delay(2000); //Delay 2 sec.
}
