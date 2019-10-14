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
//#define A0 PINA & 0x01

enum states {Release_On, Press_Off, Release_Off, Press_On} state;

void tick() {
	switch(state) {
		case Release_On:
		{		
			if ((PINA & 0x01) == 0x00) {
				state = Release_On;
				PORTB = 0x01;
				break;
			}
			else {
				state = Press_Off;
				PORTB = 0x02;
                                break;
			}
			//state = Press_Off;
		}
		case Press_Off:
		{
			if ((PINA & 0x01) == 0x01) {
                                state = Press_Off;
				PORTB = 0x02;
                                break;
                        }
                        else if ((PINA & 0x01) == 0x00) {
                                state = Release_Off;
				PORTB = 0x02;
                                break;
                        }
		}
		case Release_Off:
		{	
			if ((PINA & 0x01) == 0x00) {
                                state = Release_Off;
				PORTB = 0x02;
                                break;
                        }
                        else if ((PINA & 0x01) == 0x01) {
                                state = Press_On;
				PORTB = 0x01;
                                break;
                        }
		}
		case Press_On:
		{	
			if ((PINA & 0x01) == 0x01) {
                                state = Press_On;
				PORTB = 0x01;
                                break;
                        }
                        else if ((PINA & 0x01) == 0x00) {
                                state = Release_On;
				PORTB = 0x01;	
                                break;
                       }
		}
		default:
		{
			state = Release_On;
			break;
		}
	}
	switch(state) {
                case Release_On:
		{
                        break;
		}
                case Press_Off:
		{
                        break;
		}
                case Release_Off:
		{
                        break;
		}
                case Press_On:
		{
                        break;
		}
        }
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	state = Release_On;
	while(1) {
		tick();
	}
    return 1;
}
