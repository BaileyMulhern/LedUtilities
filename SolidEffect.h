#ifndef SOLID_EFFECT_H
#define SOLID_EFFECT_H

#include <FastLED.h>

#include "Effect.h"
#include "LedHelpers.h"

/** @class SolidEffect
 *  @brief asdf
 *
 */
class SolidEffect : public Effect
{
  private:

	CRGB color_;

  public:

	SolidEffect()
		: color_(CRGB::Black), 
		  Effect()
	{
	};

    SolidEffect(CRGB color)
		: color_(color), 
		  Effect()
	{
	};

    void draw(CRGB* leds, uint8_t num_leds);
	
};

#endif //SOLID_EFFECT