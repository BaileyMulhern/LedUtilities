#ifndef EEPROM_ADDRESS_H
#define EEPROM_ADDRESS_H

#include <Arduino.h>
#include <EEPROM.h>

typedef enum 
{
    EEPROM_EFFECT = 0,
    EEPROM_COLOR
    
} EepromAddress;

#endif //EEPROM_ADDRESS_H