#include "ScriptManager.h"


void ScriptManager::loadScript(ScriptElement *script, uint8_t length)
{
	script_queue_ = script;
	script_length_ = length;
	script_index_ = 0;
	effect_switch_ = true;
}

void ScriptManager::runScript()
{
	if(effect_switch_)
	{
		preset_ = script_queue_[script_index_].preset;
		switch_effect_manually_ = script_queue_[script_index_].switch_effect_manually;

		uint32_t ms;

		timer_.reset(script_queue_[script_index_].ms);

		effect_switch_ = false;

		if(eeprom_save_flag_)
		{
			saveEffectEeprom();
		}
	}
	//Only increment the counters if the effects are to switch automatically
	//Otherwise, do not increment the timers and wait for manual effect switch
	else if(!switch_effect_manually_)
	{
		if(timer_.isElapsed())
		{
			incrementScript();
		}
	}

	effect_manager_.runEffect(preset_);	
}

void ScriptManager::incrementScript()
{
	script_index_ = (script_index_ + 1) % script_length_;
	effect_switch_ = true;
}

void ScriptManager::resetScript()
{
	script_index_ = 0;
    effect_switch_ = true;
}


void ScriptManager::loadEffectEeprom()
{
    script_index_ = EEPROM.read(EepromAddress::EEPROM_SCRIPT_INDEX);

    if(script_index_ >= script_length_)
    {
        script_index_ = 0;
    }
}


void ScriptManager::saveEffectEeprom()
{
    EEPROM.write(EepromAddress::EEPROM_SCRIPT_INDEX, script_index_);
}



