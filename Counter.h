#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>
#include <Arduino.h>

/** @class Counter
 *  @brief Simple counter that increments at preset intervals
 */
class Counter
{
 private:
	
	typedef enum {
		INCREMENT,
		DECREMENT,
	} Direction;

	uint16_t 	count_;
	uint16_t 	step_;
	uint16_t	max_;
	Direction	direction_;
	bool		enabled_;
	bool		wrap_;
	bool		overflowed_;

 public:

	/**
	 * Counter Constructor
	 * Sets the counter to the given parameters
	 * @param count 	intial value of the Counter
	 * @param step 		the value by which to increment/decrement the counter
	 * @param max		value at which the counter which overflow once reached
	 * @param direction	whether the counter is to increment from 0 or decrement from max
	 * @param wrap		Whether or not the counter is to wrap around by default
	 */
	Counter(uint16_t max, uint16_t count = 0, uint16_t step = 1, Direction direction = INCREMENT, bool wrap = true)
		: max_(max),
		  count_(count), 
		  step_(step), 
		  direction_(direction),
		  enabled_(true),
		  wrap_(wrap),
		  overflowed_(false)
	{
	};

	uint16_t count();
	
	bool step();
	bool increment(uint16_t step = 1);
	bool decrement(uint16_t step = 1);
	void enable();
	void disable();
	void clear();
	void reset();
	void reset(uint16_t count);
};

#endif //COUNTER_H
