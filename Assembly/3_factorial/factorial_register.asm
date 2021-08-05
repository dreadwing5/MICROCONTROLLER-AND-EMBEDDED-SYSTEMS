;Write a program to find the factorial of a given 32 bit number


	AREA MULTIPLY, CODE, READONLY
	ENTRY
	
	MOV R1,#9
	MOV R2,#01
l2 	MUL R3,R2,R1
	MOV R2,R3
	SUBS R1,#01
	BNE l2
STOP B STOP
	END
	