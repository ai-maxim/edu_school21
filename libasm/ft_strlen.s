;size_t	ft_strlen(char *s);
global	_ft_strlen
	section .text

_ft_strlen:
		xor		rax, rax	;i = 0
		jmp		compare

inc:
		inc		rax			;i++

compare:
		cmp		BYTE [rdi + rax], 0		;str[i] == 0
		jne		inc 					;jump inc rax (i++)
		ret
