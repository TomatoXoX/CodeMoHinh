int led_pin = 5;

void setup(){
    pinMode(led_pin, OUTPUT);
}

void loop(){
  analogWrite(led_pin, 50);

  // set a delay before changing brightness again
  delay(5);
}