BITS 64
section .text
global asm_strncmp

asm_strncmp:
    push rbp                     ; Save base pointer
    mov rbp, rsp                 ; Set base pointer
    push rcx                     ; Save rcx (for later use)

    xor rax, rax                 ; Clear rax (this will hold the result)
    xor rcx, rcx                 ; Clear rcx (counter for looping)

loop:
    movzx bl, BYTE [rdi + rcx]    ; Load byte from first string into BL
    movzx bh, BYTE [rsi + rcx]    ; Load byte from second string into BH
    cmp bl, bh                    ; Compare the characters
    jne diff                      ; If they differ, jump to 'diff'
    test bl, bl                   ; Check if null terminator reached in first string
    je out                        ; If null, strings are equal up to this point
    inc rcx                       ; Increment counter
    cmp rcx, rdx                  ; Check if we've compared rdx bytes
    je out                        ; If yes, the strings are equal up to rdx bytes
    jmp loop                      ; Repeat the loop

diff:
    sub eax, ebx                  ; Calculate difference: eax = bl - bh
    jmp end                       ; Return the difference

out:
    xor eax, eax                  ; Set eax to 0 (strings are equal)

end:
    pop rcx                       ; Restore rcx
    mov rsp, rbp                  ; Restore stack pointer
    pop rbp                       ; Restore base pointer
    ret                           ; Return
