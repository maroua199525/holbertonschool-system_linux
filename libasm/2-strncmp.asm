BITS 64
global asm_strncmp

asm_strncmp:
    push    rbp
    mov     rbp, rsp
    push    rcx

loop:
    movzx   eax, byte [rdi]    ; Load byte from rdi into eax
    movzx   ecx, byte [rsi]    ; Load byte from rsi into ecx
    cmp     al, cl             ; Compare the bytes
    jne     compare            ; If not equal, jump to compare
    test    al, al             ; Check if the byte is null (end of string)
    je      success            ; If null, strings are equal up to this point
    inc     rdi                ; Move to the next character in rdi
    inc     rsi                ; Move to the next character in rsi
    dec     edx                ; Decrease string length counter
    jnz     loop               ; If edx is not zero, continue loop

    ; If we exit the loop and reach here, the strings are equal up to N bytes
    xor     eax, eax           ; Set eax to 0 to indicate equality
    jmp     end

compare:
    sub     eax, ecx           ; Return the difference between the bytes
    jmp     end

success:
    xor     eax, eax           ; Set eax to 0 (strings are equal)

end:
    pop     rcx
    mov     rsp, rbp
    pop     rbp
    ret
