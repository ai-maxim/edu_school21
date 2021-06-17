;char	*ft_strdup(const char *s1 = rdi) return copy dublicat
global _ft_strdup
	section	.text
	extern	_ft_strlen
	extern	_ft_strcpy
	extern	_malloc
	extern	___error

_ft_strdup:
			push	rdi
			call	_ft_strlen
			inc 	rax
			mov		rdi, rax
			call	_malloc
			jc		_done
			mov		rdi, rax
			pop		rsi
			call	_ft_strcpy
			ret

_done:
		push	rax
		call	___error
		pop		r9
		mov		[rax], r9
		mov		rax, 12
		ret
