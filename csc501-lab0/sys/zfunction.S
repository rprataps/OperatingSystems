 .data
 .text
 .globl zfunction

zfunction:
        pushl   %ebp
        movl    %esp, %ebp
        subl    $4, %esp
        andl    $0xFFFFF00F, 8(%ebp)
        movl    8(%ebp), %eax
        sall    $8, %eax
        movl    %eax, -4(%ebp)
        movl    -4(%ebp), %eax
        leave
        ret

