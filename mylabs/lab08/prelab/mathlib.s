BITS 64;
global _product

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
