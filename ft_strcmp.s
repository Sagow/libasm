	section .text
	global ft_strcmp

ft_strcmp :
		mov rcx, 0

while :
		cmp BYTE [rdi + rcx], 0
		je return
		mov dl, BYTE [rsi + rcx]
		cmp BYTE [rdi + rcx], dl
		jne return
		inc rcx
		jmp while
return :
		mov rax, 0
		mov ax, BYTE [rdi + rcx]
		sub ax, BYTE [rsi + rcx]
		ret


