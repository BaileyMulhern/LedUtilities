#include "ScriptManager.h"

void ScriptManager::loadScript(ScriptElement *script, uint8_t script_length)
{
	script_queue_ = script;
	script_length_ = script_length;
	script_index_ = 0;
	effect_switch_ = true;
}

void ScriptManager::runScript()
{
	if(effect_switch_)
	{
		effect_ = script_queue_[script_index_].effect;

		counter_ms_  = Counter( script_queue_[script_index_].wait_ms);
		counter_sec_ = Counter( (uint64_t)script_queue_[script_index_].wait_sec * Counter::PRESCALER_ONE_SECOND);
		counter_min_ = Counter( (uint64_t)script_queue_[script_index_].wait_min * Counter::PRESCALER_ONE_MINUTE);

		ms_elapsed_ = false;
		sec_elapsed_ = false;
		min_elapsed_ = false;

		effect_switch_ = false;
	}
	else
	{
		ms_elapsed_  = ms_elapsed_ || counter_ms_.tic();
		sec_elapsed_ = sec_elapsed_ || counter_sec_.tic();
		min_elapsed_ = min_elapsed_ || counter_min_.tic();	

		if(min_elapsed_ && sec_elapsed_ && ms_elapsed_)
		{
			script_index_ = (script_index_ + 1) % script_length_;
			effect_switch_ = true;
		}
	}

	effect_manager_.runEffect(effect_);	
}


void ScriptManager::resetScript()
{
	script_index_ = 0;
    effect_switch_ = true;
}



