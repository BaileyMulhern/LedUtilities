#ifndef SOLID_EFFECT_H
#define SOLID_EFFECT_H

#include <FastLED.h>
#include "Effect.h"

/** @class SolidEffect
 *  @brief asdf
 *
 */
class SolidEffect : Effect
{

  public:
    SolidEffect();

    void run(CRGB* leds, uint8_t num_leds);
};

#endif //SOLID_EFFECT