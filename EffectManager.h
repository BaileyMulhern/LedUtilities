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
        OFF = 0,
        SOLID_RED,
        SOLID_GREEN,
        SOLID_BLUE,
        SOLID_CYAN,
        SOLID_MAGENTA,
        SOLID_YELLOW,
        RAINBOW_FILL_SLOW,
        RAINBOW_FILL_FAST,
        RAINBOW_FADE_SLOW,
        RAINBOW_FADE_FAST,
        RAINBOW_EVEN_SLOW,
        RAINBOW_EVEN_FAST, 
        THEATRE_CHASE_RED_SLOW,
        THEATRE_CHASE_RED_FAST,
        THEATRE_CHASE_GREEN_SLOW,
        THEATRE_CHASE_GREEN_FAST,
        THEATRE_CHASE_BLUE_SLOW,
        THEATRE_CHASE_BLUE_FAST,
        THEATRE_CHASE_CYAN_SLOW,
        THEATRE_CHASE_CYAN_FAST,
        THEATRE_CHASE_MAGENTA_SLOW,
        THEATRE_CHASE_MAGENTA_FAST,
        THEATRE_CHASE_YELLOW_SLOW,
        THEATRE_CHASE_YELLOW_FAST,
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
    
    EffectManager(CRGB* leds, uint8_t num_leds) 
        : leds_(leds), 
		  NUM_LEDS_(num_leds), 
		  preset_(OFF), 
		  effect_(&solid_effect_)
    {
    };
	
	void runEffect(EffectPreset preset);

  private:

    CRGB* leds_;
    
    const uint8_t NUM_LEDS_;

	EffectPreset preset_;

	Effect* effect_;

	SolidEffect solid_effect_;

    MarqueeEffect marquee_effect_;

	RainbowEffect rainbow_effect_;

};

#endif //EFFECT_MANAGER_H