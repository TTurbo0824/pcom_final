void setup() {
  Serial.begin(9600); // initialize serial communications
  pinMode(0, OUTPUT);
  while (!Serial.available()) { // until the server responds,
    Serial.println("hello");    // send a hello message
    delay(500);                 // every half second
  }
}

void loop() {
  // if there are incoming bytes:
  if (Serial.available()) {
    // read incoming byte:
    int input = Serial.read();

    if (input == 'y') {
      // read the input on analog pin 0:
      digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);              // wait for a second
      digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
      delay(500);              // wait for a second
    }
    //   int sensorValue = analogRead(A0);
    //   // print out the value you read:
    Serial.println(0);
    delay(1); // delay in between reads for stability
  }
}
