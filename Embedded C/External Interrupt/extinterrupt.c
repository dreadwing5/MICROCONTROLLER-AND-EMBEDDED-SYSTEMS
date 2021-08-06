#include<lpc214x.h>

void Extint0_Isr(void)__irq;												//Declartion of ISR
unsigned char int__flag=0, flag=0;

int main(void)
{
	
			PINSEL2 = 0x00000000;					//Setup P1.25 as GPIO for LED
			IO1DIR |= 0x02000000;					//Setup P1.25 as Output Pin
			IO1SET = 	0x0200000;					//LED ON	
			
			PINSEL1 = 0x00000001;         //Setup P0.16 as EINT0
			EXTMODE = 0x01;								//Edge, i.e falling edge trigger and active low
			EXTPOLAR = 0x00;								
			VICVectAddr0 = (unsigned long) Extint0_Isr;			//Assign the EINT0 ISR function
			VICVectCntl0 = 0x20 | 0x0E; 	//Assign the VIC channel ENT0 to interrup priority 0
			VICIntEnable |=0x00004000;		//Enable ENT0 interrupt
	
	
	while(1)
	{																	//Waiting for interrupt to occur
		if(int__flag == 0x01)
		{
			if(flag ==0)
			{
				IO1CLR = 0x02000000;			//Clear the LED (LED OFF)
				flag = 1;
			} 
			else if(flag==1)
			{
				IO1SET  = 0x02000000;			//LED ON
				flag=0;
			}
			int__flag=0x00;
		}
	}
}

void Extint0_Isr(void)__irq
		{
			//Whenever there is a low level on ENT0
			
			EXTINT |=0x01;			//Clear Interrupt
			int__flag = 0x01;
			VICVectAddr = 0;		//Acknowledge Interrupt
			
			
		}	
