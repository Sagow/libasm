	section .text
	global ft_read
	extern	__errno_location

;rdi -> fd
;rsi -> buffer
;rdx -> buffer_size

ft_read :
	mov rax, 0
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret