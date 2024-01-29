#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#include <xc.h>

#define _XTAL_FREQ 20000000 // Using 20MHz Crystal


void initializePorts(void) {
    TRISB = 0x00; 
    TRISC = 0x00; 
    TRISD = 0x00; 
    TRISE = 0x00; 
    TRISA = 0x00; 
}

void turnOnAllLEDs(char *port) {
    *port = 0xFF; 
}
void turnOffAllLEDs(char *port) {
    *port = 0x00; 
}

void main(void) {
    char *portB = &PORTB;
    char *portC = &PORTC;
    char *portD = &PORTD;
    char *portE = &PORTE;
    char *portA = &PORTA;

    initializePorts();
    
    while(1) {
        turnOnAllLEDs(portB);
        turnOnAllLEDs(portC);
        turnOnAllLEDs(portD);
        turnOnAllLEDs(portE);
        turnOnAllLEDs(portA);
        __delay_ms(500); 
        
        turnOffAllLEDs(portB);
        turnOffAllLEDs(portC);
        turnOffAllLEDs(portD);
        turnOffAllLEDs(portE);
        turnOffAllLEDs(portA);
        __delay_ms(100); // Delay of 100ms
    }
}
