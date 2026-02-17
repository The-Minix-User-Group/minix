/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md'.  */

#ifndef GCC_TM_CONSTRS_H
#define GCC_TM_CONSTRS_H

static inline bool
satisfies_constraint_Z (rtx op)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 38 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(1));
}
static inline bool
satisfies_constraint_I (rtx op)
{
  HOST_WIDE_INT ival = 0;
  if (CONST_INT_P (op))
    ival = INTVAL (op);
  return (GET_CODE (op) == CONST_INT) && (
#line 43 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(SMALL_OPERAND (ival)));
}
static inline bool
satisfies_constraint_J (rtx op)
{
  HOST_WIDE_INT ival = 0;
  if (CONST_INT_P (op))
    ival = INTVAL (op);
  return (GET_CODE (op) == CONST_INT) && (
#line 48 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(ival == 0));
}
static inline bool
satisfies_constraint_G (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return (GET_CODE (op) == CONST_DOUBLE) && (
#line 55 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(op == CONST0_RTX (mode)));
}
static inline bool
satisfies_constraint_Q (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return const_arith_operand (op, mode);
}
static inline bool
satisfies_constraint_A (rtx op)
{
  return (GET_CODE (op) == MEM) && (
#line 66 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(GET_CODE(XEXP(op,0)) == REG));
}
static inline bool
satisfies_constraint_S (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return (call_insn_operand (op, mode)) && (
#line 72 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(CONSTANT_P (op)));
}
static inline bool
satisfies_constraint_T (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return (move_operand (op, mode)) && (
#line 78 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(CONSTANT_P (op)));
}
static inline bool
satisfies_constraint_W (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return (GET_CODE (op) == MEM) && (memory_operand (op, mode));
}
static inline bool
satisfies_constraint_YG (rtx op)
{
  enum machine_mode mode = GET_MODE (op);
  return (GET_CODE (op) == CONST_VECTOR) && (
#line 90 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(op == CONST0_RTX (mode)));
}
#endif /* tm-constrs.h */
