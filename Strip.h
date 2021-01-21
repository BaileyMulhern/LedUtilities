#ifndef STRIP_H
#define STRIP_H

#include <Arduino.h>
#include <FastLED.h>

/** @class Strip
 *  @brief Abstraction for the LED strip drawing
 */
class Strip
{
 private:

	CRGBSet		*leds_;
	uint16_t	length_;
	bool		additive_;
	bool		reversed_;
	bool		mirrored_;
	bool		wrapped_;

 public:

	Strip(CRGBSet* leds, bool additive = false, bool reversed = false, bool mirrored = false, bool wrapped = false) 
		: leds_(leds),
		  length_(leds->size()),
		  additive_(additive),
		  reversed_(reversed),
		  mirrored_(mirrored),
		  wrapped_(wrapped)
	{
	};

	uint16_t first();
	uint16_t center();
	uint16_t last();
	uint16_t length();
	
	uint16_t getRandomIndex();
	uint16_t getNormalizedIndex(float pos);
	
	void setAdditive(bool additive);
	void setReversed(bool reversed);
	void setMirrored(bool mirrored);
	void setWrapped(bool wrapped);

	void show();
	void off();
	void clear(CRGB color = CRGB::Black);
	void fade(uint8_t amount);

	void drawPixel(uint16_t index, CRGB color);
	void drawPixels(uint16_t index, uint16_t num, CRGB color);
	void drawPixelsInRange(uint16_t start_index, uint16_t end_index, CRGB color);
	void drawPixelNormalized(float pos, CRGB color);
	void drawPixelsNormalized(float pos, float percent, CRGB color);
	void drawPixelsInRange(float start_pos, float end_pos, CRGB color);

	void fillSolid(CRGB color);
	void fillRainbow(uint8_t initial_hue);
	void fillRainbow(uint8_t initial_hue, uint8_t delta_hue);
	void fillPalette(uint8_t initial_hue, uint8_t delta_hue, const CRGBPalette16 PALETTE, uint8_t brightness, TBlendType blend_type);

};

#endif //STRIP_H