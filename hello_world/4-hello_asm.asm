global main

section .data                  
	str: db "Hello, asm", 0xa
	len: equ $-str

section .text
	main:
	
	mov edx, len
	mov ecx, str
	mov ebx, 2
	mov eax, 4
	int 0x80

        mov ebx, 0
        mov eax, 1
        int 0x80
