;int	ft_strcmp(const char *s1, const char *s2)
global	_ft_strcmp
	section .text

_ft_strcmp:
			xor		rax, rax
			jmp		_lp
			xor		rbx,rbx
			xor		rdx,rdx
_lp:
			mov		cl, BYTE [rdi + rax]	;сохраняем в регистрах занчение по адресу
			mov		dl, BYTE [rsi + rax]
			cmp		cl, 0
			je		_done
			cmp		dl, 0		;проверка на ноль выражения
			je		_done
			cmp		dl, cl
			jne		_done
			inc		rax
			jmp		_lp

_done:
			movzx		rax, cl
			movzx		rbx, dl
			sub			rax, rbx			; найти разницу rdi и rsi
			ret
