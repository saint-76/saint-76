#include <stdint.h>
#include <string.h>
#include "msp432p401r.h"
#include "DAC.h"
#include "Piano.h"
#include "Sound.h"
#include "SysTickInts.h"


void main(void)
{
    uint8_t note = 0; // Input variable for buttons

    Piano_Init();  // Initialize buttons
    Sound_Init(); // Initialize with DAC outputting nothing

    while(1)
    {
            note = Piano_In(); // Get input from buttons

            if (note != 0)
            {
                Sound_Play(note); // Will set timer to set pitch for DAC output
            }
            else
            {
                Sound_Play(0); // Will set the DAC to output nothing
            }
    }
}
