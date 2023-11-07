	.file	"nov7.c"
	.text
	.section	.rodata
.LC0:
	.string	"true"
.LC1:
	.string	"false"
.LC2:
	.string	"Contains 10: %s\n"
.LC3:
	.string	"Contains 9: %s\n"
.LC4:
	.string	"Contains -12: %s\n"
.LC5:
	.string	"Contains 0: %s\n"
.LC6:
	.string	"Contains 53: %s\n"
.LC7:
	.string	"Contains 103: %s\n"
.LC8:
	.string	"Contains -53: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, %eax
	call	create_hashset@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-47, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$81, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$1000, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$692, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$99112, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$291, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$2299222, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-12, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-2, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$13, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$29, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$53, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$59, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$101, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$3301, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$52, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-53, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-5, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$-13, %esi
	movq	%rax, %rdi
	call	hashset_add@PLT
	movq	-8(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L2
	leaq	.LC0(%rip), %rax
	jmp	.L3
.L2:
	leaq	.LC1(%rip), %rax
.L3:
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L4
	leaq	.LC0(%rip), %rax
	jmp	.L5
.L4:
	leaq	.LC1(%rip), %rax
.L5:
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$-12, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L6
	leaq	.LC0(%rip), %rax
	jmp	.L7
.L6:
	leaq	.LC1(%rip), %rax
.L7:
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L8
	leaq	.LC0(%rip), %rax
	jmp	.L9
.L8:
	leaq	.LC1(%rip), %rax
.L9:
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$53, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L10
	leaq	.LC0(%rip), %rax
	jmp	.L11
.L10:
	leaq	.LC1(%rip), %rax
.L11:
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$103, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L12
	leaq	.LC0(%rip), %rax
	jmp	.L13
.L12:
	leaq	.LC1(%rip), %rax
.L13:
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movl	$-53, %esi
	movq	%rax, %rdi
	call	hashset_contains@PLT
	testl	%eax, %eax
	je	.L14
	leaq	.LC0(%rip), %rax
	jmp	.L15
.L14:
	leaq	.LC1(%rip), %rax
.L15:
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	printhashset@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
