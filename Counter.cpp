#include "Counter.h"

uint16_t Counter::count()
{
	return count_;
}

bool Counter::step()
{
	if(enabled_)
	{
		switch (direction_)
		{
			case INCREMENT:
				increment(step_);
				break;

			case DECREMENT:
				decrement(step_);
				break;

			default:
				break;
		}
	}
	
	return overflowed_;
}

bool Counter::increment(uint16_t step)
{
	if(count_ >= max_ - step)
	{
		count_ = (wrap_) ? (count_ + step - max_) : max_ - 1;
		overflowed_ = true;
	}
	else
	{
		count_ += step;
		overflowed_ = false;
	}
	
	return overflowed_; 
}

bool Counter::decrement(uint16_t step)
{
	if(count_ < step)
	{
		count_ = (wrap_) ? (count_ + max_ - step) : 0;
		overflowed_ = true;
	}
	else
	{
		count_ -= step_;
		overflowed_ = false;
	}

	return overflowed_;
}

void Counter::enable()
{
	enabled_ = true;
}

void Counter::disable()
{
	enabled_ = false;
}

void Counter::clear()
{
	count_ = 0;
	overflowed_ = false;
}

void Counter::reset()
{
	count_ = (direction_ == INCREMENT) ? 0 : max_ - 1;
	enabled_ = true;
	overflowed_ = false;
}

void Counter::reset(uint16_t count)
{
	count_ = count;
	enabled_ = true;
	overflowed_ = false;
}