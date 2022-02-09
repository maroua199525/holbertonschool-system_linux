BITS 64

global asm_putc               ; export to the gcc link

asm_putc:
	push rbp                    ; push the base
	mov rbp, rsp

	push rdi
	push rsi
	push rdx

	mov rax, 1
	mov [rsi], rdi
	mov rdi, 1
	mov rdx, 1
	syscall

	pop rdi
	pop rsi
	pop rdx
	mov rsp, rbp                ; return to old base
	pop rbp                     ; pop to the call base
	ret
