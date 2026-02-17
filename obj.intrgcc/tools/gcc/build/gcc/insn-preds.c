/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tree.h"
#include "tm_p.h"
#include "function.h"
#include "insn-config.h"
#include "recog.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "diagnostic-core.h"
#include "reload.h"
#include "regs.h"
#include "tm-constrs.h"

int
const_arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 24 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(SMALL_OPERAND (INTVAL (op))));
}

int
arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_arith_operand (op, mode)) || (register_operand (op, mode));
}

int
sle_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 32 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(SMALL_OPERAND (INTVAL (op) + 1)));
}

int
sleu_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (sle_operand (op, mode)) && (
#line 36 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(INTVAL (op) + 1 != 0));
}

int
const_0_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return 
#line 40 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(op == CONST0_RTX (GET_MODE (op)));
}

int
reg_or_0_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_0_operand (op, mode)) || (register_operand (op, mode));
}

int
const_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return 
#line 48 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(op == CONST1_RTX (GET_MODE (op)));
}

int
reg_or_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_1_operand (op, mode)) || (register_operand (op, mode));
}

int
const_0_or_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && ((
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(op == CONST0_RTX (GET_MODE (op)))) || (
#line 58 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(op == CONST1_RTX (GET_MODE (op)))));
}

int
pc_or_label_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case PC:
    case LABEL_REF:
      return true;
    default:
      break;
    }
  return false;
}

static inline int
splittable_const_int_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 67 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
{
  /* Don't handle multi-word moves this way; we don't want to introduce
     the individual word-mode moves until after reload.  */
  if (GET_MODE_SIZE (mode) > UNITS_PER_WORD)
    return false;

  /* Otherwise check whether the constant can be loaded in a single
     instruction.  */
  return !LUI_INT (op) && !SMALL_INT (op);
}

int
splittable_const_int_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
(splittable_const_int_operand_1 (op, mode)));
}

static inline int
move_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 80 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type symbol_type;

  /* The thinking here is as follows:

     (1) The move expanders should split complex load sequences into
	 individual instructions.  Those individual instructions can
	 then be optimized by all rtl passes.

     (2) The target of pre-reload load sequences should not be used
	 to store temporary results.  If the target register is only
	 assigned one value, reload can rematerialize that value
	 on demand, rather than spill it to the stack.

     (3) If we allowed pre-reload passes like combine and cse to recreate
	 complex load sequences, we would want to be able to split the
	 sequences before reload as well, so that the pre-reload scheduler
	 can see the individual instructions.  This falls foul of (2);
	 the splitter would be forced to reuse the target register for
	 intermediate results.

     (4) We want to define complex load splitters for combine.  These
	 splitters can request a temporary scratch register, which avoids
	 the problem in (2).  They allow things like:

	      (set (reg T1) (high SYM))
	      (set (reg T2) (low (reg T1) SYM))
	      (set (reg X) (plus (reg T2) (const_int OFFSET)))

	 to be combined into:

	      (set (reg T3) (high SYM+OFFSET))
	      (set (reg X) (lo_sum (reg T3) SYM+OFFSET))

	 if T2 is only used this once.  */
  switch (GET_CODE (op))
    {
    case CONST_INT:
      return !splittable_const_int_operand (op, mode);

    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      return (riscv_symbolic_constant_p (op, &symbol_type)
	      && !riscv_hi_relocs[symbol_type]);

    case HIGH:
      op = XEXP (op, 0);
      return riscv_symbolic_constant_p (op, &symbol_type);

    default:
      return true;
    }
}

int
move_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (general_operand (op, mode)) && (
(move_operand_1 (op, mode)));
}

int
consttable_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (
#line 136 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
(CONSTANT_P (op))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 140 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return riscv_symbolic_constant_p (op, &type);
}

int
symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
absolute_symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 147 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return (riscv_symbolic_constant_p (op, &type)
	  && type == SYMBOL_ABSOLUTE);
}

int
absolute_symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(absolute_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
plt_symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 155 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return (riscv_symbolic_constant_p (op, &type)
	  && type == SYMBOL_GOT_DISP && !SYMBOL_REF_WEAK (op) && TARGET_PLT);
}

int
plt_symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(plt_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
call_insn_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (absolute_symbolic_operand (op, mode)) || ((plt_symbolic_operand (op, mode)) || (register_operand (op, mode)));
}

int
symbol_ref_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == SYMBOL_REF) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
modular_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case PLUS:
    case MINUS:
    case MULT:
    case ASHIFT:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
equality_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
order_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
    case LT:
    case LTU:
    case LE:
    case LEU:
    case GE:
    case GEU:
    case GT:
    case GTU:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
fp_order_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case LT:
    case LE:
    case GT:
    case GE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
fp_unorder_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case ORDERED:
    case UNORDERED:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

enum constraint_num
lookup_constraint (const char *str)
{
  switch (str[0])
    {
    case 'A':
      return CONSTRAINT_A;
    case 'G':
      return CONSTRAINT_G;
    case 'I':
      return CONSTRAINT_I;
    case 'J':
      return CONSTRAINT_J;
    case 'Q':
      return CONSTRAINT_Q;
    case 'S':
      return CONSTRAINT_S;
    case 'T':
      return CONSTRAINT_T;
    case 'W':
      return CONSTRAINT_W;
    case 'Y':
      if (!strncmp (str + 1, "G", 1))
        return CONSTRAINT_YG;
      break;
    case 'Z':
      return CONSTRAINT_Z;
    case 'b':
      return CONSTRAINT_b;
    case 'f':
      return CONSTRAINT_f;
    case 'j':
      return CONSTRAINT_j;
    default: break;
    }
  return CONSTRAINT__UNKNOWN;
}

enum reg_class
regclass_for_constraint (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_f: return TARGET_HARD_FLOAT ? FP_REGS : NO_REGS;
    case CONSTRAINT_b: return ALL_REGS;
    case CONSTRAINT_j: return T_REGS;
    default: break;
    }
  return NO_REGS;
}

bool
constraint_satisfied_p (rtx op, enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_Z: return satisfies_constraint_Z (op);
    case CONSTRAINT_I: return satisfies_constraint_I (op);
    case CONSTRAINT_J: return satisfies_constraint_J (op);
    case CONSTRAINT_G: return satisfies_constraint_G (op);
    case CONSTRAINT_Q: return satisfies_constraint_Q (op);
    case CONSTRAINT_A: return satisfies_constraint_A (op);
    case CONSTRAINT_S: return satisfies_constraint_S (op);
    case CONSTRAINT_T: return satisfies_constraint_T (op);
    case CONSTRAINT_W: return satisfies_constraint_W (op);
    case CONSTRAINT_YG: return satisfies_constraint_YG (op);
    default: break;
    }
  return false;
}

bool
insn_const_int_ok_for_constraint (HOST_WIDE_INT ival, enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_I:
      return 
#line 43 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(SMALL_OPERAND (ival));

    case CONSTRAINT_J:
      return 
#line 48 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/constraints.md"
(ival == 0);

    default: break;
    }
  return false;
}

bool
insn_extra_memory_constraint (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_A:
      return true;

    case CONSTRAINT_W:
      return true;

    default: break;
    }
  return false;
}

