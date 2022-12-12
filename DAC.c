#include <stdint.h>
#include "msp432p401r.h"
#include "SysTickInts.h"

uint8_t Data;       // Index variable for the wave array
const uint8_t wave[32] = {
            8,9,11,12,13,14,14,15,15,15,14,
            14,13,12,11,9,8,7,5,4,3,2,
            2,1,1,1,2,2,3,4,5,7
    };

void DAC_Init(void)
{
    // Config P4.0 - P4.3 (LED) XXXX 1111
    P4SEL0 &= ~0x0F; // configure P3.0 as GPIO
    P4SEL1 &= ~0x0F; // configure P3.0 as GPIO
    P4DIR |= 0x0F;   // make P4.0 - P4.3 outputs
    P4OUT |= 0x00;   // initialize with ports off
    Data = 0;        // start wave array at index 0
}

void DAC_Out(void)
{
    P4OUT = wave[Data];
    Data = 0x1F & (Data + 1); // 0,1,2 ... 14,15,0,1,2 ....
}
