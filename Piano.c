#include <stdint.h>
#include "msp432p401r.h"

void Piano_Init()
{
    // Using multiple ports because these were the only input pins
    // that would work on my MSP432 Board

    // Config P3.0 (Button) XXXX XXX1
    P3SEL0 &= ~0x41; // configure P3.0 as GPIO
    P3SEL1 &= ~0x41; // configure P3.0 as GPIO
    P3DIR &= ~0x41;  // make P3.0 an input

    // Config P5.0 (Button) XXXX XXX1
    P5SEL0 &= ~0x01;
    P5SEL1 &= ~0x01;
    P5DIR &= ~0x01;

    // Config P6.4 (Button) XXX1 XXXX
    P6SEL0 &= ~0x20;
    P6SEL1 &= ~0x20;
    P6DIR &= ~0x20;

}

uint8_t Piano_In()
{
    uint8_t input = 0x00; // Variable meant to return three input bits
                          // Will return 0 if not altered by the following code

    // Checks first button input
    if (P3IN & 0x01) // Equals non-zero value if value at bit P3.0 is 1
    {
        input += 0x01; // Sets 1 to the first bit of input
    }

    if (P5IN & 0x02) // Use 0x02 instead of 0x01 because pressing P5.0 activates 5.1 ?!?!
    {
        input += 0x02; // Sets 1 to the second bit of input
    }

    if (P3IN & 0x40)
    {
        input += 0x04; // Sets 1 to the third bit of input
    }

    return input;
}
