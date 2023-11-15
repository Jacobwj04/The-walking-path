#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    200
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define WAIT_TIME 10000

int pirPin = 2;                 // PIR Out pin 
int pirStat = 0; 
int increment = 20; 

#define ENTRY 0
#define GRP_ST1 20
#define GRP_ST2 65
#define GRP_ST3 110
#define GRP_ST4 155

CRGB leds[NUM_LEDS];

void setup() { 
  delay( 3000 ); // power-up safety delay
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  // Initialise lights for entry
  setLEDColourGreen( ENTRY);
  setLEDColourBlack( GRP_ST1);
  setLEDColourBlack( GRP_ST2);
  setLEDColourBlack( GRP_ST3);
  setLEDColourBlack( GRP_ST4);
  FastLED.show();
    
}

void loop() {
  pirStat = digitalRead(pirPin); 
  if (pirStat == HIGH) {
      Serial.println("Flash to start");
      flashStart();
      Serial.println("Sequence Triggered");
      runLEDSequence();
      Serial.println("Sequence Finished");
  }
  else{
    delay(10);
    Serial.println("Ready");
  }
}

void flashStart() {
  for( int i = 1; i < 4; ++i) {
      setLEDColourBlack( GRP_ST1);
      FastLED.show();
      delay(100);
      setLEDColourBlue( GRP_ST1);
      FastLED.show();
      delay(100);
    }
}

void runLEDSequence() {
  setLEDColourRed( ENTRY);
  setLEDColourBlue( GRP_ST1);
  setLEDColourBlack( GRP_ST2);
  setLEDColourBlack( GRP_ST3);
  setLEDColourBlack( GRP_ST4);
  FastLED.show();
  Serial.println("Stage 1");
  delay(WAIT_TIME);

  setLEDColourRed( ENTRY);
  setLEDColourBlack( GRP_ST1);
  setLEDColourBlue( GRP_ST2);
  setLEDColourBlack( GRP_ST3);
  setLEDColourBlack( GRP_ST4);
  FastLED.show();
  Serial.println("Stage 2");
  delay(WAIT_TIME);

  setLEDColourRed( ENTRY);
  setLEDColourBlack( GRP_ST1);
  setLEDColourBlack( GRP_ST2);
  setLEDColourBlue( GRP_ST3);
  setLEDColourBlack( GRP_ST4);
  FastLED.show();
  Serial.println("Stage 3");
  delay(WAIT_TIME);

  setLEDColourRed( ENTRY);
  setLEDColourBlack( GRP_ST1);
  setLEDColourBlack( GRP_ST2);
  setLEDColourBlack( GRP_ST3);
  setLEDColourBlue( GRP_ST4);
  FastLED.show();
  Serial.println("Stage 4");
  delay(WAIT_TIME);

  setLEDColourGreen( ENTRY);
  setLEDColourBlack( GRP_ST1);
  setLEDColourBlack( GRP_ST2);
  setLEDColourBlack( GRP_ST3);
  setLEDColourBlack( GRP_ST4);
  FastLED.show();
  Serial.println("Reset");
  
}

void setLEDColourRed( uint8_t groupStart) {
  if(groupStart == 0) {
    increment = 20;
  }
  else {
    increment = 45;
  }
    for( int i = groupStart; i < groupStart + increment; ++i) {
        leds[i] = CRGB::Red;
    }
}

void setLEDColourGreen( uint8_t groupStart) {
  if(groupStart == 0) {
    increment = 20;
  }
  else {
    increment = 45;
  }
    for( int i = groupStart; i < groupStart + increment; ++i) {
        leds[i] = CRGB::Green;
    }
}

void setLEDColourBlue( uint8_t groupStart) {
  if(groupStart == 0) {
    increment = 20;
  }
  else {
    increment = 45;
  }
    for( int i = groupStart; i < groupStart + increment; ++i) {
        leds[i] = CRGB::Teal;
    }
}

void setLEDColourBlack( uint8_t groupStart) {
  if(groupStart == 0) {
    increment = 20;
  }
  else {
    increment = 45;
  }
    for( int i = groupStart; i < groupStart + increment; ++i) {
        leds[i] = CRGB::Black;
    }
}
