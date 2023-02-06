BITS 64

global asm_strncmp

section .text
   asm_strncmp:
         push rbp
         mov rbp, rsp
         push rcx
         xor rcx, rcx
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
      mov rax , 0
      jmp return
   greater:
      sub al, bl
      jmp return
   less:
      sub bl, al
      mov al , bl
      neg rax
      jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret