BITS 64

global asm_strpbrk

asm_strpbrk:
	push rbp
	mov rbp, rsp

	mov rax, 0h
	mov r8, 0h
	mov r9, 0h

asm_loop:
	mov bl, [rdi + R9]

	test bl, bl
	jz asm_end

	mov R8, 0h

asm_loop_1:
	mov cl, [rsi + R8]

	test cl, cl
	jz equal

	cmp bl, cl
	je found

	inc R8
	jmp asm_loop_1

equal:
    inc R9
	jmp asm_loop

found:
    mov rax, rdi
    add rax, R9

asm_end:
	mov rsp, rbp
	pop rbp
	ret
