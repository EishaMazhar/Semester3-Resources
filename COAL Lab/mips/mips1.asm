.data 
	arr: .word 1,2,3,4,5
.text 
.globl main
.ent main
main:
	la $t0,arr
	lw $t1,4($t0)
	move $a0,$t1
	li $v0,1
	syscall
	
	quit:
	
	.end main
	
	
	
	