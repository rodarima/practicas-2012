	.file	"sort.c"
	.globl	__quicksort_umbral
	.data
	.align 8
	.type	__quicksort_umbral, @object
	.size	__quicksort_umbral, 8
__quicksort_umbral:
	.quad	15
	.globl	__quicksort_int_umbral
	.align 8
	.type	__quicksort_int_umbral, @object
	.size	__quicksort_int_umbral, 8
__quicksort_int_umbral:
	.quad	15
	.text
	.globl	insertsort_int
	.type	insertsort_int, @function
insertsort_int:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	movq	%rdi, %rax
	movq	%rsi, %rdx
	movq	%rax, %rbx
	.cfi_offset 3, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	salq	$2, %rdx
	leaq	(%rax,%rdx), %r14
	leaq	4(%rax), %r12
	jmp	.L2
.L6:
	leaq	-4(%r12), %rbx
	jmp	.L3
.L5:
	movl	(%rbx), %r13d
	movl	4(%rbx), %edx
	movl	%edx, (%rbx)
	leaq	4(%rbx), %rdx
	movl	%r13d, (%rdx)
	subq	$4, %rbx
.L3:
	cmpq	%rax, %rbx
	jb	.L4
	movl	(%rbx), %ecx
	leaq	4(%rbx), %rdx
	movl	(%rdx), %edx
	cmpl	%edx, %ecx
	jg	.L5
.L4:
	addq	$4, %r12
.L2:
	cmpq	%r14, %r12
	jb	.L6
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	insertsort_int, .-insertsort_int
	.globl	insertsort
	.type	insertsort, @function
insertsort:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	movq	%rdi, %r13
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	%rsi, %rax
	movq	%rdx, %rbx
	movq	%rcx, -96(%rbp)
	movq	%r13, %r12
	imulq	%rbx, %rax
	addq	%r13, %rax
	movq	%rax, -88(%rbp)
	leaq	0(%r13,%rbx), %rax
	movq	%rax, -72(%rbp)
	jmp	.L8
.L13:
	movq	%rbx, %rax
	negq	%rax
	movq	-72(%rbp), %r12
	addq	%rax, %r12
	jmp	.L9
.L12:
	movq	%rbx, -80(%rbp)
	movq	%r12, %r15
	leaq	(%r12,%rbx), %r14
.L10:
	movzbl	(%r15), %eax
	movb	%al, -49(%rbp)
	movzbl	(%r14), %eax
	movb	%al, (%r15)
	addq	$1, %r15
	movzbl	-49(%rbp), %eax
	movb	%al, (%r14)
	addq	$1, %r14
	subq	$1, -80(%rbp)
	cmpq	$0, -80(%rbp)
	jne	.L10
	movq	%rbx, %rax
	negq	%rax
	addq	%rax, %r12
.L9:
	cmpq	%r13, %r12
	jb	.L11
	leaq	(%r12,%rbx), %rax
	movq	%rax, %rsi
	movq	%r12, %rdi
	call	*-96(%rbp)
	testl	%eax, %eax
	jg	.L12
.L11:
	addq	%rbx, -72(%rbp)
.L8:
	movq	-88(%rbp), %rax
	cmpq	%rax, -72(%rbp)
	jb	.L13
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	insertsort, .-insertsort
	.globl	med3_int
	.type	med3_int, @function
med3_int:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	movq	%rdi, %rax
	movq	%rsi, %rdx
	leaq	-1(%rdx), %rcx
	shrq	%rcx
	salq	$2, %rcx
	leaq	(%rax,%rcx), %r12
	.cfi_offset 3, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	movq	%rax, %rbx
	subq	$1, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %r14
	movl	(%r12), %edx
	movl	(%rbx), %eax
	cmpl	%eax, %edx
	jle	.L15
	movl	(%r12), %r13d
	movl	(%rbx), %eax
	movl	%eax, (%r12)
	movl	%r13d, (%rbx)
.L15:
	movl	(%rbx), %edx
	movl	(%r14), %eax
	cmpl	%eax, %edx
	jle	.L16
	movl	(%rbx), %r13d
	movl	(%r14), %eax
	movl	%eax, (%rbx)
	movl	%r13d, (%r14)
.L16:
	movl	(%r12), %edx
	movl	(%rbx), %eax
	cmpl	%eax, %edx
	jle	.L14
	movl	(%r12), %r13d
	movl	(%rbx), %eax
	movl	%eax, (%r12)
	movl	%r13d, (%rbx)
.L14:
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	med3_int, .-med3_int
	.globl	_quicksort_int
	.type	_quicksort_int, @function
_quicksort_int:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$8, %rsp
	movq	%rdi, %r12
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	%rsi, %r15
	movq	__quicksort_int_umbral(%rip), %rax
	cmpq	%r15, %rax
	jae	.L23
.L19:
	movq	%r15, %rsi
	movq	%r12, %rdi
	call	med3_int
	movq	%r12, %r13
	leaq	-1(%r15), %rax
	salq	$2, %rax
	leaq	(%r12,%rax), %rbx
.L21:
	addq	$4, %r13
	movl	0(%r13), %edx
	movl	(%r12), %eax
	cmpl	%eax, %edx
	jl	.L21
.L22:
	subq	$4, %rbx
	movl	(%rbx), %edx
	movl	(%r12), %eax
	cmpl	%eax, %edx
	jg	.L22
	movl	0(%r13), %r14d
	movl	(%rbx), %eax
	movl	%eax, 0(%r13)
	movl	%r14d, (%rbx)
	cmpq	%r13, %rbx
	ja	.L21
	movl	0(%r13), %r14d
	movl	(%rbx), %eax
	movl	%eax, 0(%r13)
	movl	%r14d, (%rbx)
	movl	(%r12), %r14d
	movl	(%rbx), %eax
	movl	%eax, (%r12)
	movl	%r14d, (%rbx)
	movq	%rbx, %rdx
	movq	%r12, %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	sarq	$2, %rax
	movl	%eax, %r13d
	movslq	%r13d, %rax
	movq	%rax, %rsi
	movq	%r12, %rdi
	call	_quicksort_int
	leal	1(%r13), %eax
	cltq
	movq	%r15, %rdx
	subq	%rax, %rdx
	leaq	4(%rbx), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_quicksort_int
	jmp	.L18
.L23:
	nop
.L18:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_quicksort_int, .-_quicksort_int
	.globl	quicksort_int
	.type	quicksort_int, @function
quicksort_int:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$8, %rsp
	movq	%rdi, %rbx
	.cfi_offset 3, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	movq	%rsi, %r12
	movl	%edx, %r13d
	movslq	%r13d, %rax
	movq	%rax, __quicksort_umbral(%rip)
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	_quicksort_int
	testl	%r13d, %r13d
	jle	.L24
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	insertsort_int
.L24:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	quicksort_int, .-quicksort_int
	.globl	med3
	.type	med3, @function
med3:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	movq	%rdi, %rax
	movq	%rdx, %r12
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	%rcx, -96(%rbp)
	leaq	-1(%rsi), %rdx
	shrq	%rdx
	imulq	%r12, %rdx
	leaq	(%rax,%rdx), %r15
	movq	%rax, %rbx
	leaq	-1(%rsi), %rdx
	imulq	%r12, %rdx
	addq	%rdx, %rax
	movq	%rax, -88(%rbp)
	movq	%rbx, %rsi
	movq	%r15, %rdi
	call	*-96(%rbp)
	testl	%eax, %eax
	jle	.L27
	movq	%r12, -72(%rbp)
	movq	%r15, %r14
	movq	%rbx, %r13
.L28:
	movzbl	(%r14), %eax
	movb	%al, -51(%rbp)
	movzbl	0(%r13), %eax
	movb	%al, (%r14)
	addq	$1, %r14
	movzbl	-51(%rbp), %eax
	movb	%al, 0(%r13)
	addq	$1, %r13
	subq	$1, -72(%rbp)
	cmpq	$0, -72(%rbp)
	jne	.L28
.L27:
	movq	-88(%rbp), %rsi
	movq	%rbx, %rdi
	call	*-96(%rbp)
	testl	%eax, %eax
	jle	.L29
	movq	%r12, -80(%rbp)
	movq	%rbx, %r14
	movq	-88(%rbp), %r13
.L30:
	movzbl	(%r14), %eax
	movb	%al, -50(%rbp)
	movzbl	0(%r13), %eax
	movb	%al, (%r14)
	addq	$1, %r14
	movzbl	-50(%rbp), %eax
	movb	%al, 0(%r13)
	addq	$1, %r13
	subq	$1, -80(%rbp)
	cmpq	$0, -80(%rbp)
	jne	.L30
.L29:
	movq	%rbx, %rsi
	movq	%r15, %rdi
	call	*-96(%rbp)
	testl	%eax, %eax
	jle	.L26
	movq	%r12, %r13
	movq	%r15, %r12
.L32:
	movzbl	(%r12), %eax
	movb	%al, -49(%rbp)
	movzbl	(%rbx), %eax
	movb	%al, (%r12)
	addq	$1, %r12
	movzbl	-49(%rbp), %eax
	movb	%al, (%rbx)
	addq	$1, %rbx
	subq	$1, %r13
	testq	%r13, %r13
	jne	.L32
.L26:
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	med3, .-med3
	.globl	_quicksort
	.type	_quicksort, @function
_quicksort:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$216, %rsp
	movq	%rdi, %r12
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	%rsi, %r15
	movq	%rdx, %rbx
	movq	%rcx, %r14
	movq	%r12, -72(%rbp)
	leaq	-1(%r15), %rax
	imulq	%rbx, %rax
	leaq	(%r12,%rax), %r13
	movq	__quicksort_umbral(%rip), %rax
	cmpq	%r15, %rax
	jae	.L46
.L34:
	leaq	-1(%r15), %rax
	shrq	%rax
	imulq	%rbx, %rax
	addq	%r12, %rax
	movq	%rax, -224(%rbp)
	movq	%r12, -232(%rbp)
	leaq	-1(%r15), %rax
	imulq	%rbx, %rax
	addq	%r12, %rax
	movq	%rax, -240(%rbp)
	movq	-232(%rbp), %rsi
	movq	-224(%rbp), %rdi
	call	*%r14
	testl	%eax, %eax
	jle	.L36
	movq	%rbx, -80(%rbp)
	movq	-224(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-232(%rbp), %rdx
	movq	%rdx, -96(%rbp)
.L37:
	movq	-88(%rbp), %rcx
	movzbl	(%rcx), %eax
	movb	%al, -54(%rbp)
	movq	-96(%rbp), %rdx
	movzbl	(%rdx), %eax
	movq	-88(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -88(%rbp)
	movzbl	-54(%rbp), %eax
	movq	-96(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -96(%rbp)
	subq	$1, -80(%rbp)
	cmpq	$0, -80(%rbp)
	jne	.L37
.L36:
	movq	-240(%rbp), %rsi
	movq	-232(%rbp), %rdi
	call	*%r14
	testl	%eax, %eax
	jle	.L38
	movq	%rbx, -104(%rbp)
	movq	-232(%rbp), %rcx
	movq	%rcx, -112(%rbp)
	movq	-240(%rbp), %rax
	movq	%rax, -120(%rbp)
.L39:
	movq	-112(%rbp), %rdx
	movzbl	(%rdx), %eax
	movb	%al, -53(%rbp)
	movq	-120(%rbp), %rcx
	movzbl	(%rcx), %eax
	movq	-112(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -112(%rbp)
	movzbl	-53(%rbp), %eax
	movq	-120(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -120(%rbp)
	subq	$1, -104(%rbp)
	cmpq	$0, -104(%rbp)
	jne	.L39
.L38:
	movq	-232(%rbp), %rsi
	movq	-224(%rbp), %rdi
	call	*%r14
	testl	%eax, %eax
	jle	.L40
	movq	%rbx, -128(%rbp)
	movq	-224(%rbp), %rax
	movq	%rax, -136(%rbp)
	movq	-232(%rbp), %rdx
	movq	%rdx, -144(%rbp)
.L41:
	movq	-136(%rbp), %rcx
	movzbl	(%rcx), %eax
	movb	%al, -52(%rbp)
	movq	-144(%rbp), %rdx
	movzbl	(%rdx), %eax
	movq	-136(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -136(%rbp)
	movzbl	-52(%rbp), %eax
	movq	-144(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -144(%rbp)
	subq	$1, -128(%rbp)
	cmpq	$0, -128(%rbp)
	jne	.L41
.L40:
	addq	%rbx, -72(%rbp)
	movq	%r12, %rsi
	movq	-72(%rbp), %rdi
	call	*%r14
	testl	%eax, %eax
	js	.L40
.L42:
	movq	%rbx, %rax
	negq	%rax
	addq	%rax, %r13
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	*%r14
	testl	%eax, %eax
	jg	.L42
	movq	%rbx, -152(%rbp)
	movq	-72(%rbp), %rcx
	movq	%rcx, -160(%rbp)
	movq	%r13, -168(%rbp)
.L43:
	movq	-160(%rbp), %rdx
	movzbl	(%rdx), %eax
	movb	%al, -51(%rbp)
	movq	-168(%rbp), %rcx
	movzbl	(%rcx), %eax
	movq	-160(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -160(%rbp)
	movzbl	-51(%rbp), %eax
	movq	-168(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -168(%rbp)
	subq	$1, -152(%rbp)
	cmpq	$0, -152(%rbp)
	jne	.L43
	cmpq	-72(%rbp), %r13
	ja	.L40
	movq	%rbx, -176(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -184(%rbp)
	movq	%r13, -192(%rbp)
.L44:
	movq	-184(%rbp), %rdx
	movzbl	(%rdx), %eax
	movb	%al, -50(%rbp)
	movq	-192(%rbp), %rcx
	movzbl	(%rcx), %eax
	movq	-184(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -184(%rbp)
	movzbl	-50(%rbp), %eax
	movq	-192(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -192(%rbp)
	subq	$1, -176(%rbp)
	cmpq	$0, -176(%rbp)
	jne	.L44
	movq	%rbx, -200(%rbp)
	movq	%r12, -208(%rbp)
	movq	%r13, -216(%rbp)
.L45:
	movq	-208(%rbp), %rdx
	movzbl	(%rdx), %eax
	movb	%al, -49(%rbp)
	movq	-216(%rbp), %rcx
	movzbl	(%rcx), %eax
	movq	-208(%rbp), %rdx
	movb	%al, (%rdx)
	addq	$1, -208(%rbp)
	movzbl	-49(%rbp), %eax
	movq	-216(%rbp), %rcx
	movb	%al, (%rcx)
	addq	$1, -216(%rbp)
	subq	$1, -200(%rbp)
	cmpq	$0, -200(%rbp)
	jne	.L45
	movq	%r13, %rdx
	movq	%r12, %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	movl	$0, %edx
	divq	%rbx
	movl	%eax, -244(%rbp)
	movslq	-244(%rbp), %rax
	movq	%r14, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rsi
	movq	%r12, %rdi
	call	_quicksort
	movl	-244(%rbp), %eax
	addl	$1, %eax
	cltq
	movq	%r15, %rsi
	subq	%rax, %rsi
	leaq	0(%r13,%rbx), %rax
	movq	%r14, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
	call	_quicksort
	jmp	.L33
.L46:
	nop
.L33:
	addq	$216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_quicksort, .-_quicksort
	.globl	quicksort
	.type	quicksort, @function
quicksort:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$8, %rsp
	movq	%rdi, %rbx
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movl	%esi, %r14d
	movq	%rdx, %r12
	movq	%rcx, %r15
	movq	%r8, %r13
	testq	%r13, %r13
	jne	.L48
	movl	%r14d, %edx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	quicksort_int
	jmp	.L47
.L48:
	movq	%r13, %rcx
	movq	%r15, %rdx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	_quicksort
	testl	%r14d, %r14d
	jle	.L47
	movq	%r13, %rcx
	movq	%r15, %rdx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	insertsort
.L47:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	quicksort, .-quicksort
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
