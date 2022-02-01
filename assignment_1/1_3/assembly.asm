.data
.balign 1
hwstr: .asciz "Hello world, the ANSWER is 4242! @[]\`{}~\n"
teststr: .asciz "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n"

.text
    .global print_asciz
    .global application
    .global to_capital
print_asciz:
    push {R5, lr} @ Push R5 and LR so these are preserved.
    movS R5, R0 @ Move the value of R0 into R5 - S updates N and Z flags. Just wanted to try, no evaluation done.
loop:
    ldrb R0, [R5] @ Loads value of register that R5 points to.
    ADD R0, R0, #0 @ This operation is performed to use for the BEQ. If the result is 0 its the terminator.
    BEQ end_print_asciz @ Evaluate branch instruction on Branch Equal.
    bl to_capital
    bl uart_put_char @ Call other label/function written in C or CPP - branch link.
    ADD R5, R5, #1 @ Make R5 point to next register.
    b loop
end_print_asciz:
    pop {R5, PC} @ Pop the registers from the stack to continue as intended.

application:
    push {R0, LR}
    ldr R0, =teststr @ Load pointer to first string item and store in R0
    bl print_asciz @ Branch link
    pop { R0, PC}

