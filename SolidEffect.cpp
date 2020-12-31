#include "SolidEffect.h"


void SolidEffect::run(CRGB* leds, uint8_t num_leds)
{
	fillSolid(leds, num_leds, color_);
}