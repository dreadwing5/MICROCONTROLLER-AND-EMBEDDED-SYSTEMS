
#include <LPC21xx.h>

unsigned int delay, Switchcount=0;
unsigned int Disp[]={0x003F0000,0X00060000,0X005B0000,0X004F0000,0X00660000,0X006D0000,0X007D0000,0X00070000,0X007F0000,
	0X006F0000,0X00770000,0X007C0000,0X00390000,0X005E0000,0X00790000,0X00710000
};


int main(){
	
PINSEL1=0X00000000;
IO0DIR = 0XF0FF0000;
	while(1){
		
		IO0SET = 0X10000000;
		IO0CLR = 0X00FF0000;
		
			for(delay=0;delay<1000;delay++);
								IO0SET = Disp[Switchcount];
					for(delay=0;delay<80000;delay++);
									Switchcount++;
								if(Switchcount==16)
									
								{
									Switchcount=0;
								}
							}
}
