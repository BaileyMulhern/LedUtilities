#include "EffectManager.h"

void EffectManager::runEffect(EffectName effect_name)
{
	//Tick the effect timer	
    counter_.update();
    rainbow_counter_.update();

    //If the new effect is different from the current effect, set flag
    bool effect_switch = !(effect_name_ == effect_name);

    if(effect_switch)
    {
        effect_name_ = effect_name;
		switch(effect_name_)
		{
			case EFFECT_OFF:
				solid_effect_ = SolidEffect();
				effect_ = &solid_effect_;
				break;
			
			case EFFECT_SOLID_RED:
				solid_effect_ = SolidEffect(CRGB::Red);
				effect_ = &solid_effect_;
				break;

			case EFFECT_SOLID_GREEN:
				solid_effect_ = SolidEffect(CRGB::Green);
				effect_ = &solid_effect_;
				break;
			
			case EFFECT_SOLID_BLUE:
				solid_effect_ = SolidEffect(CRGB::Blue);
				effect_ = &solid_effect_;
				break;

			case EFFECT_SOLID_CYAN:
				solid_effect_ = SolidEffect(CRGB::Cyan);
				effect_ = &solid_effect_;
				break;

			case EFFECT_SOLID_MAGENTA:
				solid_effect_ = SolidEffect(CRGB::Magenta);
				effect_ = &solid_effect_;
				break;
			
			case EFFECT_SOLID_YELLOW:
				solid_effect_ = SolidEffect(CRGB::Yellow);
				effect_ = &solid_effect_;
				break;
			/*
			case EFFECT_RAINBOW_FILL_SLOW:
				if(effect_switch)
				{
					initCounterRainbowSlow();
				}
				//Fill the strip with rainbow with a delta of 0 to make it solid
				ledsFillRainbow(rainbow_counter_.getCount(), 0);
				break;
			
			case EFFECT_RAINBOW_FILL_FAST:
				if(effect_switch)
				{
					initCounterRainbowFast();
				}
				//Fill the strip with rainbow with a delta of 0 to make it solid
				ledsFillRainbow(rainbow_counter_.getCount(), 0);
				break;
			
			case EFFECT_RAINBOW_FADE_SLOW:
				if(effect_switch)
				{
					initCounterRainbowSlow();
				}
				//Fill rainbow with a delta of 5 to make it fade throughout
				ledsFillRainbow(rainbow_counter_.getCount(), 5);
				break;
			
			case EFFECT_RAINBOW_FADE_FAST:
				if(effect_switch)
				{
					initCounterRainbowFast();
				}
				//Fill rainbow with a delta of 5 to make it fade throughout
				ledsFillRainbow(rainbow_counter_.getCount(), 5);
				break;
			
			case EFFECT_RAINBOW_EVEN_SLOW:
			{
				if(effect_switch)
				{
					initCounterRainbowSlow();
				}
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ < COUNT_MAX_RAINBOW_) 
									? COUNT_MAX_RAINBOW_ / NUM_LEDS_ 
									: 1;
				ledsFillRainbow(rainbow_counter_.getCount(), delta);
				break;
			}

			case EFFECT_RAINBOW_EVEN_FAST:
			{
				if(effect_switch)
				{
					initCounterRainbowFast();
				}
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ < COUNT_MAX_RAINBOW_) 
									? COUNT_MAX_RAINBOW_ / NUM_LEDS_ 
									: 1;
				ledsFillRainbow(rainbow_counter_.getCount(), delta);
				break;
			}

			case EFFECT_THEATRE_CHASE_RED_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Red, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_RED_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Red, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_GREEN_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Green, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_GREEN_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Green, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_BLUE_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Blue, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_BLUE_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Blue, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_CYAN_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Cyan, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_CYAN_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Cyan, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_MAGENTA_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Magenta, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_MAGENTA_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Magenta, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_YELLOW_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
				}
				
				ledsFillAlternating(CRGB::Yellow, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_YELLOW_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
				}
				
				ledsFillAlternating(CRGB::Yellow, 3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_RAINBOW_FILL_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
					initCounterRainbowSlow();
				}
				
				ledsFillRainbow(rainbow_counter_.getCount(), 0);
				ledsFillAlternating(3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_RAINBOW_FILL_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
					initCounterRainbowFast();
				}
				
				ledsFillRainbow(rainbow_counter_.getCount(), 0);
				ledsFillAlternating(3, counter_.getCount());
				break;
			}
			
			case EFFECT_THEATRE_CHASE_RAINBOW_FADE_SLOW:
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
					initCounterRainbowSlow();
				}
				//Fill rainbow with a delta of 5 to make it fade throughout
				ledsFillRainbow(rainbow_counter_.getCount(), 5);
				ledsFillAlternating(3, counter_.getCount());
				break;
			
			case EFFECT_THEATRE_CHASE_RAINBOW_FADE_FAST:
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
					initCounterRainbowFast();
				}
				//Fill rainbow with a delta of 5 to make it fade throughout
				ledsFillRainbow(rainbow_counter_.getCount(), 5);
				ledsFillAlternating(3, counter_.getCount());
				break;
			
			case EFFECT_THEATRE_CHASE_RAINBOW_EVEN_SLOW:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseSlow();
					initCounterRainbowSlow();
				}
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ < COUNT_MAX_RAINBOW_) 
									? COUNT_MAX_RAINBOW_ / NUM_LEDS_ 
									: 1;
				ledsFillRainbow(rainbow_counter_.getCount(), delta);
				ledsFillAlternating(3, counter_.getCount());
				break;
			}

			case EFFECT_THEATRE_CHASE_RAINBOW_EVEN_FAST:
			{
				if(effect_switch)
				{
					initCounterTheatreChaseFast();
					initCounterRainbowFast();
				}
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ < COUNT_MAX_RAINBOW_) 
									? COUNT_MAX_RAINBOW_ / NUM_LEDS_ 
									: 1;
				ledsFillRainbow(rainbow_counter_.getCount(), delta);
				ledsFillAlternating(3, counter_.getCount());
				break;
			}*/
		}
    }

    effect_->run(leds_, NUM_LEDS_);
}

void EffectManager::initCounterRainbowSlow()
{
    rainbow_counter_ = Counter(0,1,COUNT_MAX_RAINBOW_,0,Counter::WAIT_QUARTER_SECOND);
}


void EffectManager::initCounterRainbowFast()
{
    rainbow_counter_ = Counter(0,1,COUNT_MAX_RAINBOW_,0,Counter::WAIT_ONE_TWENTIETH_SECOND);
}


void EffectManager::initCounterTheatreChaseSlow()
{
    counter_ = Counter(0,1,3,0,Counter::WAIT_QUARTER_SECOND);
}


void EffectManager::initCounterTheatreChaseFast()
{
    counter_ = Counter(0,1,3,0,Counter::WAIT_ONE_TWENTIETH_SECOND);
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

void EffectManager::ledsFillAlternating(int mod, int offset)
{
	for(int i = 0; i < NUM_LEDS_; i++)
	{
        if(i % mod != offset)
        {
            leds_[i] = CRGB::Black;
        }
	}
}

void EffectManager::ledsFillAlternating(CRGB color, int mod, int offset)
{
	for(int i = 0; i < NUM_LEDS_; i++)
	{
		if(i % mod == offset)
        {
            leds_[i] = color;
        }
        else
        {
            leds_[i] = CRGB::Black;
        }
	}
}


void EffectManager::ledsFillRainbow(int hue, int delta)
{
	leds_.fill_rainbow(hue, delta);
}
*/




