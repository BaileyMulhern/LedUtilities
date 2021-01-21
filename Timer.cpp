#include "Timer.h"


bool Timer::isElapsed()
{
	if(running_)
	{
		elapsed_ = false;
		current_ = millis();

		if(current_ - last_ > interval_)
		{
			elapsed_ = true;

			if(auto_reset_)
			{
				last_ += interval_;
			}
			else
			{
				running_ = false;
			}
		}
	}

	return elapsed_;
}

bool Timer::isRunning()
{
	return running_;
}

void Timer::stop()
{
	running_ = false;
}

void Timer::reset()
{
	running_ = true;
	last_ = millis();
}

void Timer::reset(uint32_t interval)
{
	interval_ = interval;
	reset();
}

float Timer::getPercentElapsed()
{
	return (float)(current_ - last_) / interval_;
}

float Timer::getPercentRemaining()
{
	return 1.0 - (float)(current_ - last_) / interval_;
}