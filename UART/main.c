

/**
 * main.c
 */
#include "tm4c123gh6pm.h"
#include <stdint.h>

char readChar(void);
void printChar(char);
void printString(char * string);
void init_port(void);
void delay(unsigned long);

int main(void)
{
    char c;
    init_port();
    while(1){
        printString("Enter \"r\",\"g\" or \"b\" :\n\r");
        delay(5000000);
        c = readChar();
        printChar(c);
        printString("\n\r");
        switch(c){
        case 'r':
            GPIO_PORTF_DATA_R = (1<<1);
        break;
        case 'b':
             GPIO_PORTF_DATA_R = (1<<2);
        break;
        case 'g':
             GPIO_PORTF_DATA_R = (1<<3);
        break;
        default:
            GPIO_PORTF_DATA_R = 0x00;
        }
    }
	return 0;
}

void delay(unsigned long n){
    volatile long i;
    for(i=0;i<n;i++);
}

void init_port(){
    SYSCTL_RCGCUART_R |= (1<<0);
    SYSCTL_RCGCGPIO_R |= (1<<0);
    GPIO_PORTA_AFSEL_R |= (1<<0) | (1<<1);
    GPIO_PORTA_PCTL_R |= (1<<0) | (1<<4);
    GPIO_PORTA_DEN_R |= (1<<0) | (1<<1);

    UART0_CTL_R &= ~(1<<0);
    UART0_IBRD_R = 104;
    UART0_FBRD_R = 11;
    UART0_LCRH_R = (0x3<<5);
    UART0_CC_R = 0x0;
    UART0_CTL_R = (1<<0)|(1<<8)|(1<<9);

    SYSCTL_RCGCGPIO_R |= (1<<5);
    GPIO_PORTF_DIR_R |= (1<<1)|(1<<2)|(1<<3);
    GPIO_PORTF_DEN_R |= (1<<1)|(1<<2)|(1<<3);
    GPIO_PORTF_DATA_R &= ~((1<<1)|(1<<2)|(1<<3));

}

char readChar(void){
    char c;
    while((UART0_FR_R & (1<<4)) != 0);
    c = UART0_DR_R;
    return c;
}

void printChar(char c){
    while((UART0_FR_R & (1<<5)) != 0);
    UART0_DR_R = c;
}

void printString(char * string){
    while(*string){
        printChar(*(string++));
    }
}
