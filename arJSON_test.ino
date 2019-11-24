// ArduinoJson (library by Benoit Blanchon) should be installed and included

#include <ArduinoJson.h>

int waterPin = A0;
int lightPin = 12;
int fanPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
  pinMode(waterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  char json[] = "{\"name\":\"taiwan\",\"data\":[10, 5, 0]}";
  StaticJsonDocument<256> doc;
  DeserializationError err = deserializeJson(doc, json);

  if (err) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  
  int lightTime = doc["data"][0];
  int waterTime = doc["data"][1];
  int fanTime = doc["data"][2];
  
  lightBlinky(lightTime);
  waterBlinky(waterTime);
  fanBlinky(fanTime);
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

void loop() {
  // put your main code here, to run repeatedly:

}
