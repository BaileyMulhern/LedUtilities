#ifndef WIPE_H
#define WIPE_H

#include <FastLED.h>

#include "Effect.h"
#include "Strip.h"
#include "Counter.h"
#include "Timer.h"

/** @class Wipe
 *  @brief Solid wipe effect
 *
 */
class Wipe : public Effect
{
  private:

	const CRGBPalette16 PALETTE_;
	const float BLEND_RATE_;
	
	Strip *strip_;
	Counter counter_;
	Timer timer_;
	uint16_t scroll_position_;
	uint8_t palette_index_;
	bool blend_;

  public:

	Wipe(Strip *strip, uint32_t time, bool blend = false, float blend_rate = 0)
		: strip_(strip),
		  timer_(time, true),
		  blend_(blend),
		  BLEND_RATE_(blend_rate),
		  PALETTE_(RainbowStripeColors_p),
		  counter_(strip->length()),
		  scroll_position_(0),
		  palette_index_(0),
		  Effect()
	{
	};

    void reset();
	void loop();
	
};

#endif //WIPE_H