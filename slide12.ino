const int ledPin1 = 6;
const int ledPin2 = 7;
int led_brightness = 0;
bool increasing = true;
// Timing variables
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
const long interval1 = 10; // interval at which to blink first LED (milliseconds)
const long interval2 = 100; // interval at which to blink second LED (milliseconds)

unsigned long startTime = 0; // To store the time when the loop starts
const long specialInterval = 1000; // The special time interval (10 seconds)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  startTime = millis(); // Initialize the start time
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle first LED blinking
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis; // Save the last time you blinked the LED
    // If the LED is off turn it on and vice-versa
    if(increasing == true){
    // increase brightness value
    led_brightness = led_brightness + 1;
  }
  else{
    // decrease brightness value
    led_brightness = led_brightness - 1;
  }
  

  // if maximum brightness reached, start reducing brightness
  if(led_brightness >= 255){
    increasing = false;
  }
  // if minimum brightness reached, start increasing brightness
  else if(led_brightness <= 0){
    increasing = true;
  }

  // set the brightness of the led using the brightness value
  analogWrite(ledPin1, led_brightness);

  // set a delay before changing brightness again
  delay(5);
  }

  // Handle second LED blinking
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis; // Save the last time you blinked the LED
    // If the LED is off turn it on and vice-versa
    if(increasing == true){
    // increase brightness value
    led_brightness = led_brightness + 1;
  }
  else{
    // decrease brightness value
    led_brightness = led_brightness - 1;
  }
  

  // if maximum brightness reached, start reducing brightness
  if(led_brightness >= 255){
    increasing = false;
  }
  // if minimum brightness reached, start increasing brightness
  else if(led_brightness <= 0){
    increasing = true;
  }

  // set the brightness of the led using the brightness value
  analogWrite(ledPin2, led_brightness);

  // set a delay before changing brightness again
  delay(5);
  }

  // Check if the special interval has elapsed
  if (currentMillis - startTime >= specialInterval) {
    // Perform the special action
    

    // Reset start time
    startTime = currentMillis;
  }
}