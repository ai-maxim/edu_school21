;char *strcpy(char *dest = rdi, const char *src = rsi);
global _ft_strcpy
	section .text
	extern _ft_strlen ;include strlen

_ft_strcpy:
		push	rdi			;push too steck
		mov		rdi, rsi
		call	_ft_strlen
		mov		rcx, rax
		pop		rdi 		;возвращает значение rdi
		cld					;free flag DF
		mov		rax, rdi
		rep		movsb		;повторить следующую операцию
		mov		BYTE [rdi], 0
		jmp		done

done:
		ret
