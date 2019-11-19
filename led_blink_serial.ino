int ledPin = 13;
int incomingByte;
int blinkTime = 500;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  if (Serial.available() > 0) {   // see if there's incoming serial data
    incomingByte = Serial.read(); // read it
    blinkyBlinky(5, blinkTime); // 5 is number of blinks, blinkTime is the milliseconds in each state from above: int blinkTime = 500;
  }
}

void blinkyBlinky(int repeats, int time){
  for (int i = 0; i < repeats; i++){
    digitalWrite(ledPin, HIGH);
    delay(time);
    digitalWrite(ledPin, LOW);
    delay(time);
  }
}
