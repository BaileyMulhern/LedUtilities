#include "Fade.h"


void Fade::reset()
{
	strip_->clear();
	counter_.reset(initial_hue_);
	timer_.reset();
}

void Fade::loop()
{
	if(timer_.isElapsed())
	{
		counter_.step();
	}

	strip_->fillPalette(counter_.count(), delta_hue_, PALETTE_, 255, LINEARBLEND);	
}