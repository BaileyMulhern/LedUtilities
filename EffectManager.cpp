#include "EffectManager.h"

void EffectManager::runEffect(EffectPreset preset)
{
    //If the new effect is different from the current effect, set flag
    effect_switch_ |= !(preset_ == preset);

    if(effect_switch_)
    {
		effect_switch_ = false;
        preset_ = preset;

		switch(preset_)
		{
			case NONE:
				solid_effect_ = SolidEffect();
				effect_ = &solid_effect_;
				break;
			
			case SOLID:
				solid_effect_ = SolidEffect(color_);
				effect_ = &solid_effect_;
				break;

			case RAINBOW_FILL:
				rainbow_effect_ = RainbowEffect(1, 0, speed_);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_FADE:
				//Fill rainbow with a delta of 5 to make it fade throughout
				rainbow_effect_ = RainbowEffect(1, 5, speed_);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_EVEN:
			{
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ >= RainbowEffect::COUNT_MAX) 
									? 1
									: RainbowEffect::COUNT_MAX / NUM_LEDS_;
				rainbow_effect_ = RainbowEffect(1, delta, speed_);
				effect_ = &rainbow_effect_;
				break;
			}

			case THEATRE_CHASE:
			{
				marquee_effect_ = MarqueeEffect(color_, 1, 2, speed_);
				effect_ = &marquee_effect_;
				break;
			}
		
            case THEATRE_CHASE_2:
			{
				marquee_effect_ = MarqueeEffect(color_, 2, 8, speed_);
				effect_ = &marquee_effect_;
				break;
			}

            case THEATRE_CHASE_3:
			{
                uint8_t half = NUM_LEDS_ / 3;
				marquee_effect_ = MarqueeEffect(color_, half, half + half, speed_);
				effect_ = &marquee_effect_;
				break;
			}

            case SMOOTH_CHASE:
            {
                marquee_effect_ = MarqueeEffect(color_, 2, 8, speed_, true);
                effect_ = &marquee_effect_;
                break;
            }

            default:
                break;

		}
    }

    effect_->draw(leds_, NUM_LEDS_);
}

void EffectManager::setEffectSpeed(uint16_t ms)
{
    effect_switch_ |= !(speed_ == ms);
    speed_ = ms;
}

void EffectManager::setEffectColor(CRGB color)
{
    effect_switch_ |= !(color_ == color);
    color_ = color;	
}

/*
void EffectManager::ledsFillSolidBlock(CRGB color, int start, int length, DirectionCode dir = FORWARD, OverflowCode overflow = WRAP)
{
	int start_pos, end_pos;
	bool wrapped = false;
	int wrap_start_pos, wrap_end_pos;

	switch(dir)
	{
		case FORWARD :
			start_pos = start;
			end_pos = start + length - 1;
			break;

		case BACKWARD :
			start_pos = start - length + 1;
			end_pos = start;
			break;

		case MIDDLE_OUT :
			start_pos = start - (length / 2);
			end_pos = (length % 2 == 0) 
						? start + (length / 2) - 1
						: start + (length / 2);
			break;

		default :
			start_pos = 0;
			end_pos = 0;
			break;
	}

	if(start_pos < 0 && end_pos >= NUM_LEDS_)
	{
		start_pos = 0;
		end_pos = NUM_LEDS_;
	}
	else if(end_pos >= NUM_LEDS_)
	{
		switch (overflow)
		{
			case WRAP :
			{
				wrapped = true;
				wrap_start_pos = 0;
				wrap_end_pos = end_pos % NUM_LEDS_;
				end_pos = NUM_LEDS_ - 1;
				break;
			}

			case CUTOFF:
				end_pos = NUM_LEDS_ - 1;
				break;

			default :
				end_pos = NUM_LEDS_ - 1;
				break;
		}
	}
	else if(start_pos < 0)
	{
		switch (overflow)
		{
			case WRAP :
				wrapped = true;
				wrap_start_pos = start_pos % NUM_LEDS_;
				wrap_end_pos = NUM_LEDS_ - 1;
				start_pos = 0;
				break;

			case CUTOFF:
				start_pos = 0;
				break;

			default :
				start_pos = 0;
				break;
		}
	}

	if(wrapped)
	{
		leds_(wrap_start_pos, wrap_end_pos).fill_solid(color);
	}

	leds_(start_pos, end_pos).fill_solid(color);
	
}
*/




