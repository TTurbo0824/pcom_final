int ledPin = 13;
int blinkTime = 500;
int blinkFre = 5

bool eyesStinging = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  if (eyesStinging) //Only blink if it's absolutely necessary
    blinkyBlinky(blinkFre, blinkTime); // 5 is number of blinks, blinkTime is the milliseconds in each state from above: int blinkTime = 500;
}

void loop() {
}

void blinkyBlinky(int repeats, int time) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(ledPin, HIGH);
    delay(time);
    digitalWrite(ledPin, LOW);
    delay(time);
  }
