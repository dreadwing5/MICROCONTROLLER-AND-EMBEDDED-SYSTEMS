#include <LPC214x.h>
unsigned long int x=0x00000000;

int main(){
	
	unsigned int i=0;
	unsigned int j=0;
	PINSEL1=0x00000000;
	IO0DIR=0x00FF0000;
	while(1){
		{
			for(i=0;i!=0xFF;i++){
			x=i;
			x=x<<16;
			IO0PIN=x;
			for(j=0;j<=90000;j++);
				
			
			}
			for(i=0xFF;i!=0;i--){
			x=i;
			x=x<<16;
			IO0PIN=x;
			for(j=0;j<=90000;j++);
			}
		}
}
	}
