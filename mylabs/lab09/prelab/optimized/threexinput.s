	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 15
	.intel_syntax noprefix
	.globl	__Z13threexplusonei     ## -- Begin function _Z13threexplusonei
	.p2align	4, 0x90
__Z13threexplusonei:                    ## @_Z13threexplusonei
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
	call	__Z13threexplusonei
	inc	eax
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI1_0:
	.quad	4741671816366391296     ## double 1.0E+9
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
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
	sub	rsp, 48
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	mov	r14, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
	lea	rsi, [rip + L_.str]
	mov	edx, 9
	mov	rdi, r14
	call	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	mov	rbx, qword ptr [rip + __ZNSt3__13cinE@GOTPCREL]
	lea	rsi, [rbp - 24]
	mov	rdi, rbx
	call	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	lea	rsi, [rip + L_.str.1]
	mov	edx, 9
	mov	rdi, r14
	call	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	lea	rsi, [rbp - 20]
	mov	rdi, rbx
	call	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	mov	edi, dword ptr [rbp - 24]
	call	__Z13threexplusonei
	mov	rdi, r14
	mov	esi, eax
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	rbx, rax
	mov	rax, qword ptr [rax]
	mov	rsi, qword ptr [rax - 24]
	add	rsi, rbx
	lea	r14, [rbp - 56]
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
	lea	rdi, [rbp - 56]
	call	__ZNSt3__16localeD1Ev
	movsx	esi, r14b
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	lea	rbx, [rbp - 56]
	mov	rdi, rbx
	call	__ZN5timerC1Ev
	mov	rdi, rbx
	call	__ZN5timer5startEv
	mov	rdi, rbx
	call	__ZN5timer4stopEv
	mov	rdi, rbx
	call	__ZN5timer7getTimeEv
	mulsd	xmm0, qword ptr [rip + LCPI1_0]
	cvtsi2sd	xmm1, dword ptr [rbp - 20]
	divsd	xmm0, xmm1
	mov	rdi, qword ptr [rip + __ZNSt3__14coutE@GOTPCREL]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEd
	lea	rsi, [rip + L_.str.2]
	mov	edx, 12
	mov	rdi, rax
	call	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	mov	rbx, rax
	mov	rax, qword ptr [rax]
	mov	rsi, qword ptr [rax - 24]
	add	rsi, rbx
	lea	r14, [rbp - 32]
	mov	rdi, r14
	call	__ZNKSt3__18ios_base6getlocEv
Ltmp5:
	mov	rsi, qword ptr [rip + __ZNSt3__15ctypeIcE2idE@GOTPCREL]
	mov	rdi, r14
	call	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp6:
## %bb.3:
	mov	rcx, qword ptr [rax]
Ltmp7:
	mov	rdi, rax
	mov	esi, 10
	call	qword ptr [rcx + 56]
Ltmp8:
## %bb.4:
	mov	r14d, eax
	lea	rdi, [rbp - 32]
	call	__ZNSt3__16localeD1Ev
	movsx	esi, r14b
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	mov	rdi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	xor	eax, eax
	add	rsp, 48
	pop	rbx
	pop	r14
	pop	rbp
	ret
LBB1_7:
Ltmp9:
	mov	rbx, rax
	lea	rdi, [rbp - 32]
	jmp	LBB1_6
LBB1_5:
Ltmp4:
	mov	rbx, rax
	lea	rdi, [rbp - 56]
LBB1_6:
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
	.uleb128 Ltmp5-Ltmp3            ##   Call between Ltmp3 and Ltmp5
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp5-Lfunc_begin0     ## >> Call Site 4 <<
	.uleb128 Ltmp8-Ltmp5            ##   Call between Ltmp5 and Ltmp8
	.uleb128 Ltmp9-Lfunc_begin0     ##     jumps to Ltmp9
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp8-Lfunc_begin0     ## >> Call Site 5 <<
	.uleb128 Lfunc_end0-Ltmp8       ##   Call between Ltmp8 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m ## -- Begin function _ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_def_can_be_hidden	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp, 40
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	mov	r14, rdx
	mov	r15, rsi
	mov	rbx, rdi
Ltmp10:
	lea	rdi, [rbp - 80]
	mov	rsi, rbx
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp11:
## %bb.1:
	cmp	byte ptr [rbp - 80], 0
	je	LBB2_10
## %bb.2:
	mov	rax, qword ptr [rbx]
	mov	rax, qword ptr [rax - 24]
	lea	r12, [rbx + rax]
	mov	rdi, qword ptr [rbx + rax + 40]
	mov	r13d, dword ptr [rbx + rax + 8]
	mov	eax, dword ptr [rbx + rax + 144]
	cmp	eax, -1
	jne	LBB2_7
## %bb.3:
Ltmp13:
	mov	qword ptr [rbp - 64], rdi ## 8-byte Spill
	lea	rdi, [rbp - 56]
	mov	rsi, r12
	call	__ZNKSt3__18ios_base6getlocEv
Ltmp14:
## %bb.4:
Ltmp15:
	mov	rsi, qword ptr [rip + __ZNSt3__15ctypeIcE2idE@GOTPCREL]
	lea	rdi, [rbp - 56]
	call	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp16:
## %bb.5:
	mov	rcx, qword ptr [rax]
Ltmp17:
	mov	rdi, rax
	mov	esi, 32
	call	qword ptr [rcx + 56]
	mov	byte ptr [rbp - 41], al ## 1-byte Spill
Ltmp18:
## %bb.6:
	lea	rdi, [rbp - 56]
	call	__ZNSt3__16localeD1Ev
	movsx	eax, byte ptr [rbp - 41] ## 1-byte Folded Reload
	mov	dword ptr [r12 + 144], eax
	mov	rdi, qword ptr [rbp - 64] ## 8-byte Reload
LBB2_7:
	add	r14, r15
	and	r13d, 176
	cmp	r13d, 32
	mov	rdx, r15
	cmove	rdx, r14
Ltmp20:
	movsx	r9d, al
	mov	rsi, r15
	mov	rcx, r14
	mov	r8, r12
	call	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp21:
## %bb.8:
	test	rax, rax
	jne	LBB2_10
## %bb.9:
	mov	rax, qword ptr [rbx]
	mov	rax, qword ptr [rax - 24]
	lea	rdi, [rbx + rax]
	mov	esi, dword ptr [rbx + rax + 32]
	or	esi, 5
Ltmp23:
	call	__ZNSt3__18ios_base5clearEj
Ltmp24:
LBB2_10:
	lea	rdi, [rbp - 80]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
LBB2_11:
	mov	rax, rbx
	add	rsp, 40
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
LBB2_12:
Ltmp25:
	jmp	LBB2_15
LBB2_13:
Ltmp19:
	mov	r14, rax
	lea	rdi, [rbp - 56]
	call	__ZNSt3__16localeD1Ev
	jmp	LBB2_16
LBB2_14:
Ltmp22:
LBB2_15:
	mov	r14, rax
LBB2_16:
	lea	rdi, [rbp - 80]
	call	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
	jmp	LBB2_18
LBB2_17:
Ltmp12:
	mov	r14, rax
LBB2_18:
	mov	rdi, r14
	call	___cxa_begin_catch
	mov	rax, qword ptr [rbx]
	mov	rdi, qword ptr [rax - 24]
	add	rdi, rbx
Ltmp26:
	call	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp27:
## %bb.19:
	call	___cxa_end_catch
	jmp	LBB2_11
LBB2_20:
Ltmp28:
	mov	rbx, rax
Ltmp29:
	call	___cxa_end_catch
Ltmp30:
## %bb.21:
	mov	rdi, rbx
	call	__Unwind_Resume
	ud2
LBB2_22:
Ltmp31:
	mov	rdi, rax
	call	___clang_call_terminate
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase0-Lttbaseref0
Lttbaseref0:
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end1-Lcst_begin1
Lcst_begin1:
	.uleb128 Ltmp10-Lfunc_begin1    ## >> Call Site 1 <<
	.uleb128 Ltmp11-Ltmp10          ##   Call between Ltmp10 and Ltmp11
	.uleb128 Ltmp12-Lfunc_begin1    ##     jumps to Ltmp12
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp13-Lfunc_begin1    ## >> Call Site 2 <<
	.uleb128 Ltmp14-Ltmp13          ##   Call between Ltmp13 and Ltmp14
	.uleb128 Ltmp22-Lfunc_begin1    ##     jumps to Ltmp22
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp15-Lfunc_begin1    ## >> Call Site 3 <<
	.uleb128 Ltmp18-Ltmp15          ##   Call between Ltmp15 and Ltmp18
	.uleb128 Ltmp19-Lfunc_begin1    ##     jumps to Ltmp19
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp20-Lfunc_begin1    ## >> Call Site 4 <<
	.uleb128 Ltmp21-Ltmp20          ##   Call between Ltmp20 and Ltmp21
	.uleb128 Ltmp22-Lfunc_begin1    ##     jumps to Ltmp22
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp23-Lfunc_begin1    ## >> Call Site 5 <<
	.uleb128 Ltmp24-Ltmp23          ##   Call between Ltmp23 and Ltmp24
	.uleb128 Ltmp25-Lfunc_begin1    ##     jumps to Ltmp25
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp24-Lfunc_begin1    ## >> Call Site 6 <<
	.uleb128 Ltmp26-Ltmp24          ##   Call between Ltmp24 and Ltmp26
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp26-Lfunc_begin1    ## >> Call Site 7 <<
	.uleb128 Ltmp27-Ltmp26          ##   Call between Ltmp26 and Ltmp27
	.uleb128 Ltmp28-Lfunc_begin1    ##     jumps to Ltmp28
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp27-Lfunc_begin1    ## >> Call Site 8 <<
	.uleb128 Ltmp29-Ltmp27          ##   Call between Ltmp27 and Ltmp29
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp29-Lfunc_begin1    ## >> Call Site 9 <<
	.uleb128 Ltmp30-Ltmp29          ##   Call between Ltmp29 and Ltmp30
	.uleb128 Ltmp31-Lfunc_begin1    ##     jumps to Ltmp31
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp30-Lfunc_begin1    ## >> Call Site 10 <<
	.uleb128 Lfunc_end1-Ltmp30      ##   Call between Ltmp30 and Lfunc_end1
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end1:
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
	.p2align	2
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
Lttbase0:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_ ## -- Begin function _ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_def_can_be_hidden	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp, 56
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	test	rdi, rdi
	je	LBB3_20
## %bb.1:
	mov	r12, r8
	mov	r15, rcx
	mov	r14, rdi
	mov	dword ptr [rbp - 68], r9d ## 4-byte Spill
	mov	rax, rcx
	sub	rax, rsi
	mov	rcx, qword ptr [r8 + 24]
	xor	r13d, r13d
	sub	rcx, rax
	cmovg	r13, rcx
	mov	qword ptr [rbp - 88], rdx ## 8-byte Spill
	mov	rbx, rdx
	sub	rbx, rsi
	test	rbx, rbx
	jle	LBB3_3
## %bb.2:
	mov	rax, qword ptr [r14]
	mov	rdi, r14
	mov	rdx, rbx
	call	qword ptr [rax + 96]
	cmp	rax, rbx
	jne	LBB3_20
LBB3_3:
	test	r13, r13
	jle	LBB3_16
## %bb.4:
	mov	qword ptr [rbp - 80], r12 ## 8-byte Spill
	xorps	xmm0, xmm0
	movaps	xmmword ptr [rbp - 64], xmm0
	mov	qword ptr [rbp - 48], 0
	cmp	r13, 23
	jae	LBB3_8
## %bb.5:
	lea	eax, [r13 + r13]
	mov	byte ptr [rbp - 64], al
	lea	rbx, [rbp - 64]
	lea	r12, [rbp - 63]
	jmp	LBB3_9
LBB3_8:
	lea	rbx, [r13 + 16]
	and	rbx, -16
	mov	rdi, rbx
	call	__Znwm
	mov	r12, rax
	mov	qword ptr [rbp - 48], rax
	or	rbx, 1
	mov	qword ptr [rbp - 64], rbx
	mov	qword ptr [rbp - 56], r13
	lea	rbx, [rbp - 64]
LBB3_9:
	movzx	esi, byte ptr [rbp - 68] ## 1-byte Folded Reload
	mov	rdi, r12
	mov	rdx, r13
	call	_memset
	mov	byte ptr [r12 + r13], 0
	test	byte ptr [rbp - 64], 1
	je	LBB3_11
## %bb.10:
	mov	rbx, qword ptr [rbp - 48]
	jmp	LBB3_12
LBB3_11:
	inc	rbx
LBB3_12:
	mov	r12, qword ptr [rbp - 80] ## 8-byte Reload
	mov	rax, qword ptr [r14]
Ltmp32:
	mov	rdi, r14
	mov	rsi, rbx
	mov	rdx, r13
	call	qword ptr [rax + 96]
Ltmp33:
## %bb.13:
	mov	rbx, rax
	test	byte ptr [rbp - 64], 1
	je	LBB3_15
## %bb.14:
	mov	rdi, qword ptr [rbp - 48]
	call	__ZdlPv
LBB3_15:
	cmp	rbx, r13
	jne	LBB3_20
LBB3_16:
	mov	rsi, qword ptr [rbp - 88] ## 8-byte Reload
	sub	r15, rsi
	test	r15, r15
	jle	LBB3_18
## %bb.17:
	mov	rax, qword ptr [r14]
	mov	rdi, r14
	mov	rdx, r15
	call	qword ptr [rax + 96]
	cmp	rax, r15
	jne	LBB3_20
LBB3_18:
	mov	qword ptr [r12 + 24], 0
	jmp	LBB3_21
LBB3_20:
	xor	r14d, r14d
LBB3_21:
	mov	rax, r14
	add	rsp, 56
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
LBB3_22:
Ltmp34:
	mov	rbx, rax
	test	byte ptr [rbp - 64], 1
	je	LBB3_24
## %bb.23:
	mov	rdi, qword ptr [rbp - 48]
	call	__ZdlPv
LBB3_24:
	mov	rdi, rbx
	call	__Unwind_Resume
	ud2
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table3:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end2-Lcst_begin2
Lcst_begin2:
	.uleb128 Lfunc_begin2-Lfunc_begin2 ## >> Call Site 1 <<
	.uleb128 Ltmp32-Lfunc_begin2    ##   Call between Lfunc_begin2 and Ltmp32
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp32-Lfunc_begin2    ## >> Call Site 2 <<
	.uleb128 Ltmp33-Ltmp32          ##   Call between Ltmp32 and Ltmp33
	.uleb128 Ltmp34-Lfunc_begin2    ##     jumps to Ltmp34
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp33-Lfunc_begin2    ## >> Call Site 3 <<
	.uleb128 Lfunc_end2-Ltmp33      ##   Call between Ltmp33 and Lfunc_end2
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end2:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_def_can_be_hidden	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## %bb.0:
	push	rax
	call	___cxa_begin_catch
	call	__ZSt9terminatev
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Enter x: "

L_.str.1:                               ## @.str.1
	.asciz	"Enter n: "

L_.str.2:                               ## @.str.2
	.asciz	" Nanoseconds"


.subsections_via_symbols
