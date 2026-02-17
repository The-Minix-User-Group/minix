/* Generated automatically by the program `genconditions' from the target
   machine description file.  */

#include "bconfig.h"
#include "system.h"

/* It is necessary, but not entirely safe, to include the headers below
   in a generator program.  As a defensive measure, don't do so when the
   table isn't going to have anything in it.  */
#if GCC_VERSION >= 3001

/* Do not allow checking to confuse the issue.  */
#undef ENABLE_CHECKING
#undef ENABLE_TREE_CHECKING
#undef ENABLE_RTL_CHECKING
#undef ENABLE_RTL_FLAG_CHECKING
#undef ENABLE_GC_CHECKING
#undef ENABLE_GC_ALWAYS_COLLECT

#include "coretypes.h"
#include "tm.h"
#include "insn-constants.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"

/* Fake - insn-config.h doesn't exist yet.  */
#define MAX_RECOG_OPERANDS 10
#define MAX_DUP_OPERANDS 10
#define MAX_INSNS_PER_SPLIT 5

#include "regs.h"
#include "recog.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "diagnostic-core.h"
#include "reload.h"
#include "tm-constrs.h"

#define HAVE_eh_return 1
#include "except.h"

/* Dummy external declarations.  */
extern rtx insn;
extern rtx ins1;
extern rtx operands[];

#endif /* gcc >= 3.0.1 */

/* Structure definition duplicated from gensupport.h rather than
   drag in that file and its dependencies.  */
struct c_test
{
  const char *expr;
  int value;
};

/* This table lists each condition found in the machine description.
   Each condition is mapped to its truth value (0 or 1), or -1 if that
   cannot be calculated at compile time.
   If we don't have __builtin_constant_p, or it's not acceptable in array
   initializers, fall back to assuming that all conditions potentially
   vary at run time.  It works in 3.0.1 and later; 3.0 only when not
   optimizing.  */

#if GCC_VERSION >= 3001
static const struct c_test insn_conditions[] = {

  { "(TARGET_HARD_FLOAT) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 289 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    ? (int) (
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 289 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    : -1 },
#line 1655 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "!TARGET_64BIT && TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1655 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1655 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
  { "(flag_pic) && (Pmode == DImode)",
    __builtin_constant_p (
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
#line 13 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
  { "TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))\n\
   && (GET_CODE (operands[4]) != ASHIFT || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 32))",
    __builtin_constant_p 
#line 13 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))
   && (GET_CODE (operands[4]) != ASHIFT || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 32)))
    ? (int) 
#line 13 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))
   && (GET_CODE (operands[4]) != ASHIFT || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 32)))
    : -1 },
  { "(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && (Pmode == DImode)",
    __builtin_constant_p (
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
  { "(!flag_pic || flag_pie) && (Pmode == SImode)",
    __builtin_constant_p (
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
  { "(flag_pic) && (Pmode == SImode)",
    __builtin_constant_p (
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
  { "(TARGET_MULDIV) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 591 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 591 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "Pmode == DImode",
    __builtin_constant_p 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)
    ? (int) 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)
    : -1 },
#line 1602 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], QImode)\n\
    || reg_or_0_operand (operands[1], QImode))",
    __builtin_constant_p 
#line 1602 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode)))
    ? (int) 
#line 1602 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode)))
    : -1 },
  { "(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { " reload_completed && REG_P (operands[1])",
    __builtin_constant_p 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))
    ? (int) 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))
    : -1 },
#line 2326 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 2326 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn))
    ? (int) 
#line 2326 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn))
    : -1 },
  { "(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && (Pmode == SImode)",
    __builtin_constant_p (
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
#line 284 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_HARD_FLOAT",
    __builtin_constant_p 
#line 284 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)
    ? (int) 
#line 284 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)
    : -1 },
  { "(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
  { "!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))",
    __builtin_constant_p 
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
    ? (int) 
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
    : -1 },
#line 591 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_MULDIV",
    __builtin_constant_p 
#line 591 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV)
    ? (int) 
#line 591 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV)
    : -1 },
#line 163 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
  { "TARGET_ATOMIC",
    __builtin_constant_p 
#line 163 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC)
    ? (int) 
#line 163 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC)
    : -1 },
#line 1561 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], HImode)\n\
    || reg_or_0_operand (operands[1], HImode))",
    __builtin_constant_p 
#line 1561 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode)))
    ? (int) 
#line 1561 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 2241 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "! TARGET_64BIT",
    __builtin_constant_p 
#line 2241 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(! TARGET_64BIT)
    ? (int) 
#line 2241 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(! TARGET_64BIT)
    : -1 },
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
  { "flag_pic && SYMBOL_REF_LOCAL_P (operands[1])",
    __builtin_constant_p 
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1]))
    ? (int) 
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1]))
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed && register_operand (operands[1], VOIDmode))",
    __builtin_constant_p (
#line 1181 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1185 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && register_operand (operands[1], VOIDmode)))
    ? (int) (
#line 1181 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1185 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && register_operand (operands[1], VOIDmode)))
    : -1 },
  { "(reload_completed) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1993 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 1993 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)",
    __builtin_constant_p 
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1))
    ? (int) 
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1))
    : -1 },
#line 1536 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], SImode)\n\
    || reg_or_0_operand (operands[1], SImode))",
    __builtin_constant_p 
#line 1536 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode)))
    ? (int) 
#line 1536 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode)))
    : -1 },
#line 1632 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_SOFT_FLOAT\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 1632 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 1632 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 1675 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_SOFT_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1675 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1675 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
  { "(TARGET_HARD_FLOAT) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 290 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 290 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_ATOMIC) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 138 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 138 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 2253 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "reload_completed",
    __builtin_constant_p 
#line 2253 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed)
    ? (int) 
#line 2253 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed)
    : -1 },
#line 1498 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "!TARGET_64BIT\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 1498 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 1498 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
#line 1802 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "!TARGET_MEMCPY",
    __builtin_constant_p 
#line 1802 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_MEMCPY)
    ? (int) 
#line 1802 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_MEMCPY)
    : -1 },
#line 1696 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && (register_operand (operands[0], TImode)\n\
       || reg_or_0_operand (operands[1], TImode))",
    __builtin_constant_p 
#line 1696 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], TImode)
       || reg_or_0_operand (operands[1], TImode)))
    ? (int) 
#line 1696 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], TImode)
       || reg_or_0_operand (operands[1], TImode)))
    : -1 },
#line 1508 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 1508 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 1508 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 847 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 847 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 1706 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "reload_completed && !TARGET_64BIT\n\
   && riscv_split_64bit_move_p (operands[0], operands[1])",
    __builtin_constant_p 
#line 1706 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed && !TARGET_64BIT
   && riscv_split_64bit_move_p (operands[0], operands[1]))
    ? (int) 
#line 1706 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed && !TARGET_64BIT
   && riscv_split_64bit_move_p (operands[0], operands[1]))
    : -1 },
  { "(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "Pmode == SImode",
    __builtin_constant_p 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)
    ? (int) 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)
    : -1 },
#line 2201 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "riscv_can_use_return_insn ()",
    __builtin_constant_p 
#line 2201 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_can_use_return_insn ())
    ? (int) 
#line 2201 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_can_use_return_insn ())
    : -1 },
#line 1665 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1665 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1665 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
#line 823 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_MULDIV && TARGET_64BIT",
    __builtin_constant_p 
#line 823 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT)
    ? (int) 
#line 823 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT)
    : -1 },
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
  { "TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))",
    __builtin_constant_p 
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
    ? (int) 
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
    : -1 },
  { "(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 1622 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 1622 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 1622 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT",
    __builtin_constant_p 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)
    ? (int) 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)
    : -1 },
#line 759 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_MULDIV && !TARGET_64BIT",
    __builtin_constant_p 
#line 759 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && !TARGET_64BIT)
    ? (int) 
#line 759 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && !TARGET_64BIT)
    : -1 },
  { "(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 1846 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && INTVAL (operands[2]) < 32",
    __builtin_constant_p 
#line 1846 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && INTVAL (operands[2]) < 32)
    ? (int) 
#line 1846 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && INTVAL (operands[2]) < 32)
    : -1 },
#line 41 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
  { "TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))",
    __builtin_constant_p 
#line 41 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0])))
    ? (int) 
#line 41 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0])))
    : -1 },
  { "(!flag_pic || flag_pie) && (Pmode == DImode)",
    __builtin_constant_p (
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
  { "(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 1387 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_HARD_FLOAT && TARGET_64BIT",
    __builtin_constant_p 
#line 1387 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT)
    ? (int) 
#line 1387 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT)
    : -1 },
  { "(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 1717 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && reload_completed",
    __builtin_constant_p 
#line 1717 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && reload_completed)
    ? (int) 
#line 1717 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && reload_completed)
    : -1 },
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63)",
    __builtin_constant_p 
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63))
    ? (int) 
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63))
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed && REG_P (operands[1]))",
    __builtin_constant_p (
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    ? (int) (
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    : -1 },

};
#endif /* gcc >= 3.0.1 */

int
main(void)
{
  unsigned int i;
  const char *p;
  puts ("(define_conditions [");
#if GCC_VERSION >= 3001
  for (i = 0; i < ARRAY_SIZE (insn_conditions); i++)
    {
      printf ("  (%d \"", insn_conditions[i].value);
      for (p = insn_conditions[i].expr; *p; p++)
        {
          switch (*p)
	     {
	     case '\\':
	     case '\"': putchar ('\\'); break;
	     default: break;
	     }
          putchar (*p);
        }
      puts ("\")");
    }
#endif /* gcc >= 3.0.1 */
  puts ("])");
  fflush (stdout);
return ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;
}
