# Lab1-Embedded-System-Development

# Checkpoint-1

## Source code and proteus Design:

- Source code for checkpoint 1 -> ..\checkpoint-1\Mplab-code\main_function
- proteus design for Checkpoint 1 ->  ..\Proteus design\blink LED

## ScreenShoot For checkpoint-1

![Screenshot (31)](https://github.com/rwema3/Lab1-Embedded-System-Development/assets/52289151/28bca9f8-9095-4c64-a712-889340d37bec)

# Checkpoint-2

## Source code and proteus Design:

- Source code for checkpoint 1 -> ..\checkpoint-1\Mplab-code\checkpoint_2
- proteus design for Checkpoint 1 ->  ..\Proteus design\blink LED\check_2

## ScreenShoot For checkpoint-2

![Screenshot (33)](https://github.com/rwema3/Lab1-Embedded-System-Development/assets/52289151/88c155b9-4248-4ce9-afb5-5df662ccbb5f)

-------


### Checkpoint-1

```c
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
```

Checkpoint-2

```c
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#include <xc.h>

#define BUTTON_PRESSED 0

// Function to check the button state and toggle LED accordingly
void toggleLED(int *buttonState) {
    if (PORTCbits.RC0 == BUTTON_PRESSED) {
        // Button is pressed
        *buttonState = !(*buttonState);  // Toggle button state
    }

    // Check the button state and set the LED accordingly
    if (*buttonState == 1) {
        PORTBbits.RB0 = 1; // Set RB0 high
    } else {
        PORTBbits.RB0 = 0; // Set RB0 low
    }
}

void main() {
    TRISBbits.TRISB0 = 0; // Set RB0 as an output
    TRISCbits.TRISC0 = 1; // Set RC0 as an input

    int buttonState = 0;  // Variable to track button state

    while(1) {
        toggleLED(&buttonState);  // Call the function to handle button state and LED
    }    
}
```
