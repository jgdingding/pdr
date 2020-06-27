; Justin Gou
; jyg2qhc
; 4/6/2020
; threexplusone.s

BITS 64
global threexplusone

section .text

threexplusone:
	cmp rdi, 1		; if x==1, stop recurring
	je	done		; base case
	
	;xor r10, r10		; zero out r10
	;mov r10, 2			; move 2 into r10
	;mov rax, rdi		; setup for divide
	;push rdx			; save rdx;
	;xor rdx, rdx		; zero out rdx for division
	;idiv r10		; divide by 2
	;mov r10, rdx
	;pop rdx 	;

	;cmp r10, 0		; check if remainder is 0
	;je even		; jump if odd
	
	; fast way to check the least significant bit for even/odd
	;bt rdi, 0		; check if lsb is 1
	;jc odd		; jump if odd
	
	test rdi,1		; check if lsb is 1
	jnz odd		; jump if odd

	shr rdi, 1		; divide by 2
	call threexplusone	; make recursive call

	inc rax		; return 1+result from recursive call
	ret		;
odd:
	lea rdi, [rdi + 2*rdi + 1]
	;imul rdi, 3		; multiply by 3
	;inc rdi		; add one
	call threexplusone	; make recursive call

	inc rax		; return 1+result from recursive call
	ret		;
done:
	xor rax, rax		; default value is 0
	ret		;

; OPTIMIZATIONS USED:
; Originally used idiv to find the modulo to check if numbers even or odd
; 	switched to use bt rdi,0 to check lsb instead of dividing
;		Now uses test which seems to be faster
;
; Originally used idiv by 2 if the number was even
; 	Now uses a bit shift right to divide by 2
;
; Originally used imul and inc to calculate 3*x+1
; 	Now uses lea, turns out adding rdi with 2*rdi is faster
