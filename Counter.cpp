#include "Counter.h"

void Counter::reset()
{
	count_ = 0;
	last_ms_ = millis();
}

bool Counter::tic()
{
	uint64_t ms = millis(); 
    bool overflow_flag = false;

	// If the wait time has elapsed
	if (ms - last_ms_ >= prescaler_)
	{
    
		last_ms_ = ms;
		count_ += step_;

		if (count_ >= max_)
		{
			count_ = overflow_;     
			overflow_flag = true;
		}       
	}
	
	return overflow_flag;
}