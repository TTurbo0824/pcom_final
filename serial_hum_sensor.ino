/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/
int chk;
int hum;  //Stores humidity value
float temp; //Stores temperature value

//Libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>;

//Constants
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity() * 1000;
  temp = dht.readTemperature();

  //Print temp and humidity values to serial monitor
  //  byte * b = (byte *) &hum;
  //  Serial.write(b[0]);
  //  Serial.write(b[1]);
  //  Serial.write(b[2]);
  //  Serial.write(b[3]);
  Serial.write(hum);
  Serial.print("Humidity: ");
  Serial.print(hum);
  // Serial.print(" %, Temp: ");
  // Serial.print(temp);
  // Serial.println(" Celsius");
  delay(2000); //Delay 2 sec.
}
