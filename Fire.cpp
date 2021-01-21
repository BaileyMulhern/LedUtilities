#include "Fire.h"


void Fire::reset()
{
	strip_->clear();
	timer_.reset();
	for(int i = 0; i < strip_->length(); i++)
	{
		heat_[i] = 0;
	}
}

void Fire::loop()
{
	random16_add_entropy(random());

	if (timer_.isElapsed()) {
        // Step 1.  Cool down every cell a little
        for(int i = 0; i < strip_->length(); i++) {
            heat_[i] = qsub8(heat_[i],  random8(0, ((COOLING_RATE_ * 10) / strip_->length()) + 2));
        }
    
        // Step 2.  Heat from each cell drifts 'up' and diffuses a little
        for(int k = strip_->last(); k >= 2; k--) {
            heat_[k] = (heat_[k - 1] + heat_[k - 2] + heat_[k - 2] ) / 3;
        }
        
        // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
        if (random8() < SPARKING_RATE_) {
            int y = random8(7);
            heat_[y] = qadd8(heat_[y], random8(160, 255));
        }

        // Step 4.  Map from heat cells to LED colors
        for( int j = 0; j < strip_->length(); j++) {
            // Scale the heat value from 0-255 down to 0-240
            // for best results with color palettes.
            uint8_t color_index = scale8(heat_[j], 240);
            CRGB color = ColorFromPalette(PALETTE_, color_index);
            strip_->drawPixel(j, color);
        }
    }
}