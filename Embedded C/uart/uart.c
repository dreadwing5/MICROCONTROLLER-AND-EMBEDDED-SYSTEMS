#include<lpc214x.h>

unsigned int delay;
unsigned char *ptr;
unsigned char arr[] = "HELLO WORLD";


int main(){
	
	PINSEL0 = 0X00000005;
	U0LCR =		0X83;
	U0DLM = 	0X00;
	U0DLL = 	0X13;
	U0LCR = 	0X03;
	
	while(1){
		
		ptr = arr;
		while(*ptr!='\0')
		{
			while(!((U0LSR & 0X20) == 0X20));
			U0THR = *ptr++;
			
			for(delay=0;delay<=6000;delay++);
		}
		for(delay=0;delay<=6000;delay++);
		
	}
}
