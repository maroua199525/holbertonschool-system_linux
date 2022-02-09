BITS 64

global asm_memcpy				; export to the gcc link

asm_memcpy:
	push rbp					; push the base
	mov rbp, rsp				; start new base

	mov R9, 0h					; set counter to 0
asm_loop:

	cmp R9, rdx
	je asm_end

	mov bl, [rsi + R9]
	mov [rdi + R9], bl



	inc R9						; counter += 1
	jmp asm_loop				; repeat
asm_end:
	mov rsp, rbp				; return to old base
	pop rbp 					; pop to the call base
	ret
