#include "SolidEffect.h"


void SolidEffect::draw(CRGB* leds, uint8_t num_leds)
{
	switch (draw_mode_)
	{
		case CLEAR:
		case OVERWRITE:
			fillSolid(leds, num_leds, color_);
			break;

		case ADDITIVE:
			addSolid(leds, num_leds, color_);
			break;
		
		default:
			break;
	}
	
}