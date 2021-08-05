
#include <LPC21xx.h>

unsigned int delay, Switchcount=0;
unsigned int Disp[]={0x003F0000,0X00060000,0X005B0000,0X004F0000,0X00660000,0X006D0000,0X007D0000,0X00070000,0X007F0000,
	0X006F0000,0X00770000,0X007C0000,0X00390000,0X005E0000,0X00790000,0X00710000
}; //Hex Code for all the Hex digits (0-F)


int main(){
	
PINSEL1=0X00000000;			 //To select port 0 pins from 16 to 31 as GPIO
IO0DIR = 0XF0FF0000;		//To set P0.16 to P0.23 and P0.28 to P0.31 as output
	
	while(1)
	{
		
		//Display values on seven segment
		
		IO0SET = 0X10000000; 				//Make the first the display on
		IO0CLR = 0X00FF0000;				//Clear the display
		
			for(delay=0;delay<1000;delay++);
			IO0SET = Disp[Switchcount]; 				//display the value form the Disp[] array
			for(delay=0;delay<800000;delay++);		//dealy 
			Switchcount++;
			if(Switchcount==16)
			{
						Switchcount=0; //after F  go back to 0
			}
			
	}
}
