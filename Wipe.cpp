#include "Wipe.h"


void Wipe::reset()
{
	strip_->clear();
	counter_.reset();
	timer_.reset();
	scroll_position_ = 0;
}

void Wipe::loop()
{
	if(timer_.isElapsed())
	{
		if(counter_.step())
		{
			palette_index_ += 16;
		}
	}

	scroll_position_ = counter_.count();
	
	strip_->drawPixelsInRange(0, scroll_position_, ColorFromPalette(PALETTE_, palette_index_, 255, NOBLEND));
}