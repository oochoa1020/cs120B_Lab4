/*	Author: oocho002
 *  Partner(s) Name: Gurparam
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned int tmpC = 0;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char curA = 0x00;
	while(1) {
		tmpA = PINA & 0xFF;
		curA = tmpA & 0x01;
		tmpC = 0;
		tmpB = 0;
		if (curA == 0x01) {
			tmpC = tmpC + 16;
		}
		curA = tmpA & 0x02;
                if (curA == 0x02) {
			tmpC = tmpC + 32;
		}
		curA = tmpA & 0x04;
                if (curA == 0x04) {
			tmpC = tmpC + 64;
		}
		curA = tmpA & 0x08;
                if (curA == 0x08) {
			tmpC = tmpC + 128;
		}
		curA = tmpA & 0x10;
		if (curA == 0x10) {
                        tmpB = tmpB + 1;
                }
                curA = tmpA & 0x20;
                if (curA == 0x20) {
                        tmpB = tmpB + 2;
                }
                curA = tmpA & 0x40;
                if (curA == 0x40) {
                        tmpB = tmpB + 4;
                }
                curA = tmpA & 0x80;
                if (curA == 0x80) {
                        tmpB = tmpB + 8;
                }
		
		PORTB = tmpB;
		PORTC = tmpC;
	}
    return 1;
}
