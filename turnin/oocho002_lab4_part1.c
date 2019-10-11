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

enum LED_States {Press_On, Release_On, Press_Off, Release_Off} LED_State;

void tick() {
	unsigned char A0 = 0x00;
	switch(LED_State) {
		case Release_On:
			A0 = PINA & 0x01;
			if (!A0) {
				LED_State = Release_On;
			}
			else if (A0) {
				LED_State = Press_Off;
			}
			break;
		case Press_Off:
			A0 = PINA & 0x01;
			if (A0) {
                                LED_State = Press_Off;
                        }
                        else if (!A0) {
                                LED_State = Release_Off;
                        }
			break;
		case Release_Off:
			A0 = PINA & 0x01;
			if (!A0) {
                                LED_State = Release_Off;
                        }
                        else if (A0) {
                                LED_State = Press_On;
                        }
			break;
		case Press_On:
			A0 = PINA & 0x01;
			if (A0) {
                                LED_State = Press_On;
                        }
                        else if (!A0) {
                                LED_State = Release_On;
                        }
			break;
		default:
			LED_State = Release_On;
			break;
	}
	switch(LED_State) {
                case Release_On:
			PORTB = 0x01;
                        break;
                case Press_Off:
			PORTB = 0x02;
                        break;
                case Release_Off:
			PORTB = 0x02;
                        break;
                case Press_On:
			PORTB = 0x01;
                        break;
        }
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
//	unsigned char A0 = 0x00;
	while(1) {
//		A0 = PINA & 0x01;
		tick();
	}
    return 1;
}
