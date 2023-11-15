
#include <FastLED.h> 

#define NUM_LEDS 60
#define Pin1 2 // We define pin 2 here and we have connected this with the touch sensor
#define DATA_PIN1 7
#define Pin2 3 // We define pin 2 here and we have connected this with the touch sensor
#define DATA_PIN2 8
#define Pin3 4 // We define pin 2 here and we have connected this with the touch sensor
#define DATA_PIN3 9


// This is an array of leds.  One item for each led in your strip.
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];

int ledPin = 13; // Here we make a variable ledPin 13 and this is connected with the light on the breadboard
 

void setup() {
       delay(2000);
     Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(Pin1, INPUT);
pinMode(Pin2, INPUT);
pinMode(Pin3, INPUT);
//FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

    FastLED.addLeds<WS2811, DATA_PIN1, RGB>(leds1, NUM_LEDS);
    FastLED.addLeds<WS2811, DATA_PIN2, RGB>(leds2, NUM_LEDS);
    FastLED.addLeds<WS2811, DATA_PIN3, RGB>(leds3, NUM_LEDS);
    

}

// your leds.
void loop() {
   // Move a single white led 

     int Value1 = digitalRead(Pin1); 
  if (Value1 == HIGH)
  {
    for(int whiteLed = 60; whiteLed > 0; whiteLed--) {
      // Turn our current led on to white, then show the leds
      leds1[whiteLed] = 0x2F4F4F;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);


    //digitalWrite(ledPin, HIGH);
    Serial.println("Sensor 1 TOUCHED");
    }
    FastLED.show();
  }
  else // If the ledPin is low, the serial print send 'not touched' and the ledPin 13 turned off
  {
       digitalWrite(ledPin,LOW);
    Serial.println("not touched");
    for (int i=0; i<NUM_LEDS; i++){
         leds1[i] = CRGB::Black;
    }
    FastLED.show();
  }
       int Value2 = digitalRead(Pin2); 
  if (Value2 == HIGH)
  {
    for(int blueLed = 60; blueLed > 0; blueLed--) {
      // Turn our current led on to white, then show the leds
      leds3[blueLed] = CRGB:: Blue;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);


    //digitalWrite(ledPin, HIGH);
    Serial.println("Sensor 2 TOUCHED");
    }
    FastLED.show();
  }
  else // If the ledPin is low, the serial print send 'not touched' and the ledPin 13 turned off
  {
       digitalWrite(ledPin,LOW);
    Serial.println("not touched");
    for (int i=0; i<NUM_LEDS; i++){
         leds3[i] = CRGB::Black;
    }
    FastLED.show();
  }
       int Value3 = digitalRead(Pin3); 
  if (Value3 == HIGH)
  {
    for(int redLed = 60; redLed > 0; redLed--) {
      // Turn our current led on to white, then show the leds
      leds3[redLed] = CRGB:: Red;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);


    //digitalWrite(ledPin, HIGH);
    Serial.println("Sensor 3 TOUCHED");
    }
    FastLED.show();
  }
  else // If the ledPin is low, the serial print send 'not touched' and the ledPin 13 turned off
  {
       digitalWrite(ledPin,LOW);
    Serial.println("not touched");
    for (int i=0; i<NUM_LEDS; i++){
         leds3[i] = CRGB::Black;
    }
    FastLED.show();
  }
  delay(10);  // We do here a delay so we can read the serial print
}
