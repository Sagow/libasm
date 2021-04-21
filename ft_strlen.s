	section .text
	global ft_strlen

ft_strlen :
		mov rax, 0
while :
		cmp BYTE [rdi + rax], 0
		je end_while
		inc rax
		jmp while
end_while :
		ret
