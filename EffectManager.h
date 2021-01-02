#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>

#include "Effect.h"
#include "SolidEffect.h"
#include "MarqueeEffect.h"
#include "Counter.h"

class EffectManager 
{

 public:

    typedef enum
    {
        EFFECT_OFF = 0,
        EFFECT_SOLID_RED,
        EFFECT_SOLID_GREEN,
        EFFECT_SOLID_BLUE,
        EFFECT_SOLID_CYAN,
        EFFECT_SOLID_MAGENTA,
        EFFECT_SOLID_YELLOW,
        EFFECT_RAINBOW_FILL_SLOW,
        EFFECT_RAINBOW_FILL_FAST,
        EFFECT_RAINBOW_FADE_SLOW,
        EFFECT_RAINBOW_FADE_FAST,
        EFFECT_RAINBOW_EVEN_SLOW,
        EFFECT_RAINBOW_EVEN_FAST, 
        EFFECT_THEATRE_CHASE_RED_SLOW,
        EFFECT_THEATRE_CHASE_RED_FAST,
        EFFECT_THEATRE_CHASE_GREEN_SLOW,
        EFFECT_THEATRE_CHASE_GREEN_FAST,
        EFFECT_THEATRE_CHASE_BLUE_SLOW,
        EFFECT_THEATRE_CHASE_BLUE_FAST,
        EFFECT_THEATRE_CHASE_CYAN_SLOW,
        EFFECT_THEATRE_CHASE_CYAN_FAST,
        EFFECT_THEATRE_CHASE_MAGENTA_SLOW,
        EFFECT_THEATRE_CHASE_MAGENTA_FAST,
        EFFECT_THEATRE_CHASE_YELLOW_SLOW,
        EFFECT_THEATRE_CHASE_YELLOW_FAST,
        EFFECT_THEATRE_CHASE_RAINBOW_FILL_SLOW,
        EFFECT_THEATRE_CHASE_RAINBOW_FILL_FAST,
        EFFECT_THEATRE_CHASE_RAINBOW_FADE_SLOW,
        EFFECT_THEATRE_CHASE_RAINBOW_FADE_FAST,
        EFFECT_THEATRE_CHASE_RAINBOW_EVEN_SLOW,
        EFFECT_THEATRE_CHASE_RAINBOW_EVEN_FAST,
        EFFECT_TEST,
        EFFECT_NUM_EFFECTS,
    } EffectName;

    typedef enum {
		FORWARD,
		BACKWARD,
		MIDDLE_OUT,
    } DirectionCode;

    typedef enum {
        WRAP,
		CUTOFF,        
    } OverflowCode;
    
    EffectManager(CRGB* leds, uint8_t num_leds) 
        : leds_(leds), 
		  NUM_LEDS_(num_leds), 
		  effect_name_(EFFECT_OFF), 
		  effect_(&solid_effect_),
		  counter_(),
          rainbow_counter_()
    {
    };
	
	void runEffect(EffectName effect_name);



 private:

    CRGB* leds_;
    
    const uint8_t NUM_LEDS_;

	EffectName effect_name_;

	Effect* effect_;

	SolidEffect solid_effect_;

    MarqueeEffect marquee_effect_;

    Counter counter_;

    Counter rainbow_counter_;

    static const uint16_t COUNT_MAX_RAINBOW_ = 255;
    
    void initCounterRainbowSlow();

    void initCounterRainbowFast();

    void initCounterTheatreChaseSlow();

    void initCounterTheatreChaseFast();
	
	void ledsFillSolidBlock(CRGB color, int start, int length, DirectionCode dir = FORWARD, OverflowCode overflow = WRAP);  

    void ledsFillAlternating(int mod, int offset);
    
    void ledsFillAlternating(CRGB color, int mod, int offset);

	void ledsFillRainbow(int hue, int delta);
};

#endif //EFFECT_MANAGER_H