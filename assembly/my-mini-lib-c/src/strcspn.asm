
  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_strcspn
my_strcspn:

%else
  global strcspn
strcspn:
%endif

	push rbx
	mov rax, 0
	mov rbx, 0

	mov r8, rsi
	jmp strcspn_loop

strcspn_inc:
	inc rdi
	mov r8, rsi

	inc rax

	cmp [rdi], byte 0
	jz strcspn_exit

	jmp strcspn_loop

strcspn_loop:
	mov bl, [r8]
	cmp bl, byte 0
	je strcspn_inc

	cmp byte [rdi], bl
	jz strcspn_exit

	inc r8
	jmp strcspn_loop

strcspn_exit:
	pop rbx
	ret
