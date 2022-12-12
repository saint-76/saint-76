#include <stdint.h>
#include <string.h>
#include "SysTickInts.h"
#include "DAC.h"
#include "msp432p401r.h"

void Sound_Init(void)  // Values based on chart for notes provided
{
    SysTick_Init(0); // DAC function will not activate when this is set to 0
}

void Sound_Play(uint8_t note)
{
    switch(note)
    {
        case 0x01 :
            SysTick->LOAD = (213); // C 523 Hz
                                   // (3 * (10^6)) / (32 * 523Hz)
                                   // DAC function is activated in SysTick file
         break;
        case 0x02 :
            SysTick->LOAD = (190); // B 494 Hz
         break;
        case 0x03 :
            SysTick->LOAD = (213); // A 440 Hz
         break;
        case 0x04 :
            SysTick->LOAD = (239); // G 392Hz
         break;
        case 0x05 :
            SysTick->LOAD = (269); // F 349 Hz
         break;
        case 0x06 :
            SysTick->LOAD = (284); // E 330 Hz
         break;
        case 0x07 :
            SysTick->LOAD = (318); // D 294 Hz
         break;
        default :
            SysTick->LOAD = 0; // DAC function will never be reached with this value
         break;
     }
}

