  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strcasecmp
my_strcasecmp:

%else
  global strcasecmp
strcasecmp:
%endif
global strcasecmp:

strcasecmp:
    mov rax, 1
    ret