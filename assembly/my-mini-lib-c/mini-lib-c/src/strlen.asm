  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strlen
my_strlen:

%else
  global strlen
strlen:

%endif

  mov   rax, 0

strlen_loop:
  cmp   [rdi + rax], byte 0
  jz    strlen_ret

  inc   rax
  jmp   strlen_loop

strlen_ret:
  ret