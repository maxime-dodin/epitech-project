
  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strncmp
my_strncmp:

%else
  global strncmp
strncmp:
%endif

	mov rcx, 0

loop_strncmp:
	cmp [rdi], byte 0
	je end_strncmp
	cmp [rsi], byte 0
	je end_strncmp

	cmp rdi, rsi
	jne end_strncmp

	inc rdi
	inc rsi
	inc rcx

	cmp rdx, rcx
	jle end_strncmp
	jmp loop_strncmp

end_strncmp:
	movzx rax, byte [rdi]
	movzx rbx, byte [rsi]
	sub rax, rbx
	ret
