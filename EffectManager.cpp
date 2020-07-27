#include "EffectManager.h"

void EffectManager::runEffect(Effect effect)
{
	//Tick the effect timer	
    counter_.tic();
    rainbow_counter_.tic();

    //If the new effect is different from the current effect, set flag
    bool effect_switch = !(effect_ == effect);

    switch(effect)
    {
        case EFFECT_OFF:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Black;
                ledsFillSolid(CRGB::Black);
                initCounterSolid();
            }
            break;
        
        case EFFECT_SOLID_RED:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Red;
                ledsFillSolid(CRGB::Red);
                initCounterSolid();
            }
            break;

        case EFFECT_SOLID_GREEN:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Green;
                ledsFillSolid(CRGB::Green);
                initCounterSolid();
            }
            break;
        
        case EFFECT_SOLID_BLUE:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Blue;
                ledsFillSolid(CRGB::Blue);
                initCounterSolid();
            }
            break;

        case EFFECT_SOLID_CYAN:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Cyan;
                ledsFillSolid(CRGB::Cyan);
                initCounterSolid();
            }
            break;

        case EFFECT_SOLID_MAGENTA:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Magenta;
                ledsFillSolid(CRGB::Magenta);
                initCounterSolid();
            }
            break;
        
        case EFFECT_SOLID_YELLOW:
            if(effect_switch)
            {
                effect_ = effect;
                color_ = CRGB::Yellow;
                ledsFillSolid(CRGB::Yellow);
                initCounterSolid();
            }
            break;

        case EFFECT_RAINBOW_FILL_SLOW:
            if(effect_switch)
            {
                effect_ = effect;
                initCounterRainbowSlow();
            }
            //Fill the strip with rainbow with a delta of 0 to make it solid
            ledsFillRainbow(rainbow_counter_.getCount(), 0);
            break;
        
        case EFFECT_RAINBOW_FILL_FAST:
            if(effect_switch)
            {
                effect_ = effect;
                initCounterRainbowFast();
            }
            //Fill the strip with rainbow with a delta of 0 to make it solid
            ledsFillRainbow(rainbow_counter_.getCount(), 0);
            break;
        
        case EFFECT_RAINBOW_FADE_SLOW:
            if(effect_switch)
            {
                effect_ = effect;
                initCounterRainbowSlow();
            }
            //Fill rainbow with a delta of 5 to make it fade throughout
            ledsFillRainbow(rainbow_counter_.getCount(), 5);
            break;
        
        case EFFECT_RAINBOW_FADE_FAST:
            if(effect_switch)
            {
                effect_ = effect;
                initCounterRainbowFast();
            }
            //Fill rainbow with a delta of 5 to make it fade throughout
            ledsFillRainbow(rainbow_counter_.getCount(), 5);
            break;
        
        case EFFECT_RAINBOW_EVEN_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
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
                effect_ = effect;
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
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Red, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_RED_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Red, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_GREEN_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Green, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_GREEN_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Green, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_BLUE_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Blue, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_BLUE_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Blue, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_CYAN_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Cyan, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_CYAN_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Cyan, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_MAGENTA_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Magenta, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_MAGENTA_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Magenta, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_YELLOW_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseSlow();
            }
            
            ledsFillAlternating(CRGB::Yellow, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_YELLOW_FAST:
        {
            if(effect_switch)
            {
                effect_ = effect;
                initCounterTheatreChaseFast();
            }
            
            ledsFillAlternating(CRGB::Yellow, 3, counter_.getCount());
            break;
        }

        case EFFECT_THEATRE_CHASE_RAINBOW_FILL_SLOW:
        {
            if(effect_switch)
            {
                effect_ = effect;
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
                effect_ = effect;
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
                effect_ = effect;
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
                effect_ = effect;
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
                effect_ = effect;
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
                effect_ = effect;
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
        }
    }
}


void EffectManager::loadEffectEeprom()
{
    last_effect_eeprom_ = EEPROM.read(EepromAddress::EEPROM_EFFECT);

    if(last_effect_eeprom_ < 0 || last_effect_eeprom_ >= Effect::EFFECT_NUM_EFFECTS)
    {
        last_effect_eeprom_ = EFFECT_OFF;
    }
}


void EffectManager::saveEffectEeprom()
{
    if(effect_ != last_effect_eeprom_)
    {
        last_effect_eeprom_ = effect_;
        EEPROM.write(EepromAddress::EEPROM_EFFECT, last_effect_eeprom_);
    }
}


void EffectManager::initCounterSolid()
{
    counter_ = Counter(0,0,0,0,0);
}


void EffectManager::initCounterRainbowSlow()
{
    rainbow_counter_ = Counter(0,1,COUNT_MAX_RAINBOW_,0,Counter::PRESCALER_QUARTER_SECOND);
}


void EffectManager::initCounterRainbowFast()
{
    rainbow_counter_ = Counter(0,1,COUNT_MAX_RAINBOW_,0,Counter::PRESCALER_ONE_TWENTIETH_SECOND);
}


void EffectManager::initCounterTheatreChaseSlow()
{
    counter_ = Counter(0,1,3,0,Counter::PRESCALER_QUARTER_SECOND);
}


void EffectManager::initCounterTheatreChaseFast()
{
    counter_ = Counter(0,1,3,0,Counter::PRESCALER_ONE_TWENTIETH_SECOND);
}


void EffectManager::ledsFillSolid(CRGB color)
{
	leds_.fill_solid(color);
}


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





