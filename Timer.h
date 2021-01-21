#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

/** @class Timer
 *  @brief Simple timer that trips after a given amount of time in milliseconds
 */
class Timer
{
 private:
	
	uint32_t 	interval_;
	uint32_t	current_;
	uint32_t 	last_;
	bool 		auto_reset_;
	bool 		elapsed_;
	bool		running_;

 public:

	static const uint8_t  ONE_MILLISECOND = 		1;
    static const uint8_t  ONE_HUNDREDTH_SECOND =   	10;
	static const uint8_t  ONE_TENTH_SECOND = 		100;
	static const uint8_t  QUARTER_SECOND = 			250;
	static const uint16_t HALF_SECOND = 			500;
	static const uint16_t THREE_QUARTER_SECOND =	750;
	static const uint16_t ONE_SECOND = 				1000;
	static const uint16_t TEN_SECONDS =				10000;
	static const uint16_t THIRTY_SECONDS =			30000;
	static const uint16_t ONE_MINUTE = 				60000;

	Timer(uint32_t interval, bool auto_reset) 
		: interval_(interval), 
		  current_(millis()),
		  last_(millis()),
		  auto_reset_(auto_reset), 
		  elapsed_(false), 
		  running_(false)
	{
	};
	
	bool	isElapsed();
	bool	isRunning();

	void	stop();
	void	reset();
	void	reset(uint32_t interval);

	float 	getPercentElapsed();
	float	getPercentRemaining();

};

#endif //TIMER_H