#include "RainbowEffect.h"


void RainbowEffect::draw(CRGB* leds, uint8_t num_leds)
{
	hue_counter_.update();

	fillRainbow(leds, num_leds, hue_counter_.getCount(), hue_delta_);
}