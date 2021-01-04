#include "ScriptManager.h"
#include "Arduino.h"

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
        color_ = script_queue_[script_index_].color;
        speed_ = script_queue_[script_index_].effect_speed;

		counter_ms_  = Counter( script_queue_[script_index_].wait_ms);
		counter_sec_ = Counter( (uint64_t)script_queue_[script_index_].wait_sec * Counter::WAIT_ONE_SECOND);
		counter_min_ = Counter( (uint64_t)script_queue_[script_index_].wait_min * Counter::WAIT_ONE_MINUTE);

		ms_elapsed_ = false;
		sec_elapsed_ = false;
		min_elapsed_ = false;

		switch_effect_manually_ = script_queue_[script_index_].switch_effect_manually;

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
		ms_elapsed_  = ms_elapsed_ || counter_ms_.update();
		sec_elapsed_ = sec_elapsed_ || counter_sec_.update();
		min_elapsed_ = min_elapsed_ || counter_min_.update();	

		if(min_elapsed_ && sec_elapsed_ && ms_elapsed_)
		{
			incrementScript();
		}
	}

    effect_manager_.setEffectColor(color_);
    effect_manager_.setEffectSpeed(speed_);
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



