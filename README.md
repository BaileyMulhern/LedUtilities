# LedUtilities

Led Utilities is a library made to be an easy way quickly control and display a 
plethora of lighting effects on your LED strips from an Arduino. Many implementations 
of LED strip effects such as rainbow fades and flashing effects rely on the `delay()` 
function, a blocking function that pauses the Arduino for the desired number of 
milliseconds before resuming. This library provides a non-blocking method to easily 
fit quality LED effects into any Arduino project. This project does utilize the 
FastLED library as a means to control the LED strips and acts as augmentation to 
that library.

There are two primary goals of this library:

- Easy to Implement - going from a blank Arduino file to having a plethora of 
  scrolling effects should be a painless and simple process

- Flexibility & Customization - users should have the ability to create whatever 
  looks and patterns they desire using the expandable framework

## Example Usage

Here is an example program in which the LED strip transitions through the preset 
effect script. In this case, the LED strip displays solid red, solid green, solid
blue, and a fading rainbow, transitioning automatically every 5 seconds between 
the individual effects.

```C++

#define LED_PIN         2
#define NUM_LEDS        24

CRGB leds[NUM_LEDS];

ScriptManager::ScriptElement script[] = {
    /*			EFFECT	   		    			WAIT TIME	MANUAL */
    /*		 	NAME						   MIN SEC MS	SWITCH */		
    {EffectManager::EFFECT_SOLID_RED, 			0, 	5, 	0,	false},
    {EffectManager::EFFECT_SOLID_GREEN,			0, 	5, 	0,	false},
    {EffectManager::EFFECT_SOLID_BLUE,			0, 	5, 	0,	false},
    {EffectManager::EFFECT_RAINBOW_FILL_FAST,	0, 	5,	0,	false},
    /* INSERT ADDITIONAL EFFECTS HERE */
};
ScriptManager scriptManager(leds, NUM_LEDS);

void setup(void)
{
    /* Pin Setup */
    pinMode(LED_PIN, OUTPUT);
    /* FastLED Setup */
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    /* Load Preset Script into ScriptManager*/
    scriptManager.loadScript(script);
}

void loop(void)
{
    /*
     * INSERT ADDITIONAL CODE HERE
     */
	 
    /* Continuously Update Effect */
    scriptManager.runScript();
    /* Display LED strip */
    FastLED.show();
}

```

## Installation

The LedUtilities library can be installed by downloading the repository and placing it within your Arduino project folder. Within your Arduino project, it should be placed in a subfolder named `src` then included in the code using `#include src/LedUtilities` at the top of your .ino file.

## TO-DO

[ ] Provide detailed list of preset effects in README
[ ] Finish adding Doxygen comments throughout project
[ ] Create repository wiki

