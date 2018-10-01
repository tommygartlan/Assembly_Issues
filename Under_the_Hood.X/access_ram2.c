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
void test(void);
//volatile unsigned char countc @ 0x301;
unsigned char countc @ 0x301;
/*****************************************
				Macros
******************************************/

#define ImDebugging     //Comment if not debugging so delays are included

/*****************************************
 			Main Program
******************************************/
void main(void)
{
    
     
    
	unsigned char count = 0;     //what address do the variables end up at?
	unsigned long long_count=0;
	
    unsigned int countb=0;
    
	Initial();
    test();
						
	count = 2;								
	LATB = count;
#ifndef ImDebugging
	delay_1s();
#endif
    
    
	countb = 4;
	LATB = countb;
#ifndef ImDebugging
	delay_1s();
#endif

	countc = 5;   //what happens here in assembly as oppose to assembly for countb = 4
	LATB = countc;                  
#ifndef	ImDebugging								 
	delay_1s();
#endif	
    
    
    count = 260;								
	LATB = count;
    LATB = count >> 8;
#ifndef ImDebugging
	delay_1s();
#endif
    
    countb = 260;								
	LATB = countb;
    LATB = countb >> 8;
#ifndef ImDebugging
	delay_1s();
#endif
    
    long_count = 0x01020304;
    LATB = long_count;
    LATB = long_count >> 8;
    LATB = long_count >> 16;
    LATB = long_count >> 24;
	while(1);
	
	
}


/************************************************
 				Initial
    This function initialises SFRs and 
	global variables
*************************************************/

void Initial(void)
{
    unsigned char i = 0;   //local dyanmic variable
	ADCON1 = 0x0f; //pic18f4520
	
	TRISA = 0xff;
	TRISB = 0x00;
	LATB = 0x00;
    for (i=0;i<3;i++)
    {
        LATB = i;
    }
}

void delay_1s(void)
{
    unsigned char i;
    for (i=0;i<25;i++)
            __delay_ms(40);  //max value is 40 since this depends on the _delay() function which has a max number of cycles
    
}

void test(void)
{
    unsigned char j;
    for (j=4;j<8;j++)
        LATB = j;
}