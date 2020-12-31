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
    Effect(){};

    virtual void run(CRGB* leds, uint8_t num_leds) = 0;
};

#endif //EFFECT
