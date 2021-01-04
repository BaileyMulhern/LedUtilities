#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <Arduino.h>
#include <EEPROM.h>
#include <FastLED.h>

#include "EffectManager.h"
#include "Effect.h"
#include "SolidEffect.h"
#include "Counter.h"

class ScriptManager 
{
  public:

	typedef struct  {
		EffectManager::EffectPreset preset;
		uint32_t wait_ms;
		uint16_t wait_sec;
		uint16_t wait_min;
		bool switch_effect_manually;
	} ScriptElement;

	static const int WAIT_INFINITE = -1;

	ScriptManager(CRGB* leds, uint8_t num_leds, bool save_effect = false) 
		: effect_manager_(leds, num_leds),
		  script_queue_(), 
		  script_length_(0), 
		  script_index_(0), 
		  effect_switch_(false), 
		  preset_(EffectManager::OFF), 
		  eeprom_save_flag_(save_effect),
		  counter_ms_(),
		  counter_sec_(),
		  counter_min_(), 
		  ms_elapsed_(false),
		  sec_elapsed_(false),
		  min_elapsed_(false) 
	{
	};

	void loadScript(ScriptElement *script, uint8_t length);
	
	void runScript();
	
	void incrementScript();

	void resetScript();

	void loadEffectEeprom();

  private:

	typedef enum 
	{
		EEPROM_SCRIPT_INDEX = 0,
		
	} EepromAddress;

	EffectManager effect_manager_;
	
	ScriptElement *script_queue_;

	uint8_t script_length_;

	uint8_t script_index_;

	bool effect_switch_;

	EffectManager::EffectPreset preset_;

	bool eeprom_save_flag_;

	Counter counter_ms_;

	Counter counter_sec_;

	Counter counter_min_;

	bool ms_elapsed_;

	bool sec_elapsed_;

	bool min_elapsed_;
	
	bool switch_effect_manually_;

	void saveEffectEeprom();

};

#endif //SCRIPT_MANAGER_H