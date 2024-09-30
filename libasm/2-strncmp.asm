BITS 64
section .text
global asm_strncmp

asm_strncmp:
    xor rax, rax            ; Clear rax (will store the result)
    xor rcx, rcx            ; Clear rcx (counter)

loop:
    mov bl, BYTE [rdi + rcx]    ; Load byte from first string into BL
    mov bh, BYTE [rsi + rcx]    ; Load byte from second string into BH
    cmp bl, bh                  ; Compare the two characters
    jne diff                    ; If they differ, jump to 'diff'
    inc rcx                     ; Increment counter
    cmp rcx, rdx                ; Check if we've reached the specified length
    je out                      ; If yes, exit with result 0
    test bl, bl                 ; Check for null terminator in first string
    je out                      ; Exit if null terminator (strings are equal up to that point)
    jmp loop                    ; Repeat the loop

diff:
    sub rax, rbx                ; Calculate difference: rax = BL - BH
    mov al, bl                  ; Place the value of the differing character from the first string in rax
    sub al, bh                  ; Subtract the corresponding character from the second string
    ret                         ; Return the difference (rax)

out:
    ret                         ; Return 0 (strings are equal)
