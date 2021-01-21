#include "EffectManager.h"

void EffectManager::runEffect(EffectPreset preset)
{
    //If the new effect is different from the current effect, set flag
    effect_switch_ |= !(effect_preset_ == preset);

    if(effect_switch_)
    {
		effect_switch_ = false;
        effect_preset_ = preset;

		switch(effect_preset_)
		{
			case WIPE:
				effect_ = &wipe_;
				break;

			case FIRE:
				effect_ = &fire_;
				break;

			case CONFETTI:
				effect_ = &confetti_;
				break;

			case FADE:
				effect_ = &fade_;
				break;
				
            default:
                break;

		}

		effect_->reset();
    }

    effect_->loop();
}