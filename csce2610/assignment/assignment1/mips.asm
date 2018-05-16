add $v0, $a0, $zero
LOOP: slti $v1, $s0, -24
beq $t0, $zero, final
addi $t1, $s0, 2
sll $t2, $s0, 12
nor $a1, $s1, $t2
sw $t1, 0($t2)
addi $s0, $s0, -44
addiu $t4, $t5, 1
addu $t6, $t7, $t8
and $t1, $t2, $t3
andi $s0, $s2, 123
j EXIT
jr $ra
bne $a2, $zero, LOOP
lw $t7, 8($t2)
print: slt $t6, $t7, $s0
sltiu $s6, $s7, 95
bne $s3, $s4, print
sltu $t1, $s3, $s5
last: srl $s4, $s5, 10
sw $t1, -4($t3)
sub $s0, $s1, $s2
jal last
subu $t5, $t6, $t3
final: or $a3, $s1, $s2
ori $t5, $t9, 3
EXIT: