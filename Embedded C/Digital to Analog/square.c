#include <lpc214x.h>
void delay(void);
	
int main(){

	
		PINSEL1=0x00000000;				//Configure P0.16 to P0.31 as GPIO
		IO0DIR=0x00FF0000;        //Configure P0.16 to P0.23 as Output
	while(1){
		IO0PIN=0x00000000;				//Input low
		delay();
		IO0PIN=0x00FF0000;        //Input high
		delay();
	}
}

void delay(void){
	int i=0;
	for(i=0;i<=95000;i++);
}
