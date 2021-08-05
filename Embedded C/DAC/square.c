#include <lpc214x.h>
void delay(void)
	
int main(){

		PINSEL1=0x00000000;
		IO0DIR=0x00FF0000;
	while(1){
		IO0PIN=0x00000000;
		delay();
		IO0PIN=0x00FF0000;
		delay();
	}
}

void delay(void){
	int i=0;
	for(i=0;i<=95000;i++)
}