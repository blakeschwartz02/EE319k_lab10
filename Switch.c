// Switch.c
// This software to input from switches or buttons
// Runs on TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 1/14/21
// Lab number: 10
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data


void PortE_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x10; // Port E
	
	__asm__ {
		NOP
		NOP
	}
	
	GPIO_PORTE_DIR_R &= ~(0x07); //PE0-2 = inputs
	GPIO_PORTE_DEN_R |= 0x07;
	
	GPIO_PORTE_PDR_R |= 0x03; // pull down for PE0-1

}

uint32_t PortE_In(void){ 
  // write this
	uint8_t SwitIn = GPIO_PORTE_DATA_R;
	SwitIn &= 0x03; // mask off bits used
	return SwitIn;
}

