#include "LedHelpers.h"

void fillSolid(CRGB* leds, uint8_t num_leds, CRGB color)
{
	for(int i = 0; i < num_leds; i++)
	{
		leds[i] = color;
	}
}