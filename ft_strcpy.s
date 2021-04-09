	section .text
	global ft_strcpy

ft_strcpy :
		mov rcx, 0
		mov rax, rdi
while :
		mov r8b, [rsi + rcx]
		mov [rdi + rcx], r8b
		inc rcx
		cmp BYTE [rsi + rcx - 1], 0
		jne while
		ret