BITS 64
section .text
global asm_strncmp

asm_strncmp:
    mov rax, 0            ; Clear rax (return value)
    mov rcx, 0            ; Initialize counter

loop:
    mov BL, BYTE [rdi + rcx]    ; Load byte from first string into BL
    mov BH, BYTE [rsi + rcx]    ; Load byte from second string into BH
    cmp BL, BH                  ; Compare the two characters
    jnz diff                    ; If they differ, go to 'diff'
    inc rcx                     ; Increment the counter
    cmp rcx, rdx                ; Check if we've reached the specified length
    je out                      ; If yes, return 0
    jmp loop                    ; Repeat the loop

diff:
    sub rax, rbx                ; Compute difference between characters (BL - BH)
    ret                         ; Return the difference in rax

out:
    ret                         ; Return 0 if strings are equal
