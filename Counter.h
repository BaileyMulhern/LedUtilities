#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>
#include <Arduino.h>

#define NO_WAIT		0

class Counter
{

 public:

	static const uint64_t PRESCALER_ONE_MILLISECOND = 			1;
	static const uint64_t PRESCALER_ONE_TWENTIETH_SECOND = 		50;
	static const uint64_t PRESCALER_ONE_TENTH_SECOND = 			100;
	static const uint64_t PRESCALER_QUARTER_SECOND = 			250;
	static const uint64_t PRESCALER_HALF_SECOND = 				500;
	static const uint64_t PRESCALER_THREE_QUARTER_SECOND = 		750;
	static const uint64_t PRESCALER_ONE_SECOND = 				1000;
	static const uint64_t PRESCALER_TEN_SECONDS =				10000;
	static const uint64_t PRESCALER_THIRTY_SECONDS =			30000;
	static const uint64_t PRESCALER_ONE_MINUTE = 				60000;
	static const uint64_t PRESCALER_FIVE_MINUTES =				300000;
	static const uint64_t PRESCALER_ONE_HOUR = 					3600000;

	
	//Default constructor
	Counter() 
		: count_(0), 
		  step_(0), 
		  max_(0), 
		  overflow_(0), 
		  prescaler_(0),
		  last_ms_(millis()) {
	};

	Counter(uint64_t prescaler) 
		: count_(0), 
		  step_(1), 
		  max_(1), 
		  overflow_(0), 
		  prescaler_(prescaler),
		  last_ms_(millis()) {
	};

	Counter(uint32_t count, uint32_t step, uint32_t max, uint32_t overflow, uint64_t prescaler)
		: count_(count), 
		  step_(step), 
		  max_(max), 
		  overflow_(overflow), 
		  prescaler_(prescaler),
		  last_ms_(millis()) {
	};
	
	~Counter() {
	};
	
	uint32_t getCount() { return count_; };
	
	uint32_t getStep() { return step_; };
	
	uint32_t getMax() { return max_; };
	
	uint32_t getOverflow() { return overflow_; };

	uint64_t getPrescaler() { return prescaler_; };

	void setPrescaler(uint64_t prescaler) { prescaler_ = prescaler; };
	
	void reset();
	
	bool tic();
  	
 private:
	
	uint32_t count_;
	
	uint32_t step_;
	
	uint32_t max_;
	
	uint32_t overflow_;

	uint64_t prescaler_;
	
	uint64_t last_ms_;

};

#endif //COUNTER
