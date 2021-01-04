#include "LedHelpers.h"

void clear(CRGB* leds, uint8_t num_leds)
{
	fill_solid(leds, num_leds, 0);
}

void fillSolid(CRGB* leds, uint8_t num_leds, CRGB color)
{
	fill_solid(leds, num_leds, color);
}

void fillRainbow(CRGB* leds, uint8_t num_leds, int hue, int delta)
{
	fill_rainbow(leds, num_leds, hue, delta);
}

void addSolid(CRGB* leds, uint8_t num_leds, CRGB color)
{
	for(int i = 0; i < num_leds; i++)
	{
		leds[i] += color;
	}
}