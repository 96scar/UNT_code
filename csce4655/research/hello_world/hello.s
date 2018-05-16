	.syntax unified
	.eabi_attribute 6, 2
	.eabi_attribute 8, 1
	.eabi_attribute 9, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.file	"hello.ll"
	.text
	.globl	main
	.align	2
	.type	main,%function
main:                                   @ @main
@ BB#0:
	push	{r4, lr}
	ldr	r4, .LCPI0_0
	ldr	r1, .LCPI0_1
	mov	r2, #12
	mov	r0, r4
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	ldr	r0, [r4]
	sub	r0, r0, #12
	ldr	r0, [r0]
	add	r0, r0, r4
	ldr	r4, [r0, #124]
	cmp	r4, #0
	beq	.LBB0_5
@ BB#1:                                 @ %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
	ldrb	r0, [r4, #28]
	cmp	r0, #0
	beq	.LBB0_3
@ BB#2:
	ldrb	r0, [r4, #39]
	b	.LBB0_4
.LBB0_3:
	mov	r0, r4
	bl	_ZNKSt5ctypeIcE13_M_widen_initEv
	ldr	r0, [r4]
	mov	r1, #10
	ldr	r2, [r0, #24]
	mov	r0, r4
	mov	lr, pc
	mov	pc, r2
.LBB0_4:                                @ %_ZNKSt5ctypeIcE5widenEc.exit
	lsl	r0, r0, #24
	asr	r1, r0, #24
	ldr	r0, .LCPI0_0
	bl	_ZNSo3putEc
	bl	_ZNSo5flushEv
	mov	r0, #0
	pop	{r4, lr}
	mov	pc, lr
.LBB0_5:
	bl	_ZSt16__throw_bad_castv
@ BB#6:
	.align	2
.LCPI0_0:
	.long	_ZSt4cout
	.align	2
.LCPI0_1:
	.long	.L.str
.Ltmp0:
	.size	main, .Ltmp0-main

	.align	2
	.type	_GLOBAL__I_a,%function
_GLOBAL__I_a:                           @ @_GLOBAL__I_a
@ BB#0:
	push	{r4, lr}
	ldr	r4, .LCPI1_0
	mov	r0, r4
	bl	_ZNSt8ios_base4InitC1Ev
	ldr	r0, .LCPI1_1
	ldr	r2, .LCPI1_2
	mov	r1, r4
	bl	__cxa_atexit
	pop	{r4, lr}
	mov	pc, lr
@ BB#1:
	.align	2
.LCPI1_0:
	.long	_ZStL8__ioinit
	.align	2
.LCPI1_1:
	.long	_ZNSt8ios_base4InitD1Ev
	.align	2
.LCPI1_2:
	.long	__dso_handle
.Ltmp1:
	.size	_GLOBAL__I_a, .Ltmp1-_GLOBAL__I_a

	.type	_ZStL8__ioinit,%object  @ @_ZStL8__ioinit
	.lcomm	_ZStL8__ioinit,1
	.type	.L.str,%object          @ @.str
	.section	.rodata.str1.1,"aMS",%progbits,1
.L.str:
	.asciz	 "Hello world!"
	.size	.L.str, 13

	.section	.ctors,"aw",%progbits
	.align	2
	.long	_GLOBAL__I_a

