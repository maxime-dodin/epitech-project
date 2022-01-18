  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strstr
my_strstr:

%else
  global strstr
strstr:
%endif

	push rbp
	mov rbp, rsp
	mov rax, 0

strstr_search:
	cmp [rdi], byte 0
	jz strstr_end

	mov r8b, [rsi]
	cmp [rdi], r8b
	jz strstr_compare

strstr_continue:
	inc rdi
	jmp strstr_search

strstr_compare:
	mov rcx, 0
	mov rax, rdi

strstr_compare_loop:
	mov r8b, [rsi + rcx]
	cmp r8b, byte 0
	jz  strstr_end

	cmp [rdi + rcx], r8b
	jnz strstr_not_found

	inc rcx
	jmp strstr_compare_loop

strstr_not_found:
	mov rax, 0
	jmp strstr_continue

strstr_end:
	mov rsp, rbp
	pop rbp
	ret