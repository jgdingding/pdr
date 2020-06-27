; Justin Gou
; jyg2qhc
; 4/5/2020
; threexplusone.s

BITS 64
global _threexplusone

section .text

_threexplusone:
	cmp rdi, 1		; if x==1, stop recurring
	je	done		; base case

	xor r10, r10		; zero out r10
	mov r10, 2			; move 2 into r10
	mov rax, rdi		; setup for divide
	push rdx			; save rdx;
	xor rdx, rdx		; zero out rdx for division
	idiv r10		; divide by 2
	mov r10, rdx
	pop rdx 	;

	cmp r10, 0		; check if remainder is 0
	je even		; jump if odd
	
	imul rdi, 3		; multiply x by 3
	inc rdi			; add one to x
	call _threexplusone	; make recursive call

	inc rax		; return 1+result from recursive call
	ret		;
even:
	shr rdi, 1		; divide by 2
	call _threexplusone	; make recursive call

	inc rax		; return 1+result from recursive call
	ret		;
done:
	xor rax, rax		; default value is 0
	ret		;
