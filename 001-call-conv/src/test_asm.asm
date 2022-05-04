.intel_syntax noprefix


# .data
# msg_format: .ascii "the negative sum is %lld\n"
# .byte 0
# msg_len: .quad $ - msg_format

# msg_format1: .ascii "this is some string...\n"
# msg_len1: .quad $ - msg_format1

.text

.global test_asm_in_exe

.extern printf

.extern msg_format
.extern msg_len
.extern msg_format1
.extern msg_len1

#define p7 [rsp + 17*8]
#define p6 [rsp + 16*8]
#define p5 [rsp + 14*8]
#define p4 [rsp + 13*8]
#define p3 [rsp + 12*8]
#define p2 [rsp + 11*8]
#define p1 [rsp + 10*8]
#define p0 [rsp + 9*8]


#define v7 [rsp + 8*8]
#define v6 [rsp + 7*8]
#define v5 [rsp + 6*8]
#define v4 [rsp + 5*8]
#define v3 [rsp + 4*8]
#define v2 [rsp + 3*8]
#define v1 [rsp + 2*8]
#define v0 [rsp + 1*8]
#define sum [rsp]

#define reg_arg0 rdi
#define reg_arg1 rsi
#define reg_arg2 rdx
#define reg_arg3 rcx
#define reg_arg4 r8
#define reg_arg5 r9

# .macro assign_neg num
#     mov rax, p\num
#     neg rax
#     mov v\num, rax
# .endm

test_asm_in_exe:
    sub rsp, 15*8
    

    mov p0, reg_arg0
    mov p1, reg_arg1
    mov p2, reg_arg2
    mov p3, reg_arg3
    mov p4, reg_arg4
    mov p5, reg_arg5

    mov rax, p0
    neg rax
    mov v0, rax

    mov rax, p1
    neg rax
    mov v1, rax

    mov rax, p2
    neg rax
    mov v2, rax

    mov rax, p3
    neg rax
    mov v3, rax

    mov rax, p4
    neg rax
    mov v4, rax

    mov rax, p5 
    neg rax
    mov v5, rax

    mov rax, p6
    neg rax
    mov v6, rax

    mov rax, p7
    neg rax
    mov v7, rax

    xor rax, rax
    add rax, v0
    add rax, v1
    add rax, v2
    add rax, v3
    add rax, v4
    add rax, v5
    add rax, v6
    add rax, v7
    mov sum, rax


    
    # # write(fd, buffer, len)
    mov rax, 1
    mov reg_arg0, 1
    lea reg_arg1, [msg_format1 + rip]
    lea reg_arg2, [msg_len1 + rip]
    mov reg_arg2, [reg_arg2]
    syscall

    # # printf(msg_format, sum)
    lea reg_arg0, [msg_format + rip]
    mov reg_arg1, sum
    call printf

    mov rax, sum

    add rsp, 15*8
    ret
