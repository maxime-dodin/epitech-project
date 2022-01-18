  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strcmp
my_strcmp:

%else
  global strcmp
strcmp:

%endif

aled:
    cmp byte [rsi], 0
    jz  return
    cmpsb
    jz  aled

return:
  mov rax, [rdi]
  sub rax, [rsi]
  ret