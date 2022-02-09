BITS 64

global asm_memcpy           ; export to the gcc link+

section .text
asm_memcpy:
	push 	rbp
	mov		rbp,	rsp
	xor		rcx,	rcx		; Create a counter and init to zero

loop:
	cmp		byte[rsi + rcx], 0 		; Compare arg2[i] == 0
	je		return_value	   		; If true so go return_value
	cmp		rdx,	rcx	   			; Compare i == arg3
	je 		return_value
	mov		r8b,	[rsi + rcx] 	; cpy arg2[i] in tmp register
	mov		[rdi + rcx],	r8b 	; cpy tmp register to arg1[i]
	inc		rcx		    			; i++
	jmp	loop		    			; go loop again

return_value:
	mov		rsp,	rbp		; Get back the status stack
	pop		rbp				; Delete the element to the stack

	ret 					; return (ptr)
