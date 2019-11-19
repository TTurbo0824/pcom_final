/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/

//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float humF;  //Stores humidity value
  int humI;
  float temp; //Stores temperature value
  //Read data and store it to variables hum and temp
  humF = dht.readHumidity()*100;
  humI = (int)humF;
  temp = dht.readTemperature();

  //Print temp and humidity values to serial monitor
  Serial.println(humI);
  // Serial.print("Humidity: ");
  // Serial.print(hum);
  // Serial.print(" %, Temp: ");
  // Serial.print(temp); 
  // Serial.println(" Celsius");
  delay(2000); //Delay 2 sec.
}
