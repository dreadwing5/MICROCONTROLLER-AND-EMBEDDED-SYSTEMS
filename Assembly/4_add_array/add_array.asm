;	To Add an array of 16 bit numbers

		area addarray,code, readonly
		entry
		mov r0,	#3			;counter
		ldr r1, memory		;loading the starting add. of array
		ldrh r2, [r1]		;loading the first number
loop	add  r1,#2			;increment the counter by two
		ldrh r3, [r1]		;load the second number
		add	 r2,r2,r3		;store the sum in r3 register r2 = r2+r3
		subs r0,#1
		bne	loop
		ldr r4,result
		str r2,[r4]
		
		 
		
stop	b	stop

memory 	dcd 0x40000000
result 	dcd	0x40000020
		end