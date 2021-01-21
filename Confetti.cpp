#include "Confetti.h"


void Confetti::reset()
{
	strip_->clear();
	glitter_timer_.reset();
	fade_timer_.reset();
}

void Confetti::loop()
{
	random16_add_entropy(random());

	if (fade_timer_.isElapsed()) 
	{
		strip_->fade(FADE_RATE_);
    }

	if(glitter_timer_.isElapsed() && random8() < GLITTER_RATE_)
	{
		uint16_t glitter_index = strip_->getRandomIndex();
		CRGB random_color = ColorFromPalette(PALETTE_, random8());
		strip_->drawPixels(glitter_index, GLITTER_LENGTH_, random_color);
	}
}