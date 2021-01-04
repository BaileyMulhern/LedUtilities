#include "EffectManager.h"

void EffectManager::runEffect(EffectPreset preset)
{
    //If the new effect is different from the current effect, set flag
    bool effect_switch = !(preset_ == preset);

    if(effect_switch)
    {
        preset_ = preset;

		switch(preset_)
		{
			case OFF:
				solid_effect_ = SolidEffect();
				effect_ = &solid_effect_;
				break;
			
			case SOLID_RED:
				solid_effect_ = SolidEffect(CRGB::Red);
				effect_ = &solid_effect_;
				break;

			case SOLID_GREEN:
				solid_effect_ = SolidEffect(CRGB::Green);
				effect_ = &solid_effect_;
				break;
			
			case SOLID_BLUE:
				solid_effect_ = SolidEffect(CRGB::Blue);
				effect_ = &solid_effect_;
				break;

			case SOLID_CYAN:
				solid_effect_ = SolidEffect(CRGB::Cyan);
				effect_ = &solid_effect_;
				break;

			case SOLID_MAGENTA:
				solid_effect_ = SolidEffect(CRGB::Magenta);
				effect_ = &solid_effect_;
				break;
			
			case SOLID_YELLOW:
				solid_effect_ = SolidEffect(CRGB::Yellow);
				effect_ = &solid_effect_;
				break;

			case RAINBOW_FILL_SLOW:
				rainbow_effect_ = RainbowEffect(1, 0, Counter::WAIT_QUARTER_SECOND);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_FILL_FAST:
				rainbow_effect_ = RainbowEffect(1, 0, Counter::WAIT_ONE_TWENTIETH_SECOND);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_FADE_SLOW:
				//Fill rainbow with a delta of 5 to make it fade throughout
				rainbow_effect_ = RainbowEffect(1, 5, SLOW);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_FADE_FAST:
				//Fill rainbow with a delta of 5 to make it fade throughout
				rainbow_effect_ = RainbowEffect(1, 5, FAST);
				effect_ = &rainbow_effect_;
				break;
			
			case RAINBOW_EVEN_SLOW:
			{
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ >= RainbowEffect::COUNT_MAX) 
									? 1
									: RainbowEffect::COUNT_MAX / NUM_LEDS_;
				rainbow_effect_ = RainbowEffect(1, delta, SLOW);
				effect_ = &rainbow_effect_;
				break;
			}

			case RAINBOW_EVEN_FAST:
			{
				//Fill rainbow with a delta that makes the rainbow evenly spread throughout
				uint8_t delta = (NUM_LEDS_ >= RainbowEffect::COUNT_MAX) 
									? 1
									: RainbowEffect::COUNT_MAX / NUM_LEDS_;
				rainbow_effect_ = RainbowEffect(1, delta, FAST);
				effect_ = &rainbow_effect_;
				break;
			}

			case THEATRE_CHASE_RED_SLOW:
			{		
				marquee_effect_ = MarqueeEffect(CRGB::Red, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_RED_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Red, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_GREEN_SLOW:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Green, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_GREEN_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Green, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_BLUE_SLOW:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Blue, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_BLUE_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Blue, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_CYAN_SLOW:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Cyan, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_CYAN_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Cyan, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_MAGENTA_SLOW:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Magenta, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_MAGENTA_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Magenta, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_YELLOW_SLOW:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Yellow, 1, 2, SLOW);
				effect_ = &marquee_effect_;
				break;
			}

			case THEATRE_CHASE_YELLOW_FAST:
			{
				marquee_effect_ = MarqueeEffect(CRGB::Yellow, 1, 2, FAST);
				effect_ = &marquee_effect_;
				break;
			}
		}
    }

    effect_->draw(leds_, NUM_LEDS_);
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




