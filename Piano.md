Hello!

This project was an implementation from a professor at CSUF and who is fluent in DSPs.
For the following will be snippets from the project description and steps of what is needed to be done to complete the project.
By all means I am not taking credit for the project instructions and the creation of the project. I am just showing the way I have completed the project
and my set of code for the completion of the project. This will also entitle you to create a circuit that I will not be showing as this is the sole purpose of the code
I created to demonstrate the functionality of the project.

_**System Requirements**_

**Step 1**

Most digital music devices rely on high-speed DAC converters to create the analog waveforms required to produce high-quality sound. 
In this lab, you will create a very simple sound generation system that illustrates this application of the DAC.
Your goal is to create an embedded system that plays three notes, which will be a digital piano with three keys.
The first step is to design and test a 4-bit binary-weighted DAC, which converts 4-bits of digital output from the MSP432 to an analog signal. 
You will convert the four digital bits to an analog output using a simple resistor network.
During the static testing phase, you will connect the DAC analog output to your voltmeter and measure resolution, range, precision and accuracy (Figure 1, left).
During the dynamic testing phase you will connect the DAC output to headphones, and listen to sounds created by your software (Figure 1, right). 
It doesn’t matter what range the DAC is, as long as there is an approximate linear relationship between the digital data and the speaker current.
The performance score of this lab is not based on loudness, but sound quality. The quality of the music will depend on both hardware and software factors.
The precision of the DAC, external noise, and the dynamic range of the speaker are some of the hardware factors.
Software factors include the DAC output rate and the number of data points stored in the sound data. 
You can create a 3k resistor from two 1.5k resistors. You can create a 6k resistor from two 12k resistors.
 
![image](https://user-images.githubusercontent.com/76075833/206940796-35a6063b-1951-450c-8a81-40e54e95bd8d.png)

Figure 1: DAC allows the software to create music.

**Step 2**

The second step is to design a low-level device driver for the DAC. Remember, the goal of a device driver is to separate what the device does from how it works. “What it does” means the general descriptions and function prototypes of DAC_Init and DAC_Out that are placed in DAC.h. “How it works” means the implementations of DAC_Init and DAC_Out that will be placed in DAC.c. 

**Step 3**

The third step is to design a low-level device driver for the three keys of the piano. For example, if you could create public functions Piano_Init and Piano_In, where Piano_In returns a logical key code for the pattern of keys that are pressed. You may design this driver however you wish, but the goal is to abstract the details of how it works (which port, which pin) from what it does (which key pressed). 

**Step 4**

The fourth step is to organize the sound generation software into a device driver. You will need a data structure to store the sound waveform. You are free to design your own format, as long as it uses a formal data structure. Although you will be playing only three notes, the design should allow additional notes to be added with minimal effort. For example, you could create public functions Sound_Init and Sound_Play(note), where the parameter note specifies the frequency (pitch) of the sound. Calling Sound_Play(Off) makes it silent and calling Sound_Play(C) plays the note C. A background thread within the sound driver implemented with SysTick interrupts (see “EGCP_450_Lab_6.zip”) will fetch data out of your music structure and send them to the DAC. 

**Step 5**

The last step is to write a main program that links the modules together creating the digital piano.
