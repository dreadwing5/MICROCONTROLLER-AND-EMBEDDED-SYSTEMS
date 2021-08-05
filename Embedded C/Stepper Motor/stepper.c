
#include<LPC214x.h>

void clock_wise(void);
void anti_clock_wise(void);

unsigned long int var1, var2;
unsigned 	int i=0, j=0,k=0;

int main()
{
	
	PINSEL0 = 0x00000000; 	//P0.12 to P0.15 assigned to GPIO
	IO0DIR	= 0x0000F000;	//P0.12 to P0.15 as Output

//Makes the stepper motor to rotate infinitely
	while(1)
	{
		 for(j=0;j<50;j++)  //50 times in Clockwise Rotation (360 degree)
		{
			clock_wise();
		}

		for(k=0;k<65000;k++);
				//Delay to show Clockwise Rotation

		for(j=0;j<50;j++)  //50 times in Anticlockwise Rotation (360 degree)
		{
			anti_clock_wise();
		}

		for(k=0;k<65000;k++); 	//Delay to show AntiClockwise Rotation



	}
}

void clock_wise(void){
	var1 = 0x00001000;  //Starting value for Clockwise
	for (i = 0; i <= 3; i++)		//for A B C D stepping
	{
		IO0PIN = var1;

		for (k = 0; k < 300000; k++);		//Delay for step speed variation
			
		var1 = var1<<1;					//left shit in clockwise direction
		
		
	}
	
	
}

void anti_clock_wise(void){
	var2 = 0x00008000;  //Starting value for anticlockwise , Pin-14 is selected
	for (i = 0; i <= 3; i++)		//for A B C D stepping
	{
		IO0PIN = var2;			//Give logic-1 to the selected pin

		for (k = 0; k < 300000; k++);			//Delay for step speed variation
		
		var2 = var2>>1;					//Right  shit in anti-clockwise direction
		
		
	}
	
	
}
	
