/* Generated automatically by the program `genemit'
from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"
#include "expr.h"
#include "optabs.h"
#include "dfp.h"
#include "flags.h"
#include "output.h"
#include "insn-config.h"
#include "hard-reg-set.h"
#include "recog.h"
#include "resource.h"
#include "reload.h"
#include "diagnostic-core.h"
#include "regs.h"
#include "tm-constrs.h"
#include "ggc.h"
#include "basic-block.h"
#include "target.h"

#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:411 */
rtx
gen_addsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:411 */
rtx
gen_adddf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:490 */
rtx
gen_subsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:490 */
rtx
gen_subdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:578 */
rtx
gen_mulsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:578 */
rtx
gen_muldf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
rtx
gen_mulditi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
rtx
gen_umulditi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_ZERO_EXTEND (TImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:665 */
rtx
gen_muldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:665 */
rtx
gen_umuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_ZERO_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:680 */
rtx
gen_usmulditi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:705 */
rtx
gen_usmuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:737 */
rtx
gen_mulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:737 */
rtx
gen_umulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:770 */
rtx
gen_usmulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:792 */
rtx
gen_divsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:792 */
rtx
gen_udivsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UDIV (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:801 */
rtx
gen_divdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:801 */
rtx
gen_udivdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UDIV (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:810 */
rtx
gen_modsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MOD (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:810 */
rtx
gen_umodsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UMOD (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:819 */
rtx
gen_moddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MOD (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:819 */
rtx
gen_umoddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UMOD (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:828 */
rtx
gen_divsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:828 */
rtx
gen_divdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:844 */
rtx
gen_sqrtsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SQRT (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:844 */
rtx
gen_sqrtdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SQRT (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:856 */
rtx
gen_fmasf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	operand3));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:856 */
rtx
gen_fmadf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	operand3));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:867 */
rtx
gen_fmssf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	gen_rtx_NEG (SFmode,
	operand3)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:867 */
rtx
gen_fmsdf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	gen_rtx_NEG (DFmode,
	operand3)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:878 */
rtx
gen_nfmasf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (SFmode,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	operand3)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:878 */
rtx
gen_nfmadf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (DFmode,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	operand3)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:890 */
rtx
gen_nfmssf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (SFmode,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	gen_rtx_NEG (SFmode,
	operand3))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:890 */
rtx
gen_nfmsdf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (DFmode,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	gen_rtx_NEG (DFmode,
	operand3))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:935 */
rtx
gen_abssf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ABS (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:935 */
rtx
gen_absdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ABS (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:951 */
rtx
gen_sminsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMIN (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:951 */
rtx
gen_smindf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMIN (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:960 */
rtx
gen_smaxsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMAX (SFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:960 */
rtx
gen_smaxdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMAX (DFmode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:977 */
rtx
gen_negsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:977 */
rtx
gen_negdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:985 */
rtx
gen_one_cmplsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NOT (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:985 */
rtx
gen_one_cmpldi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NOT (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1001 */
rtx
gen_andsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_AND (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1001 */
rtx
gen_anddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_AND (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1010 */
rtx
gen_iorsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IOR (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1010 */
rtx
gen_iordi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IOR (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1019 */
rtx
gen_xorsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1019 */
rtx
gen_xordi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1035 */
rtx
gen_truncdfsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT_TRUNCATE (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1049 */
rtx
gen_truncdisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1090 */
rtx
gen_zero_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
rtx
gen_zero_extendhisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
rtx
gen_zero_extendhidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
rtx
gen_zero_extendqihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (HImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
rtx
gen_zero_extendqisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1149 */
rtx
gen_zero_extendqidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1178 */
rtx
gen_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendqihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (HImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendqisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendqidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendhihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (HImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendhisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
rtx
gen_extendhidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1218 */
rtx
gen_extendsfdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT_EXTEND (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1234 */
rtx
gen_fix_truncdfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1244 */
rtx
gen_fix_truncsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1254 */
rtx
gen_fix_truncdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1264 */
rtx
gen_fix_truncsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1274 */
rtx
gen_floatsidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1284 */
rtx
gen_floatdidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1294 */
rtx
gen_floatsisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1304 */
rtx
gen_floatdisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1314 */
rtx
gen_floatunssidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FLOAT (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1324 */
rtx
gen_floatunsdidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FLOAT (DFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1334 */
rtx
gen_floatunssisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FLOAT (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1344 */
rtx
gen_floatunsdisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FLOAT (SFmode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1354 */
rtx
gen_fixuns_truncdfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1364 */
rtx
gen_fixuns_truncsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1374 */
rtx
gen_fixuns_truncdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1384 */
rtx
gen_fixuns_truncsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1404 */
rtx
gen_got_loadsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	5));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1404 */
rtx
gen_got_loaddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	5));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1413 */
rtx
gen_tls_add_tp_lesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	7));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1413 */
rtx
gen_tls_add_tp_ledi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	7));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1424 */
rtx
gen_got_load_tls_gdsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	9));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1424 */
rtx
gen_got_load_tls_gddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	9));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1433 */
rtx
gen_got_load_tls_iesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	8));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1433 */
rtx
gen_got_load_tls_iedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	8));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1570 */
rtx
gen_addhihi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (HImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1570 */
rtx
gen_addsihi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (HImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1579 */
rtx
gen_xorhihi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (HImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1579 */
rtx
gen_xorsihi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (HImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
rtx
gen_load_lowdf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (1,
		operand1),
	0));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
rtx
gen_load_lowdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	0));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1727 */
rtx
gen_load_lowtf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (TFmode,
	gen_rtvec (1,
		operand1),
	0));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
rtx
gen_load_highdf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
rtx
gen_load_highdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1741 */
rtx
gen_load_hightf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (TFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
rtx
gen_store_worddf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
rtx
gen_store_worddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1756 */
rtx
gen_store_wordtf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1781 */
rtx
gen_fence (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	11);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1786 */
rtx
gen_fence_i (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	12);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
rtx
gen_ashlsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
rtx
gen_ashrsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1817 */
rtx
gen_lshrsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
rtx
gen_ashldi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
rtx
gen_ashrdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1860 */
rtx
gen_lshrdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
rtx
gen_ashlsi3_extend (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
rtx
gen_ashrsi3_extend (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1875 */
rtx
gen_lshrsi3_extend (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2025 */
rtx
gen_cstoresf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2025 */
rtx
gen_cstoredf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2101 */
rtx
gen_jump (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_LABEL_REF (VOIDmode,
	operand0));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2121 */
rtx
gen_indirect_jumpsi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2121 */
rtx
gen_indirect_jumpdi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2145 */
rtx
gen_tablejumpsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2145 */
rtx
gen_tablejumpdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2173 */
rtx
gen_blockage (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	10);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2204 */
rtx
gen_simple_return (void)
{
  return simple_return_rtx;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2213 */
rtx
gen_simple_return_internal (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		simple_return_rtx,
		gen_rtx_USE (VOIDmode,
	operand0)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2238 */
rtx
gen_eh_set_lr_si (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	3),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2244 */
rtx
gen_eh_set_lr_di (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	3),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2288 */
rtx
gen_sibcall_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2308 */
rtx
gen_sibcall_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2318 */
rtx
gen_sibcall_value_multiple_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	copy_rtx (operand1)),
	copy_rtx (operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2343 */
rtx
gen_call_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1),
		gen_hard_reg_clobber (SImode, 1)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2365 */
rtx
gen_call_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 1)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2377 */
rtx
gen_call_value_multiple_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	copy_rtx (operand1)),
	copy_rtx (operand2))),
		gen_hard_reg_clobber (SImode, 1)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2414 */
rtx
gen_nop (void)
{
  return const0_rtx;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2421 */
rtx
gen_trap (void)
{
  return gen_rtx_TRAP_IF (VOIDmode,
	const1_rtx,
	const0_rtx);
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:49 */
rtx
gen_mem_thread_fence_1 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (1,
		copy_rtx (operand0)),
	17)),
		operand1));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:73 */
rtx
gen_atomic_storesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	16));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:73 */
rtx
gen_atomic_storedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	16));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_addsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_PLUS (SImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_orsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_IOR (SImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_xorsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_XOR (SImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_andsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_AND (SImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_adddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_PLUS (DImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_ordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_IOR (DImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_xordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_XOR (DImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_anddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_AND (DImode,
	operand0,
	operand1),
		operand2),
	14));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_addsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_PLUS (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_orsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_IOR (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_xorsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_XOR (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_andsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_AND (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_adddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_PLUS (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_ordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_IOR (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_xordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_XOR (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:92 */
rtx
gen_atomic_fetch_anddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_AND (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	14))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:104 */
rtx
gen_atomic_exchangesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		operand1,
		operand3),
	15)),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	operand2)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:104 */
rtx
gen_atomic_exchangedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		operand1,
		operand3),
	15)),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	operand2)));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:115 */
rtx
gen_atomic_cas_value_strongsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (4,
		operand2,
		operand3,
		operand4,
		operand5),
	13)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:115 */
rtx
gen_atomic_cas_value_strongdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (4,
		operand2,
		operand3,
		operand4,
		operand5),
	13)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:420 */
rtx
gen_addsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:420 */
rtx
gen_adddi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:499 */
rtx
gen_subsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:499 */
rtx
gen_subdi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:587 */
rtx
gen_mulsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:587 */
rtx
gen_muldi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
extern rtx gen_split_298 (rtx, rtx *);
rtx
gen_split_298 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 659 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[4] = riscv_subword (operands[0], true);
  operands[5] = riscv_subword (operands[0], false);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  operand5 = operands[5];
  (void) operand5;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	copy_rtx (operand1)),
	gen_rtx_SIGN_EXTEND (TImode,
	copy_rtx (operand2))),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)]))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	copy_rtx (operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:640 */
extern rtx gen_split_299 (rtx, rtx *);
rtx
gen_split_299 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 659 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[4] = riscv_subword (operands[0], true);
  operands[5] = riscv_subword (operands[0], false);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  operand5 = operands[5];
  (void) operand5;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	copy_rtx (operand1)),
	gen_rtx_ZERO_EXTEND (TImode,
	copy_rtx (operand2))),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)]))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	copy_rtx (operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:680 */
extern rtx gen_split_300 (rtx, rtx *);
rtx
gen_split_300 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 699 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[4] = riscv_subword (operands[0], true);
  operands[5] = riscv_subword (operands[0], false);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  operand5 = operands[5];
  (void) operand5;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	copy_rtx (operand1)),
	gen_rtx_SIGN_EXTEND (TImode,
	copy_rtx (operand2))),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)]))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	copy_rtx (operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:719 */
rtx
gen_mulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx operand3 ATTRIBUTE_UNUSED;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 727 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_mulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))));
  emit_insn (gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:719 */
rtx
gen_umulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx operand3 ATTRIBUTE_UNUSED;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 727 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_umulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2))));
  emit_insn (gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:752 */
rtx
gen_usmulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx operand3 ATTRIBUTE_UNUSED;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 760 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_usmulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))));
  emit_insn (gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1090 */
extern rtx gen_split_304 (rtx, rtx *);
rtx
gen_split_304 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 1102 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{ operands[1] = gen_lowpart (DImode, operands[1]); }
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1109 */
extern rtx gen_split_305 (rtx, rtx *);
rtx
gen_split_305 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 1126 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"

  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
extern rtx gen_split_306 (rtx, rtx *);
rtx
gen_split_306 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1142 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
    operands[1] = gen_lowpart (SImode, operands[1]);
    operands[2] = GEN_INT(GET_MODE_BITSIZE(SImode) - 16);
  }
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1130 */
extern rtx gen_split_307 (rtx, rtx *);
rtx
gen_split_307 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1142 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
    operands[1] = gen_lowpart (DImode, operands[1]);
    operands[2] = GEN_INT(GET_MODE_BITSIZE(DImode) - 16);
  }
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1178 */
extern rtx gen_split_308 (rtx, rtx *);
rtx
gen_split_308 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 1187 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (REGNO (operands[0]) == REGNO (operands[1]))
    {
      emit_note (NOTE_INSN_DELETED);
      DONE;
    }
  operands[1] = gen_rtx_REG (DImode, REGNO (operands[1]));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_309 (rtx, rtx *);
rtx
gen_split_309 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_310 (rtx, rtx *);
rtx
gen_split_310 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_311 (rtx, rtx *);
rtx
gen_split_311 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_312 (rtx, rtx *);
rtx
gen_split_312 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_313 (rtx, rtx *);
rtx
gen_split_313 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1198 */
extern rtx gen_split_314 (rtx, rtx *);
rtx
gen_split_314 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 1209 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1457 */
extern rtx gen_split_315 (rtx, rtx *);
rtx
gen_split_315 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1463 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_move_integer (operands[2], operands[0], INTVAL (operands[1]));
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1457 */
extern rtx gen_split_316 (rtx, rtx *);
rtx
gen_split_316 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1463 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_move_integer (operands[2], operands[0], INTVAL (operands[1]));
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1469 */
extern rtx gen_split_317 (rtx, rtx *);
rtx
gen_split_317 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 1475 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_symbol (operands[2], operands[1],
		     MAX_MACHINE_MODE, &operands[3]);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand3));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1469 */
extern rtx gen_split_318 (rtx, rtx *);
rtx
gen_split_318 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 1475 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_symbol (operands[2], operands[1],
		     MAX_MACHINE_MODE, &operands[3]);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand3));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1486 */
rtx
gen_movdi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1490 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (DImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1521 */
rtx
gen_movsi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1525 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (SImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1549 */
rtx
gen_movhi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1553 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (HImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1590 */
rtx
gen_movqi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1594 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (QImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1610 */
rtx
gen_movsf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1614 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (SFmode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1641 */
rtx
gen_movdf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1645 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (DFmode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1684 */
rtx
gen_movti (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1688 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (TImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1703 */
extern rtx gen_split_326 (rtx, rtx *);
rtx
gen_split_326 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1709 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1703 */
extern rtx gen_split_327 (rtx, rtx *);
rtx
gen_split_327 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1709 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1714 */
extern rtx gen_split_328 (rtx, rtx *);
rtx
gen_split_328 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1719 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1714 */
extern rtx gen_split_329 (rtx, rtx *);
rtx
gen_split_329 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 1719 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1771 */
rtx
gen_clear_cache (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 1775 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"

{
  emit_insn(gen_fence_i());
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit (operand0);
  emit (operand1);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1797 */
rtx
gen_movmemsi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 1803 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (riscv_expand_block_move (operands[0], operands[1], operands[2]))
    DONE;
  else
    FAIL;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1917 */
rtx
gen_condjump (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	operand0,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1923 */
rtx
gen_cbranchsi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 1931 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1923 */
rtx
gen_cbranchdi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 1931 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1936 */
rtx
gen_cbranchsf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 1944 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1936 */
rtx
gen_cbranchdf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 1944 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
extern rtx gen_split_337 (rtx, rtx *);
rtx
gen_split_337 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
#line 1970 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  int shift = GET_MODE_BITSIZE (SImode) - 1 - INTVAL (operands[3]);
  operands[3] = GEN_INT (shift);

  if (GET_CODE (operands[0]) == EQ)
    operands[0] = gen_rtx_GE (SImode, operands[4], const0_rtx);
  else
    operands[0] = gen_rtx_LT (SImode, operands[4], const0_rtx);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFT (SImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1949 */
extern rtx gen_split_338 (rtx, rtx *);
rtx
gen_split_338 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
#line 1970 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  int shift = GET_MODE_BITSIZE (DImode) - 1 - INTVAL (operands[3]);
  operands[3] = GEN_INT (shift);

  if (GET_CODE (operands[0]) == EQ)
    operands[0] = gen_rtx_GE (DImode, operands[4], const0_rtx);
  else
    operands[0] = gen_rtx_LT (DImode, operands[4], const0_rtx);
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFT (DImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
extern rtx gen_split_339 (rtx, rtx *);
rtx
gen_split_339 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
#line 2001 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[3] = GEN_INT (GET_MODE_BITSIZE (SImode) - INTVAL (operands[3]));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFT (SImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:1980 */
extern rtx gen_split_340 (rtx, rtx *);
rtx
gen_split_340 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
#line 2001 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[3] = GEN_INT (GET_MODE_BITSIZE (DImode) - INTVAL (operands[3]));
}
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFT (DImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2014 */
rtx
gen_cstoresi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2020 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_scc (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2014 */
rtx
gen_cstoredi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2020 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_scc (operands);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2109 */
rtx
gen_indirect_jump (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 2112 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  operands[0] = force_reg (Pmode, operands[0]);
  if (Pmode == SImode)
    emit_jump_insn (gen_indirect_jumpsi (operands[0]));
  else
    emit_jump_insn (gen_indirect_jumpdi (operands[0]));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2128 */
rtx
gen_tablejump (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2132 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (CASE_VECTOR_PC_RELATIVE)
      operands[0] = expand_simple_binop (Pmode, PLUS, operands[0],
					 gen_rtx_LABEL_REF (Pmode, operands[1]),
					 NULL_RTX, 0, OPTAB_DIRECT);

  if (CASE_VECTOR_PC_RELATIVE && Pmode == DImode)
    emit_jump_insn (gen_tablejumpdi (operands[0], operands[1]));
  else
    emit_jump_insn (gen_tablejumpsi (operands[0], operands[1]));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0));
  emit_insn (gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2161 */
rtx
gen_prologue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 2164 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_prologue ();
  DONE;
}
  }
  emit_insn (const1_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2180 */
rtx
gen_epilogue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 2183 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_epilogue (false);
  DONE;
}
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2188 */
rtx
gen_sibcall_epilogue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 2191 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_epilogue (true);
  DONE;
}
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2199 */
rtx
gen_return (void)
{
  return simple_return_rtx;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2222 */
rtx
gen_eh_return (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 2225 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  if (GET_MODE (operands[0]) != word_mode)
    operands[0] = convert_to_mode (word_mode, operands[0], 0);
  if (TARGET_64BIT)
    emit_insn (gen_eh_set_lr_di (operands[0]));
  else
    emit_insn (gen_eh_set_lr_si (operands[0]));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
  }
  emit_insn (gen_rtx_USE (VOIDmode,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2250 */
extern rtx gen_split_350 (rtx, rtx *);
rtx
gen_split_350 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 2255 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_set_return_address (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2277 */
rtx
gen_sibcall (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2283 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_call (true, NULL_RTX, XEXP (operands[0], 0), operands[1]);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2297 */
rtx
gen_sibcall_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2303 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_call (true, operands[0], XEXP (operands[1], 0), operands[2]);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2332 */
rtx
gen_call (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2338 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_call (false, NULL_RTX, XEXP (operands[0], 0), operands[1]);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2353 */
rtx
gen_call_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2359 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  riscv_expand_call (false, operands[0], XEXP (operands[1], 0), operands[2]);
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md:2393 */
rtx
gen_untyped_call (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 2399 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
{
  int i;

  emit_call_insn (GEN_CALL (operands[0], const0_rtx, NULL, const0_rtx));

  for (i = 0; i < XVECLEN (operands[2], 0); i++)
    {
      rtx set = XVECEXP (operands[2], 0, i);
      riscv_emit_move (SET_DEST (set), SET_SRC (set));
    }

  emit_insn (gen_blockage ());
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	const0_rtx),
		operand1,
		operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:36 */
rtx
gen_mem_thread_fence (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 39 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
{
  if (INTVAL (operands[0]) != MEMMODEL_RELAXED)
    {
      rtx mem = gen_rtx_MEM (BLKmode, gen_rtx_SCRATCH (Pmode));
      MEM_VOLATILE_P (mem) = 1;
      emit_insn (gen_mem_thread_fence_1 (mem, operands[0]));
    }
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
  }
  emit (operand0);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:129 */
rtx
gen_atomic_compare_and_swapsi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3,
	rtx operand4,
	rtx operand5,
	rtx operand6,
	rtx operand7)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[8];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
    operands[4] = operand4;
    operands[5] = operand5;
    operands[6] = operand6;
    operands[7] = operand7;
#line 139 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
{
  emit_insn (gen_atomic_cas_value_strongsi (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx compare = operands[1];
  if (operands[3] != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (SImode, operands[1], operands[3]);
      compare = gen_reg_rtx (SImode);
      emit_insn (gen_rtx_SET (VOIDmode, compare, difference));
    }

  rtx eq = gen_rtx_EQ (SImode, compare, const0_rtx);
  rtx result = gen_reg_rtx (SImode);
  emit_insn (gen_rtx_SET (VOIDmode, result, eq));
  emit_insn (gen_rtx_SET (VOIDmode, operands[0], gen_lowpart (SImode, result)));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
    operand4 = operands[4];
    (void) operand4;
    operand5 = operands[5];
    (void) operand5;
    operand6 = operands[6];
    (void) operand6;
    operand7 = operands[7];
    (void) operand7;
  }
  emit (operand0);
  emit (operand1);
  emit (operand2);
  emit (operand3);
  emit (operand4);
  emit (operand5);
  emit (operand6);
  emit (operand7);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:129 */
rtx
gen_atomic_compare_and_swapdi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3,
	rtx operand4,
	rtx operand5,
	rtx operand6,
	rtx operand7)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[8];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
    operands[4] = operand4;
    operands[5] = operand5;
    operands[6] = operand6;
    operands[7] = operand7;
#line 139 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
{
  emit_insn (gen_atomic_cas_value_strongdi (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx compare = operands[1];
  if (operands[3] != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (DImode, operands[1], operands[3]);
      compare = gen_reg_rtx (DImode);
      emit_insn (gen_rtx_SET (VOIDmode, compare, difference));
    }

  rtx eq = gen_rtx_EQ (DImode, compare, const0_rtx);
  rtx result = gen_reg_rtx (DImode);
  emit_insn (gen_rtx_SET (VOIDmode, result, eq));
  emit_insn (gen_rtx_SET (VOIDmode, operands[0], gen_lowpart (SImode, result)));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
    operand4 = operands[4];
    (void) operand4;
    operand5 = operands[5];
    (void) operand5;
    operand6 = operands[6];
    (void) operand6;
    operand7 = operands[7];
    (void) operand7;
  }
  emit (operand0);
  emit (operand1);
  emit (operand2);
  emit (operand3);
  emit (operand4);
  emit (operand5);
  emit (operand6);
  emit (operand7);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md:159 */
rtx
gen_atomic_test_and_set (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 164 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
{
  /* We have no QImode atomics, so use the address LSBs to form a mask,
     then use an aligned SImode atomic. */
  rtx result = operands[0];
  rtx mem = operands[1];
  rtx model = operands[2];
  rtx addr = force_reg (Pmode, XEXP (mem, 0));

  rtx aligned_addr = gen_reg_rtx (Pmode);
  emit_move_insn (aligned_addr, gen_rtx_AND (Pmode, addr, GEN_INT (-4)));

  rtx aligned_mem = change_address (mem, SImode, aligned_addr);
  set_mem_alias_set (aligned_mem, 0);

  rtx offset = gen_reg_rtx (SImode);
  emit_move_insn (offset, gen_rtx_AND (SImode, gen_lowpart (SImode, addr),
				       GEN_INT (3)));

  rtx tmp = gen_reg_rtx (SImode);
  emit_move_insn (tmp, GEN_INT (1));

  rtx shmt = gen_reg_rtx (SImode);
  emit_move_insn (shmt, gen_rtx_ASHIFT (SImode, offset, GEN_INT (3)));

  rtx word = gen_reg_rtx (SImode);
  emit_move_insn (word, gen_rtx_ASHIFT (SImode, tmp, shmt));

  tmp = gen_reg_rtx (SImode);
  emit_insn (gen_atomic_fetch_orsi (tmp, aligned_mem, word, model));

  emit_move_insn (gen_lowpart (SImode, result),
		  gen_rtx_LSHIFTRT (SImode, tmp,
				    gen_lowpart (SImode, shmt)));
  DONE;
}
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit (operand0);
  emit (operand1);
  emit (operand2);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:6 */
extern rtx gen_peephole2_360 (rtx, rtx *);
rtx
gen_peephole2_360 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_fmt_ee (GET_CODE (operand4), DImode,
		operand1,
		operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:22 */
extern rtx gen_peephole2_361 (rtx, rtx *);
rtx
gen_peephole2_361 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_fmt_ee (GET_CODE (operand4), SImode,
		operand1,
		operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md:34 */
extern rtx gen_peephole2_362 (rtx, rtx *);
rtx
gen_peephole2_362 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_fmt_ee (GET_CODE (operand4), SImode,
		operand1,
		operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}



void
add_clobbers (rtx pattern ATTRIBUTE_UNUSED, int insn_code_number)
{
  switch (insn_code_number)
    {
    case 262:
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    case 237:
      XVECEXP (pattern, 0, 2) = gen_hard_reg_clobber (SImode, 1);
      break;

    case 236:
    case 235:
      XVECEXP (pattern, 0, 1) = gen_hard_reg_clobber (SImode, 1);
      break;

    case 261:
    case 234:
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 291:
    case 290:
    case 287:
    case 286:
    case 285:
    case 284:
    case 270:
    case 269:
    case 230:
    case 178:
    case 176:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 289:
    case 288:
    case 283:
    case 282:
    case 281:
    case 280:
    case 268:
    case 267:
    case 231:
    case 179:
    case 177:
    case 37:
    case 34:
    case 33:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    default:
      gcc_unreachable ();
    }
}


int
added_clobbers_hard_reg_p (int insn_code_number)
{
  switch (insn_code_number)
    {
    case 262:
    case 261:
    case 234:
    case 291:
    case 290:
    case 287:
    case 286:
    case 285:
    case 284:
    case 270:
    case 269:
    case 230:
    case 178:
    case 176:
    case 289:
    case 288:
    case 283:
    case 282:
    case 281:
    case 280:
    case 268:
    case 267:
    case 231:
    case 179:
    case 177:
    case 37:
    case 34:
    case 33:
      return 0;

    case 237:
    case 236:
    case 235:
      return 1;

    default:
      gcc_unreachable ();
    }
}
