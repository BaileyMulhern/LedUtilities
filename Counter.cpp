#include "Counter.h"


void Counter::reset()
{
	count_ = 0;
	last_ms_ = millis();
}

bool Counter::update()
{
    bool overflow_flag = false;
	uint64_t ms = millis(); 

    if(wait_ == 5000 || wait_ == 5)
    {
        Serial.println(wait_);
        Serial.println((long)ms);
        Serial.println(last_ms_);
    }

	// If the wait time has elapsed
	if (ms - last_ms_ >= wait_)
	{
    
		last_ms_ = ms;
		count_ += step_;

		// Set counter back to the overflow_ value
		if (count_ > max_)
		{
			count_ = overflow_;     
			overflow_flag = true;
		}       
	}
	
	// Return true if the timer overflowed
	return overflow_flag;
}