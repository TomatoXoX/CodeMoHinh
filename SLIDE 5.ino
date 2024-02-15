const int ledPin1 = 2; // LED on digital pin 2 - Blinks at 1 Hz
const int ledPin2 = 3; // LED on digital pin 3 - Fades in and out over 5 seconds
const int ledPin4 = 5; // New LED on digital pin 5
const int ledPin5 = 6; // New LED on digital pin 6
const int ledPin6 = 7; // New LED on digital pin 7
const int ledPin7 = 9; // New LED on digital pin 9 - On for 4s, off for 4s
const int ledPin8 = 10; // New LED on digital pin 10 - Always on
const int ledPin9 = 11; // New LED on digital pin 11 - Gradual fade in/out over 10s

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis7 = 0;
unsigned long previousMillis9 = 0;

const long interval1 = 500;  // Interval at which to blink LED 1 (milliseconds)
const long interval2 = 20;   // Interval at which to update the fade for LED 2 (milliseconds)
const long interval3 = 2000; // Interval at which to turn on each of the ordered LEDs (milliseconds)
const long interval7 = 4000; // 4 seconds interval for LED 7
const long interval9 = 40;   // 20ms interval for fading LED 9

int brightness2 = 0;
int fadeAmount2 = 1; // Fade amount for LED 2
int brightness9 = 0;
int fadeAmount9 = 1; // Fade amount for LED 9 over 10 seconds

int currentOrderedLED = 4;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT); // LED 8 will be always on
  pinMode(ledPin9, OUTPUT);

  digitalWrite(ledPin8, HIGH); // Turn LED 8 on
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle LED 1 (Blinking at 1Hz)
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    digitalWrite(ledPin1, !digitalRead(ledPin1));
  }

  // Handle LED 2 (Fade in and out)
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    analogWrite(ledPin2, brightness2);
    brightness2 += fadeAmount2;
    if (brightness2 <= 0 || brightness2 >= 255) {
      brightness2 = constrain(brightness2, 0, 255);
      fadeAmount2 = -fadeAmount2;
    }
  }

  // Handle LEDs 4, 5, and 6 (shine in order)
  if (currentMillis - previousMillis3 >= interval3) {
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(currentOrderedLED, HIGH);
    currentOrderedLED++;
    if (currentOrderedLED > 7) {
      currentOrderedLED = 5;
    }
    previousMillis3 = currentMillis;
  }

  // Handle LED 7 (On for 4s, off for 4s)
  if (currentMillis - previousMillis7 >= interval7) {
    previousMillis7 = currentMillis;
    digitalWrite(ledPin7, !digitalRead(ledPin7));
  }

// Handle LED 9 (Gradual fade in/out over 10s)
if (currentMillis - previousMillis9 >= interval9) {
  previousMillis9 = currentMillis;
  analogWrite(ledPin9, brightness9);
  brightness9 += fadeAmount9;
  if (brightness9 <= 0 || brightness9 >= 255) {
    brightness9 = constrain(brightness9, 0, 255);
    fadeAmount9 = -fadeAmount9; // Reverse the direction of the fade
  }
}
}
