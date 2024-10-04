BITS 64
section .text
global asm_strcmp
asm_strcmp:
        push    rbp
        mov     rbp, rsp

        cmp     rdi, 0          ; check if rdi is null
        je      out
        cmp     rsi, 0          ; check if rsi is null
        je      out

        xor     rax, rax        ; assume strings are equal (rax = 0)

loop:
        mov     al, [rdi]       ; load char from rdi
        mov     cl, [rsi]       ; load char from rsi
        cmp     al, cl          ; compare the characters
        jne     not_equal       ; if not equal, go to not_equal

        cmp     al, 0           ; check for null terminator
        je      out             ; if both strings ended, they are equal

        inc     rdi             ; move to next char in rdi
        inc     rsi             ; move to next char in rsi
        jmp     loop            ; repeat the loop

not_equal:
        cmp     al, cl          ; compare characters
        jg      greater         ; if al > cl, jump to greater
        jl      less            ; if al < cl, jump to less

greater:
        mov     rax, 1          ; set return value to 1
        jmp     out

less:
        mov     rax, -1         ; set return value to -1
        jmp     out

out:
        mov     rsp, rbp
        pop     rbp
        ret                     ; return rax
