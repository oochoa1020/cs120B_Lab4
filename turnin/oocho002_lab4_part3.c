/*	Author: Gurparamdeep Grewal	
 *  Partner(s) Name: Omar Ochoa
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//#define A0 PINA & 0x01

enum states {wait, begin, press1, unlk} state;

void tick() {

	unsigned char poundSymb = PINA & 0x08; 
	unsigned char lockIn    = PINA & 0x12;
	unsigned char maskFlag  = PINA & 0x28; 
	
	switch(state)
	{ //transitions
		case begin:
			PORTB = 0;
			if(maskFlag == poundSymb){ state = wait;}
			else { state = begin;} 
			break;
		case wait:
			if(maskFlag == poundSymb){ state = wait;}
			else if(maskFlag == 0x02) { state = unlk;}
			else { state = begin;}
			break;
		case press1:
			if(maskFlag == poundSymb){ state = press1;}
			else if(maskFlag == 0x02) { state = begin;}
			else { state = unlck;}
			break;
		case unlk:
			PORTB = 1;
			if(lockIn){ state = begin;}
			else if(maskFlag == poundSymb){ state = press1;}
			else { state = unlk;}
			break;
		default:
			state = begin;
			break;

















/*	unsigned char tmpB = 0x07;
	switch(state) {
		
		case wait:
		{
			if ((~PINA & 0x03) == 0x00) {
				PORTB = tmpB;
                                state = wait;
                                break;
                        }
			else if ((~PINA & 0x03) == 0x03) {
                                state = both;
                                tmpB = 0;
                                PORTB = tmpB;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x01) {
                                state = press0;
				if (tmpB < 9) {
					tmpB = tmpB + 1;
				}
                                PORTB = tmpB;
                                break;
                        }
			else if ((~PINA & 0x03) == 0x02) {
                                state = press1;
                                if (tmpB > 0) {
                                        tmpB = tmpB - 1;
                                }
                                PORTB = tmpB;
                                break;
                        }
		}
		case press0:
		{		
			if ((~PINA & 0x03) == 0x00) {
				PORTB = tmpB;
                                state = wait;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x03) {
                                state = both;
                                tmpB = 0;
                                PORTB = tmpB;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x01) {
				PORTB = tmpB;
                                state = press0;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x02) {
                                state = press1;
                                if (tmpB > 0) {
                                        tmpB = tmpB - 1;
                                }
                                PORTB = tmpB;
                                break;
                        }	
		}
		case press1:
		{	
		        if ((~PINA & 0x03) == 0x00) {
                                PORTB = tmpB;
				state = wait;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x03) {
                                state = both;
                                tmpB = 0;
                                PORTB = tmpB;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x01) {
                                state = press0;
                                if (tmpB < 9) {
                                        tmpB = tmpB + 1;
                                }
                                PORTB = tmpB;
                                break;
                        }
          		else if ((~PINA & 0x03) == 0x02) {
				PORTB = tmpB;
                                state = press1;
                                break;
                        }
		}
		case both:
		{	
		        if ((~PINA & 0x03) == 0x00) {
				PORTB = tmpB;
                                state = wait;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x03) {
				PORTB = tmpB;
                                state = both;
                                break;
                        }
                        else if ((~PINA & 0x03) == 0x01) {
                                state = press0;
                                if (tmpB < 9) {
                                        tmpB = tmpB + 1;
                                }
                                PORTB = tmpB;
                                break;
                        }
          		else if ((~PINA & 0x03) == 0x02) {
                                state = press1;
                                if (tmpB > 0) {
                                        tmpB = tmpB - 1;
                                }
                                PORTB = tmpB;
                                break;
                        }
		}	
		default:
		{
			state = press0;
			break;
		}
	}
	switch(state) {
		case wait:
		{
                        break;
		}
                case press0:
		{
                        break;
		}
                
                case press1:
		{
                        break;
		}
                case both:
		{
                        break;
		}
        }
}
*/

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	state = wait;
//	unsigned char A0 = 0x00;
	while(1) {
//		A0 = PINA & 0x01;
		tick();
	}
    return 1;
}
