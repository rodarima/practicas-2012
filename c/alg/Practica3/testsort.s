	.file	"testsort.c"
	.text
	.globl	cmp_int
	.type	cmp_int, @function
cmp_int:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, %rdx
	movq	%rsi, %rax
	movl	(%rdx), %esi
	movl	(%rax), %ecx
	cmpl	%ecx, %esi
	jge	.L2
	movl	$-1, %eax
	jmp	.L3
.L2:
	movl	(%rdx), %edx
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	$1, %eax
	jmp	.L3
.L4:
	movl	$0, %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	cmp_int, .-cmp_int
	.globl	cmp_double
	.type	cmp_double, @function
cmp_double:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	ucomisd	-16(%rbp), %xmm0
	seta	%al
	testb	%al, %al
	je	.L6
	movl	$-1, %eax
	jmp	.L7
.L6:
	movsd	-16(%rbp), %xmm0
	ucomisd	-8(%rbp), %xmm0
	seta	%al
	testb	%al, %al
	je	.L8
	movl	$1, %eax
	jmp	.L7
.L8:
	movl	$0, %eax
.L7:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	cmp_double, .-cmp_double
	.globl	cmp_char
	.type	cmp_char, @function
cmp_char:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, -2(%rbp)
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, -1(%rbp)
	movzbl	-2(%rbp), %eax
	cmpb	-1(%rbp), %al
	jge	.L10
	movl	$-1, %eax
	jmp	.L11
.L10:
	movzbl	-2(%rbp), %eax
	cmpb	-1(%rbp), %al
	jle	.L12
	movl	$1, %eax
	jmp	.L11
.L12:
	movl	$0, %eax
.L11:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	cmp_char, .-cmp_char
	.globl	cmp_persona
	.type	cmp_persona, @function
cmp_persona:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L14
	movl	$-1, %eax
	jmp	.L15
.L14:
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L16
	movl	$1, %eax
	jmp	.L15
.L16:
	movl	$0, %eax
.L15:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	cmp_persona, .-cmp_persona
	.globl	u_sec
	.type	u_sec, @function
u_sec:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	-16(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday
	testl	%eax, %eax
	jns	.L18
	xorpd	%xmm0, %xmm0
	jmp	.L19
.L18:
	movq	-8(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-16(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	u_sec, .-u_sec
	.section	.rodata
	.align 8
.LC4:
	.string	"qsort(numeros, NMAX, sizeof(int), cmp_int): %fus (%f)us/n\n"
	.align 8
.LC5:
	.string	"quicksort(numeros, 15, NMAX, sizeof(int), cmp_int): %fus (%f)us/n\n"
.LC6:
	.string	"quicksortbin: %fus (%f)us/n\n"
	.align 8
.LC7:
	.string	"quicksort_int(numeros, NMAX, 15): %fus (%f)us/n\n"
	.align 8
.LC9:
	.string	"insertsort_int(numeros, NMAX): %fus (%f)us/n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movl	$128000, %edi
	.cfi_offset 3, -24
	call	malloc
	movq	%rax, -72(%rbp)
	movl	$0, %eax
	movq	%rax, -80(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L21
.L24:
	movl	$0, -24(%rbp)
	jmp	.L22
.L23:
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-72(%rbp), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -24(%rbp)
.L22:
	cmpl	$31999, -24(%rbp)
	jle	.L23
	movl	$0, %eax
	call	u_sec
	movsd	%xmm0, -64(%rbp)
	movq	-72(%rbp), %rax
	movl	$cmp_int, %ecx
	movl	$4, %edx
	movl	$32000, %esi
	movq	%rax, %rdi
	call	qsort
	movl	$0, %eax
	call	u_sec
	subsd	-64(%rbp), %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	-80(%rbp), %xmm0
	addsd	-64(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	addl	$1, -20(%rbp)
.L21:
	cmpl	$99, -20(%rbp)
	jle	.L24
	movsd	-80(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC4, %eax
	movsd	-80(%rbp), %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	movq	%rax, -80(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L25
.L28:
	movl	$0, -24(%rbp)
	jmp	.L26
.L27:
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-72(%rbp), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -24(%rbp)
.L26:
	cmpl	$31999, -24(%rbp)
	jle	.L27
	movl	$0, %eax
	call	u_sec
	movsd	%xmm0, -56(%rbp)
	movq	-72(%rbp), %rax
	movl	$cmp_int, %r8d
	movl	$4, %ecx
	movl	$32000, %edx
	movl	$15, %esi
	movq	%rax, %rdi
	call	quicksort
	movl	$0, %eax
	call	u_sec
	subsd	-56(%rbp), %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	-80(%rbp), %xmm0
	addsd	-56(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	addl	$1, -20(%rbp)
.L25:
	cmpl	$99, -20(%rbp)
	jle	.L28
	movsd	-80(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC5, %eax
	movsd	-80(%rbp), %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	movq	%rax, -80(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L29
.L32:
	movl	$0, -24(%rbp)
	jmp	.L30
.L31:
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-72(%rbp), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -24(%rbp)
.L30:
	cmpl	$31999, -24(%rbp)
	jle	.L31
	movl	$0, %eax
	call	u_sec
	movsd	%xmm0, -48(%rbp)
	movq	-72(%rbp), %rax
	movl	$0, %r8d
	movl	$4, %ecx
	movl	$32000, %edx
	movl	$15, %esi
	movq	%rax, %rdi
	call	quicksort
	movl	$0, %eax
	call	u_sec
	subsd	-48(%rbp), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	-80(%rbp), %xmm0
	addsd	-48(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	addl	$1, -20(%rbp)
.L29:
	cmpl	$99, -20(%rbp)
	jle	.L32
	movsd	-80(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC6, %eax
	movsd	-80(%rbp), %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	movq	%rax, -80(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L33
.L36:
	movl	$0, -24(%rbp)
	jmp	.L34
.L35:
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-72(%rbp), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -24(%rbp)
.L34:
	cmpl	$31999, -24(%rbp)
	jle	.L35
	movl	$0, %eax
	call	u_sec
	movsd	%xmm0, -40(%rbp)
	movq	-72(%rbp), %rax
	movl	$15, %edx
	movl	$32000, %esi
	movq	%rax, %rdi
	call	quicksort_int
	movl	$0, %eax
	call	u_sec
	subsd	-40(%rbp), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	-80(%rbp), %xmm0
	addsd	-40(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	addl	$1, -20(%rbp)
.L33:
	cmpl	$99, -20(%rbp)
	jle	.L36
	movsd	-80(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC7, %eax
	movsd	-80(%rbp), %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	movq	%rax, -80(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L37
.L40:
	movl	$0, -24(%rbp)
	jmp	.L38
.L39:
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rbx
	addq	-72(%rbp), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -24(%rbp)
.L38:
	cmpl	$31999, -24(%rbp)
	jle	.L39
	movl	$0, %eax
	call	u_sec
	movsd	%xmm0, -32(%rbp)
	movq	-72(%rbp), %rax
	movl	$32000, %esi
	movq	%rax, %rdi
	call	insertsort_int
	movl	$0, %eax
	call	u_sec
	subsd	-32(%rbp), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	-80(%rbp), %xmm0
	addsd	-32(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	addl	$1, -20(%rbp)
.L37:
	cmpl	$1, -20(%rbp)
	jle	.L40
	movsd	-80(%rbp), %xmm0
	movsd	.LC8(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movl	$.LC9, %eax
	movsd	-80(%rbp), %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1093567616
	.align 8
.LC2:
	.long	0
	.long	1079574528
	.align 8
.LC3:
	.long	0
	.long	1088372736
	.align 8
.LC8:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
