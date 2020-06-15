#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include "EffectManager.h"
#include "Counter.h"
#include <FastLED.h>


class ScriptManager 
{

 public:

	typedef struct  {
		EffectManager::Effect effect;
		uint32_t wait_ms;
		uint16_t wait_sec;
		uint16_t wait_min;
	} ScriptElement;

	ScriptManager(CRGB* leds, uint8_t num_leds) 
		: effect_manager_(leds, num_leds),
		  script_queue_(), 
		  script_length_(0), 
		  script_index_(0), 
		  effect_switch_(false), 
		  effect_(0), 
		  counter_ms_(),
		  counter_sec_(),
		  counter_min_(), 
		  ms_elapsed_(false),
		  sec_elapsed_(false),
		  min_elapsed_(false) {
	};

	void loadScript(ScriptElement *script, uint8_t script_length);
	
	void runScript();

	void resetScript();


 private:

	EffectManager effect_manager_;
	
	ScriptElement *script_queue_;

	uint8_t script_length_;

	uint8_t script_index_;

	bool effect_switch_;

	EffectManager::Effect effect_;

	Counter counter_ms_;

	Counter counter_sec_;

	Counter counter_min_;

	bool ms_elapsed_;

	bool sec_elapsed_;

	bool min_elapsed_;

};

#endif //SCRIPT_MANAGER_H