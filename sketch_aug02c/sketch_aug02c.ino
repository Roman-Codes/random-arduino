#include <Adafruit_NeoPixel.h>

// ================================================================
// ===                NEOPIXEL AHRS ROUTINE                     ===
// ================================================================

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example in the lbrary folder for more information on possible values.



//#include   // NeoPixel library from Adafruit
#define PIXELPIN       4        // Arduino pin connected to strip
#define NUMPIXELS      60       // Total number of RGB LEDs on strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXELPIN, NEO_GRB + NEO_KHZ800);
void update_led_ahrs(float yaw, float pitch, float roll) {
  // Note: the YPR values are in DEGREES! not radians
  
  // Clean slate. 
  pixels.clear();

  // Determine the "nose" of the AHRS from yaw angle indication
  int yaw_index = int(NUMPIXELS * (180.0 + yaw) / 360.0);

  // Light intensity for pitch and roll quadrants 
  float roll_brightness = 255 * roll / 180.0;
  float pitch_brightness = 255 * pitch / 180.0;

  // Bread and butter: Counts through a quadrant's worth of NeoPixel indecies
  // and determines the appropriate color for all four quadrants. The pitch and
  // roll brightness values then scale how red, blue, or green each pixel. This
  // emulates in admittedly simplistic fashion a Great Circle around an RGB
  // sphere with red at the "South Pole", green at the "Equator", and blue at 
  // the "North Pole". Green values are inversely proportional to pitch and roll
  int i;
  for (i = 0; i < (NUMPIXELS / 4); i++){
    if (pitch >= 0) {
      pixels.setPixelColor((yaw_index - (NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(pitch_brightness, 255-2*pitch_brightness, 0));
      pixels.setPixelColor((yaw_index + (3*NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(0, 255-2*pitch_brightness, pitch_brightness));
    } else {
      pixels.setPixelColor((yaw_index - (NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(0, 255 + 2*pitch_brightness, -1 * pitch_brightness));
      pixels.setPixelColor((yaw_index + (3*NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(-1 * pitch_brightness, 255 + 2*pitch_brightness, 0));
    }

    if (roll >= 0) {
      pixels.setPixelColor((yaw_index - (3*NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(roll_brightness, 255-roll_brightness, 0));
      pixels.setPixelColor((yaw_index + (NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(0, 255-roll_brightness, roll_brightness));
    } else {
      pixels.setPixelColor((yaw_index - (3*NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(0, 255 + 2*roll_brightness, -1 * roll_brightness));
      pixels.setPixelColor((yaw_index + (NUMPIXELS/8) + i) % NUMPIXELS, pixels.Color(-1 * roll_brightness, 255 + 2*roll_brightness, 0));
    }      
  }

  // Set the "nose indicator" and turn the device on
  pixels.setPixelColor(yaw_index, pixels.Color(255,255,255)); // White as can be
  pixels.show();
}
