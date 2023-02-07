BITS 64

global asm_strncmp

section .text
   asm_strncmp:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
   loop_in_bytes_of_sour_and_dest:
            cmp rdx, 0
            je return
            cmp rcx, rdx
            je compar
            mov al, [rdi + rcx]
            mov bl, [rsi + rcx]
            cmp al, 0
            je compar
            cmp bl, 0
            je compar
            cmp al , bl
            jne compar
            inc rcx
            jmp loop_in_bytes_of_sour_and_dest
   compar:
      cmp al , bl
      je equal
      jg greater
      jl less
   equal:
      mov rax , 0x0
      jmp return
   greater:
      mov rax , 0x1
      jmp return
   less:
      sub bl, al
      mov al , bl
      mov rax , -0x1
      jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret