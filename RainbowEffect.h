#ifndef RAINBOW_EFFECT_H
#define RAINBOW_EFFECT_H

#include <FastLED.h>

#include "Effect.h"
#include "LedHelpers.h"
#include "Counter.h"

/** @class RainbowEffect
 *  @brief asdf
 *
 */
class RainbowEffect : public Effect
{

  public:

	static const uint16_t COUNT_MAX = 255;

	RainbowEffect()
		: hue_delta_(0),
		  hue_counter_(),
		  Effect()
	{
	};

    RainbowEffect(uint8_t hue_step, uint8_t hue_delta, uint32_t wait, 
					uint8_t initial_hue = 0)
		: hue_delta_(hue_delta),
		  hue_counter_(initial_hue, hue_step, COUNT_MAX, 0, wait),
		  Effect()
	{
	};

    void draw(CRGB* leds, uint8_t num_leds);

  private:
	
	uint8_t hue_delta_;	

	Counter hue_counter_;

};

#endif //RAINBOW_EFFECT