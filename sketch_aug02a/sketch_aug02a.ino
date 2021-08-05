#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUM_LEDS 23

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int pinX = A0;
int pinY = A1;
int pinZ = A2;
int xValue = 0;
int yValue = 0;
int zValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(pinX) -354;
  yValue = analogRead(pinY) -353;
  zValue = analogRead(pinZ) -444;

  Serial.println(xValue);
  Serial.println(yValue);
  Serial.println(zValue);
  delay(1000);        //
//  delay in between reads for stability/

// set pixel to red, delay(1000)
  strip.setPixelColor(0, 255, 0, 0);
  strip.show();
  delay(1000);
  // set pixel to off, delay(1000)
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();
  delay(1000);
}
