	section .text
	global ft_strlen

ft_strlen :
		mov rax, 0			; par convention, il est préférable d'utiliser RCX en tant que compteur de boucle (tout comme on utilise i en C)
		cmp rdi, 0			; securite NULL
		je end_while
while :
		cmp BYTE [rdi + rax], 0		; Il y a une méthode plus propre de faire ça. cmp BYTE [rdi], 0
		je end_while
		inc rax
		jmp while
end_while :
		ret

; l'équivalent en C de ton code serait ça:
; 
; i = 0;
; while (*s)
; {
;     s++;
;     i++;
; }
; return (i);

; Il y a pas plus simple?

; Attention, tu segfault en cas de RDI = NULL

; Il est possible de faire des opérations entre []
; exemple BYTE [RDI + RCX]. *wink* *wink*

; Tu devrais faire le Makefile le plus vite possible, pour éviter de te battre avec 35 commandes a chaque fois.
; Inspire toi du miens (ou prends le mien), si ça te prends trop la tête. ça te fera gagner beaucoup de temps.
; github.com/TheKrainBow/libasm

; Je t'aime <3