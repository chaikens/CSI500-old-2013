.section .text
 .globl _start
_start: 
        movl $4,%eax
        movl $1,%ebx
        movl $mess,%ecx
        movl $13,%edx
        int $0x80
        movl $1,%eax
        movl $195,%ebx
        int $0x80

.section .data
mess:  
        .ascii "Hello World!\n"
