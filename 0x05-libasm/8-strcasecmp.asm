BITS 64

global asm_strcasecmp

section .text
asm_strcasecmp:
    push    rbp
    push    rcx
    mov     rbp, rsp
    xor     rcx, rcx

loop_1:
    mov   r8,  [rdi + rcx]
    mov   r9,  [rsi + rcx]
    cmp     r8b, 0
    je      end
    cmp     r9b, 0
    je      end

compare_upper_first:
    cmp     r8b, 'A'
    jae     compare_upper_z
    jmp     compare_upper_sec

compare_upper_z:
    cmp     r8b, 'Z'
    jbe     to_lower_first
    jmp     compare_upper_sec

to_lower_first:
    xor     r8b, 32

compare_upper_sec:
    cmp     r9b, 'A'
    jae     compare_z_sec
    jmp     loop_2

compare_z_sec:
    cmp     r9b, 'Z'
    jbe     to_lower_sec
    jmp     loop_2

to_lower_sec:
    xor     r9b, 32

loop_2:
    mov     dl, r9b
    cmp     r8b, dl
    jne     end
    inc     rcx
    jmp     loop_1

end:
    movzx     rax, BYTE [rdi + rcx]
    movzx     r9, BYTE [rsi + rcx]
    sub       rax, r9
    mov       rsp, rbp
    pop       rcx
    pop       rbp
    ret
