  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_memcpy
my_memcpy:

%else
  global memcpy

memcpy:
%endif:

	mov rcx, 0

memcpy_loop:
	cmp rcx, rdx
	jz  memcpy_end
	mov al, byte [rsi+rcx]
	mov [rdi+rcx], byte al
    inc rcx
	jmp memcpy_loop

memcpy_end:
	mov rax, rdi
	ret