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
	static const uint8_t  WAIT_ONE_MILLISECOND = 		1;
	static const uint8_t  WAIT_ONE_TWENTIETH_SECOND = 	50;
	static const uint8_t  WAIT_ONE_TENTH_SECOND = 		100;
	static const uint8_t  WAIT_QUARTER_SECOND = 		250;
	static const uint16_t WAIT_HALF_SECOND = 			500;
	static const uint16_t WAIT_THREE_QUARTER_SECOND = 	750;
	static const uint16_t WAIT_ONE_SECOND = 			1000;
	static const uint16_t WAIT_TEN_SECONDS =			10000;
	static const uint16_t WAIT_THIRTY_SECONDS =			30000;
	static const uint16_t WAIT_ONE_MINUTE = 			60000;
	static const uint32_t WAIT_FIVE_MINUTES =			300000;
	static const uint32_t WAIT_ONE_HOUR = 				3600000;

	
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
	Counter(uint32_t wait) 
		: count_(0), 
		  step_(1), 
		  max_(1), 
		  overflow_(0), 
		  wait_(wait),
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
	Counter(uint16_t count, uint16_t step, uint16_t max, uint16_t overflow, uint32_t wait)
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
	uint16_t getCount() { return count_; };
	
	uint16_t getStep() { return step_; };
	
	uint16_t getMax() { return max_; };
	
	uint16_t getOverflow() { return overflow_; };

	uint32_t getWait() { return wait_; };

	void setWait(uint32_t wait) { wait_ = wait; };
	
	void reset();
	
	bool update();
  	
 private:
	
	uint16_t count_;
	
	uint16_t step_;
	
	uint16_t max_;
	
	uint16_t overflow_;

	uint32_t wait_;
	
	uint32_t last_ms_;

};

#endif //COUNTER
