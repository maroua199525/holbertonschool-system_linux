BITS 64
global asm_strncmp

asm_strncmp:
    push    rbp
    mov     rbp, rsp
    push    rcx

start_loop:
    movzx   eax, byte [rdi]    ; Load byte from first string (rdi) into eax
    movzx   ecx, byte [rsi]    ; Load byte from second string (rsi) into ecx
    cmp     al, cl             ; Compare characters
    jne     handle_diff        ; If they are not the same, go to handle_diff
    test    al, al             ; Check for null character (end of string)
    je      equal              ; If null, strings are equal up to this point
    inc     rdi                ; Move to next byte in rdi
    inc     rsi                ; Move to next byte in rsi
    dec     edx                ; Reduce comparison length (edx)
    jnz     start_loop         ; Continue if length is not zero

    ; If we get here, strings are equal up to N characters
    xor     eax, eax           ; Set eax to 0 (equal)
    jmp     finish

handle_diff:
    sub     eax, ecx           ; Calculate difference between bytes
    jmp     finish

equal:
    xor     eax, eax           ; Set eax to 0 (equal)

finish:
    pop     rcx
    mov     rsp, rbp
    pop     rbp
    ret
