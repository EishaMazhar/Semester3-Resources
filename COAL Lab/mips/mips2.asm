.data
X: .word 0

.text
.globl main
main:
li $v0,5
syscall
move $t0,$v0
sw $t0,X
sll $t0,$t0,4
lw $t1,X
sll $t1,$t1,2
addu $t0,$t0,$t1
lw $t1,X
sll $t1,$t1,1
addu $t0,$t0,$t1
lw $t1,X
addu $t0,$t0,$t1
sw $t0,X

move $a0,$t0
li $v0,1
syscall


li $v0, 10 # call code for terminate
syscall # system call
.end main