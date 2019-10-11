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

enum LED_States {Press_On, Release_On, Press_Off, Release_Off} LED_State;

void tick() {
	switch(LED_State) {
		case Release_On:
			if (!A0) {
				LED_State = Release_On;
			}
			else if (A0) {
				LED_State = Press_Off;
			}
			break;
		case Press_Off:
			break;
		case Release_Off:
			break;
		case Press_Off:
			break;
		default:
			LED_State = Release_On;
			break
	}
	switch(LED_State) {
                case Release_On:
                        break;
                case Press_Off:
                        break;
                case Release_Off:
                        break;
                case Press_Off:
                        break;
                default:
                        break
        }
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned int tmpC = 0;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char curA = 0x00;
	while(1) {

	}
    return 1;
}
