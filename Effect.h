#ifndef EFFECT_H
#define EFFECT_H

#include <FastLED.h>

/** @class Effect
 *  @brief asdf
 *
 */
class Effect
{

  public:

	typedef enum {
		CLEAR,
		OVERWRITE,
		ADDITIVE,
	} DrawMode;

	DrawMode draw_mode_;

    Effect(DrawMode draw_mode = CLEAR)
		: draw_mode_(draw_mode)
	{
	};

    virtual void draw(CRGB* leds, uint8_t num_leds) = 0;


};

#endif //EFFECT
