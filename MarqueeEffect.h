#ifndef MARQUEE_EFFECT_H
#define MARQUEE_EFFECT_H

#include <FastLED.h>

#include "Effect.h"
#include "LedHelpers.h"
#include "Counter.h"

/** @class MarqueeEffect
 *  @brief asdf
 *
 */
class MarqueeEffect : public Effect
{

  public:

	MarqueeEffect()
    : color_(CRGB::Black),
      num_on_(0),
      num_off_(0), 
      smooth_(false),
      scroll_counter_(),
      Effect()
    {
    };

    MarqueeEffect(CRGB color, uint8_t num_on, uint8_t num_off, uint32_t wait, bool smooth = false)
	: color_(color), 
      num_on_(num_on),
      num_off_(num_off),
      smooth_(smooth),
      scroll_counter_(0, 1, num_on + num_off, 0, wait),
	  Effect()
    {

    };

    void run(CRGB* leds, uint8_t num_leds);

  private:

    CRGB color_;
	uint8_t num_on_;
    uint8_t num_off_;
    bool smooth_;
    Counter scroll_counter_;


};

#endif //MARQUEE_EFFECT