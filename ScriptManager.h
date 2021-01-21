#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <Arduino.h>
#include <EEPROM.h>
#include <FastLED.h>

#include "EffectManager.h"
#include "Strip.h"
#include "Timer.h"
#include "Counter.h"

typedef struct  {
	EffectPreset preset;
	uint32_t ms;
	bool switch_effect_manually;
} ScriptElement;

class ScriptManager 
{
  private:

	typedef enum 
	{
		EEPROM_SCRIPT_INDEX = 0,
		
	} EepromAddress;

	ScriptElement *script_queue_;
	EffectManager effect_manager_;
	EffectPreset preset_;
	Timer timer_;

	uint8_t script_length_;
	uint8_t script_index_;

	bool effect_switch_;
	bool eeprom_save_flag_;
	bool switch_effect_manually_;

	void saveEffectEeprom();

  public:

	static const int WAIT_INFINITE = -1;

	ScriptManager(Strip *strip, bool save_effect = false) 
		: effect_manager_(strip),
		  eeprom_save_flag_(save_effect),
		  preset_(WIPE), 
		  timer_(0, false),
		  script_queue_(), 
		  script_length_(0), 
		  script_index_(0), 
		  effect_switch_(false),
		  switch_effect_manually_(false)	  
	{
	};

	void loadScript(ScriptElement *script, uint8_t length);
	void runScript();
	void incrementScript();
	void resetScript();
	void loadEffectEeprom();

};

#endif //SCRIPT_MANAGER_H