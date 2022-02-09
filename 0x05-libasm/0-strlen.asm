BITS 64

global asm_strlen               ; the gcc link

asm_strlen:
	push rbp                    ; push the base
	mov rbp, rsp                ; start new base

	mov R9, 0h                  ; set counter to 0
asm_loop:

	cmp  byte [rdi + R9], 0h    ; compare first argument + counter to \0
	je asm_end                  ; return if true

	inc R9                      ; counter += 1
	jmp asm_loop                ; repeat
asm_end:
	mov rax, R9                 ; pass the counter to the return
	mov rsp, rbp                ; return to old base
	pop rbp                     ; pop to the call base
	ret
