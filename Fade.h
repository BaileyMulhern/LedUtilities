#ifndef FADE_H
#define FADE_H

#include <FastLED.h>

#include "Effect.h"
#include "Strip.h"
#include "Counter.h"
#include "Timer.h"

/** @class Fade
 *  @brief Palette fade effect
 *
 */
class Fade : public Effect
{
  private:

	const CRGBPalette16 PALETTE_;
	const uint8_t PALETTE_MAX_ = 255;
	
	Strip *strip_;
	Counter counter_;
	Timer timer_;
	uint8_t initial_hue_;
	uint8_t delta_hue_;

  public:

	Fade(Strip *strip, uint32_t time, uint8_t initial_hue, uint8_t delta_hue)
		: strip_(strip),
		  timer_(time, true),
		  initial_hue_(initial_hue),
		  delta_hue_(delta_hue),
		  PALETTE_(RainbowColors_p),
		  counter_(PALETTE_MAX_, initial_hue, delta_hue),
		  Effect()
	{
	};

    void reset();
	void loop();
	
};

#endif //FADE_H