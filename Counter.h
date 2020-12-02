#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>
#include <Arduino.h>

/** @class Counter
 *  @brief Simple counter that increments at preset intervals
 * 
 * 	By calling tic() every update, the counter will increment by the step size every
 * 	interval as given by the prescaler value. Using a value of NO_WAIT will increment 
 * 	the timer upon every call of tic().
 *
 */
class Counter
{

 public:

	static const uint8_t  WAIT_NONE =					0;
	static const uint64_t WAIT_ONE_MILLISECOND = 		1;
	static const uint64_t WAIT_ONE_TWENTIETH_SECOND = 	50;
	static const uint64_t WAIT_ONE_TENTH_SECOND = 		100;
	static const uint64_t WAIT_QUARTER_SECOND = 		250;
	static const uint64_t WAIT_HALF_SECOND = 			500;
	static const uint64_t WAIT_THREE_QUARTER_SECOND = 	750;
	static const uint64_t WAIT_ONE_SECOND = 			1000;
	static const uint64_t WAIT_TEN_SECONDS =			10000;
	static const uint64_t WAIT_THIRTY_SECONDS =			30000;
	static const uint64_t WAIT_ONE_MINUTE = 			60000;
	static const uint64_t WAIT_FIVE_MINUTES =			300000;
	static const uint64_t WAIT_ONE_HOUR = 				3600000;

	
	/**
	 * Default Counter Constructor
	 * Sets the counter to a single increment counter that will increment each
	 * call of update()
	 */
	Counter() 
		: count_(0), 
		  step_(1), 
		  max_(1), 
		  overflow_(0), 
		  wait_(WAIT_NONE),
		  last_ms_(millis()) {
	};

	/**
	 * Counter Constructor
	 * Sets the counter to the default counter with the given delay time
	 * @param wait delay in milliseconds between each increment/decrement of the counter
	 */
	Counter(uint64_t wait) 
		: count_(0), 
		  step_(1), 
		  max_(1), 
		  overflow_(0), 
		  wait_(wait)
		  last_ms_(millis()) {
	};

	/**
	 * Counter Constructor
	 * Sets the counter to the given parameters
	 * @param count 	intial value of the Counter
	 * @param step 		the value by which to increment/decrement the counter
	 * @param max		value at which the counter which overflow once reached
	 * @param overflow	value taken by the counter once it reaches max and overflows
	 * @param wait 		delay in milliseconds between each increment/decrement of the counter
	 */
	Counter(uint32_t count, uint32_t step, uint32_t max, uint32_t overflow, uint64_t wait)
		: count_(count), 
		  step_(step), 
		  max_(max), 
		  overflow_(overflow), 
		  wait_(wait),
		  last_ms_(millis()) {
	};
	
	/**
	 * Counter Deconstructor
	 * Destroys the Counter object
	 */
	~Counter() {
	};
	
	/**
	 * Get method for count_
	 * @return 
	 */
	uint32_t getCount() { return count_; };
	
	uint32_t getStep() { return step_; };
	
	uint32_t getMax() { return max_; };
	
	uint32_t getOverflow() { return overflow_; };

	uint64_t getWait() { return wait_; };

	void setWait(uint64_t wait) { wait_ = wait; };
	
	void reset();
	
	bool update();
  	
 private:
	
	uint32_t count_;
	
	uint32_t step_;
	
	uint32_t max_;
	
	uint32_t overflow_;

	uint64_t wait_;
	
	uint64_t last_ms_;

};

#endif //COUNTER
