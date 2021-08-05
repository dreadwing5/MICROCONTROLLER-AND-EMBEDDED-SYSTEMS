#include<lpc214x.h>

void Extint0_Isr(void)__irq;//declartion of ISR
unsigned char int__flag=0,flag=0;

int main(void)
{
	
			PINSEL2 = 0x00000000;
			IO1DIR |= 0x02000000;
			IO1SET = 0x20000000;
			PINSEL1 = 0x00000001;
			EXTMODE = 0x01;
			EXTPOLAR = 0x00;
			VICVectAddr0 = (unsigned long) Extint0_Isr;
			VICVectCntl0 = 0x20 | 0x00004000;
			VICIntEnable |=0x00004000;
	
	
	while(1)
	{
		if(int__flag == 0x01)
		{
			if(flag ==0)
			{
				IO1CLR = 0x02000000;
				flag = 1;
			} 
			else if(flag==1)
			{
				IO1SET  = 0x02000000;
				flag=0;
			}
			int__flag=0x00;
		}
	}
}
