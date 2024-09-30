BITS 64
		section .text
		global asm_strncmp
asm_strncmp:
        mov rax, 0
	mov rcx, 0
loop:
        mov BL, BYTE [rdi + rcx]    ; store first arg char in BL
        mov BH, BYTE [rsi + rcx]    ; store second arg char in BH
        cmp BL, BH	; compare them
        jnz diff	; when not zero return 1 or -1
        inc rcx		; dec counter
        cmp rcx, rdx	; when rdx is at zero
        je out		; return 0
        jmp loop	; loop again
diff:
	sub rdi + rcx, rsi + rcx
	cmp rdi + rcx, 0
	jg greater
	jl less
        je out
greater:
	mov rax, 1
	jmp out
less:
	mov rax, -1
	jmp out
out:
        ret
