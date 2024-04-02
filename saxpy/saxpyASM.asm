; Tyrone Uy, Kendrick Pua, S12

section .text
bits 64
default rel

global saxpyASM
extern printf

saxpyASM:
	;RCX:X, RDX:Y, R8:Z, XMM3:A, RBP+32 = N

	;to fix extra inputs
	push rsi
	push rbp
	mov rbp, rsp
	add rbp, 16
	add rbp, 8
	
	;clear rax
	xor rax, rax

	;to get n
	mov esi, [rbp+32]


loop_start: 
	cmp rax, rsi
	je loop_end

	;load element
	movss xmm1, [rcx+rax*4]

	;multiply
	mulss xmm1, xmm3

	;add
	addss xmm1, [rdx+rax*4]

	;store value in Z
	movss [r8+rax*4], xmm1
	
	inc rax
	jmp loop_start

loop_end:
	pop rbp
	pop rsi
	ret


