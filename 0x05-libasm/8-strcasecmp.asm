BITS 64

global asm_strcasecmp			; export to the gcc link


asm_strcasecmp:
	push rbp					; push the base
	mov rbp, rsp				; start new base

	mov R8, 0h					; set return to 0
	mov R9, 0h					; set counter to 0

asm_loop:
	mov al, [rdi + R9]			; store the char of first argument + counter in al
	mov bl, [rsi + R9]			; store the char of second argument + counter in ab

	cmp al, 65
	jl nop_cap
	cmp al, 90
	jg nop_cap

	add al, 32

compare:
	cmp al, bl					; compare the char + counter of first and second argument
	je equal_char				; if equal jump to equal_char

	movzx R8, al
	movzx rcx, bl
	sub R8, rcx

	test R8, R8
	jnz asm_end
	test rcx, rcx
	jz asm_end

	jmp asm_end

nop_cap:
	cmp bl, 65
	jl compare
	cmp bl, 90
	jg compare
	add bl, 32
	jmp compare

equal_char:
	cmp al, 0h					; compare al to Null
	mov R8, 0					; set return to 0 if true
	je asm_end					; jmp to asm_end

	inc R9						; increace counter
	jmp asm_loop				; loop again

asm_end:
	cmp R8, 32
	je new_end
	mov rax, R8					; pass the counter to the return register
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret

new_end:
	mov R8, 0h
	mov rax, R8					; pass the counter to the return register
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret
