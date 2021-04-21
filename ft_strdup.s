	section .text
	global ft_strdup
	extern	ft_strlen, malloc, ft_strcpy

;char	*strdup(const char *s)

ft_strdup :
		push rdi
		call ft_strlen
		pop rdi
		push rdi
		mov rdi, rax
		call malloc wrt ..plt
		cmp rax, 0
		je null
		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call ft_strcpy
		ret

null :
		mov rax, 0
		ret
