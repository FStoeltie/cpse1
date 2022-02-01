.align 1
.data
MyArray: .skip 101

.text
.align 1

msg: .asciz "test1234567890\n" 
.global put_char
.global swap

swap:
	PUSH {R0-R7, LR}
	@ ldr R6, =msg	@ load message
	ldr R4, =MyArray
	@MOV R3, R0
	@bl put_char
	@MOV R0, R3
	@bl put_char
	@ MOV R0, #'a'
	@ strb R0, [R4]
	@ b done
	@ MOV R5, #'z'
	@ STRB R5, [R4, #1]
	@ ADD R6, R6, #1
	@ MOV R0, #'A'
	MOV R1, #0 		@ mov value of #1 in R1
	MOV R2, R0 		@ mov value of register R0 into R2
	MOV R3, #1		@ mov value of #0 in R3
	@ POP {R0-R5, PC}
loop:
	CMP R3, #98		@ compare R3, value to see if end of buffer
	BEQ done 		@ if R3 equal to value of end of buffer go to branch done
	@ADD R5, R0, R1
	MOV R2, R4
	ADD R2, R3
	LDRB R5, [R2]	@ load byte into register R4 from the address that R0 points to with offset found in register R1
	SUB R2, R2, #1
	@ MOV R5, #'a'
	STRB R5, [R2]
	@STRB R4, [R2] 	@ Store the result of R4 into the location that R2 points to - which should be the prev address
	@MOV R0, R4
	@ LDRB R0, [R6]
	@ BL put_char
	@ ADD R1, R1, #1
	@ MOV R1, #0
	ADD R3, R3, #1
	@ ADD R6, R6, #1
	B loop
	@ b done
done:
	MOV R2, R4
	ADD R2, R2, #97 @ [0, 1, 2, 3, 4, 5, 6, 7, 8, ...n]
	@ MOV R0, #'a'
	STRB R0, [R2] 
	@ strb R0, [R4]
	@ MOV R0, #'e'
	@ bl put_char
	@ LDRB R0, [R4, #1]
	@ MOV R0, R5
	@ bl put_char
	@ MOV R0, #'n'
	@ bl put_char
	@ MOV R0, #'d'
	@ bl put_char
	@ MOV R0, #'\n'
	@ bl put_char
	POP {R0-R7, PC}

.global application
application:
	push {R0, LR}
	MOV R0, #'e'
	bl swap
	MOV R0, #'n'
	bl swap
	MOV R0, #'d'
	bl swap
	MOV R0, #'x'
	bl swap
   @ push { r5, lr }
   @ ldr r0, =msg
   @PUSH {R0-R5, LR}
   @POP {R0-R5, PC}
	@ b swap
	POP {R0, PC}

.global print_asciz
print_asciz:
   push { r5-r6, lr }
   ldr  r5, =MyArray
   @ mov r6, #'e'
   @ strb r6, [r5]
   @ mov r6, #'n'
   @ strb r6, [r5, #1]
   @ mov r6, #'d'
   @ strb r6, [r5, #2]
   @mov r6, #'\n'
   @strb r6, [r5, #3]
   @mov r6, #0
   @strb r6, [r5, #4]
loop_asciz: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  done_asciz
   bl   put_char
   add  r5, r5, #1
   b    loop_asciz

done_asciz: 
   pop  { r5-r6, pc }

@ Added this
.global decode
decode:
    push { R0, LR }
    ldr R0, =compressedText @ Load pointer to first string item and store in R0
    movs R5, R0
    movs R10, R0 @ contains starting address
    bl print_ascizd @ Branch link
    pop { R0, PC }

print_ascizd:
    push { R5, lr } @ Push R5 and LR so these are preserved.
    movS R5, R0 @ Move the value of R0 into R5 - S updates N and Z flags. Just wanted to try, no evaluation done.
    movs R4, #0 @ keep track of current position of text to read
loopd:
    ldrb R0, [R5] @ Loads value of register that R5 points to.
    ADD R0, R0, #0 @ This operation is performed to use for the BEQ. If the result is 0 its the terminator.
    BEQ end_print_asciz @ Evaluate branch instruction on Branch Equal.
    CMP R0, #64
    BEQ to_decode
    BNE print_char
    @bl put_char @ Call other label/function written in C or CPP - branch link.
    @ADD R5, R5, #1 @ Make R5 point to next register.
    @ADD R4, R4, #1 @ add 1 to current index 
    @b loopd
end_print_asciz:
    pop { R5, PC } @ Pop the registers from the stack to continue as intended.

readBuffer:
	@ push { lr }
	@POP {R1-R2}
	@b loopxdone
	PUSH {R3-R7}
	@ MOV R6, R0
	@b loopxdone
	@MOV R5, #99
	@SUB R5, R5, R6
	ldr R4, =MyArray
	MOV R5, #97 @ 971

	ADD R5, R4, R5
	SUB R5, R1
	MOV R8, R5
	MOV R3, R5 @ counter max
	ADD R3, R2 @ counter max
	@ SUB R3, R3, #1
	@ ADD R3, #2 @ counter max
	@b loopxdone
loopx:
	CMP R5, R3
	BEQ loopxdone
	MOV R9, R5
	MOV R5, R8
	ldrb R0, [R5]
	MOV R5, R9
	MOV R7, R0
	bl put_char
	MOV R0, R7
	bl swap
	@MOV R0, R7
	@MOV R0, R8
	
	@ADD R5, R5, #1
	ADD R5, R5, #1
	B loopx
	@B loopxdone
	@ldrb R0, [R5] @ Loads value of register that R5 points to.
	@ADD R0, R0, #0 @ This operation is performed to use for the BEQ. If the result is 0 its the terminator.
	@BEQ end_print_asciz @ Evaluate branch instruction on Branch Equal.
	@CMP R0, #64

	@MOV R5, #98
	@ MOV R8, #1
	@  LDRB R0, [R5]
	@ MOV R0, R1
	@  MOV R7, R0
	@ MOV R0, #'@'
	@  bl put_char
	@  LDRB R0, [R5, #1]
	@  bl put_char
	@  MOV R0, R7
	@POP {R4-R7}
	@  ADD R5, R5, #3

@swapx:

loopxdone:
	POP {R3-R7}
	POP {R1-R2}
	@POP {R1-R7}
	ADD R5, R5, #3
	b loopd
	@ pop { pc }

to_decode:
	PUSH {R1-R2}
	@ADD R5, R5, #3
	@POP {R1-R2}
	@b loopd
	@ push {R1-R2}
	@MOV R1, R5
	@ADD R1, R1, #1 @ from where to start reading
	LDRB R1, [R5, #1]
	SUB R1, R1, #'0'
	LDRB R2, [R5, #2]
	SUB R2, R2, #'0'
	b readBuffer

	@ ADD R5, R5, #3
	@ POP {R0-R7}
	@ b loopd

	@PUSH {LR}
	@ CMP R0, #64 @ compare to character 
	@ BEQ done2 @ decode by looking back if character 64
	@ B done
	@ADD R5, R5, #2

print_char:
	@ PUSH {R8}
	MOV R8, R0
	@MOV R9, R1
	bl put_char
	MOV R0, R8
	@MOV R1, R9
	bl swap
	ADD R5, R5, #1
	@ POP {R8}
	b loopd
.end