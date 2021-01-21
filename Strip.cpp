#include "Strip.h"


uint16_t Strip::first()
{
	return 0;
}

uint16_t Strip::center()
{
	return (mirrored_) ? length_ / 4 : length_ / 2;
}

uint16_t Strip::last()
{
	return (mirrored_) ? length_ / 2 - 1 : length_ - 1;
}

uint16_t Strip::length()
{
	return (mirrored_) ? length_ / 2 : length_;
}

uint16_t Strip::getRandomIndex()
{
	return random16(length());
}

uint16_t Strip::getNormalizedIndex(float pos)
{
	return (uint16_t)(pos * last());
}

void Strip::setAdditive(bool additive)
{
	additive_ = additive;
}

void Strip::setReversed(bool reversed)
{
	reversed_ = reversed;
}

void Strip::setMirrored(bool mirrored)
{
	mirrored_ = mirrored;
}

void Strip::setWrapped(bool wrapped)
{
	wrapped_ = wrapped;
}

void Strip::show()
{
	FastLED.show();
}

void Strip::off()
{
	*leds_ = CRGB::Black;
}

void Strip::clear(CRGB color)
{
	*leds_ = color;
}

void Strip::fade(uint8_t amount)
{
	*leds_->fadeToBlackBy(amount);
}

void Strip::drawPixel(uint16_t index, CRGB color)
{
	if(!wrapped_ && index >= length_)
	{
		return;
	} 
	
	uint16_t effective_length, effective_index;

	effective_length = (mirrored_) ? length_ / 2 : length_;
	effective_index = index % length_;
	effective_index = (reversed_) ? effective_length - effective_index - 1 : effective_index;

	if(index < effective_length)
	{
		if(additive_)
		{
			(*leds_)[effective_index] |= color;

			if(mirrored_)
			{
				(*leds_)[length_ - effective_index - 1] |= color;
			}
		}
		else
		{
			(*leds_)[effective_index] = color;

			if(mirrored_)
			{
				(*leds_)[length_ - effective_index - 1] = color;
			}
		}
	}
}

void Strip::drawPixels(uint16_t index, uint16_t num, CRGB color)
{
	drawPixelsInRange(index, index + num - 1, color);
}

void Strip::drawPixelsInRange(uint16_t start_index, uint16_t end_index, CRGB color)
{
	if(start_index < length_)
	{
		if(end_index >= length_)
		{
			for(int i = start_index; i < length_; i++)
			{
				drawPixel(i, color);
			}
			
			if(wrapped_)
			{
				end_index -= length_;
				for(int i = 0; i <= end_index; i++)
				{
					drawPixel(i, color);
				}
			}
		}
		else
		{
			for(int i = start_index; i <= end_index; i++)
			{
				drawPixel(i, color);
			}
		}
	} 
}

void Strip::drawPixelNormalized(float pos, CRGB color)
{
	drawPixel(getNormalizedIndex(pos), color);
}
void Strip::drawPixelsNormalized(float pos, float percent, CRGB color)
{
	drawPixels(getNormalizedIndex(pos), getNormalizedIndex(pos + percent), color);
}

void Strip::drawPixelsInRange(float start_pos, float end_pos, CRGB color)
{
	drawPixelsInRange(getNormalizedIndex(start_pos), getNormalizedIndex(end_pos), color);
}

void Strip::fillSolid(CRGB color)
{
	if(additive_)
	{
		*leds_ |= color;
	}
	else
	{
		*leds_ = color;
	}
	
}

void Strip::fillRainbow(uint8_t initial_hue)
{
	leds_->fill_rainbow(initial_hue);
}

void Strip::fillRainbow(uint8_t initial_hue, uint8_t delta_hue)
{
	leds_->fill_rainbow(initial_hue, delta_hue);
}

void Strip::fillPalette(uint8_t initial_hue, uint8_t delta_hue, const CRGBPalette16 PALETTE, uint8_t brightness, TBlendType blend_type)
{
	uint8_t index = initial_hue;

	for(int i = 0; i < length(); i++)
	{
		drawPixel(i, ColorFromPalette(PALETTE, index, brightness, blend_type));
		index += delta_hue;
	}	
}