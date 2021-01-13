#ifndef FIRE_EFFECT_H
#define FIRE_EFFECT_H

#include <FastLED.h>

#include "Effect.h"
#include "LedHelpers.h"

/** @class FireEffect
 *  @brief asdf
 *
 */
class FireEffect : public Effect
{
  public:

	FireEffect()
		: size_(0),
          cooling_(80),
          sparks_(3),
          sparking_(50),
          spark_height_(4),
		  reversed_(false),
          mirrored_(false),
		  Effect()
	{
	};

    FireEffect(uint8_t size, uint8_t cooling = 55, uint8_t sparks = 20, uint8_t sparking = 120, uint8_t spark_height = 5, 
				bool reversed = false, bool mirrored = true)
		: size_(size),
          cooling_(cooling),
          sparks_(sparks),
          sparking_(sparking),
		  spark_height_(spark_height),
          reversed_(reversed),
          mirrored_(mirrored),
		  Effect()
	{
		if (mirrored_)
            size_ /= 2;

        heat_ = new byte[size_] { 0 };
	};

	~FireEffect()          
    {
        delete [] heat_;
    }

    void draw(CRGB* leds, uint8_t num_leds);

  private:

	uint8_t size_;
    uint8_t cooling_;
    uint8_t sparks_;
    uint8_t sparking_;
	uint8_t spark_height_;
    bool    reversed_;
    bool    mirrored_;

    byte* 	heat_;

    // When diffusing the fire upwards, these control how much to blend in from the cells below (ie: downward neighbors)
    // You can tune these coefficients to control how quickly and smoothly the fire spreads.  

    static const byte BLEND_SELF_ = 2;
    static const byte BLEND_NEIGHBOR_1_ = 3;
    static const byte BLEND_NEIGHBOR_2_ = 2;
    static const byte BLEND_NEIGHBOR_3_ = 1;
    static const byte BLEND_TOTAL = (BLEND_SELF_ + BLEND_NEIGHBOR_1_ + BLEND_NEIGHBOR_2_ + BLEND_NEIGHBOR_3_);
	
};

#endif //FIRE_EFFECT