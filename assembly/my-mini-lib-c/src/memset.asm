  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_memset
my_memset:

%else
  global memset
memset:
%endif

	mov rcx, 0

memset_loop:
	cmp rcx, rdx
	jz  memset_ret
	mov [rdi+rcx], byte sil
	inc rcx
    jmp memset_loop

memset_ret:
	mov rax, rdi
	ret