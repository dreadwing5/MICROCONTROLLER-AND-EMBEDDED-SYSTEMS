#include <LPC214x.h>
unsigned long int x=0x00000000;

int main(){
	
	unsigned int i=0;
	unsigned int j=0;
	PINSEL1=0x00000000;
	IO0DIR=0x00FF0000;
	while(1)
	{
		//Increasing ramp
			for(i=0;i!=0xFF;i++){			//Loop between min value and max value(0xFF)
			x=i;											// 8 bit to 32 bit conversion
			x=x<<16;			//We only want value from 16 to 23
			IO0PIN=x;
			for(j=0;j<=90000;j++); //No delay in actual program, we need a smooth graph
			}
			
			//Decreasing ramp
			for(i=0xFF;i!=0;i--){			//Start decrementing till we reach min value i.e 0x00
			x=i;
			x=x<<16;
			IO0PIN=x;
			for(j=0;j<=90000;j++);
			}
		
}
	}
