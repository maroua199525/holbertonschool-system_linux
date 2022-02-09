BITS 64

global asm_puts               ; export to the gcc link
extern asm_strlen


asm_puts:
	push rbp                    ; push the base
	mov rbp, rsp                ; start new base

	push rdi
	push rsi
	push rdx

	call asm_strlen

	mov rdx, rax
	mov rax, 1
	mov rsi, rdi
	mov rdi, 1
	syscall

	pop rdi
	pop rsi
	pop rdx
	mov rsp, rbp                ; return to old base
	pop rbp                     ; pop to the call base
	ret
