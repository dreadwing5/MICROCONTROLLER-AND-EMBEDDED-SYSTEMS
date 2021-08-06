#include<lpc214x.h>

unsigned int delay;
unsigned char *ptr;
unsigned char arr[] = "HELLO WORLD";


int main(){
	
	PINSEL0 = 0X00000005;		//Select two TXD0 and RXD0 line
	U0LCR =		0X83;					//enable divisor latch register and select the 8 bit word length
	U0DLM = 	0X00;
	U0DLL = 	0X13;					//selct the baud rate 9600bps
	U0LCR = 	0X03;					//disable the latch register so that we can access the data
	
	while(1){
		
		ptr = arr;
		while(*ptr!='\0')		//read while charater is not null character
		{
			while(!((U0LSR & 0X20) == 0X20));			//check wheter transmit holding is empty or not
			U0THR = *ptr++;
			
			//To check the status of tranmitter buffer, if it is empty then copy the next data
			
			for(delay=0;delay<=6000;delay++);
		}
		for(delay=0;delay<=6000;delay++);
		
	}
}
