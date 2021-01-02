#include "MarqueeEffect.h"


void MarqueeEffect::run(CRGB* leds, uint8_t num_leds)
{
	scroll_counter_.update();

    uint8_t total = num_on_ + num_off_;
    uint16_t start = scroll_counter_.getCount();

    if(!smooth_)
    {
        start = (start * num_on_) % total;
    }

    fillSolid(leds, num_leds, CRGB::Black);

    for(int i = 0; i < num_leds; i++)
    {
        for(int j = 0; j < num_on_; j++)
        {
            if(i % total == (start + j) % total)
            {
                leds[i] = color_;
            }
        }
    }
    
}