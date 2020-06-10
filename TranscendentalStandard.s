	.file	"TranscendentalStandard.c"
	.text
	.section	.rodata
.LC2:
	.string	"Time Spent: %f"
	.text
	.globl	ln
	.type	ln, @function
ln:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L2
.L3:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %xmm0
	call	log@PLT
	movq	%xmm0, %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	y.4105(%rip), %rdx
	movq	%rax, (%rcx,%rdx)
	addl	$1, -28(%rbp)
.L2:
	cmpl	$9, -28(%rbp)
	jle	.L3
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	y.4105(%rip), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	ln, .-ln
	.globl	exponent
	.type	exponent, @function
exponent:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L6
.L7:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %xmm0
	call	exp@PLT
	movq	%xmm0, %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	leaq	y.4116(%rip), %rdx
	movq	%rax, (%rcx,%rdx)
	addl	$1, -28(%rbp)
.L6:
	cmpl	$9, -28(%rbp)
	jle	.L7
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	y.4116(%rip), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	exponent, .-exponent
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movl	%edi, -132(%rbp)
	movq	%rsi, -144(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -112(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -104(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	.LC6(%rip), %xmm0
	movsd	%xmm0, -88(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	.LC8(%rip), %xmm0
	movsd	%xmm0, -72(%rbp)
	movsd	.LC9(%rip), %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	.LC10(%rip), %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	.LC11(%rip), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	.LC12(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	.LC13(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	exponent
	movq	%rax, -128(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	ln
	movq	%rax, -120(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.local	y.4105
	.comm	y.4105,88,32
	.local	y.4116
	.comm	y.4116,88,32
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1093567616
	.align 8
.LC3:
	.long	2296604913
	.long	1055193269
	.align 8
.LC4:
	.long	3944497965
	.long	1058682594
	.align 8
.LC5:
	.long	3539053052
	.long	1062232653
	.align 8
.LC6:
	.long	1202590843
	.long	1065646817
	.align 8
.LC7:
	.long	2576980378
	.long	1069128089
	.align 8
.LC8:
	.long	0
	.long	1072693248
	.align 8
.LC9:
	.long	0
	.long	1076101120
	.align 8
.LC10:
	.long	0
	.long	1079574528
	.align 8
.LC11:
	.long	0
	.long	1083129856
	.align 8
.LC12:
	.long	0
	.long	1086556160
	.align 8
.LC13:
	.long	0
	.long	1090021888
	.ident	"GCC: (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
