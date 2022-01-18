  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_rindex
  extern strlen
my_rindex:

%else
  global rindex
  extern strlen
rindex:

%endif

	mov rax, 0
	mov rdx, 0

str_goto_end:
	mov r8b, [rdi + rdx]
	cmp r8b, 0
	jz find
	inc rdx
	jmp str_goto_end

find:
	mov r8b, [rdi + rdx]
	cmp rdx, -1
	jz reached_end
	cmp r8b, sil
	jz result
	dec rdx
	jmp find

reached_end:
	cmp sil, 0
	jnz end_null
	jmp result

result:
	cmp rdx, 0
	jz end
	inc rdi
	dec rdx
	jmp result

end_null:
	ret

end:
	mov rax, rdi
	ret