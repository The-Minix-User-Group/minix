/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "flags.h"
#include "ggc.h"
#include "rtl.h"
#include "expr.h"
#include "insn-codes.h"
#include "tm_p.h"
#include "function.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "insn-config.h"

#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "diagnostic-core.h"
#include "output.h"
#include "target.h"
#include "tm-constrs.h"

static const char *
output_3 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 431 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_4 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 431 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_5 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 431 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_6 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 431 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_15 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 519 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "subw\t%0,%z1,%2" : "sub\t%0,%z1,%2"; }
}

static const char *
output_16 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 519 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "subw\t%0,%z1,%2" : "sub\t%0,%z1,%2"; }
}

static const char *
output_17 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 519 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "subw\t%0,%z1,%2" : "sub\t%0,%z1,%2"; }
}

static const char *
output_18 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 519 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "subw\t%0,%z1,%2" : "sub\t%0,%z1,%2"; }
}

static const char *
output_26 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 598 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "mulw\t%0,%1,%2" : "mul\t%0,%1,%2"; }
}

static const char *
output_27 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 598 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "mulw\t%0,%1,%2" : "mul\t%0,%1,%2"; }
}

static const char *
output_28 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 598 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "mulw\t%0,%1,%2" : "mul\t%0,%1,%2"; }
}

static const char *
output_29 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 598 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "mulw\t%0,%1,%2" : "mul\t%0,%1,%2"; }
}

static const char *
output_42 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 797 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "divw\t%0,%1,%2" : "div\t%0,%1,%2"; }
}

static const char *
output_43 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 797 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "divuw\t%0,%1,%2" : "divu\t%0,%1,%2"; }
}

static const char *
output_46 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 815 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "remw\t%0,%1,%2" : "rem\t%0,%1,%2"; }
}

static const char *
output_47 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 815 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "remuw\t%0,%1,%2" : "remu\t%0,%1,%2"; }
}

static const char *
output_52 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 848 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
    return "fsqrt.s\t%0,%1";
}
}

static const char *
output_53 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 848 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
    return "fsqrt.d\t%0,%1";
}
}

static const char * const output_83[] = {
  "sext.w\t%0,%1",
  "sw\t%1,%0",
};

static const char * const output_90[] = {
  "#",
  "lwu\t%0,%1",
};

static const char *
output_91 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1114 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (which_alternative == 0)
    return "#";

  operands[1] = gen_lowpart (SImode, operands[1]);
  return "lwu\t%0,%1";
}
}

static const char * const output_92[] = {
  "#",
  "lhu\t%0,%1",
};

static const char * const output_93[] = {
  "#",
  "lhu\t%0,%1",
};

static const char * const output_94[] = {
  "and\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_95[] = {
  "and\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_96[] = {
  "and\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_97[] = {
  "#",
  "lw\t%0,%1",
};

static const char * const output_98[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_99[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_100[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_101[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_102[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_103[] = {
  "#",
  "lh\t%0,%1",
};

static const char *
output_131 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1501 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_132 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1511 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_133 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1538 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_134 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1563 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_135 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1575 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_136 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1575 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "addw\t%0,%1,%2" : "add\t%0,%1,%2"; }
}

static const char *
output_139 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1604 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_140 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1625 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_141 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1635 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_142 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1658 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_143 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1668 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_144 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1678 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_146 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1732 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 0);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_147 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1732 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 0);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_148 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1732 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 0);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_149 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1747 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 1);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_150 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1747 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 1);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_151 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1747 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = riscv_subword (operands[0], 1);
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_152 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1762 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[1] = riscv_subword (operands[1], INTVAL (operands[2]));
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_153 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1762 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[1] = riscv_subword (operands[1], INTVAL (operands[2]));
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_154 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1762 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[1] = riscv_subword (operands[1], INTVAL (operands[2]));
  return riscv_output_move (operands[0], operands[1]);
}
}

static const char *
output_157 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1822 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "sllw\t%0,%1,%2" : "sll\t%0,%1,%2";
}
}

static const char *
output_158 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1822 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "sraw\t%0,%1,%2" : "sra\t%0,%1,%2";
}
}

static const char *
output_159 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1822 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "srlw\t%0,%1,%2" : "srl\t%0,%1,%2";
}
}

static const char *
output_168 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1865 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "sll\t%0,%1,%2";
}
}

static const char *
output_169 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1865 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "sra\t%0,%1,%2";
}
}

static const char *
output_170 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1865 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "srl\t%0,%1,%2";
}
}

static const char *
output_171 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1881 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sllw\t%0,%1,%2";
}
}

static const char *
output_172 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1881 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sraw\t%0,%1,%2";
}
}

static const char *
output_173 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1881 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "srlw\t%0,%1,%2";
}
}

static const char *
output_174 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1908 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[3]) == CONST_INT)
    return "b%C1z\t%2,%0";
  return "b%C1\t%2,%3,%0";
}
}

static const char *
output_175 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1908 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[3]) == CONST_INT)
    return "b%C1z\t%2,%0";
  return "b%C1\t%2,%3,%0";
}
}

static const char *
output_214 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_215 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_216 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_217 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_218 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_219 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_220 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_221 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2085 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_232 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2292 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[0]) ? "jr\t%0"
	   : absolute_symbolic_operand (operands[0], VOIDmode) ? "tail\t%0"
	   : "tail\t%0@"; }
}

static const char *
output_233 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2313 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[1]) ? "jr\t%1"
	   : absolute_symbolic_operand (operands[1], VOIDmode) ? "tail\t%1"
	   : "tail\t%1@"; }
}

static const char *
output_234 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2327 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[1]) ? "jr\t%1"
	   : absolute_symbolic_operand (operands[1], VOIDmode) ? "tail\t%1"
	   : "tail\t%1@"; }
}

static const char *
output_235 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2348 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[0]) ? "jalr\t%0"
	   : absolute_symbolic_operand (operands[0], VOIDmode) ? "call\t%0"
	   : "call\t%0@"; }
}

static const char *
output_236 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2371 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[1]) ? "jalr\t%1"
	   : absolute_symbolic_operand (operands[1], VOIDmode) ? "call\t%1"
	   : "call\t%1@"; }
}

static const char *
output_237 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2386 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ return REG_P (operands[1]) ? "jalr\t%1"
	   : absolute_symbolic_operand (operands[1], VOIDmode) ? "call\t%1"
	   : "call\t%1@"; }
}

static const char *
output_240 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 54 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
{
  switch (INTVAL (operands[1]))
    {
    case MEMMODEL_SEQ_CST:
    case MEMMODEL_ACQ_REL:
      return "fence rw,rw";
    case MEMMODEL_ACQUIRE:
    case MEMMODEL_CONSUME:
      return "fence r,rw";
    case MEMMODEL_RELEASE:
      return "fence rw,w";
    default:
      gcc_unreachable();
    }
}
}



static const struct insn_operand_data operand_data[] = 
{
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,W",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,W",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,i,m,r,*J*r,*m,*f,*f",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*m,*f,*f",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*m,*f,*f",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*r",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*f",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,Q",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*r",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,I,m,rJ,*r*J,*f",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*r,*r,*r,*m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r,*f,*G*r,*m,*r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "Gr,m,r",
    SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*r,*r,*m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r*G,*m,*r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*r,*r,*r,*m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r,*f,*r*G,*m,*r",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "rG,m,rG",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,i,m,rJ",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,f",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "rJ,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0,0",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,m",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,m",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "f,f",
    TFmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_arith_operand,
    "I",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_order_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_order_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    pmode_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    call_insn_operand,
    "j,S",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "j,S",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=j,j",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    call_insn_operand,
    "r,S",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "r,S",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    BLKmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=A",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=A",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=&r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    splittable_const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    splittable_const_int_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    TImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "",
    DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "",
    TImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "",
    TFmode,
    0,
    0,
    1,
    1
  },
  {
    pmode_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    pmode_register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0,
    0,
    0
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    modular_operator,
    "",
    DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    modular_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    0,
    1,
    0
  },
  {
    modular_operator,
    "",
    SImode,
    0,
    1,
    0,
    0
  },
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data_d insn_data[] = 
{
  /* <internal>:0 */
  {
    "*placeholder_for_nothing",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:411 */
  {
    "addsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fadd.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:411 */
  {
    "adddf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fadd.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_adddf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:426 */
  {
    "*addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_3 },
#else
    { 0, 0, output_3 },
#endif
    { 0 },
    &operand_data[7],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:426 */
  {
    "*addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_4 },
#else
    { 0, 0, output_4 },
#endif
    { 0 },
    &operand_data[10],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:426 */
  {
    "*addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_5 },
#else
    { 0, 0, output_5 },
#endif
    { 0 },
    &operand_data[13],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:426 */
  {
    "*addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_6 },
#else
    { 0, 0, output_6 },
#endif
    { 0 },
    &operand_data[16],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:435 */
  {
    "*adddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[19],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:444 */
  {
    "*addsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[22],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:454 */
  {
    "*adddisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[16],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:463 */
  {
    "*adddisisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[10],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:472 */
  {
    "*adddi3_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[16],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:490 */
  {
    "subsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsub.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:490 */
  {
    "subdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsub.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:505 */
  {
    "*subdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[25],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:514 */
  {
    "*subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_15 },
#else
    { 0, 0, output_15 },
#endif
    { 0 },
    &operand_data[28],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:514 */
  {
    "*subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_16 },
#else
    { 0, 0, output_16 },
#endif
    { 0 },
    &operand_data[31],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:514 */
  {
    "*subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_17 },
#else
    { 0, 0, output_17 },
#endif
    { 0 },
    &operand_data[34],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:514 */
  {
    "*subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_18 },
#else
    { 0, 0, output_18 },
#endif
    { 0 },
    &operand_data[37],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:523 */
  {
    "*subsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[40],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:533 */
  {
    "*subdisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[37],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:542 */
  {
    "*subdisisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[31],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:551 */
  {
    "*subsidisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[34],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:560 */
  {
    "*subdi3_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[43],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:578 */
  {
    "mulsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmul.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:578 */
  {
    "muldf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmul.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:593 */
  {
    "*mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_26 },
#else
    { 0, 0, output_26 },
#endif
    { 0 },
    &operand_data[46],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:593 */
  {
    "*mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_27 },
#else
    { 0, 0, output_27 },
#endif
    { 0 },
    &operand_data[49],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:593 */
  {
    "*mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_28 },
#else
    { 0, 0, output_28 },
#endif
    { 0 },
    &operand_data[52],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:593 */
  {
    "*mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_29 },
#else
    { 0, 0, output_29 },
#endif
    { 0 },
    &operand_data[55],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:602 */
  {
    "*muldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:611 */
  {
    "*muldi3_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:621 */
  {
    "*muldi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
  {
    "mulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulditi3 },
    &operand_data[61],
    3,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
  {
    "umulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulditi3 },
    &operand_data[61],
    3,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:665 */
  {
    "muldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulh\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldi3_highpart },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:665 */
  {
    "umuldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umuldi3_highpart },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:680 */
  {
    "usmulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulditi3 },
    &operand_data[61],
    3,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:705 */
  {
    "usmuldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhsu\t%0,%2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmuldi3_highpart },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:737 */
  {
    "mulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulh\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsi3_highpart },
    &operand_data[46],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:737 */
  {
    "umulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulsi3_highpart },
    &operand_data[46],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:770 */
  {
    "usmulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhsu\t%0,%2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulsi3_highpart },
    &operand_data[46],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:792 */
  {
    "divsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_42 },
#else
    { 0, 0, output_42 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divsi3 },
    &operand_data[46],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:792 */
  {
    "udivsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_43 },
#else
    { 0, 0, output_43 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_udivsi3 },
    &operand_data[46],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:801 */
  {
    "divdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divdi3 },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:801 */
  {
    "udivdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "divu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_udivdi3 },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:810 */
  {
    "modsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_46 },
#else
    { 0, 0, output_46 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_modsi3 },
    &operand_data[46],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:810 */
  {
    "umodsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_47 },
#else
    { 0, 0, output_47 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umodsi3 },
    &operand_data[46],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:819 */
  {
    "moddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "rem\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_moddi3 },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:819 */
  {
    "umoddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "remu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umoddi3 },
    &operand_data[58],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:828 */
  {
    "divsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fdiv.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:828 */
  {
    "divdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fdiv.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:844 */
  {
    "sqrtsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_52 },
#else
    { 0, 0, output_52 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sqrtsf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:844 */
  {
    "sqrtdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_53 },
#else
    { 0, 0, output_53 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sqrtdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:856 */
  {
    "fmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmasf4 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:856 */
  {
    "fmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmadf4 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:867 */
  {
    "fmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmssf4 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:867 */
  {
    "fmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmsdf4 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:878 */
  {
    "nfmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nfmasf4 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:878 */
  {
    "nfmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nfmadf4 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:890 */
  {
    "nfmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nfmssf4 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:890 */
  {
    "nfmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nfmsdf4 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:903 */
  {
    "*nfmasf4_fastmath",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:903 */
  {
    "*nfmadf4_fastmath",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:916 */
  {
    "*nfmssf4_fastmath",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[65],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:916 */
  {
    "*nfmsdf4_fastmath",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[69],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:935 */
  {
    "abssf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_abssf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:935 */
  {
    "absdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_absdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:951 */
  {
    "sminsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmin.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sminsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:951 */
  {
    "smindf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmin.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smindf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:960 */
  {
    "smaxsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmax.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smaxsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:960 */
  {
    "smaxdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmax.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smaxdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:977 */
  {
    "negsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fneg.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negsf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:977 */
  {
    "negdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fneg.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:985 */
  {
    "one_cmplsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_one_cmplsi2 },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:985 */
  {
    "one_cmpldi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_one_cmpldi2 },
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1001 */
  {
    "andsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_andsi3 },
    &operand_data[73],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1001 */
  {
    "anddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_anddi3 },
    &operand_data[76],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1010 */
  {
    "iorsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_iorsi3 },
    &operand_data[73],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1010 */
  {
    "iordi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_iordi3 },
    &operand_data[76],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1019 */
  {
    "xorsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xorsi3 },
    &operand_data[73],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1019 */
  {
    "xordi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xordi3 },
    &operand_data[76],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1035 */
  {
    "truncdfsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_truncdfsf2 },
    &operand_data[79],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1049 */
  {
    "truncdisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_83 },
#else
    { 0, output_83, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_truncdisi2 },
    &operand_data[81],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1061 */
  {
    "*ashr_truncqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[83],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1061 */
  {
    "*ashr_trunchi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[86],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1061 */
  {
    "*ashr_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[89],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1071 */
  {
    "*lshr32_truncqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[83],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1071 */
  {
    "*lshr32_trunchi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[86],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1071 */
  {
    "*lshr32_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sra\t%0,%1,32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[49],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1090 */
  {
    "zero_extendsidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_90 },
#else
    { 0, output_90, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendsidi2 },
    &operand_data[92],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1109 */
  {
    "*clear_upper32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_91 },
#else
    { 0, 0, output_91 },
#endif
    { 0 },
    &operand_data[94],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
  {
    "zero_extendhisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_92 },
#else
    { 0, output_92, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendhisi2 },
    &operand_data[96],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
  {
    "zero_extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_93 },
#else
    { 0, output_93, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendhidi2 },
    &operand_data[98],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
  {
    "zero_extendqihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_94 },
#else
    { 0, output_94, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqihi2 },
    &operand_data[100],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
  {
    "zero_extendqisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_95 },
#else
    { 0, output_95, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqisi2 },
    &operand_data[102],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
  {
    "zero_extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_96 },
#else
    { 0, output_96, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqidi2 },
    &operand_data[104],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1178 */
  {
    "extendsidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_97 },
#else
    { 0, output_97, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendsidi2 },
    &operand_data[106],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_98 },
#else
    { 0, output_98, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqihi2 },
    &operand_data[100],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendqisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_99 },
#else
    { 0, output_99, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqisi2 },
    &operand_data[102],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_100 },
#else
    { 0, output_100, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqidi2 },
    &operand_data[104],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendhihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_101 },
#else
    { 0, output_101, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhihi2 },
    &operand_data[108],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_102 },
#else
    { 0, output_102, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhisi2 },
    &operand_data[96],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_103 },
#else
    { 0, output_103, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhidi2 },
    &operand_data[98],
    2,
    2,
    0,
    2,
    2
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1218 */
  {
    "extendsfdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendsfdf2 },
    &operand_data[110],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1234 */
  {
    "fix_truncdfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncdfsi2 },
    &operand_data[112],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1244 */
  {
    "fix_truncsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncsfsi2 },
    &operand_data[114],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1254 */
  {
    "fix_truncdfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncdfdi2 },
    &operand_data[116],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1264 */
  {
    "fix_truncsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncsfdi2 },
    &operand_data[118],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1274 */
  {
    "floatsidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.w\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatsidf2 },
    &operand_data[120],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1284 */
  {
    "floatdidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.l\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatdidf2 },
    &operand_data[122],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1294 */
  {
    "floatsisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.w\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatsisf2 },
    &operand_data[124],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1304 */
  {
    "floatdisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.l\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatdisf2 },
    &operand_data[126],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1314 */
  {
    "floatunssidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.wu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunssidf2 },
    &operand_data[120],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1324 */
  {
    "floatunsdidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.lu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunsdidf2 },
    &operand_data[122],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1334 */
  {
    "floatunssisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.wu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunssisf2 },
    &operand_data[124],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1344 */
  {
    "floatunsdisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.lu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunsdisf2 },
    &operand_data[126],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1354 */
  {
    "fixuns_truncdfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.wu.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncdfsi2 },
    &operand_data[112],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1364 */
  {
    "fixuns_truncsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.wu.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncsfsi2 },
    &operand_data[114],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1374 */
  {
    "fixuns_truncdfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.lu.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncdfdi2 },
    &operand_data[116],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1384 */
  {
    "fixuns_truncsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.lu.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncsfdi2 },
    &operand_data[118],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1404 */
  {
    "got_loadsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_loadsi },
    &operand_data[128],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1404 */
  {
    "got_loaddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_loaddi },
    &operand_data[130],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1413 */
  {
    "tls_add_tp_lesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%2,%%tprel_add(%3)",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tls_add_tp_lesi },
    &operand_data[132],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1413 */
  {
    "tls_add_tp_ledi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%2,%%tprel_add(%3)",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tls_add_tp_ledi },
    &operand_data[136],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1424 */
  {
    "got_load_tls_gdsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.gd\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_gdsi },
    &operand_data[128],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1424 */
  {
    "got_load_tls_gddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.gd\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_gddi },
    &operand_data[130],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1433 */
  {
    "got_load_tls_iesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.ie\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_iesi },
    &operand_data[128],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1433 */
  {
    "got_load_tls_iedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.ie\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_iedi },
    &operand_data[130],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1446 */
  {
    "*lowsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%R2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[140],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1446 */
  {
    "*lowdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%R2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[143],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1495 */
  {
    "*movdi_32bit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_131 },
#else
    { 0, 0, output_131 },
#endif
    { 0 },
    &operand_data[146],
    2,
    2,
    0,
    8,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1505 */
  {
    "*movdi_64bit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_132 },
#else
    { 0, 0, output_132 },
#endif
    { 0 },
    &operand_data[148],
    2,
    2,
    0,
    8,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1533 */
  {
    "*movsi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_133 },
#else
    { 0, 0, output_133 },
#endif
    { 0 },
    &operand_data[150],
    2,
    2,
    0,
    8,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1558 */
  {
    "*movhi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_134 },
#else
    { 0, 0, output_134 },
#endif
    { 0 },
    &operand_data[152],
    2,
    2,
    0,
    6,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1570 */
  {
    "addhihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_135 },
#else
    { 0, 0, output_135 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addhihi3 },
    &operand_data[154],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1570 */
  {
    "addsihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_136 },
#else
    { 0, 0, output_136 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addsihi3 },
    &operand_data[157],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1579 */
  {
    "xorhihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xorhihi3 },
    &operand_data[154],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1579 */
  {
    "xorsihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xorsihi3 },
    &operand_data[157],
    3,
    3,
    0,
    2,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1599 */
  {
    "*movqi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_139 },
#else
    { 0, 0, output_139 },
#endif
    { 0 },
    &operand_data[160],
    2,
    2,
    0,
    6,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1619 */
  {
    "*movsf_hardfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_140 },
#else
    { 0, 0, output_140 },
#endif
    { 0 },
    &operand_data[162],
    2,
    2,
    0,
    10,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1629 */
  {
    "*movsf_softfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_141 },
#else
    { 0, 0, output_141 },
#endif
    { 0 },
    &operand_data[164],
    2,
    2,
    0,
    3,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1652 */
  {
    "*movdf_hardfloat_rv32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_142 },
#else
    { 0, 0, output_142 },
#endif
    { 0 },
    &operand_data[166],
    2,
    2,
    0,
    8,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1662 */
  {
    "*movdf_hardfloat_rv64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_143 },
#else
    { 0, 0, output_143 },
#endif
    { 0 },
    &operand_data[168],
    2,
    2,
    0,
    10,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1672 */
  {
    "*movdf_softfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_144 },
#else
    { 0, 0, output_144 },
#endif
    { 0 },
    &operand_data[170],
    2,
    2,
    0,
    3,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1693 */
  {
    "*movti",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[172],
    2,
    2,
    0,
    4,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
  {
    "load_lowdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_146 },
#else
    { 0, 0, output_146 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_lowdf },
    &operand_data[174],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
  {
    "load_lowdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_147 },
#else
    { 0, 0, output_147 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_lowdi },
    &operand_data[176],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
  {
    "load_lowtf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_148 },
#else
    { 0, 0, output_148 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_lowtf },
    &operand_data[178],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
  {
    "load_highdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_149 },
#else
    { 0, 0, output_149 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_highdf },
    &operand_data[180],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
  {
    "load_highdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_150 },
#else
    { 0, 0, output_150 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_highdi },
    &operand_data[183],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
  {
    "load_hightf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_151 },
#else
    { 0, 0, output_151 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_load_hightf },
    &operand_data[186],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
  {
    "store_worddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_152 },
#else
    { 0, 0, output_152 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_store_worddf },
    &operand_data[189],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
  {
    "store_worddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_153 },
#else
    { 0, 0, output_153 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_store_worddi },
    &operand_data[192],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
  {
    "store_wordtf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_154 },
#else
    { 0, 0, output_154 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_store_wordtf },
    &operand_data[195],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1781 */
  {
    "fence",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%|fence%-",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fence },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1786 */
  {
    "fence_i",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fence.i",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fence_i },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
  {
    "ashlsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_157 },
#else
    { 0, 0, output_157 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashlsi3 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
  {
    "ashrsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_158 },
#else
    { 0, 0, output_158 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashrsi3 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
  {
    "lshrsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_159 },
#else
    { 0, 0, output_159 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lshrsi3 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1832 */
  {
    "*ashldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1832 */
  {
    "*ashrdisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sraw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1832 */
  {
    "*lshrdisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "srlw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1841 */
  {
    "*ashldi3_truncsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[204],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1851 */
  {
    "*ashldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1851 */
  {
    "*ashldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[207],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1851 */
  {
    "*ashldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[210],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1851 */
  {
    "*ashldisi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sllw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
  {
    "ashldi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_168 },
#else
    { 0, 0, output_168 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashldi3 },
    &operand_data[213],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
  {
    "ashrdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_169 },
#else
    { 0, 0, output_169 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashrdi3 },
    &operand_data[213],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
  {
    "lshrdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_170 },
#else
    { 0, 0, output_170 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lshrdi3 },
    &operand_data[213],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
  {
    "ashlsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_171 },
#else
    { 0, 0, output_171 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashlsi3_extend },
    &operand_data[216],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
  {
    "ashrsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_172 },
#else
    { 0, 0, output_172 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashrsi3_extend },
    &operand_data[216],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
  {
    "lshrsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_173 },
#else
    { 0, 0, output_173 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lshrsi3_extend },
    &operand_data[216],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1899 */
  {
    "*branch_ordersi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_174 },
#else
    { 0, 0, output_174 },
#endif
    { 0 },
    &operand_data[219],
    4,
    4,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1899 */
  {
    "*branch_orderdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_175 },
#else
    { 0, 0, output_175 },
#endif
    { 0 },
    &operand_data[223],
    4,
    4,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
  {
    "*branch_on_bitsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[227],
    4,
    5,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
  {
    "*branch_on_bitdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[232],
    4,
    5,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
  {
    "*branch_on_bit_rangesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[227],
    4,
    5,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
  {
    "*branch_on_bit_rangedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[232],
    4,
    5,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2025 */
  {
    "cstoresf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.s\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoresf4 },
    &operand_data[237],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2025 */
  {
    "cstoredf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.d\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoredf4 },
    &operand_data[241],
    4,
    4,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2035 */
  {
    "*seq_zero_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2035 */
  {
    "*seq_zero_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[49],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2035 */
  {
    "*seq_zero_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2035 */
  {
    "*seq_zero_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2044 */
  {
    "*sne_zero_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2044 */
  {
    "*sne_zero_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[49],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2044 */
  {
    "*sne_zero_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2044 */
  {
    "*sne_zero_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgt_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[245],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgtu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[245],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgt_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[248],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgtu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[248],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgt_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[251],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgtu_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[251],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgt_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[254],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2053 */
  {
    "*sgtu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[254],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sge_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sgeu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sge_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[49],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sgeu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[49],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sge_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sgeu_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sge_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2062 */
  {
    "*sgeu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[58],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*slt_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*sltu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[198],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*slt_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*sltu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[201],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*slt_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*sltu_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[216],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*slt_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[213],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2071 */
  {
    "*sltu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[213],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sle_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_214 },
#else
    { 0, 0, output_214 },
#endif
    { 0 },
    &operand_data[257],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sleu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_215 },
#else
    { 0, 0, output_215 },
#endif
    { 0 },
    &operand_data[257],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sle_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_216 },
#else
    { 0, 0, output_216 },
#endif
    { 0 },
    &operand_data[260],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sleu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_217 },
#else
    { 0, 0, output_217 },
#endif
    { 0 },
    &operand_data[260],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sle_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_218 },
#else
    { 0, 0, output_218 },
#endif
    { 0 },
    &operand_data[263],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sleu_sidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_219 },
#else
    { 0, 0, output_219 },
#endif
    { 0 },
    &operand_data[263],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sle_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_220 },
#else
    { 0, 0, output_220 },
#endif
    { 0 },
    &operand_data[266],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2080 */
  {
    "*sleu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_221 },
#else
    { 0, 0, output_221 },
#endif
    { 0 },
    &operand_data[266],
    3,
    3,
    0,
    1,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2101 */
  {
    "jump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "j\t%l0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_jump },
    &operand_data[219],
    1,
    1,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2121 */
  {
    "indirect_jumpsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jumpsi },
    &operand_data[30],
    1,
    1,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2121 */
  {
    "indirect_jumpdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jumpdi },
    &operand_data[27],
    1,
    1,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2145 */
  {
    "tablejumpsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejumpsi },
    &operand_data[269],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2145 */
  {
    "tablejumpdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejumpdi },
    &operand_data[271],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2173 */
  {
    "blockage",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_blockage },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2204 */
  {
    "simple_return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_simple_return },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2213 */
  {
    "simple_return_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_simple_return_internal },
    &operand_data[273],
    1,
    1,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2238 */
  {
    "eh_set_lr_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_set_lr_si },
    &operand_data[274],
    1,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2244 */
  {
    "eh_set_lr_di",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_set_lr_di },
    &operand_data[276],
    1,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2288 */
  {
    "sibcall_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_232 },
#else
    { 0, 0, output_232 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_internal },
    &operand_data[278],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2308 */
  {
    "sibcall_value_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_233 },
#else
    { 0, 0, output_233 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_value_internal },
    &operand_data[280],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2318 */
  {
    "sibcall_value_multiple_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_234 },
#else
    { 0, 0, output_234 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_value_multiple_internal },
    &operand_data[280],
    4,
    5,
    2,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2343 */
  {
    "call_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_235 },
#else
    { 0, 0, output_235 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_internal },
    &operand_data[285],
    2,
    2,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2365 */
  {
    "call_value_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_236 },
#else
    { 0, 0, output_236 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_value_internal },
    &operand_data[287],
    3,
    3,
    0,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2377 */
  {
    "call_value_multiple_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_237 },
#else
    { 0, 0, output_237 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_value_multiple_internal },
    &operand_data[287],
    4,
    4,
    2,
    2,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2414 */
  {
    "nop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "nop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nop },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2421 */
  {
    "trap",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sbreak",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_trap },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:49 */
  {
    "mem_thread_fence_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_240 },
#else
    { 0, 0, output_240 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mem_thread_fence_1 },
    &operand_data[291],
    2,
    2,
    1,
    0,
    3
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:73 */
  {
    "atomic_storesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoswap.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_storesi },
    &operand_data[293],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:73 */
  {
    "atomic_storedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoswap.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_storedi },
    &operand_data[296],
    3,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_addsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoadd.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_addsi },
    &operand_data[299],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_orsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoor.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_orsi },
    &operand_data[299],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_xorsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoxor.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_xorsi },
    &operand_data[299],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_andsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoand.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_andsi },
    &operand_data[299],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_adddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoadd.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_adddi },
    &operand_data[302],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_ordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoor.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_ordi },
    &operand_data[302],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_xordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoxor.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_xordi },
    &operand_data[302],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
  {
    "atomic_anddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoand.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_anddi },
    &operand_data[302],
    3,
    3,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_addsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoadd.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_addsi },
    &operand_data[305],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_orsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoor.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_orsi },
    &operand_data[305],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_xorsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoxor.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_xorsi },
    &operand_data[305],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_andsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoand.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_andsi },
    &operand_data[305],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_adddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoadd.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_adddi },
    &operand_data[309],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_ordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoor.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_ordi },
    &operand_data[309],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_xordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoxor.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_xordi },
    &operand_data[309],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
  {
    "atomic_fetch_anddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoand.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_anddi },
    &operand_data[309],
    4,
    4,
    2,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:104 */
  {
    "atomic_exchangesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoswap.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_exchangesi },
    &operand_data[313],
    4,
    4,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:104 */
  {
    "atomic_exchangedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "amoswap.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_exchangedi },
    &operand_data[317],
    4,
    4,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:115 */
  {
    "atomic_cas_value_strongsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "1: lr.w%A5 %0,%1; bne %0,%z2,1f; sc.w%A4 %6,%z3,%1; bnez %6,1b; 1:",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_cas_value_strongsi },
    &operand_data[321],
    6,
    7,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:115 */
  {
    "atomic_cas_value_strongdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "1: lr.d%A5 %0,%1; bne %0,%z2,1f; sc.d%A4 %6,%z3,%1; bnez %6,1b; 1:",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_cas_value_strongdi },
    &operand_data[328],
    6,
    7,
    1,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:47 */
  {
    "*local_pic_loadqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lb\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[335],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:47 */
  {
    "*local_pic_loadhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lh\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[337],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:47 */
  {
    "*local_pic_loadsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[339],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:47 */
  {
    "*local_pic_loaddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[341],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:53 */
  {
    "*local_pic_loadsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "flw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[343],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:53 */
  {
    "*local_pic_loaddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fld\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[346],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:60 */
  {
    "*local_pic_loadsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "flw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[349],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:60 */
  {
    "*local_pic_loaddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fld\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[352],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[337],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[339],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[341],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[337],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[339],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loaduhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[341],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loadusi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[337],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loadusi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[339],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:67 */
  {
    "*local_pic_loadusi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[341],
    2,
    2,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:73 */
  {
    "*local_pic_storediqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sb\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[355],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:73 */
  {
    "*local_pic_storedihi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sh\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[358],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:73 */
  {
    "*local_pic_storedisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[361],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:73 */
  {
    "*local_pic_storedidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[364],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:80 */
  {
    "*local_pic_storesiqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sb\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[367],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:80 */
  {
    "*local_pic_storesihi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sh\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[370],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:80 */
  {
    "*local_pic_storesisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[373],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:80 */
  {
    "*local_pic_storesidi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[376],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:87 */
  {
    "*local_pic_storedisf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[379],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:87 */
  {
    "*local_pic_storedidf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[382],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:94 */
  {
    "*local_pic_storesisf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:94 */
  {
    "*local_pic_storesidf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[388],
    2,
    3,
    0,
    1,
    1
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:420 */
  {
    "addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addsi3 },
    &operand_data[391],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:420 */
  {
    "adddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_adddi3 },
    &operand_data[394],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:499 */
  {
    "subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subsi3 },
    &operand_data[397],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:499 */
  {
    "subdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subdi3 },
    &operand_data[400],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:587 */
  {
    "mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsi3 },
    &operand_data[397],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:587 */
  {
    "muldi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldi3 },
    &operand_data[400],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
  {
    "muldi3+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[403],
    0,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
  {
    "muldi3+2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[403],
    0,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:680 */
  {
    "mulsidi3-1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[403],
    0,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:719 */
  {
    "mulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsidi3 },
    &operand_data[407],
    3,
    4,
    0,
    1,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:719 */
  {
    "umulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulsidi3 },
    &operand_data[407],
    3,
    4,
    0,
    1,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:752 */
  {
    "usmulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulsidi3 },
    &operand_data[407],
    3,
    4,
    0,
    1,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1090 */
  {
    "usmulsidi3+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[411],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1109 */
  {
    "usmulsidi3+2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[413],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
  {
    "usmulsidi3+3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[415],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
  {
    "usmulsidi3+4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[417],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1178 */
  {
    "usmulsidi3+5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[411],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "usmulsidi3+6",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[419],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "usmulsidi3+7",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[421],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "usmulsidi3+8",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[423],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "movdi-7",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[425],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "movdi-6",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[415],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
  {
    "movdi-5",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[417],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1457 */
  {
    "movdi-4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[427],
    0,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1457 */
  {
    "movdi-3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[430],
    0,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1469 */
  {
    "movdi-2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[433],
    0,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1469 */
  {
    "movdi-1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[436],
    0,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1486 */
  {
    "movdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movdi },
    &operand_data[439],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1521 */
  {
    "movsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movsi },
    &operand_data[441],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1549 */
  {
    "movhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movhi },
    &operand_data[443],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1590 */
  {
    "movqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movqi },
    &operand_data[445],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1610 */
  {
    "movsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movsf },
    &operand_data[447],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1641 */
  {
    "movdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movdf },
    &operand_data[449],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1684 */
  {
    "movti",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movti },
    &operand_data[451],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1703 */
  {
    "movti+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[453],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1703 */
  {
    "movti+2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[455],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1714 */
  {
    "clear_cache-2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[457],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1714 */
  {
    "clear_cache-1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[459],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1771 */
  {
    "clear_cache",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_clear_cache },
    &operand_data[461],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1797 */
  {
    "movmemsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movmemsi },
    &operand_data[463],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1917 */
  {
    "condjump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_condjump },
    &operand_data[467],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1923 */
  {
    "cbranchsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchsi4 },
    &operand_data[469],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1923 */
  {
    "cbranchdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchdi4 },
    &operand_data[473],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1936 */
  {
    "cbranchsf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchsf4 },
    &operand_data[477],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1936 */
  {
    "cbranchdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchdf4 },
    &operand_data[481],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
  {
    "cbranchdf4+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[485],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
  {
    "cbranchdf4+2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[490],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
  {
    "cstoresi4-2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[485],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
  {
    "cstoresi4-1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[490],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2014 */
  {
    "cstoresi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoresi4 },
    &operand_data[495],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2014 */
  {
    "cstoredi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoredi4 },
    &operand_data[499],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2109 */
  {
    "indirect_jump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jump },
    &operand_data[280],
    1,
    1,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2128 */
  {
    "tablejump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejump },
    &operand_data[503],
    2,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2161 */
  {
    "prologue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_prologue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2180 */
  {
    "epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_epilogue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2188 */
  {
    "sibcall_epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_epilogue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2199 */
  {
    "return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_return },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2222 */
  {
    "eh_return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_return },
    &operand_data[505],
    1,
    1,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2250 */
  {
    "eh_return+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[506],
    0,
    2,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2277 */
  {
    "sibcall",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall },
    &operand_data[508],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2297 */
  {
    "sibcall_value",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_value },
    &operand_data[508],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2332 */
  {
    "call",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call },
    &operand_data[508],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2353 */
  {
    "call_value",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_value },
    &operand_data[508],
    4,
    4,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2393 */
  {
    "untyped_call",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_untyped_call },
    &operand_data[508],
    3,
    3,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:36 */
  {
    "mem_thread_fence",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mem_thread_fence },
    &operand_data[292],
    1,
    1,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:129 */
  {
    "atomic_compare_and_swapsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_compare_and_swapsi },
    &operand_data[512],
    8,
    8,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:129 */
  {
    "atomic_compare_and_swapdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_compare_and_swapdi },
    &operand_data[520],
    8,
    8,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:159 */
  {
    "atomic_test_and_set",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_test_and_set },
    &operand_data[528],
    3,
    3,
    0,
    1,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:6 */
  {
    "atomic_test_and_set+1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[531],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:22 */
  {
    "atomic_test_and_set+2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[536],
    0,
    5,
    0,
    0,
    0
  },
  /* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:34 */
  {
    "atomic_test_and_set+3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[541],
    0,
    5,
    0,
    0,
    0
  },
};


const char *
get_insn_name (int code)
{
  if (code == NOOP_MOVE_INSN_CODE)
    return "NOOP_MOVE";
  else
    return insn_data[code].name;
}
