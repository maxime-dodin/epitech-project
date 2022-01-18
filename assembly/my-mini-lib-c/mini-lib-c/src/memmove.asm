  BITS 64
  section .text

%ifdef UNIT_TEST
  global my_memmove
my_memmove:

%else
  global memmove

memmove:
%endif:

emmove:

    ; Preserve destination address because we have to return it.
 mov     rax,    rdi
 ; If dest < src, we can always do a fast pointer-incrementing move.
 ; If dest == src, do nothing.
 cmp     rdi,    rsi
 je      .done
 jb      .fast
 ; If dest > src and there are no overlapping regions (dest >= src+num), we
 ; can still do a fast pointer-incrementing move.
 mov     rcx,    rsi
 add     rcx,    rdx
 cmp     rdi,    rcx
 jae     .fast
 ; If dest > src and dest < src+num, we have to do a right-to-left move to
 ; preserve overlapping data.
 .slow:
     ; Set the direction flag so copying is right-to-left.
     std
     ; Set the move count register.
     mov     rcx,    rdx
     ; Update pointers to the right-hand side (minus one).
     dec     rdx
     add     rsi,    rdx
     add     rdi,    rdx
     ; Do a byte-by-byte move.
     rep     movsb
     ; Reset the direction flag.
     cld
     ret
 .fast:
     ; Do a byte-by-byte move.
     mov     rcx,    rdx
     rep     movsb

 .done:
     ret