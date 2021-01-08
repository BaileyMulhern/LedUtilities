#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>

#include "Effect.h"
#include "SolidEffect.h"
#include "MarqueeEffect.h"
#include "RainbowEffect.h"
#include "Counter.h"

class EffectManager 
{
  public:

    typedef enum
    {
        NONE = 0,
        SOLID,
        RAINBOW_FILL,
        RAINBOW_FADE,
        RAINBOW_EVEN, 
        THEATRE_CHASE,
        THEATRE_CHASE_2,
        THEATRE_CHASE_3,
        NUM_PRESETS,
    } EffectPreset;

    typedef enum {
		FORWARD,
		BACKWARD,
		MIDDLE_OUT,
    } DirectionCode;

    typedef enum {
        WRAP,
		CUTOFF,        
    } OverflowCode;

	static const uint16_t VERY_FAST =	Counter::WAIT_ONE_MILLISECOND;
	static const uint16_t FAST = 		Counter::WAIT_ONE_TENTH_SECOND;
	static const uint16_t MEDIUM = 		Counter::WAIT_QUARTER_SECOND;
	static const uint16_t SLOW = 		Counter::WAIT_HALF_SECOND;
	static const uint16_t VERY_SLOW = 	Counter::WAIT_ONE_SECOND;
    
    EffectManager(CRGB* leds, uint8_t num_leds, CRGB color = CRGB::Red, 
                    uint16_t speed = MEDIUM, EffectPreset preset = NONE) 
        : leds_(leds), 
		  NUM_LEDS_(num_leds), 
		  color_(color),
          speed_(speed),
          preset_(preset), 
		  effect_(&solid_effect_)
    {
    };
	
	void runEffect(EffectPreset preset);

    void setEffectSpeed(uint16_t ms);

    void setEffectColor(CRGB color);

  private:

    CRGB* leds_;
    
    const uint8_t NUM_LEDS_;

	EffectPreset preset_;

	CRGB color_;
    
    uint16_t speed_;
    
    bool effect_switch_;

	Effect* effect_;

	SolidEffect solid_effect_;

    MarqueeEffect marquee_effect_;

	RainbowEffect rainbow_effect_;

};

#endif //EFFECT_MANAGER_H