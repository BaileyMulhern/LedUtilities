#ifndef CONFETTI_H
#define CONFETTI_H

#include <FastLED.h>

#include "Effect.h"
#include "Strip.h"
#include "Timer.h"

/** @class Confetti
 *  @brief Led confetti effect
 *
 */
class Confetti : public Effect
{
  private:

	const CRGBPalette16 PALETTE_;
	const uint8_t GLITTER_RATE_;
	const uint8_t FADE_RATE_;
	const uint8_t GLITTER_LENGTH_;

	Strip *strip_;
	Timer glitter_timer_;
	Timer fade_timer_;

  public:

    Confetti(Strip *strip, uint16_t glitter_time, uint16_t fade_time)
		: strip_(strip),
		  glitter_timer_(glitter_time, true),
		  fade_timer_(fade_time, true),
		  PALETTE_(RainbowColors_p),
		  GLITTER_RATE_(30),
		  FADE_RATE_(1),
		  GLITTER_LENGTH_(5),
		  Effect()
	{
	};

    void reset();
	void loop();

};

#endif //FIRE_EFFECT