	section .text
	global ft_strcmp

ft_strcmp :
		mov rcx, 0
while :
		cmp BYTE [rdi + rcx], 0
		je return
		cmp BYTE [rdi + rcx], BYTE [rsi + rcx]
		jne return
		inc rcx
		jmp while
return :
		mov rax, [rdi + rcx]
		sub rax, [rsi + rcx]
		ret


