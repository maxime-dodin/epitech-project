  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strchr
my_strchr:

%else
  global strchr
strchr:
%endif
	mov rax, 0
	mov rcx, 0

match:
	cmp [rdi], byte 0
	jz ret_false

	cmp [rdi], byte sil
	jz ret_true
	inc rdi
	jmp match

ret_false:
	cmp sil, byte 0
	jnz end_false
	jmp ret_true

ret_true:
	cmp rcx, byte 0
	jz end_true
	inc rdi
	dec rcx
	jmp ret_true

end_false:
	mov rax, 0
	ret

end_true:
	mov rax, rdi
	ret