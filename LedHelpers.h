#ifndef LED_HELPERS_H
#define LED_HELPERS_H

#include <FastLED.h>

void clear(CRGB* leds, uint8_t num_leds);

void fillSolid(CRGB* leds, uint8_t num_leds, CRGB color);

void fillRainbow(CRGB* leds, uint8_t num_leds, int hue, int delta);

void addSolid(CRGB* leds, uint8_t num_leds, CRGB color);


#endif //LED_HELPERS