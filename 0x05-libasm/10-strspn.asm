BITS 64
global asm_strspn

section .text
asm_strspn:
	push rbp
	mov rbp, rsp
	push rcx
	push r8
	push r9

	xor rax, rax
	xor r8, r8
	xor r9, r9
loop_1:
	mov r8b, [rdi + rax]
	test r8b, r8b
	jz end
	xor rcx, rcx
loop_2:
	mov r9b, [rsi + rcx]
	test r9b, r9b
	jz end
	cmp r8b, r9b
	je out
	inc rcx
	jmp loop_2
out:
	inc eax
	jmp loop_1
end:
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
