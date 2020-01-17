    .data

text:
   .asciz "Hello World, THE answer IS 42!@[]`{}~\n"
   .cpu cortex-m0
   .text
   .align 1
   .global application


application:
        push { lr }
        ldr r0, =text
        bl print_asciz
        pop { pc }