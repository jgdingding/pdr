BITS 64;
global _product
global _power

section .text

_product:
	xor rax, rax	; zero out return register
	xor r10, r10	; zero out counter i
start:
	cmp r10, rdi	; is i >= num1?
	jge done		; if so, we are done with the loop
	add rax, rsi	; add one instance of num2 to return register
	inc r10			; num1++;
	jmp start		; done with this iteration
done:
					; Standard epilogue, return value already in rax
	ret

_power:
	cmp rsi, 0		; is exponent <= 0?
	jle basecase	; if so, we are done recurring

	dec rsi			; decrement exponent
	call _power		; recursive call

	push rsi		; save exponent
	mov rsi, rax	; setup parameter for product
	call _product	; make product call
	pop rsi			; restore exponent

	ret				; return when done multiplying

basecase:
	mov rax, 1		; base case
	ret
