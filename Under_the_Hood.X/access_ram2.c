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

volatile unsigned char countc @ 0x101; 
/*****************************************
				Macros
******************************************/
#define ImDebugging
/*****************************************
 			Main Program
******************************************/
void main(void)
{
    
    
    
	unsigned char count = 0;     //what address do the variables end up at?
	unsigned long long_count=0;
	
    unsigned int countb=0;
    
    unsigned char countd;
    
    
        
         
    
    countb = 0;
    //countc = 0;
    countd =0;
	Initial();
	
	//foreground program
	
	TRISB = 0x00;       
	PORTB = 0x01;		
						
	
	
	count = 2;			
						
						
	PORTB = count;
#ifndef ImDebugging
	delay_1s();
#endif
	countb = 4;
	PORTB = countb;
#ifndef ImDebugging
	delay_1s();
#endif
	
	countc = 5;   //what happens here in assembly as oppose to assembly for countb = 4
	PORTB = countc;                  
#ifndef	ImDebugging								 
	delay_1s();
#endif	
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

