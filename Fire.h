#ifndef FIRE_H
#define FIRE_H

#include <FastLED.h>

#include "Effect.h"
#include "Strip.h"
#include "Timer.h"

/** @class FireEffect
 *  @brief Led fire effect
 *
 */
class Fire : public Effect
{
  private:

	const CRGBPalette16 PALETTE_;
	const uint8_t SPARKING_RATE_;
	const uint8_t COOLING_RATE_;

	Strip *strip_;
	Timer timer_;
	uint8_t *heat_;

  public:

    Fire(Strip *strip, uint16_t time)
		: strip_(strip),
		  timer_(time, true),
		  PALETTE_(HeatColors_p),
		  SPARKING_RATE_(100),
		  COOLING_RATE_(35),
		  Effect()
	{
		heat_ = new uint8_t[strip_->length()];
	};

	~Fire()          
    {
        delete[] heat_;
    };

    void reset();
	void loop();

};

#endif //FIRE_EFFECT