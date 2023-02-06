BITS 64

global asm_strncmp

asm_strncmp:
	push rbp
	mov rbp, rsp
	mov QWORD [rbp - 40], rdx
	mov QWORD [rbp - 32], rsi
	mov QWORD [rbp - 24], rdi
	mov DWORD [rbp - 16], 0
	mov QWORD [rbp - 8], 0
	jmp s1_s2_n_null
walk_str:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	movsx edx, al
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	movsx eax, al
	sub edx, eax
	mov eax, edx
	mov DWORD [rbp - 16], eax
	add QWORD [rbp - 24], 1
	add QWORD [rbp - 32], 1
	add QWORD [rbp - 8], 1
s1_s2_n_null:
	mov rax, QWORD [rbp - 24]
	movzx eax, BYTE [rax]
	test al, al
	jne n_eq_test
	mov rax, QWORD [rbp - 32]
	movzx eax, BYTE [rax]
	test al, al
	je eq_test_may
n_eq_test:
	cmp DWORD [rbp - 16], 0
	jne eq_test_may
	mov rax, QWORD [rbp - 8]
	cmp rax, QWORD [rbp - 40]
	jb walk_str
eq_test_may:
	cmp DWORD [rbp - 16], 0
	jle eq_test_min
	mov eax, 1
	jmp end_1
eq_test_min:
	cmp DWORD [rbp - 16], 0
	jns end_0
	mov eax, -1
	jmp end_1
end_0:
	mov eax, 0
end_1:
	pop rbp
	ret