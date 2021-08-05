
#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    20

CRGB leds[NUM_LEDS];

// These constants won't change. They're used to give names to the pins used:
 
// Analog input pin that the gyro is attached to

int pinX = A0;
int pinY = A1;
int pinZ = A2;

int xValue = 0;
int yValue = 0;
int zValue = 0;
int outputRedValue = 0;
int outputGreenValue = 0;
int outputBlueValue = 0;

const int lengthSensorPin = A5;

int redValue = 0;        // value read from the gyro
int greenValue = 0;
int blueValue = 0;

int lengthValue = 0;

int outputLengthValue = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // read the analog in value:
  redValue = analogRead(pinX);
  greenValue = analogRead(pinY);
  blueValue = analogRead(pinZ);

  lengthValue = analogRead(lengthSensorPin);
  
  // map it to the range of the analog out:
  outputRedValue = map(redValue, -360, 360, 0, 255);
  outputGreenValue = map(greenValue, -360, 360, 0, 255);
  outputBlueValue = map(blueValue, -360, 360, 0, 255);

  outputLengthValue = map(lengthValue, 0, 1023, 0, 20);
  
  // change the analog out value:

  // print the results to the Serial Monitor:
  Serial.print("RGB LED Value = (");
  Serial.print(outputRedValue);
  Serial.print(", ");
  Serial.print(outputGreenValue);
  Serial.print(", ");
  Serial.print(outputBlueValue);
  Serial.print("length - ");
  Serial.print(outputLengthValue);
  Serial.println(")");

  // LED sos:
  for (int i = 0; i <= outputLengthValue; i++) {
    leds[i] = CRGB(outputRedValue, outputGreenValue, outputBlueValue);
    FastLED.show();
  }

  for (int i = outputLengthValue; i <= 20; i++) {
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
    }
    
}
