	
	AREA program,code,readonly
	entry
	mov r0,#0x40000000
	ldr r1, [r0]
	mov r2,#01
	cmp r1,#0
	beq l1
l2 	mul r3,r2,r1
	mov r2,r3
	subs r1,#0x01
	bne l2
l1	add r0, #0x04
	str r2, [r0]
stop b stop
	end