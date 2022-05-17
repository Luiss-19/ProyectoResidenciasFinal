// Copyright (C) 2014 Diego Herranz

#include <pic10fregs.h>
#include <delay.h>

// FUSES START
// Minimum modifications needed. Rest of fuses left as default.

//The code generated by SDCC does probably not work when XINST (extended instruction set) is enabled
#pragma config XINST=OFF

// Oscillator Selection bits (Internal oscillator, port function on RA6, EC used by USB (INTIO))
#pragma config FOSC = INTOSCIO_EC

// Watchdog timer OFF
#pragma config WDT = OFF

// Single-Supply ICSP OFF
#pragma config LVP = OFF

// FUSES END

#define LED_LAT LATCbits.LATC0
#define LED_TRIS TRISCbits.TRISC0

void main(void)
{
	LED_TRIS = 0; // Pin as output
	LED_LAT = 0; // LED off
	
	while (1) {
		LED_LAT = !LED_LAT; // Toggle LED
		delay1ktcy(125); //500ms @ 1MHz
	}
}