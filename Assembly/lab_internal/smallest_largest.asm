;Write an ALP to find both the smallest and largest number in an array of 32 bit numbers.
;Store both the smallest and largest in two consecutive memory locations of internal RAM.


	AREA smallest, CODE, READONLY
	ENTRY
	MOV R1,#N-1		;cOUNTER
	LDR R0,=array		;load the array in r0
	LDR R2,[R0]			;two register to keep track of smallest and largest
	LDR R5,[R0]		
LOOP	ADD R0,R0,#4		
	LDR R3,[R0]		
	LDR R6,[R0]		
	CMP R3,R2	;(r3-r2)	
	CMP R6,R5		
	MOVLT R2,R3		;N!=V
	MOVGT R5,R6		;Z=0, N=V
	SUBS R1,R1,#1		
	BNE LOOP		
	LDR R4,mem32		
	STR R2,[R4]		
	ADD R4,R4,#4		
	STR R5,[R4]		
STOP    B STOP
array   DCD 0x50, 0x40, 0x90, 0x20, 0x10, 0x30, -0x3	
N EQU  7			
mem32 DCD 0x40000000		
	
	END