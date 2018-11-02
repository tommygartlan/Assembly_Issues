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

unsigned char global_val[3] = {0x05,0x07,0x09};

/*****************************************
				Macros
******************************************/

/*****************************************
 			Main Program
******************************************/
void main(void)
{
	unsigned char count = 0;
	Initial();                    //Function
	
	//foreground program
	
	TRISB = 0x00;       //clrf 0x93
	LATB = 0x01;		//movlw 0x01
						//movwf 0x81
	
	LATB = global_val[1];
	while(1)
	{
		//delay_1s();
        LATB = 0x55;
		
        count++;
		//delay_1s();
        LATB = 0xAA;
	}
		
	
	
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
	LATB = 0x00;
}


void delay_1s(void)
{
    unsigned char i;
    for (i=0;i<25;i++)
            __delay_ms(40);  //max value is 40 since this depends on the _delay() function which has a max number of cycles
    
}


