	.syntax unified
	.eabi_attribute 6, 2
	.eabi_attribute 8, 1
	.eabi_attribute 9, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.file	"hello.bc"
	.text
	.globl	main
	.align	2
	.type	main,%function
main:                                   @ @main
@ BB#0:
	push	{lr}
	sub	sp, sp, #4
	mov	r0, #0
	str	r0, [sp]
	ldr	r0, .LCPI0_0
	bl	printf
	mov	r0, #0
	add	sp, sp, #4
	pop	{lr}
	mov	pc, lr
@ BB#1:
	.align	2
.LCPI0_0:
	.long	.L.str
.Ltmp0:
	.size	main, .Ltmp0-main

	.type	.L.str,%object          @ @.str
	.section	.rodata.str1.1,"aMS",%progbits,1
.L.str:
	.asciz	 "Hello World!"
	.size	.L.str, 13


