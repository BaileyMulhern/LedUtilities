#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>

#include "Strip.h"
#include "Wipe.h"
#include "Fire.h"
#include "Confetti.h"
#include "Fade.h"

typedef enum
{
	WIPE,
	FIRE,
	CONFETTI,
	FADE,
} EffectPreset;

class EffectManager 
{

  private:

	Strip *strip_;
	Effect *effect_;

    Wipe wipe_;
	Fire fire_;
	Confetti confetti_;
	Fade fade_;

	bool effect_switch_;
	EffectPreset effect_preset_;

  public:
    
    EffectManager(Strip *strip) 
        : strip_(strip),
    	  wipe_(strip, 20),
		  fire_(strip, 20),
		  confetti_(strip, 10, 10),
		  fade_(strip, 50, 0, 3),
		  effect_switch_(true),
		  effect_preset_(WIPE)
    {
    };
	
	void runEffect(EffectPreset preset);

};

#endif //EFFECT_MANAGER_H