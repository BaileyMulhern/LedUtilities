#include "FireEffect.h"


void FireEffect::draw(CRGB* leds, uint8_t num_leds)
{
	// First cool each cell by a little bit
        for (int i = 0; i < size_; i++)
		{
            heat_[i] = max(0L, heat_[i] - random(0, ((cooling_ * 10) / size_) + 2));
		}

        // Next drift heat up and diffuse it a little but
        for (int i = 0; i < size_; i++)
		{
            heat_[i] = (heat_[i] * BLEND_SELF_ + 
                       heat_[(i + 1) % size_] * BLEND_NEIGHBOR_1_ + 
                       heat_[(i + 2) % size_] * BLEND_NEIGHBOR_2_ + 
                       heat_[(i + 3) % size_] * BLEND_NEIGHBOR_3_) 
                      / BLEND_TOTAL;
		}

        // Randomly ignite new sparks down in the flame kernel
        for (int i = 0; i < sparks_; i++)
        {
            if (random(255) < sparking_)
            {
                int y = size_ - 1 - random(spark_height_);
                heat_[y] = heat_[y] + random(160, 255); // This randomly rolls over sometimes of course, and that's essential to the effect
            }
        }

        // Finally convert heat to a color
        for (int i = 0; i < size_; i++)
        {
			CRGB color = HeatColor(heat_[i]);
            int j = reversed_ ? (size_ - 1 - i) : i;
            leds[j] = color;
            if (mirrored_)
            {
                int j2 = !reversed_ ? (2 * size_ - 1 - i) : size_ + i;
                leds[j2] = color;
            }
        }

		delay(50);
	
}