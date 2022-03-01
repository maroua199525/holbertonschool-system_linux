BITS 64
	global asm_puti

	extern asm_putc

	section .text
asm_puti:
	push rbp
	mov rbp, rsp
	push r15
	push r13
    push r14
	xor r15, r15
    movsx r15, edi
    xor rax, rax
	xor r14, r14
	cmp r15, 0
	jge cero
    mov rdi, 45
	imul r15, -1
	mov r13, 1
	call asm_putc
cero:
	test r15, r15
	jnz loop
	mov rdi, 48
	call asm_putc
	mov r13, 1
loop:
	xor rdx, rdx
	test r15, r15
	jz out
	mov rax, r15
	mov rbx, 10
	div rbx
	mov r15, rax
	after_div:
	push rdx
	after_push:
	inc r14
	jmp loop
out:
	mov r15, r14
stdout:
	test r15, r15
	jz end_1
	pop rdi
	after_pop:
	add rdi, 48
	call asm_putc
	dec r15
	jmp stdout

end_1:
	cmp r13, 1
	jne end
	inc r14
end:
	mov rax, r14
    pop r14
    pop r15
	pop r13
	mov rsp, rbp
	pop rbp
	ret
