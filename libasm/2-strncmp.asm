BITS 64
section .text
global asm_strncmp

asm_strncmp:
    mov rax, 0            ; Clear rax (will store the result)
    mov rcx, 0            ; Clear rcx (counter)

loop:
    mov bl, BYTE [rdi + rcx]    ; Load byte from first string into BL
    mov bh, BYTE [rsi + rcx]    ; Load byte from second string into BH
    cmp bl, bh                  ; Compare the two characters
    jne diff                    ; If they differ, go to 'diff'
    inc rcx                     ; Increment counter
    cmp rcx, rdx                ; If we've reached the specified length (rdx)
    je out                      ; Return 0 if strings are equal up to rdx
    test bl, bl                 ; Check for null terminator in the first string
    je out                      ; If we hit null terminator, exit
    jmp loop                    ; Repeat loop

diff:
    sub rax, rbx                ; Calculate difference: rax = BL - BH
    ret                         ; Return the difference

out:
    ret   