// example from https://www.pjrc.com/teensy/td_keyboard.html
// use digi pins 2-6

const int thumbPin = 2;
const int indexPin = 3;
const int middlePin = 4;
const int ringPin = 5;
const int pinkyPin = 6;
const int hapticPin = 7;

int thumbState = 0;
int indexState = 0;
int middleState = 0;
int ringState = 0;
int pinkyState = 0;
int binary = 0;
int doPrint = 0;

void setup() {
  pinMode(thumbPin, INPUT_PULLUP);
  pinMode(indexPin, INPUT_PULLUP);
  pinMode(middlePin, INPUT_PULLUP);
  pinMode(ringPin, INPUT_PULLUP);
  pinMode(pinkyPin, INPUT_PULLUP);  
  pinMode(hapticPin, OUTPUT);
}

void loop() {
  doPrint = 0;
  binary = 0;
  
  // get ready to signal
  digitalWrite(hapticPin, HIGH);
  delay(250);
  
  // see if writing
  thumbState = digitalRead(thumbPin);
  indexState = digitalRead(indexPin);
  middleState = digitalRead(middlePin);
  ringState = digitalRead(ringPin);
  pinkyState = digitalRead(pinkyPin);
  if (thumbState == LOW) {  
    binary = binary + 1; 
    doPrint = 1;
  } 
  if (indexState == LOW) {
    binary = binary + 10;
    doPrint = 1;
  }
  if (middleState == LOW) {
    binary = binary + 100;
    doPrint = 1;
  }
  if (ringState == LOW) {
    binary = binary + 1000;
    doPrint = 1;
  }
  if (pinkyState == LOW) {
    binary = binary + 10000;
    doPrint = 1;
  }
  
  // only write if there is something to print
  if (doPrint == 1) {
    Keyboard.println(binary);
  }
  delay(250);
  digitalWrite(hapticPin, LOW);
  delay(500);
}
