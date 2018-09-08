/***************************************************
	Tommy Gartlan Sep 2012

Looking at C to assembly translation and then to machine code

*****************************************************/


/*************************************************************
    Device Header File (Indirectly pulls in the pic18f4520.h
*************************************************************/
#include <xc.h>


/*************************************************************
 Compiler Directive to tell he compiler what clock freq is being used
*************************************************************/
#define _XTAL_FREQ 19660800
//#define _XTAL_FREQ 1

/*************************************************************
 Function Prototypes
*************************************************************/

void Initial(void);
void delay_1s(void);


/*****************************************
  Global Variables
******************************************/



/*****************************************
				Macros
******************************************/

/*****************************************
 			Main Program
******************************************/
volatile unsigned char outside_count @0x104 = 0;
const unsigned char table1[10]= {2,4,6,8,10,12,14,16,18,20};
unsigned char table2[10]= {2,4,6,8,10,12,14,16,18,20};
void main(void)
{
	unsigned char count = 0;
    unsigned long long_count =0;
	Initial();
	
	TRISB = 0x00;       
	PORTB = 0x01;		
	count = 6;
    outside_count = 8;
	PORTB = count;
	PORTB = outside_count;
    PORTB= table1[1];
    PORTB= table1[2];
    PORTB= table1[3];
    PORTB= table1[4];
    PORTB= table2[1];
    PORTB= table2[2];
    PORTB= table2[3];
    PORTB= table2[4];
    while(1);
		
	
}


/************************************************
 				Initial
    This function initialises SFRs and 
	global variables
*************************************************/

void Initial(void)
{
	ADCON1 = 0x0f; //pic18f4520

	TRISA = 0xff;
	TRISB = 0x00;
	PORTB = 0x00;
}


void delay_1s(void)
{
    unsigned char i;
    for (i=0;i<25;i++)
            __delay_ms(40);  //max value is 40 since this depends on the _delay() function which has a max number of cycles
    
}


