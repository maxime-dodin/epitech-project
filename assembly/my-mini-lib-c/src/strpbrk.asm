  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strpbrk
    extern strchr
my_strpbrk:

%else
  global strpbrk
    extern strchr
strpbrk:
%endif

    mov rax, 0
    mov rcx, 0

check:
  xor r9, r9
  cmp byte [rdi, rcx], 0
  je strpbrk_res_default
  jne strpbrk_loop

strpbrk_contains:
  inc rcx

  jmp check
strpbrk_loop:
  cmp byte [rsi, r9], 0
  je strpbrk_res_default

  mov r10b, byte [rdi + rcx]
  mov r11b, byte [rsi + r9]

  cmp r10b, r11b
  jne strpbrk_contains
  je strpbrk_res_find

  inc r9
  jmp strpbrk_loop

strpbrk_res_find:
    add rdi, rcx
    mov rax, rdi
    ret
strpbrk_res_default:
    xor rax, rax
    ret