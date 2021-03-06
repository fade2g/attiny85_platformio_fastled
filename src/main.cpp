// Test for using attiny85 with platformio
// code is copy & paste from https://github.com/FastLED/FastLED/blob/master/examples/Cylon/Cylon.ino
// Hardware is a ring of 12 ws2812 RGB LED, order of colors is GRB

// used clion IDE for development. Build throws error (incl. upload) but it still works somehow. Feels like npm install :-)

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 12

#define DATA_PIN 0

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
    Serial.begin(57600);
    Serial.println("resetting");
    LEDS.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);
    LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() {
    static uint8_t hue = 0;
    Serial.print("x");
    // First slide the led in one direction
    for(int i = 0; i < NUM_LEDS; i++) {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        FastLED.show();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
    }
    Serial.print("x");

    // Now go in the other direction.
    for(int i = (NUM_LEDS)-1; i >= 0; i--) {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        FastLED.show();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
    }
}