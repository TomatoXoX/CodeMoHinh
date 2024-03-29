const int ledPin1 = 3; 
const int ledPin2 = 5; 
const int ledPin4 = 6; 
const int ledPin5 = 9; 
const int ledPin6 = 10; 
const int ledPin7 = 11;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

const long interval1 = 5;
const long interval2 = 10;
const long offInterval = 200; // Interval to keep the LEDs off

int brightness1 = 0;
int fadeAmount1 = 1;

int brightness2 = 255;
int fadeAmount2 = -1;

bool led1IsOff = false;
bool led2IsOff = false;

unsigned long led1OffMillis = 0;
unsigned long led2OffMillis = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle LED 2, 4, and 5 (Fade in and out)
  if (!led2IsOff && currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    brightness2 += fadeAmount2;

    if (brightness2 <= 0 || brightness2 >= 255) {
      if (brightness2 <= 0) {
        brightness2 = 0;
        led2IsOff = true;
        led2OffMillis = currentMillis;
      }
      fadeAmount2 = -fadeAmount2;
    }

    analogWrite(ledPin2, brightness2);
    analogWrite(ledPin4, brightness2);
    analogWrite(ledPin5, brightness2);
  } else if (led2IsOff && currentMillis - led2OffMillis >= offInterval) {
    led2IsOff = false;
  }

  // Handle LED 1, 6, and 7 (Fade in and out)
  if (!led1IsOff && currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    brightness1 += fadeAmount1;

    if (brightness1 <= 0 || brightness1 >= 255) {
      if (brightness1 <= 0) {
        brightness1 = 0;
        led1IsOff = true;
        led1OffMillis = currentMillis;
      }
      fadeAmount1 = -fadeAmount1;
    }

    analogWrite(ledPin1, brightness1);
    analogWrite(ledPin6, brightness1);
    analogWrite(ledPin7, brightness1);
  } else if (led1IsOff && currentMillis - led1OffMillis >= offInterval) {
    led1IsOff = false;
  }
}
