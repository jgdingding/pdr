	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 15
	.intel_syntax noprefix
	.globl	__Z7collatzi            ## -- Begin function _Z7collatzi
	.p2align	4, 0x90
__Z7collatzi:                           ## @_Z7collatzi
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
                                        ## kill: def $edi killed $edi def $rdi
	cmp	edi, 1
	jne	LBB0_1
## %bb.5:
	xor	eax, eax
	pop	rbp
	ret
LBB0_1:
	test	dil, 1
	jne	LBB0_3
## %bb.2:
	mov	eax, edi
	shr	eax, 31
	add	eax, edi
	sar	eax
	mov	edi, eax
	jmp	LBB0_4
LBB0_3:
	lea	edi, [rdi + 2*rdi + 1]
LBB0_4:
	call	__Z7collatzi
	inc	eax
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r14
	push	rbx
	sub	rsp, 16
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	mov	edi, 27
	call	__Z7collatzi
	mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
	mov	esi, eax
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	rbx, rax
	mov	rax, qword ptr [rax]
	mov	rsi, qword ptr [rax - 24]
	add	rsi, rbx
	lea	r14, [rbp - 24]
	mov	rdi, r14
	call	__ZNKSt3__18ios_base6getlocEv
Ltmp0:
	mov	rsi, qword ptr [rip + __ZNSt3__15ctypeIcE2idE@GOTPCREL]
	mov	rdi, r14
	call	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp1:
## %bb.1:
	mov	rcx, qword ptr [rax]
Ltmp2:
	mov	rdi, rax
	mov	esi, 10
	call	qword ptr [rcx + 56]
Ltmp3:
## %bb.2:
	mov	r14d, eax
	lea	rdi, [rbp - 24]
	call	__ZNSt3__16localeD1Ev
	movsx	esi, r14b
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	xor	eax, eax
	add	rsp, 16
	pop	rbx
	pop	r14
	pop	rbp
	ret
LBB1_3:
Ltmp4:
	mov	rbx, rax
	lea	rdi, [rbp - 24]
	call	__ZNSt3__16localeD1Ev
	mov	rdi, rbx
	call	__Unwind_Resume
	ud2
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table1:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp3-Ltmp0            ##   Call between Ltmp0 and Ltmp3
	.uleb128 Ltmp4-Lfunc_begin0     ##     jumps to Ltmp4
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp3-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Lfunc_end0-Ltmp3       ##   Call between Ltmp3 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.p2align	2
                                        ## -- End function

.subsections_via_symbols
