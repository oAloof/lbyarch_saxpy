; Assembly version of SAXPY

section .text
bits 64
default rel

global saxpyASM

saxpyASM:
    ; Input: RCX = n, XMM0 = A, RDX = X, R8 = Y, R9 = Z
    xor rax, rax  ; clear RAX to use as loop counter

loop_start:
    cmp rax, rcx       ; Compare loop counter with n (end of array)
    jge loop_end       

    ; Load the current element from X and Y, multiply X[i] by A and add Y[i]
    movss xmm1, [rdx + rax * 4]  ; Load X[i] into xmm1
    mulss xmm1, xmm0             ; xmm1 = xmm1 * A
    addss xmm1, [r8 + rax * 4]   ; xmm1 = xmm1 + Y[i]

    ; Store the result in Z[i]
    movss [r9 + rax * 4], xmm1   ; Store xmm1 into Z[i]

    inc rax                      ; Increment loop counter
    jmp loop_start               

loop_end:
    ret