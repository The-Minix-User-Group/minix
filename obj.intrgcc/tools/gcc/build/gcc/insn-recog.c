/* Generated automatically by the program `genrecog' from the target
   machine description file.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
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



/* `recog' contains a decision tree that recognizes whether the rtx
   X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.  If the rtx is valid, recog
   returns a nonnegative number which is the insn code number for the
   pattern that matched.  This is the same as the order in the machine
   description of the entry that matched.  This number can be used as an
   index into `insn_data' and other tables.

   The third argument to recog is an optional pointer to an int.  If
   present, recog will accept a pattern if it matches except for missing
   CLOBBER expressions at the end.  In that case, the value pointed to by
   the optional pointer will be set to the number of CLOBBERs that need
   to be added (it should be initialized to zero by the caller).  If it
   is set nonzero, the caller should allocate a PARALLEL of the
   appropriate size, copy the initial entries, and call add_clobbers
   (found in insn-emit.c) to fill in the CLOBBERs.


   The function split_insns returns 0 if the rtl could not
   be split or the split rtl as an INSN list if it can be.

   The function peephole2_insns returns 0 if the rtl could not
   be matched. If there was a match, the new rtl is returned in an INSN list,
   and LAST_INSN will point to the last recognized insn in the old sequence.
*/


extern rtx gen_split_298 (rtx, rtx *);
extern rtx gen_split_299 (rtx, rtx *);
extern rtx gen_split_300 (rtx, rtx *);
extern rtx gen_split_304 (rtx, rtx *);
extern rtx gen_split_305 (rtx, rtx *);
extern rtx gen_split_306 (rtx, rtx *);
extern rtx gen_split_307 (rtx, rtx *);
extern rtx gen_split_308 (rtx, rtx *);
extern rtx gen_split_309 (rtx, rtx *);
extern rtx gen_split_310 (rtx, rtx *);
extern rtx gen_split_311 (rtx, rtx *);
extern rtx gen_split_312 (rtx, rtx *);
extern rtx gen_split_313 (rtx, rtx *);
extern rtx gen_split_314 (rtx, rtx *);
extern rtx gen_split_315 (rtx, rtx *);
extern rtx gen_split_316 (rtx, rtx *);
extern rtx gen_split_317 (rtx, rtx *);
extern rtx gen_split_318 (rtx, rtx *);
extern rtx gen_split_326 (rtx, rtx *);
extern rtx gen_split_327 (rtx, rtx *);
extern rtx gen_split_328 (rtx, rtx *);
extern rtx gen_split_329 (rtx, rtx *);
extern rtx gen_split_337 (rtx, rtx *);
extern rtx gen_split_338 (rtx, rtx *);
extern rtx gen_split_339 (rtx, rtx *);
extern rtx gen_split_340 (rtx, rtx *);
extern rtx gen_split_350 (rtx, rtx *);
extern rtx gen_peephole2_360 (rtx, rtx *);
extern rtx gen_peephole2_361 (rtx, rtx *);
extern rtx gen_peephole2_362 (rtx, rtx *);



static int
recog_1 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L8;
    }
 L2351: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L878;
    }
 L2367: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L2070;
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L1860;
    }
  goto ret0;

 L8: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L2391;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2391: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L9;
    case MINUS:
      goto L79;
    case MULT:
      goto L156;
    case DIV:
      goto L378;
    case SQRT:
      goto L389;
    case FMA:
      goto L401;
    case NEG:
      goto L432;
    case ABS:
      goto L497;
    case SMIN:
      goto L508;
    case SMAX:
      goto L520;
    case FLOAT_EXTEND:
      goto L690;
    case FLOAT:
      goto L715;
    case UNSIGNED_FLOAT:
      goto L735;
    case UNSPEC:
      goto L2406;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2351;

 L9: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L10;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L10: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L11;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L11: ATTRIBUTE_UNUSED_LABEL
  if (
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 2;  /* adddf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L79: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L2408;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2408: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L80;
    }
 L2409: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L468;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L80: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L81;
    }
  x2 = XEXP (x1, 0);
  goto L2409;

 L81: ATTRIBUTE_UNUSED_LABEL
  if (
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 13;  /* subdf3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2409;

 L468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == MULT)
    goto L469;
  x1 = XEXP (x0, 0);
  goto L2351;

 L469: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L2410;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2410: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L470;
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L487;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L470: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L471;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L472;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L472: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 910 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 63;  /* *nfmadf4_fastmath */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L488;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L488: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 65;  /* *nfmsdf4_fastmath */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L156: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L157;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L158;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L158: ATTRIBUTE_UNUSED_LABEL
  if (
#line 284 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 25;  /* muldf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L379;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L380;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L380: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 832 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 51;  /* divdf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L389: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L390;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L390: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 847 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 53;  /* sqrtdf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L401: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L402;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L403;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_MODE (x2) == DFmode)
    goto L2413;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2413: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NEG)
    goto L419;
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L404;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L419: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L420;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L420: ATTRIBUTE_UNUSED_LABEL
  if (
#line 873 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 57;  /* fmsdf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L404: ATTRIBUTE_UNUSED_LABEL
  if (
#line 862 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 55;  /* fmadf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L2414;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2414: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FMA)
    goto L433;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L532;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L433: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L434;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L434: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L435;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L435: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_MODE (x3) == DFmode)
    goto L2417;
  x1 = XEXP (x0, 0);
  goto L2351;

 L2417: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L453;
  if (register_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L436;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L453: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DFmode))
    {
      operands[3] = x4;
      goto L454;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L454: ATTRIBUTE_UNUSED_LABEL
  if (
#line 897 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 61;  /* nfmsdf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L436: ATTRIBUTE_UNUSED_LABEL
  if (
#line 885 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 59;  /* nfmadf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L532: ATTRIBUTE_UNUSED_LABEL
  if (
#line 980 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 73;  /* negdf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L497: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L498;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L498: ATTRIBUTE_UNUSED_LABEL
  if (
#line 938 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 67;  /* absdf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L509;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L509: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L510;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L510: ATTRIBUTE_UNUSED_LABEL
  if (
#line 955 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 69;  /* smindf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L521;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L521: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L522;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L522: ATTRIBUTE_UNUSED_LABEL
  if (
#line 964 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 71;  /* smaxdf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L691;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L691: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1221 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 104;  /* extendsfdf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L716;
    }
 L720: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L721;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L716: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 109;  /* floatsidf2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L720;

 L721: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1287 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 110;  /* floatdidf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L735: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L736;
    }
 L740: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L741;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L736: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1317 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 113;  /* floatunssidf2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L740;

 L741: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1327 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 114;  /* floatunsdidf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L2406: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L2418;
    case 2:
      goto L2419;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L2418: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L895;
  x1 = XEXP (x0, 0);
  goto L2351;

 L895: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L896;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L896: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1731 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 288 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 146;  /* load_lowdf */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L2419: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 1)
    goto L910;
  x1 = XEXP (x0, 0);
  goto L2351;

 L910: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L911;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L911: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L912;
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L912: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1746 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 288 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 149;  /* load_highdf */
    }
  x1 = XEXP (x0, 0);
  goto L2351;

 L878: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L879;
    }
  x1 = XEXP (x0, 0);
  goto L2367;

 L879: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1655 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 142;  /* *movdf_hardfloat_rv32 */
    }
 L883: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1665 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 143;  /* *movdf_hardfloat_rv64 */
    }
 L887: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1675 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 144;  /* *movdf_softfloat */
    }
  x1 = XEXP (x0, 0);
  goto L2367;

 L2070: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2071;
    }
  goto ret0;

 L2071: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L2072;
    }
  goto ret0;

 L2072: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 289;  /* *local_pic_storedidf */
    }
 L2098: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 291;  /* *local_pic_storesidf */
    }
  goto ret0;

 L1860: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode
      && GET_CODE (x1) == MEM)
    goto L1861;
  goto ret0;

 L1861: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1862;
    }
  goto ret0;

 L1862: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 268;  /* *local_pic_loaddf */
    }
 L1888: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 270;  /* *local_pic_loaddf */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_2 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L15;
    case TRUNCATE:
      goto L66;
    case MINUS:
      goto L121;
    case MULT:
      goto L162;
    case DIV:
      goto L324;
    case UDIV:
      goto L330;
    case MOD:
      goto L348;
    case UMOD:
      goto L354;
    case NOT:
      goto L536;
    case AND:
      goto L545;
    case IOR:
      goto L556;
    case XOR:
      goto L567;
    case ZERO_EXTEND:
      goto L637;
    case SIGN_EXTEND:
      goto L668;
    case FIX:
      goto L695;
    case UNSIGNED_FIX:
      goto L755;
    case UNSPEC:
      goto L2455;
    case LO_SUM:
      goto L819;
    case ASHIFT:
      goto L950;
    case ASHIFTRT:
      goto L955;
    case LSHIFTRT:
      goto L960;
    case EQ:
      goto L1199;
    case NE:
      goto L1219;
    case GT:
      goto L1239;
    case GTU:
      goto L1244;
    case GE:
      goto L1285;
    case GEU:
      goto L1290;
    case LT:
      goto L1325;
    case LTU:
      goto L1330;
    case LE:
      goto L1371;
    case LEU:
      goto L1376;
    default:
     break;
   }
 L2444: ATTRIBUTE_UNUSED_LABEL
  if (fp_order_operator (x1, SImode))
    {
      operands[1] = x1;
      goto L1187;
    }
  goto ret0;

 L15: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2461;
    case DImode:
      goto L2460;
    default:
      break;
    }
  goto ret0;

 L2461: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L52;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L16;
    }
  goto ret0;

 L52: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L53;
    }
  goto ret0;

 L53: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L54;
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L62;
    }
  goto ret0;

 L54: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L55;
    }
  goto ret0;

 L55: ATTRIBUTE_UNUSED_LABEL
  if (
#line 458 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 9;  /* *adddisi3 */
    }
  goto ret0;

 L62: ATTRIBUTE_UNUSED_LABEL
  if (
#line 467 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 10;  /* *adddisisi3 */
    }
  goto ret0;

 L16: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 3;  /* *addsi3 */
    }
 L27: ATTRIBUTE_UNUSED_LABEL
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L28;
    }
  goto ret0;

 L28: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 5;  /* *addsi3 */
    }
  goto ret0;

 L2460: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L21;
    }
  goto ret0;

 L21: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L22;
    }
 L33: ATTRIBUTE_UNUSED_LABEL
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L34;
    }
  goto ret0;

 L22: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 4;  /* *addsi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L33;

 L34: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 6;  /* *addsi3 */
    }
  goto ret0;

 L66: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L2462;
  goto ret0;

 L2462: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L67;
    case MINUS:
      goto L144;
    case MULT:
      goto L195;
    case LSHIFTRT:
      goto L295;
    case ASHIFTRT:
      goto L603;
    case ASHIFT:
      goto L990;
    default:
     break;
   }
  goto ret0;

 L67: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L68;
    }
  goto ret0;

 L68: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L69;
    }
  goto ret0;

 L69: ATTRIBUTE_UNUSED_LABEL
  if (
#line 477 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 11;  /* *adddi3_truncsi */
    }
  goto ret0;

 L144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L145;
    }
  goto ret0;

 L145: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L146;
    }
  goto ret0;

 L146: ATTRIBUTE_UNUSED_LABEL
  if (
#line 565 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 23;  /* *subdi3_truncsi */
    }
  goto ret0;

 L195: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L196;
    }
  goto ret0;

 L196: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L197;
    }
  goto ret0;

 L197: ATTRIBUTE_UNUSED_LABEL
  if (
#line 616 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 31;  /* *muldi3_truncsi */
    }
  goto ret0;

 L295: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L2468;
  goto ret0;

 L2468: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == MULT)
    goto L296;
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L623;
    }
  goto ret0;

 L296: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L2470;
  goto ret0;

 L2470: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L297;
    case ZERO_EXTEND:
      goto L307;
    default:
     break;
   }
  goto ret0;

 L297: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L298;
    }
  goto ret0;

 L298: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L299;
  goto ret0;

 L299: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L300;
    }
  goto ret0;

 L300: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 746 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && !TARGET_64BIT))
    {
      return 39;  /* mulsi3_highpart */
    }
  goto ret0;

 L307: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L308;
    }
  goto ret0;

 L308: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode)
    goto L2472;
  goto ret0;

 L2472: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTEND:
      goto L309;
    case SIGN_EXTEND:
      goto L319;
    default:
     break;
   }
  goto ret0;

 L309: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L310;
    }
  goto ret0;

 L310: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 746 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && !TARGET_64BIT))
    {
      return 40;  /* umulsi3_highpart */
    }
  goto ret0;

 L319: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L320;
    }
  goto ret0;

 L320: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 779 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && !TARGET_64BIT))
    {
      return 41;  /* usmulsi3_highpart */
    }
  goto ret0;

 L623: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1076 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 89;  /* *lshr32_truncsi */
    }
  goto ret0;

 L603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L604;
    }
  goto ret0;

 L604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L605;
    }
  goto ret0;

 L605: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63)))
    {
      return 86;  /* *ashr_truncsi */
    }
  goto ret0;

 L990: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L991;
    }
  goto ret0;

 L991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L992;
    }
  goto ret0;

 L992: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1846 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && INTVAL (operands[2]) < 32))
    {
      return 163;  /* *ashldi3_truncsi */
    }
  goto ret0;

 L121: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L122;
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L92;
    }
 L96: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L97;
    }
  goto ret0;

 L122: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L123;
    }
  goto ret0;

 L123: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L2474;
  goto ret0;

 L2474: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L124;
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L132;
    }
  goto ret0;

 L124: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L125;
    }
  goto ret0;

 L125: ATTRIBUTE_UNUSED_LABEL
  if (
#line 537 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 20;  /* *subdisi3 */
    }
  goto ret0;

 L132: ATTRIBUTE_UNUSED_LABEL
  if (
#line 546 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 21;  /* *subdisisi3 */
    }
  goto ret0;

 L92: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2478;
    case DImode:
      goto L2477;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L96;

 L2478: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L138;
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      return 15;  /* *subsi3 */
    }
  x2 = XEXP (x1, 0);
  goto L96;

 L138: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L139;
    }
  x2 = XEXP (x1, 0);
  goto L96;

 L139: ATTRIBUTE_UNUSED_LABEL
  if (
#line 555 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 22;  /* *subsidisi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L96;

 L2477: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L104;
    }
  x2 = XEXP (x1, 0);
  goto L96;

 L104: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 17;  /* *subsi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L96;

 L97: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2479;
    case DImode:
      goto L2480;
    default:
      break;
    }
  goto ret0;

 L2479: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L98;
    }
  goto ret0;

 L98: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 16;  /* *subsi3 */
    }
  goto ret0;

 L2480: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L110;
    }
  goto ret0;

 L110: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 18;  /* *subsi3 */
    }
  goto ret0;

 L162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2483;
    case DImode:
      goto L2482;
    default:
      break;
    }
  goto ret0;

 L2483: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L187;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L163;
    }
  goto ret0;

 L187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L188;
    }
  goto ret0;

 L188: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L189;
  goto ret0;

 L189: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L190;
    }
  goto ret0;

 L190: ATTRIBUTE_UNUSED_LABEL
  if (
#line 606 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 30;  /* *muldisi3 */
    }
  goto ret0;

 L163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2484;
    case DImode:
      goto L2485;
    default:
      break;
    }
  goto ret0;

 L2484: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L164;
    }
  goto ret0;

 L164: ATTRIBUTE_UNUSED_LABEL
  if (
#line 597 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV))
    {
      return 26;  /* *mulsi3 */
    }
  goto ret0;

 L2485: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L176;
    }
  goto ret0;

 L176: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 597 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV) && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 28;  /* *mulsi3 */
    }
  goto ret0;

 L2482: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L169;
    }
  goto ret0;

 L169: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2486;
    case DImode:
      goto L2487;
    default:
      break;
    }
  goto ret0;

 L2486: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L170;
    }
  goto ret0;

 L170: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 597 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 27;  /* *mulsi3 */
    }
  goto ret0;

 L2487: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L182;
    }
  goto ret0;

 L182: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 597 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 29;  /* *mulsi3 */
    }
  goto ret0;

 L324: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L325;
    }
  goto ret0;

 L325: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L326;
    }
  goto ret0;

 L326: ATTRIBUTE_UNUSED_LABEL
  if (
#line 796 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV))
    {
      return 42;  /* divsi3 */
    }
  goto ret0;

 L330: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L331;
    }
  goto ret0;

 L331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L332;
    }
  goto ret0;

 L332: ATTRIBUTE_UNUSED_LABEL
  if (
#line 796 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV))
    {
      return 43;  /* udivsi3 */
    }
  goto ret0;

 L348: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L349;
    }
  goto ret0;

 L349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L350;
    }
  goto ret0;

 L350: ATTRIBUTE_UNUSED_LABEL
  if (
#line 814 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV))
    {
      return 46;  /* modsi3 */
    }
  goto ret0;

 L354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L355;
    }
  goto ret0;

 L355: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L356;
    }
  goto ret0;

 L356: ATTRIBUTE_UNUSED_LABEL
  if (
#line 814 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV))
    {
      return 47;  /* umodsi3 */
    }
  goto ret0;

 L536: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      return 74;  /* one_cmplsi2 */
    }
  goto ret0;

 L545: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L546;
    }
  goto ret0;

 L546: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 76;  /* andsi3 */
    }
  goto ret0;

 L556: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L557;
    }
  goto ret0;

 L557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 78;  /* iorsi3 */
    }
  goto ret0;

 L567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L568;
    }
  goto ret0;

 L568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 80;  /* xorsi3 */
    }
  goto ret0;

 L637: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L2488;
    case QImode:
      goto L2489;
    default:
      break;
    }
  goto ret0;

 L2488: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      return 92;  /* zero_extendhisi2 */
    }
  goto ret0;

 L2489: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 95;  /* zero_extendqisi2 */
    }
  goto ret0;

 L668: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2490;
    case HImode:
      goto L2491;
    default:
      break;
    }
  goto ret0;

 L2490: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 99;  /* extendqisi2 */
    }
  goto ret0;

 L2491: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      return 102;  /* extendhisi2 */
    }
  goto ret0;

 L695: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L2492;
    case SFmode:
      goto L2493;
    default:
      break;
    }
  goto ret0;

 L2492: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L696;
    }
  goto ret0;

 L696: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1237 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 105;  /* fix_truncdfsi2 */
    }
  goto ret0;

 L2493: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L701;
    }
  goto ret0;

 L701: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1247 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 106;  /* fix_truncsfsi2 */
    }
  goto ret0;

 L755: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L2494;
    case SFmode:
      goto L2495;
    default:
      break;
    }
  goto ret0;

 L2494: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L756;
    }
  goto ret0;

 L756: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1357 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 117;  /* fixuns_truncdfsi2 */
    }
  goto ret0;

 L2495: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L761;
    }
  goto ret0;

 L761: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1367 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 118;  /* fixuns_truncsfsi2 */
    }
  goto ret0;

 L2455: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L2496;
    case 3:
      goto L2497;
    default:
      break;
    }
  goto ret0;

 L2496: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case HOST_WIDE_INT_CONSTANT (5):
      goto L775;
    case HOST_WIDE_INT_CONSTANT (9):
      goto L799;
    case HOST_WIDE_INT_CONSTANT (8):
      goto L809;
    default:
      break;
    }
  goto ret0;

 L775: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L776;
    }
  goto ret0;

 L776: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1408 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    {
      return 121;  /* got_loadsi */
    }
  goto ret0;

 L799: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L800;
    }
  goto ret0;

 L800: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1428 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    {
      return 125;  /* got_load_tls_gdsi */
    }
  goto ret0;

 L809: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L810;
    }
  goto ret0;

 L810: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    {
      return 127;  /* got_load_tls_iesi */
    }
  goto ret0;

 L2497: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 7)
    goto L785;
  goto ret0;

 L785: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L786;
    }
  goto ret0;

 L786: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L787;
    }
  goto ret0;

 L787: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (symbolic_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L788;
    }
  goto ret0;

 L788: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    {
      return 123;  /* tls_add_tp_lesi */
    }
  goto ret0;

 L819: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L820;
    }
  goto ret0;

 L820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L821;
    }
  goto ret0;

 L821: ATTRIBUTE_UNUSED_LABEL
  if (
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    {
      return 129;  /* *lowsi */
    }
  goto ret0;

 L950: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2501;
    case DImode:
      goto L2502;
    default:
      break;
    }
  goto ret0;

 L2501: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L966;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L951;
    }
  goto ret0;

 L966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L967;
    }
  goto ret0;

 L967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L968;
  goto ret0;

 L968: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L969;
    }
  goto ret0;

 L969: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1836 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 160;  /* *ashldisi3 */
    }
  goto ret0;

 L951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 157;  /* ashlsi3 */
    }
 L997: ATTRIBUTE_UNUSED_LABEL
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L998;
    }
 L1009: ATTRIBUTE_UNUSED_LABEL
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1010;
    }
  goto ret0;

 L998: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)))
    {
      return 164;  /* *ashldisi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1009;

 L1010: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 166;  /* *ashldisi3 */
    }
  goto ret0;

 L2502: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1003;
    }
  goto ret0;

 L1003: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1004;
    }
 L1015: ATTRIBUTE_UNUSED_LABEL
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1016;
    }
  goto ret0;

 L1004: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 165;  /* *ashldisi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1015;

 L1016: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1855 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && (GET_CODE (operands[2]) == CONST_INT ? INTVAL (operands[2]) < 32 : 1)) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 167;  /* *ashldisi3 */
    }
  goto ret0;

 L955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L2504;
  goto ret0;

 L2504: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L974;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L956;
    }
  goto ret0;

 L974: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L975;
    }
  goto ret0;

 L975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L976;
  goto ret0;

 L976: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L977;
    }
  goto ret0;

 L977: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1836 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 161;  /* *ashrdisi3 */
    }
  goto ret0;

 L956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 158;  /* ashrsi3 */
    }
  goto ret0;

 L960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L2506;
  goto ret0;

 L2506: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L982;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L961;
    }
  goto ret0;

 L982: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L983;
    }
  goto ret0;

 L983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L984;
  goto ret0;

 L984: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L985;
    }
  goto ret0;

 L985: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1836 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 162;  /* *lshrdisi3 */
    }
  goto ret0;

 L961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 159;  /* lshrsi3 */
    }
  goto ret0;

 L1199: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2507;
    case DImode:
      goto L2508;
    default:
      break;
    }
  goto L2444;

 L2507: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1200;
    }
  goto L2444;

 L1200: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 182;  /* *seq_zero_sisi */
    }
  goto L2444;

 L2508: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1205;
    }
  goto L2444;

 L1205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 183;  /* *seq_zero_disi */
    }
  goto L2444;

 L1219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2509;
    case DImode:
      goto L2510;
    default:
      break;
    }
  goto ret0;

 L2509: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1220;
    }
  goto ret0;

 L1220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 186;  /* *sne_zero_sisi */
    }
  goto ret0;

 L2510: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1225;
    }
  goto ret0;

 L1225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 187;  /* *sne_zero_disi */
    }
  goto ret0;

 L1239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2511;
    case DImode:
      goto L2512;
    default:
      break;
    }
  goto L2444;

 L2511: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1240;
    }
  goto L2444;

 L1240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      return 190;  /* *sgt_sisi */
    }
  goto L2444;

 L2512: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1250;
    }
  goto L2444;

 L1250: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1251;
    }
  goto L2444;

 L1251: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 192;  /* *sgt_disi */
    }
  x1 = XEXP (x0, 1);
  goto L2444;

 L1244: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2513;
    case DImode:
      goto L2514;
    default:
      break;
    }
  goto ret0;

 L2513: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1245;
    }
  goto ret0;

 L1245: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      return 191;  /* *sgtu_sisi */
    }
  goto ret0;

 L2514: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1256;
    }
  goto ret0;

 L1256: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1257;
    }
  goto ret0;

 L1257: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 193;  /* *sgtu_disi */
    }
  goto ret0;

 L1285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2515;
    case DImode:
      goto L2516;
    default:
      break;
    }
  goto L2444;

 L2515: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1286;
    }
  goto L2444;

 L1286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    {
      return 198;  /* *sge_sisi */
    }
  goto L2444;

 L2516: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1296;
    }
  goto L2444;

 L1296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 200;  /* *sge_disi */
    }
  goto L2444;

 L1290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2517;
    case DImode:
      goto L2518;
    default:
      break;
    }
  goto ret0;

 L2517: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1291;
    }
  goto ret0;

 L1291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    {
      return 199;  /* *sgeu_sisi */
    }
  goto ret0;

 L2518: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1301;
    }
  goto ret0;

 L1301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 201;  /* *sgeu_disi */
    }
  goto ret0;

 L1325: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2519;
    case DImode:
      goto L2520;
    default:
      break;
    }
  goto L2444;

 L2519: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1326;
    }
  goto L2444;

 L1326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 206;  /* *slt_sisi */
    }
  goto L2444;

 L2520: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1336;
    }
  goto L2444;

 L1336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1337;
    }
  goto L2444;

 L1337: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 208;  /* *slt_disi */
    }
  x1 = XEXP (x0, 1);
  goto L2444;

 L1330: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2521;
    case DImode:
      goto L2522;
    default:
      break;
    }
  goto ret0;

 L2521: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1331;
    }
  goto ret0;

 L1331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 207;  /* *sltu_sisi */
    }
  goto ret0;

 L2522: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1342;
    }
  goto ret0;

 L1342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1343;
    }
  goto ret0;

 L1343: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 209;  /* *sltu_disi */
    }
  goto ret0;

 L1371: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2523;
    case DImode:
      goto L2524;
    default:
      break;
    }
  goto L2444;

 L2523: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1372;
    }
  goto L2444;

 L1372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, SImode))
    {
      operands[2] = x2;
      return 214;  /* *sle_sisi */
    }
  goto L2444;

 L2524: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1382;
    }
  goto L2444;

 L1382: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1383;
    }
  goto L2444;

 L1383: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 216;  /* *sle_disi */
    }
  x1 = XEXP (x0, 1);
  goto L2444;

 L1376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2525;
    case DImode:
      goto L2526;
    default:
      break;
    }
  goto ret0;

 L2525: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1377;
    }
  goto ret0;

 L1377: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, SImode))
    {
      operands[2] = x2;
      return 215;  /* *sleu_sisi */
    }
  goto ret0;

 L2526: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1388;
    }
  goto ret0;

 L1388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1389;
    }
  goto ret0;

 L1389: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 217;  /* *sleu_disi */
    }
  goto ret0;

 L1187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L2527;
    case DFmode:
      goto L2528;
    default:
      break;
    }
  goto ret0;

 L2527: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L1188;
    }
  goto ret0;

 L1188: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L1189;
    }
  goto ret0;

 L1189: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2030 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 180;  /* cstoresf4 */
    }
  goto ret0;

 L2528: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L1194;
    }
  goto ret0;

 L1194: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L1195;
    }
  goto ret0;

 L1195: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2030 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 181;  /* cstoredf4 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_3 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L38;
    case SIGN_EXTEND:
      goto L44;
    case MINUS:
      goto L85;
    case MULT:
      goto L201;
    case TRUNCATE:
      goto L245;
    case DIV:
      goto L336;
    case UDIV:
      goto L342;
    case MOD:
      goto L360;
    case UMOD:
      goto L366;
    case NOT:
      goto L540;
    case AND:
      goto L550;
    case IOR:
      goto L561;
    case XOR:
      goto L572;
    case ZERO_EXTEND:
      goto L627;
    case FIX:
      goto L705;
    case UNSIGNED_FIX:
      goto L765;
    case UNSPEC:
      goto L2585;
    case LO_SUM:
      goto L825;
    case ASHIFT:
      goto L1020;
    case ASHIFTRT:
      goto L1026;
    case LSHIFTRT:
      goto L1032;
    case EQ:
      goto L1209;
    case NE:
      goto L1229;
    case GT:
      goto L1261;
    case GTU:
      goto L1267;
    case GE:
      goto L1305;
    case GEU:
      goto L1310;
    case LT:
      goto L1347;
    case LTU:
      goto L1353;
    case LE:
      goto L1393;
    case LEU:
      goto L1399;
    default:
     break;
   }
  goto ret0;

 L38: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L39;
    }
  goto ret0;

 L39: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L40;
    }
  goto ret0;

 L40: ATTRIBUTE_UNUSED_LABEL
  if (
#line 439 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 7;  /* *adddi3 */
    }
  goto ret0;

 L44: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2591;
    case QImode:
      goto L2594;
    case HImode:
      goto L2595;
    default:
      break;
    }
  goto ret0;

 L2591: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L45;
    case MINUS:
      goto L115;
    case ASHIFT:
      goto L1039;
    case ASHIFTRT:
      goto L1046;
    case LSHIFTRT:
      goto L1053;
    case REG:
    case SUBREG:
    case MEM:
      goto L2593;
    default:
      goto ret0;
   }
 L2593: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L660;
    }
  goto ret0;

 L45: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L46;
    }
  goto ret0;

 L46: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L47;
    }
  goto ret0;

 L47: ATTRIBUTE_UNUSED_LABEL
  if (
#line 449 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 8;  /* *addsi3_extended */
    }
  goto ret0;

 L115: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L116;
    }
  goto ret0;

 L116: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L117;
    }
  goto ret0;

 L117: ATTRIBUTE_UNUSED_LABEL
  if (
#line 528 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 19;  /* *subsi3_extended */
    }
  goto ret0;

 L1039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1040;
    }
  goto ret0;

 L1040: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1041;
    }
  goto ret0;

 L1041: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1880 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 171;  /* ashlsi3_extend */
    }
  goto ret0;

 L1046: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1047;
    }
  goto ret0;

 L1047: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1048;
    }
  goto ret0;

 L1048: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1880 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 172;  /* ashrsi3_extend */
    }
  goto ret0;

 L1053: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1054;
    }
  goto ret0;

 L1054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1055;
    }
  goto ret0;

 L1055: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1880 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 173;  /* lshrsi3_extend */
    }
  goto ret0;

 L660: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1181 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 97;  /* extendsidi2 */
    }
  goto ret0;

 L2594: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L673;
    }
  goto ret0;

 L673: ATTRIBUTE_UNUSED_LABEL
  if (
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 100;  /* extendqidi2 */
    }
  goto ret0;

 L2595: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L686;
    }
  goto ret0;

 L686: ATTRIBUTE_UNUSED_LABEL
  if (
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 103;  /* extendhidi2 */
    }
  goto ret0;

 L85: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L86;
    }
  goto ret0;

 L86: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L87;
    }
  goto ret0;

 L87: ATTRIBUTE_UNUSED_LABEL
  if (
#line 509 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 14;  /* *subdi3 */
    }
  goto ret0;

 L201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L202;
    }
  goto ret0;

 L202: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L203;
    }
  goto ret0;

 L203: ATTRIBUTE_UNUSED_LABEL
  if (
#line 625 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 32;  /* *muldi3 */
    }
  goto ret0;

 L245: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L246;
  goto ret0;

 L246: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == MULT)
    goto L247;
  goto ret0;

 L247: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode)
    goto L2599;
  goto ret0;

 L2599: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L248;
    case ZERO_EXTEND:
      goto L258;
    default:
     break;
   }
  goto ret0;

 L248: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L249;
    }
  goto ret0;

 L249: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L250;
  goto ret0;

 L250: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L251;
    }
  goto ret0;

 L251: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (64)]
      && 
#line 674 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 35;  /* muldi3_highpart */
    }
  goto ret0;

 L258: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L259;
    }
  goto ret0;

 L259: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode)
    goto L2601;
  goto ret0;

 L2601: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTEND:
      goto L260;
    case SIGN_EXTEND:
      goto L289;
    default:
     break;
   }
  goto ret0;

 L260: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L261;
    }
  goto ret0;

 L261: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (64)]
      && 
#line 674 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 36;  /* umuldi3_highpart */
    }
  goto ret0;

 L289: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L290;
    }
  goto ret0;

 L290: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (64)]
      && 
#line 714 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 38;  /* usmuldi3_highpart */
    }
  goto ret0;

 L336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L337;
    }
  goto ret0;

 L337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L338;
    }
  goto ret0;

 L338: ATTRIBUTE_UNUSED_LABEL
  if (
#line 805 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 44;  /* divdi3 */
    }
  goto ret0;

 L342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L343;
    }
  goto ret0;

 L343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L344;
    }
  goto ret0;

 L344: ATTRIBUTE_UNUSED_LABEL
  if (
#line 805 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 45;  /* udivdi3 */
    }
  goto ret0;

 L360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L361;
    }
  goto ret0;

 L361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L362;
    }
  goto ret0;

 L362: ATTRIBUTE_UNUSED_LABEL
  if (
#line 823 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 48;  /* moddi3 */
    }
  goto ret0;

 L366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L367;
    }
  goto ret0;

 L367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L368;
    }
  goto ret0;

 L368: ATTRIBUTE_UNUSED_LABEL
  if (
#line 823 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 49;  /* umoddi3 */
    }
  goto ret0;

 L540: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L541;
    }
  goto ret0;

 L541: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 75;  /* one_cmpldi2 */
    }
  goto ret0;

 L550: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L2603;
  goto ret0;

 L2603: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L551;
    }
 L2604: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L633;
    }
  goto ret0;

 L551: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L552;
    }
  x2 = XEXP (x1, 0);
  goto L2604;

 L552: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 77;  /* anddi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2604;

 L633: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == HOST_WIDE_INT_CONSTANT (4294967295)
      && 
#line 1113 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 91;  /* *clear_upper32 */
    }
  goto ret0;

 L561: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L562;
    }
  goto ret0;

 L562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L563;
    }
  goto ret0;

 L563: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 79;  /* iordi3 */
    }
  goto ret0;

 L572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L573;
    }
  goto ret0;

 L573: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L574;
    }
  goto ret0;

 L574: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 81;  /* xordi3 */
    }
  goto ret0;

 L627: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2605;
    case HImode:
      goto L2606;
    case QImode:
      goto L2607;
    default:
      break;
    }
  goto ret0;

 L2605: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L628;
    }
  goto ret0;

 L628: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1093 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 90;  /* zero_extendsidi2 */
    }
  goto ret0;

 L2606: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L642;
    }
  goto ret0;

 L642: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 93;  /* zero_extendhidi2 */
    }
  goto ret0;

 L2607: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L655;
    }
  goto ret0;

 L655: ATTRIBUTE_UNUSED_LABEL
  if (
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 96;  /* zero_extendqidi2 */
    }
  goto ret0;

 L705: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L2608;
    case SFmode:
      goto L2609;
    default:
      break;
    }
  goto ret0;

 L2608: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L706;
    }
  goto ret0;

 L706: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1257 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 107;  /* fix_truncdfdi2 */
    }
  goto ret0;

 L2609: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L711;
    }
  goto ret0;

 L711: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1267 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 108;  /* fix_truncsfdi2 */
    }
  goto ret0;

 L765: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L2610;
    case SFmode:
      goto L2611;
    default:
      break;
    }
  goto ret0;

 L2610: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L766;
    }
  goto ret0;

 L766: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1377 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 119;  /* fixuns_truncdfdi2 */
    }
  goto ret0;

 L2611: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L771;
    }
  goto ret0;

 L771: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1387 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 120;  /* fixuns_truncsfdi2 */
    }
  goto ret0;

 L2585: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L2612;
    case 3:
      goto L2613;
    case 2:
      goto L2617;
    default:
      break;
    }
  goto ret0;

 L2612: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case HOST_WIDE_INT_CONSTANT (5):
      goto L780;
    case HOST_WIDE_INT_CONSTANT (9):
      goto L804;
    case HOST_WIDE_INT_CONSTANT (8):
      goto L814;
    case HOST_WIDE_INT_CONSTANT (0):
      goto L900;
    default:
      break;
    }
  goto ret0;

 L780: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L781;
    }
  goto ret0;

 L781: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1408 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    {
      return 122;  /* got_loaddi */
    }
  goto ret0;

 L804: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L805;
    }
  goto ret0;

 L805: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1428 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    {
      return 126;  /* got_load_tls_gddi */
    }
  goto ret0;

 L814: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L815;
    }
  goto ret0;

 L815: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1437 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(flag_pic) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    {
      return 128;  /* got_load_tls_iedi */
    }
  goto ret0;

 L900: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L901;
    }
  goto ret0;

 L901: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1731 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 289 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 147;  /* load_lowdi */
    }
  goto ret0;

 L2613: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 7)
    goto L792;
  goto ret0;

 L792: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L793;
    }
  goto ret0;

 L793: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L794;
    }
  goto ret0;

 L794: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (symbolic_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L795;
    }
  goto ret0;

 L795: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1419 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!flag_pic || flag_pie) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    {
      return 124;  /* tls_add_tp_ledi */
    }
  goto ret0;

 L2617: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 1)
    goto L916;
  goto ret0;

 L916: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L917;
    }
  goto ret0;

 L917: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L918;
    }
  goto ret0;

 L918: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1746 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 289 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 150;  /* load_highdi */
    }
  goto ret0;

 L825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L826;
    }
  goto ret0;

 L826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L827;
    }
  goto ret0;

 L827: ATTRIBUTE_UNUSED_LABEL
  if (
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    {
      return 130;  /* *lowdi */
    }
  goto ret0;

 L1020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1021;
    }
  goto ret0;

 L1021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1022;
    }
  goto ret0;

 L1022: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1864 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 168;  /* ashldi3 */
    }
  goto ret0;

 L1026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1027;
    }
  goto ret0;

 L1027: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1028;
    }
  goto ret0;

 L1028: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1864 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 169;  /* ashrdi3 */
    }
  goto ret0;

 L1032: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1033;
    }
  goto ret0;

 L1033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1034;
    }
  goto ret0;

 L1034: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1864 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 170;  /* lshrdi3 */
    }
  goto ret0;

 L1209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2618;
    case DImode:
      goto L2619;
    default:
      break;
    }
  goto ret0;

 L2618: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1210;
    }
  goto ret0;

 L1210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 184;  /* *seq_zero_sidi */
    }
  goto ret0;

 L2619: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1215;
    }
  goto ret0;

 L1215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 185;  /* *seq_zero_didi */
    }
  goto ret0;

 L1229: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2620;
    case DImode:
      goto L2621;
    default:
      break;
    }
  goto ret0;

 L2620: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1230;
    }
  goto ret0;

 L1230: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 188;  /* *sne_zero_sidi */
    }
  goto ret0;

 L2621: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1235;
    }
  goto ret0;

 L1235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 189;  /* *sne_zero_didi */
    }
  goto ret0;

 L1261: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2622;
    case DImode:
      goto L2623;
    default:
      break;
    }
  goto ret0;

 L2622: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1262;
    }
  goto ret0;

 L1262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1263;
    }
  goto ret0;

 L1263: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 194;  /* *sgt_sidi */
    }
  goto ret0;

 L2623: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1274;
    }
  goto ret0;

 L1274: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1275;
    }
  goto ret0;

 L1275: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 196;  /* *sgt_didi */
    }
  goto ret0;

 L1267: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2624;
    case DImode:
      goto L2625;
    default:
      break;
    }
  goto ret0;

 L2624: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1268;
    }
  goto ret0;

 L1268: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1269;
    }
  goto ret0;

 L1269: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 195;  /* *sgtu_sidi */
    }
  goto ret0;

 L2625: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1280;
    }
  goto ret0;

 L1280: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1281;
    }
  goto ret0;

 L1281: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 197;  /* *sgtu_didi */
    }
  goto ret0;

 L1305: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2626;
    case DImode:
      goto L2627;
    default:
      break;
    }
  goto ret0;

 L2626: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1306;
    }
  goto ret0;

 L1306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 202;  /* *sge_sidi */
    }
  goto ret0;

 L2627: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1316;
    }
  goto ret0;

 L1316: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 204;  /* *sge_didi */
    }
  goto ret0;

 L1310: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2628;
    case DImode:
      goto L2629;
    default:
      break;
    }
  goto ret0;

 L2628: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1311;
    }
  goto ret0;

 L1311: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 203;  /* *sgeu_sidi */
    }
  goto ret0;

 L2629: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1321;
    }
  goto ret0;

 L1321: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 205;  /* *sgeu_didi */
    }
  goto ret0;

 L1347: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2630;
    case DImode:
      goto L2631;
    default:
      break;
    }
  goto ret0;

 L2630: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1348;
    }
  goto ret0;

 L1348: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1349;
    }
  goto ret0;

 L1349: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 210;  /* *slt_sidi */
    }
  goto ret0;

 L2631: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1360;
    }
  goto ret0;

 L1360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1361;
    }
  goto ret0;

 L1361: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 212;  /* *slt_didi */
    }
  goto ret0;

 L1353: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2632;
    case DImode:
      goto L2633;
    default:
      break;
    }
  goto ret0;

 L2632: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1354;
    }
  goto ret0;

 L1354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1355;
    }
  goto ret0;

 L1355: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 211;  /* *sltu_sidi */
    }
  goto ret0;

 L2633: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1366;
    }
  goto ret0;

 L1366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1367;
    }
  goto ret0;

 L1367: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 213;  /* *sltu_didi */
    }
  goto ret0;

 L1393: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2634;
    case DImode:
      goto L2635;
    default:
      break;
    }
  goto ret0;

 L2634: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1394;
    }
  goto ret0;

 L1394: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1395;
    }
  goto ret0;

 L1395: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 218;  /* *sle_sidi */
    }
  goto ret0;

 L2635: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1406;
    }
  goto ret0;

 L1406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1407;
    }
  goto ret0;

 L1407: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 220;  /* *sle_didi */
    }
  goto ret0;

 L1399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2636;
    case DImode:
      goto L2637;
    default:
      break;
    }
  goto ret0;

 L2636: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1400;
    }
  goto ret0;

 L1400: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1401;
    }
  goto ret0;

 L1401: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 219;  /* *sleu_sidi */
    }
  goto ret0;

 L2637: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1412;
    }
  goto ret0;

 L1412: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1413;
    }
  goto ret0;

 L1413: ATTRIBUTE_UNUSED_LABEL
  if (
#line 250 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 221;  /* *sleu_didi */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_4 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SFmode:
      goto L2339;
    case DFmode:
      goto L2340;
    case SImode:
      goto L2341;
    case DImode:
      goto L2342;
    case TImode:
      goto L2343;
    case QImode:
      goto L2345;
    case HImode:
      goto L2346;
    case TFmode:
      goto L2353;
    default:
      break;
    }
 L1057: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == PC)
    goto L1420;
  if (register_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L1473;
    }
  goto ret0;

 L2339: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L2;
    }
 L2350: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L870;
    }
 L2366: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L2057;
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L1847;
    }
  goto L1057;

 L2: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L2368;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2368: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L3;
    case MINUS:
      goto L73;
    case MULT:
      goto L150;
    case DIV:
      goto L372;
    case SQRT:
      goto L384;
    case FMA:
      goto L394;
    case NEG:
      goto L424;
    case ABS:
      goto L492;
    case SMIN:
      goto L502;
    case SMAX:
      goto L514;
    case FLOAT_TRUNCATE:
      goto L578;
    case FLOAT:
      goto L725;
    case UNSIGNED_FLOAT:
      goto L745;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2350;

 L3: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L4: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L5;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L5: ATTRIBUTE_UNUSED_LABEL
  if (
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 1;  /* addsf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L73: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L2381;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2381: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L74;
    }
 L2382: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L459;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L74: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L75;
    }
  x2 = XEXP (x1, 0);
  goto L2382;

 L75: ATTRIBUTE_UNUSED_LABEL
  if (
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 12;  /* subsf3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2382;

 L459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == MULT)
    goto L460;
  x1 = XEXP (x0, 0);
  goto L2350;

 L460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L2383;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2383: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L461;
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L479;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L461: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L462;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L462: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L463;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L463: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 910 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 62;  /* *nfmasf4_fastmath */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L479: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L480;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L480: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 923 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 64;  /* *nfmssf4_fastmath */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L150: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L151;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L152;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L152: ATTRIBUTE_UNUSED_LABEL
  if (
#line 283 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 24;  /* mulsf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L373;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L373: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L374;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L374: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 832 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 50;  /* divsf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L384: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L385;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L385: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 847 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 52;  /* sqrtsf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L394: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L395;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L395: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L396;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_MODE (x2) == SFmode)
    goto L2386;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2386: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NEG)
    goto L411;
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L397;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L412;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L412: ATTRIBUTE_UNUSED_LABEL
  if (
#line 873 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 56;  /* fmssf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L397: ATTRIBUTE_UNUSED_LABEL
  if (
#line 862 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 54;  /* fmasf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L2387;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2387: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FMA)
    goto L425;
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L527;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L425: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L426;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L426: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L427;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L427: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_MODE (x3) == SFmode)
    goto L2390;
  x1 = XEXP (x0, 0);
  goto L2350;

 L2390: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L444;
  if (register_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L428;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L444: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SFmode))
    {
      operands[3] = x4;
      goto L445;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L445: ATTRIBUTE_UNUSED_LABEL
  if (
#line 897 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 60;  /* nfmssf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L428: ATTRIBUTE_UNUSED_LABEL
  if (
#line 885 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 58;  /* nfmasf4 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L527: ATTRIBUTE_UNUSED_LABEL
  if (
#line 980 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 72;  /* negsf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L492: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L493;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L493: ATTRIBUTE_UNUSED_LABEL
  if (
#line 938 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 66;  /* abssf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L503;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L503: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L504;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L504: ATTRIBUTE_UNUSED_LABEL
  if (
#line 955 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 68;  /* sminsf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L515;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L516;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L516: ATTRIBUTE_UNUSED_LABEL
  if (
#line 964 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 70;  /* smaxsf3 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L578: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L579;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L579: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1038 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 82;  /* truncdfsf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L725: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L726;
    }
 L730: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L731;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L726: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1297 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 111;  /* floatsisf2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L730;

 L731: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1307 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 112;  /* floatdisf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L746;
    }
 L750: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L751;
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L746: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1337 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    {
      return 115;  /* floatunssisf2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L750;

 L751: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1347 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_64BIT))
    {
      return 116;  /* floatunsdisf2 */
    }
  x1 = XEXP (x0, 0);
  goto L2350;

 L870: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L871;
    }
  x1 = XEXP (x0, 0);
  goto L2366;

 L871: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1622 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
    {
      return 140;  /* *movsf_hardfloat */
    }
 L875: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1632 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_SOFT_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
    {
      return 141;  /* *movsf_softfloat */
    }
  x1 = XEXP (x0, 0);
  goto L2366;

 L2057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2058;
    }
  goto L1057;

 L2058: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L2059;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2059: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 288;  /* *local_pic_storedisf */
    }
 L2085: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 290;  /* *local_pic_storesisf */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1847: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode
      && GET_CODE (x1) == MEM)
    goto L1848;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1849;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1849: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 267;  /* *local_pic_loadsf */
    }
 L1875: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 269;  /* *local_pic_loadsf */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2340: ATTRIBUTE_UNUSED_LABEL
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1057;

 L2341: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L14;
    }
 L2344: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L582;
    }
 L2364: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1979;
 L2354: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1575;
    }
 L2358: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1829;
    }
  goto L1057;

 L14: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L2420;
  x1 = XEXP (x0, 0);
  goto L2344;

 L2420: ATTRIBUTE_UNUSED_LABEL
  tem = recog_2 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L2344;

 L582: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L2529;
 L838: ATTRIBUTE_UNUSED_LABEL
  if (move_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L839;
    }
  x1 = XEXP (x0, 0);
  goto L2364;

 L2529: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case TRUNCATE:
      goto L583;
    case UNSPEC:
      goto L2531;
    default:
     break;
   }
  goto L838;

 L583: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L584;
    }
  goto L838;

 L584: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1052 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 83;  /* truncdisi2 */
    }
  x1 = XEXP (x0, 1);
  goto L838;

 L2531: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 2)
    goto L928;
  goto L838;

 L928: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L2532;
    case DImode:
      goto L2533;
    default:
      break;
    }
  goto L838;

 L2532: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L929;
    }
  goto L838;

 L929: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L930;
    }
  goto L838;

 L930: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 288 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 152;  /* store_worddf */
    }
  x1 = XEXP (x0, 1);
  goto L838;

 L2533: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L935;
    }
  goto L838;

 L935: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L936;
    }
  goto L838;

 L936: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 289 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    {
      return 153;  /* store_worddi */
    }
  x1 = XEXP (x0, 1);
  goto L838;

 L839: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1536 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode))))
    {
      return 133;  /* *movsi_internal */
    }
  x1 = XEXP (x0, 0);
  goto L2364;

 L1979: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1980;
    }
  goto L2354;

 L1980: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L1981;
    }
  x1 = XEXP (x0, 0);
  goto L2354;

 L1981: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 282;  /* *local_pic_storedisi */
    }
 L2033: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 286;  /* *local_pic_storesisi */
    }
  x1 = XEXP (x0, 0);
  goto L2354;

 L1575: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L2534;
  x1 = XEXP (x0, 0);
  goto L2358;

 L2534: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC_VOLATILE)
    goto L2536;
  x1 = XEXP (x0, 0);
  goto L2358;

 L2536: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2)
    goto L2538;
  x1 = XEXP (x0, 0);
  goto L2358;

 L2538: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case HOST_WIDE_INT_CONSTANT (16):
      goto L1576;
    case HOST_WIDE_INT_CONSTANT (14):
      goto L1588;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1576: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1577;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1577: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1578;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1578: ATTRIBUTE_UNUSED_LABEL
  if (
#line 79 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 241;  /* atomic_storesi */
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1588: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == SImode)
    goto L2540;
  x1 = XEXP (x0, 0);
  goto L2358;

 L2540: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1589;
    case IOR:
      goto L1597;
    case XOR:
      goto L1605;
    case AND:
      goto L1613;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1590;
  x1 = XEXP (x0, 0);
  goto L2358;

 L1590: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1591;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1591: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1592;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1592: ATTRIBUTE_UNUSED_LABEL
  if (
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 243;  /* atomic_addsi */
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1598;
  x1 = XEXP (x0, 0);
  goto L2358;

 L1598: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1599;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1599: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1600;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1600: ATTRIBUTE_UNUSED_LABEL
  if (
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 244;  /* atomic_orsi */
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1605: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1606;
  x1 = XEXP (x0, 0);
  goto L2358;

 L1606: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1607;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1607: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1608;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1608: ATTRIBUTE_UNUSED_LABEL
  if (
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 245;  /* atomic_xorsi */
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1613: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1614;
  x1 = XEXP (x0, 0);
  goto L2358;

 L1614: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1615;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1615: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1616;
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1616: ATTRIBUTE_UNUSED_LABEL
  if (
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 246;  /* atomic_andsi */
    }
  x1 = XEXP (x0, 0);
  goto L2358;

 L1829: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L2544;
  x1 = XEXP (x0, 0);
  goto L1057;

 L2544: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L1830;
    case ZERO_EXTEND:
      goto L1898;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1830: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1831;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1831: ATTRIBUTE_UNUSED_LABEL
  if (
#line 50 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 265;  /* *local_pic_loadsi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2546;
    case HImode:
      goto L2547;
    case SImode:
      goto L2548;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2546: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1899;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1899: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1900;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1900: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 272;  /* *local_pic_loaduqi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2547: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1917;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1917: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1918;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1918: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 275;  /* *local_pic_loaduhi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2548: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1935;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1935: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1936;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1936: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 278;  /* *local_pic_loadusi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2342: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L37;
    }
 L2347: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L939;
    }
 L2365: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1992;
 L2355: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1581;
    }
 L2359: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1834;
    }
  goto L1057;

 L37: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L2549;
  x1 = XEXP (x0, 0);
  goto L2347;

 L2549: ATTRIBUTE_UNUSED_LABEL
  tem = recog_3 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L2347;

 L939: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 2)
    goto L940;
  if (move_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L831;
    }
  x1 = XEXP (x0, 0);
  goto L2365;

 L940: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L941;
    }
  x1 = XEXP (x0, 0);
  goto L2365;

 L941: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L942;
    }
  x1 = XEXP (x0, 0);
  goto L2365;

 L942: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1761 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 290 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 154;  /* store_wordtf */
    }
  x1 = XEXP (x0, 0);
  goto L2365;

 L831: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1498 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
    {
      return 131;  /* *movdi_32bit */
    }
 L835: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1508 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
    {
      return 132;  /* *movdi_64bit */
    }
  x1 = XEXP (x0, 0);
  goto L2365;

 L1992: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1993;
    }
  goto L2355;

 L1993: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L1994;
    }
  x1 = XEXP (x0, 0);
  goto L2355;

 L1994: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 283;  /* *local_pic_storedidi */
    }
 L2046: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 287;  /* *local_pic_storesidi */
    }
  x1 = XEXP (x0, 0);
  goto L2355;

 L1581: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L2638;
  x1 = XEXP (x0, 0);
  goto L2359;

 L2638: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC_VOLATILE)
    goto L2640;
  x1 = XEXP (x0, 0);
  goto L2359;

 L2640: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2)
    goto L2642;
  x1 = XEXP (x0, 0);
  goto L2359;

 L2642: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case HOST_WIDE_INT_CONSTANT (16):
      goto L1582;
    case HOST_WIDE_INT_CONSTANT (14):
      goto L1620;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1582: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1583;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1583: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1584;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1584: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 79 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 242;  /* atomic_storedi */
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1620: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DImode)
    goto L2644;
  x1 = XEXP (x0, 0);
  goto L2359;

 L2644: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1621;
    case IOR:
      goto L1629;
    case XOR:
      goto L1637;
    case AND:
      goto L1645;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1621: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1622;
  x1 = XEXP (x0, 0);
  goto L2359;

 L1622: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1623;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1623: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1624;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1624: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 247;  /* atomic_adddi */
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1629: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1630;
  x1 = XEXP (x0, 0);
  goto L2359;

 L1630: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1631;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1631: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1632;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1632: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 248;  /* atomic_ordi */
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1637: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1638;
  x1 = XEXP (x0, 0);
  goto L2359;

 L1638: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1639;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1639: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1640;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1640: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 249;  /* atomic_xordi */
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1645: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1646;
  x1 = XEXP (x0, 0);
  goto L2359;

 L1646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1647;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1647: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1648;
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1648: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 89 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 250;  /* atomic_anddi */
    }
  x1 = XEXP (x0, 0);
  goto L2359;

 L1834: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L2648;
  x1 = XEXP (x0, 0);
  goto L1057;

 L2648: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L1835;
    case ZERO_EXTEND:
      goto L1904;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1836;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1836: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 50 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 266;  /* *local_pic_loaddi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1904: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2650;
    case HImode:
      goto L2651;
    case SImode:
      goto L2652;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2650: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1905;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1905: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1906;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1906: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 273;  /* *local_pic_loaduqi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2651: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1923;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1923: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1924;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1924: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 276;  /* *local_pic_loaduhi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2652: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1941;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1941: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1942;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1942: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 279;  /* *local_pic_loadusi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2343: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L217;
    }
 L2352: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L890;
    }
  goto L1057;

 L217: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode
      && GET_CODE (x1) == MULT)
    goto L218;
  x1 = XEXP (x0, 0);
  goto L2352;

 L218: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L2653;
  x1 = XEXP (x0, 0);
  goto L2352;

 L2653: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L219;
    case ZERO_EXTEND:
      goto L238;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2352;

 L219: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L220;
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L221;
  x1 = XEXP (x0, 0);
  goto L2352;

 L221: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L222;
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L222: ATTRIBUTE_UNUSED_LABEL
  if (
#line 647 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 33;  /* mulditi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L238: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L239;
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode)
    goto L2655;
  x1 = XEXP (x0, 0);
  goto L2352;

 L2655: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L240;
    case SIGN_EXTEND:
      goto L279;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2352;

 L240: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L241;
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L241: ATTRIBUTE_UNUSED_LABEL
  if (
#line 647 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 34;  /* umulditi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L280;
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L280: ATTRIBUTE_UNUSED_LABEL
  if (
#line 687 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 37;  /* usmulditi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2352;

 L890: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L891;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L891: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1696 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], TImode)
       || reg_or_0_operand (operands[1], TImode))))
    {
      return 145;  /* *movti */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2345: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L587;
    }
 L2349: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L866;
    }
 L2362: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1953;
  if (register_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L1819;
    }
  goto L1057;

 L587: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == TRUNCATE)
    goto L588;
  x1 = XEXP (x0, 0);
  goto L2349;

 L588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L2657;
  x1 = XEXP (x0, 0);
  goto L2349;

 L2657: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFTRT:
      goto L589;
    case LSHIFTRT:
      goto L610;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2349;

 L589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L590;
    }
  x1 = XEXP (x0, 0);
  goto L2349;

 L590: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L591;
    }
  x1 = XEXP (x0, 0);
  goto L2349;

 L591: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63)))
    {
      return 84;  /* *ashr_truncqi */
    }
  x1 = XEXP (x0, 0);
  goto L2349;

 L610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L611;
    }
  x1 = XEXP (x0, 0);
  goto L2349;

 L611: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1076 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 87;  /* *lshr32_truncqi */
    }
  x1 = XEXP (x0, 0);
  goto L2349;

 L866: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L867;
    }
  x1 = XEXP (x0, 0);
  goto L2362;

 L867: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1602 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode))))
    {
      return 139;  /* *movqi_internal */
    }
  x1 = XEXP (x0, 0);
  goto L2362;

 L1953: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1954;
    }
  goto L1057;

 L1954: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L1955;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1955: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 280;  /* *local_pic_storediqi */
    }
 L2007: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 284;  /* *local_pic_storesiqi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1819: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == MEM)
    goto L1820;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1821;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1821: ATTRIBUTE_UNUSED_LABEL
  if (
#line 50 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 263;  /* *local_pic_loadqi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2346: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L594;
    }
 L2348: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L842;
    }
 L2363: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1966;
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L1824;
    }
  goto L1057;

 L594: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L2659;
  x1 = XEXP (x0, 0);
  goto L2348;

 L2659: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case TRUNCATE:
      goto L595;
    case ZERO_EXTEND:
      goto L646;
    case SIGN_EXTEND:
      goto L664;
    case PLUS:
      goto L847;
    case XOR:
      goto L857;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2348;

 L595: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L2664;
  x1 = XEXP (x0, 0);
  goto L2348;

 L2664: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFTRT:
      goto L596;
    case LSHIFTRT:
      goto L616;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2348;

 L596: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L597;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L598;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L598: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1066 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && IN_RANGE (INTVAL (operands[2]), 32, 63)))
    {
      return 85;  /* *ashr_trunchi */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L617;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L617: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1076 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 88;  /* *lshr32_trunchi */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L646: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 94;  /* zero_extendqihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2666;
    case HImode:
      goto L2667;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2666: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 98;  /* extendqihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2667: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      return 101;  /* extendhihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L847: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L2668;
    case SImode:
      goto L2669;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2668: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L848;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, HImode))
    {
      operands[2] = x2;
      return 135;  /* addhihi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2669: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L853;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L853: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 136;  /* addsihi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L2670;
    case SImode:
      goto L2671;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2670: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L858;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, HImode))
    {
      operands[2] = x2;
      return 137;  /* xorhihi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L2671: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L863;
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      return 138;  /* xorsihi3 */
    }
  x1 = XEXP (x0, 0);
  goto L2348;

 L842: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L843;
    }
  x1 = XEXP (x0, 0);
  goto L2363;

 L843: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1561 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode))))
    {
      return 134;  /* *movhi_internal */
    }
  x1 = XEXP (x0, 0);
  goto L2363;

 L1966: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1967;
    }
  goto L1057;

 L1967: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L1968;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1968: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 281;  /* *local_pic_storedihi */
    }
 L2020: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 285;  /* *local_pic_storesihi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1824: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L2672;
  x1 = XEXP (x0, 0);
  goto L1057;

 L2672: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L1825;
    case ZERO_EXTEND:
      goto L1892;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (absolute_symbolic_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1826;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1826: ATTRIBUTE_UNUSED_LABEL
  if (
#line 50 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 264;  /* *local_pic_loadhi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2674;
    case HImode:
      goto L2675;
    case SImode:
      goto L2676;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2674: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1893;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1893: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1894;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1894: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 271;  /* *local_pic_loaduqi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2675: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1911;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1911: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1912;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1912: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 274;  /* *local_pic_loaduhi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2676: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1929;
  x1 = XEXP (x0, 0);
  goto L1057;

 L1929: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1930;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1930: ATTRIBUTE_UNUSED_LABEL
  if (
#line 70 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(flag_pic && SYMBOL_REF_LOCAL_P (operands[1])))
    {
      return 277;  /* *local_pic_loadusi */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2353: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L904;
    }
  goto L1057;

 L904: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TFmode)
    goto L2677;
  x1 = XEXP (x0, 0);
  goto L1057;

 L2677: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L2679;
  x1 = XEXP (x0, 0);
  goto L1057;

 L2679: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L2681;
    case 2:
      goto L2682;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2681: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L905;
  x1 = XEXP (x0, 0);
  goto L1057;

 L905: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L906;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L906: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1731 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 290 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 148;  /* load_lowtf */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L2682: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 1)
    goto L922;
  x1 = XEXP (x0, 0);
  goto L1057;

 L922: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L923;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L923: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L924;
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L924: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1746 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 290 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 151;  /* load_hightf */
    }
  x1 = XEXP (x0, 0);
  goto L1057;

 L1420: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L2683;
    case DImode:
      goto L2684;
    default:
      break;
    }
 L1058: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L1059;
    case LABEL_REF:
      goto L1417;
    default:
     break;
   }
  goto ret0;

 L2683: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1421;
    }
  goto L1058;

 L1421: ATTRIBUTE_UNUSED_LABEL
  if (
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode))
    {
      return 223;  /* indirect_jumpsi */
    }
  x1 = XEXP (x0, 1);
  goto L1058;

 L2684: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1425;
    }
  goto L1058;

 L1425: ATTRIBUTE_UNUSED_LABEL
  if (
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode))
    {
      return 224;  /* indirect_jumpdi */
    }
  x1 = XEXP (x0, 1);
  goto L1058;

 L1059: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (order_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1060;
    }
 L1092: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1093;
    }
  goto ret0;

 L1060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L2685;
    case DImode:
      goto L2686;
    default:
      break;
    }
  goto L1092;

 L2685: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1061;
    }
  goto L1092;

 L1061: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1062;
    }
  goto L1092;

 L1062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1063;
  x2 = XEXP (x1, 0);
  goto L1092;

 L1063: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  goto L1064;

 L1064: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return 174;  /* *branch_ordersi */
    }
  x2 = XEXP (x1, 0);
  goto L1092;

 L2686: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1070;
    }
  goto L1092;

 L1070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L1071;
    }
  goto L1092;

 L1071: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1072;
  x2 = XEXP (x1, 0);
  goto L1092;

 L1072: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  goto L1073;

 L1073: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 175;  /* *branch_orderdi */
    }
  x2 = XEXP (x1, 0);
  goto L1092;

 L1093: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L2687;
    case DImode:
      goto L2688;
    default:
      break;
    }
  goto ret0;

 L2687: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == ZERO_EXTRACT)
    goto L1094;
  goto ret0;

 L1094: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1095;
    }
  goto ret0;

 L1095: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L2689;
  goto ret0;

 L2689: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x4, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L1096;
 L2690: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, VOIDmode))
    {
      operands[3] = x4;
      goto L1151;
    }
  goto ret0;

 L1096: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, VOIDmode))
    {
      operands[3] = x4;
      goto L1097;
    }
  x4 = XEXP (x3, 1);
  goto L2690;

 L1097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1098;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2690;

 L1098: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1099;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2690;

 L1099: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L1100;

 L1100: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 176;  /* *branch_on_bitsi */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2690;

 L1151: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1152;
  goto ret0;

 L1152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1153;
  goto ret0;

 L1153: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1154;
  goto ret0;

 L1154: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L1155;

 L1155: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 178;  /* *branch_on_bit_rangesi */
    }
  goto ret0;

 L2688: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == ZERO_EXTRACT)
    goto L1122;
  goto ret0;

 L1122: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1123;
    }
  goto ret0;

 L1123: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L2691;
  goto ret0;

 L2691: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x4, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L1124;
 L2692: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, VOIDmode))
    {
      operands[3] = x4;
      goto L1179;
    }
  goto ret0;

 L1124: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, VOIDmode))
    {
      operands[3] = x4;
      goto L1125;
    }
  x4 = XEXP (x3, 1);
  goto L2692;

 L1125: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1126;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2692;

 L1126: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1127;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2692;

 L1127: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L1128;

 L1128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 177;  /* *branch_on_bitdi */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L2692;

 L1179: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1180;
  goto ret0;

 L1180: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1181;
  goto ret0;

 L1181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1182;
  goto ret0;

 L1182: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L1183;

 L1183: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 179;  /* *branch_on_bit_rangedi */
    }
  goto ret0;

 L1417: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  return 222;  /* jump */

 L1473: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CALL)
    goto L1474;
  goto ret0;

 L1474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L1475;
  goto ret0;

 L1475: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1476;
    }
  goto ret0;

 L1476: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L1477;

 L1477: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2312 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn)))
    {
      return 233;  /* sibcall_value_internal */
    }
 L1534: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 236;  /* call_value_internal */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_5 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (register_operand (x2, TImode))
    {
      operands[0] = x2;
      goto L207;
    }
  if (GET_CODE (x2) == PC)
    goto L1429;
 L1496: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1497;
    }
 L1569: ATTRIBUTE_UNUSED_LABEL
  operands[0] = x2;
  goto L1570;
 L1651: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2700;
    case DImode:
      goto L2701;
    case SFmode:
      goto L2702;
    case DFmode:
      goto L2703;
    case QImode:
      goto L2698;
    case HImode:
      goto L2699;
    default:
      break;
    }
  goto ret0;

 L207: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == MULT)
    goto L208;
  x2 = XEXP (x1, 0);
  goto L1496;

 L208: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode)
    goto L2704;
  x2 = XEXP (x1, 0);
  goto L1496;

 L2704: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L209;
    case ZERO_EXTEND:
      goto L228;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L1496;

 L209: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L210;
    }
  x2 = XEXP (x1, 0);
  goto L1496;

 L210: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L211;
  x2 = XEXP (x1, 0);
  goto L1496;

 L211: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L212;
    }
  x2 = XEXP (x1, 0);
  goto L1496;

 L212: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L213;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L213: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L214;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L214: ATTRIBUTE_UNUSED_LABEL
  if (
#line 647 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 33;  /* mulditi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L228: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L229;
    }
  x2 = XEXP (x1, 0);
  goto L1496;

 L229: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode)
    goto L2706;
  x2 = XEXP (x1, 0);
  goto L1496;

 L2706: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L230;
    case SIGN_EXTEND:
      goto L269;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L1496;

 L230: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L231;
    }
  x2 = XEXP (x1, 0);
  goto L1496;

 L231: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L232;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L232: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L233;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L233: ATTRIBUTE_UNUSED_LABEL
  if (
#line 647 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 34;  /* umulditi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L269: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L270;
    }
  x2 = XEXP (x1, 0);
  goto L1496;

 L270: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L271;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L272;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L272: ATTRIBUTE_UNUSED_LABEL
  if (
#line 687 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_MULDIV && TARGET_64BIT))
    {
      return 37;  /* usmulditi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1496;

 L1429: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2708;
    case DImode:
      goto L2709;
    default:
      break;
    }
 L1077: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L1078;
  x2 = XEXP (x1, 0);
  goto L1569;

 L2708: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1430;
    }
  goto L1077;

 L1430: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L1431;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L1077;

 L1431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1432;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L1077;

 L1432: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  return 225;  /* tablejumpsi */

 L2709: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1437;
    }
  goto L1077;

 L1437: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L1438;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L1077;

 L1438: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L1439;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L1077;

 L1439: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L1440;

 L1440: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 226;  /* tablejumpdi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L1077;

 L1078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (equality_operator (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1079;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1079: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L2710;
    case DImode:
      goto L2711;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L2710: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L1080;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1080: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1081;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1081: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT)
    goto L2712;
  x2 = XEXP (x1, 0);
  goto L1569;

 L2712: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x5, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L1082;
 L2713: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L1137;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1082: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L1083;
    }
  x5 = XEXP (x4, 1);
  goto L2713;

 L1083: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1084;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2713;

 L1084: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L1085;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2713;

 L1085: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L1086;

 L1086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L1087;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2713;

 L1087: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1088;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2713;

 L1088: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      return 176;  /* *branch_on_bitsi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2713;

 L1137: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1138;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1138: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1139;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L1140;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1140: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L1141;

 L1141: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L1142;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1142: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      return 178;  /* *branch_on_bit_rangesi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L2711: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L1107;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1107: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L1108;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1108: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT)
    goto L2714;
  x2 = XEXP (x1, 0);
  goto L1569;

 L2714: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x5, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L1109;
 L2715: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L1164;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1109: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L1110;
    }
  x5 = XEXP (x4, 1);
  goto L2715;

 L1110: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1111;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1111: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L1112;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1112: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L1113;

 L1113: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L1114;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1114: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1115;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1115: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L1116;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1116: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 177;  /* *branch_on_bitdi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2715;

 L1164: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1165;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1165: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L1166;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1166: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L1167;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1167: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L1168;

 L1168: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L1169;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1169: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1170;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1170: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L1171;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1171: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 179;  /* *branch_on_bit_rangedi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1497: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L1498;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L1499;
  x2 = XEXP (x1, 0);
  goto L1569;

 L1499: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L1500;
    }
  x2 = XEXP (x1, 0);
  goto L1569;

 L1500: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L1501;

 L1501: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L1502;
    case CLOBBER:
      goto L1527;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L1503;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1503: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L1504;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1504: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L1505;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1505: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1506;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1506: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 2326 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 234;  /* sibcall_value_multiple_internal */
    }
 L1562: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 237;  /* call_value_multiple_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1527: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 1)
    {
      return 236;  /* call_value_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1569;

 L1570: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 17)
    goto L1571;
  x2 = XEXP (x1, 0);
  goto L1651;

 L1571: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1572;
  x2 = XEXP (x1, 0);
  goto L1651;

 L1572: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (const_int_operand (x1, SImode))
    {
      operands[1] = x1;
      return 240;  /* mem_thread_fence_1 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1651;

 L2700: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1972;
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1652;
    }
  goto ret0;

 L1972: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1973;
    }
  goto ret0;

 L1973: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1974;
    }
  goto ret0;

 L1974: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1975;
  goto ret0;

 L1975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2716;
    case SImode:
      goto L2717;
    default:
      break;
    }
  goto ret0;

 L2716: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1976;
    }
  goto ret0;

 L1976: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 282;  /* *local_pic_storedisi */
    }
  goto ret0;

 L2717: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2028;
    }
  goto ret0;

 L2028: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 286;  /* *local_pic_storesisi */
    }
  goto ret0;

 L1652: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L2719;
  goto ret0;

 L2719: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 15)
    goto L1749;
  if (memory_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1653;
    }
  goto ret0;

 L1749: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (memory_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1750;
    }
  goto ret0;

 L1750: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1751;
    }
  goto ret0;

 L1751: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1752;
  goto ret0;

 L1752: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1753;
  goto ret0;

 L1753: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1754;
    }
  goto ret0;

 L1754: ATTRIBUTE_UNUSED_LABEL
  if (
#line 112 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 259;  /* atomic_exchangesi */
    }
  goto ret0;

 L1653: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1654;
  goto ret0;

 L1654: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1655;
  goto ret0;

 L1655: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L2720;
  goto ret0;

 L2720: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC_VOLATILE)
    goto L2722;
  goto ret0;

 L2722: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L2724;
    case 4:
      goto L2725;
    default:
      break;
    }
  goto ret0;

 L2724: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 14)
    goto L1656;
  goto ret0;

 L1656: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_MODE (x3) == SImode)
    goto L2726;
  goto ret0;

 L2726: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1657;
    case IOR:
      goto L1669;
    case XOR:
      goto L1681;
    case AND:
      goto L1693;
    default:
     break;
   }
  goto ret0;

 L1657: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1658;
  goto ret0;

 L1658: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1659;
    }
  goto ret0;

 L1659: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1660;
    }
  goto ret0;

 L1660: ATTRIBUTE_UNUSED_LABEL
  if (
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 251;  /* atomic_fetch_addsi */
    }
  goto ret0;

 L1669: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1670;
  goto ret0;

 L1670: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1671;
    }
  goto ret0;

 L1671: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1672;
    }
  goto ret0;

 L1672: ATTRIBUTE_UNUSED_LABEL
  if (
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 252;  /* atomic_fetch_orsi */
    }
  goto ret0;

 L1681: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1682;
  goto ret0;

 L1682: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1683;
    }
  goto ret0;

 L1683: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1684;
    }
  goto ret0;

 L1684: ATTRIBUTE_UNUSED_LABEL
  if (
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 253;  /* atomic_fetch_xorsi */
    }
  goto ret0;

 L1693: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1694;
  goto ret0;

 L1694: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1695;
    }
  goto ret0;

 L1695: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1696;
    }
  goto ret0;

 L1696: ATTRIBUTE_UNUSED_LABEL
  if (
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 254;  /* atomic_fetch_andsi */
    }
  goto ret0;

 L2725: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 13)
    goto L1786;
  goto ret0;

 L1786: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1787;
    }
  goto ret0;

 L1787: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1788;
    }
  goto ret0;

 L1788: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L1789;
    }
  goto ret0;

 L1789: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (const_int_operand (x3, SImode))
    {
      operands[5] = x3;
      goto L1790;
    }
  goto ret0;

 L1790: ATTRIBUTE_UNUSED_LABEL
  if (
#line 125 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 261;  /* atomic_cas_value_strongsi */
    }
  goto ret0;

 L2701: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1985;
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1700;
    }
  goto ret0;

 L1985: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1986;
    }
  goto ret0;

 L1986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1987;
    }
  goto ret0;

 L1987: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1988;
  goto ret0;

 L1988: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2730;
    case SImode:
      goto L2731;
    default:
      break;
    }
  goto ret0;

 L2730: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1989;
    }
  goto ret0;

 L1989: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 283;  /* *local_pic_storedidi */
    }
  goto ret0;

 L2731: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2041;
    }
  goto ret0;

 L2041: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 272 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 287;  /* *local_pic_storesidi */
    }
  goto ret0;

 L1700: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L2733;
  goto ret0;

 L2733: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 15)
    goto L1759;
  if (memory_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1701;
    }
  goto ret0;

 L1759: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (memory_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1760;
    }
  goto ret0;

 L1760: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1761;
    }
  goto ret0;

 L1761: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1762;
  goto ret0;

 L1762: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1763;
  goto ret0;

 L1763: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1764;
    }
  goto ret0;

 L1764: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 112 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 260;  /* atomic_exchangedi */
    }
  goto ret0;

 L1701: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1702;
  goto ret0;

 L1702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1703;
  goto ret0;

 L1703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L2734;
  goto ret0;

 L2734: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC_VOLATILE)
    goto L2736;
  goto ret0;

 L2736: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L2738;
    case 4:
      goto L2739;
    default:
      break;
    }
  goto ret0;

 L2738: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 14)
    goto L1704;
  goto ret0;

 L1704: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_MODE (x3) == DImode)
    goto L2740;
  goto ret0;

 L2740: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1705;
    case IOR:
      goto L1717;
    case XOR:
      goto L1729;
    case AND:
      goto L1741;
    default:
     break;
   }
  goto ret0;

 L1705: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1706;
  goto ret0;

 L1706: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1707;
    }
  goto ret0;

 L1707: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1708;
    }
  goto ret0;

 L1708: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 255;  /* atomic_fetch_adddi */
    }
  goto ret0;

 L1717: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1718;
  goto ret0;

 L1718: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1719;
    }
  goto ret0;

 L1719: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1720;
    }
  goto ret0;

 L1720: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 256;  /* atomic_fetch_ordi */
    }
  goto ret0;

 L1729: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1730;
  goto ret0;

 L1730: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1731;
    }
  goto ret0;

 L1731: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1732;
    }
  goto ret0;

 L1732: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 257;  /* atomic_fetch_xordi */
    }
  goto ret0;

 L1741: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1742;
  goto ret0;

 L1742: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_0_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1743;
    }
  goto ret0;

 L1743: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1744;
    }
  goto ret0;

 L1744: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 101 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 258;  /* atomic_fetch_anddi */
    }
  goto ret0;

 L2739: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 13)
    goto L1812;
  goto ret0;

 L1812: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1813;
    }
  goto ret0;

 L1813: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L1814;
    }
  goto ret0;

 L1814: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L1815;
    }
  goto ret0;

 L1815: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (const_int_operand (x3, SImode))
    {
      operands[5] = x3;
      goto L1816;
    }
  goto ret0;

 L1816: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 125 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 262;  /* atomic_cas_value_strongdi */
    }
  goto ret0;

 L2702: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L2050;
  if (register_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L1840;
    }
  goto ret0;

 L2050: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2051;
    }
  goto ret0;

 L2051: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2052;
    }
  goto ret0;

 L2052: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2053;
  goto ret0;

 L2053: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2744;
    case SImode:
      goto L2745;
    default:
      break;
    }
  goto ret0;

 L2744: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2054;
    }
  goto ret0;

 L2054: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 288;  /* *local_pic_storedisf */
    }
  goto ret0;

 L2745: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2080;
    }
  goto ret0;

 L2080: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 290;  /* *local_pic_storesisf */
    }
  goto ret0;

 L1840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == MEM)
    goto L1841;
  goto ret0;

 L1841: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1842;
    }
  goto ret0;

 L1842: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1843;
  goto ret0;

 L1843: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2746;
    case SImode:
      goto L2747;
    default:
      break;
    }
  goto ret0;

 L2746: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1844;
    }
  goto ret0;

 L1844: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 267;  /* *local_pic_loadsf */
    }
  goto ret0;

 L2747: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1870;
    }
  goto ret0;

 L1870: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 276 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 269;  /* *local_pic_loadsf */
    }
  goto ret0;

 L2703: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L2063;
  if (register_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L1853;
    }
  goto ret0;

 L2063: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2064;
    }
  goto ret0;

 L2064: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2065;
    }
  goto ret0;

 L2065: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2066;
  goto ret0;

 L2066: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2748;
    case SImode:
      goto L2749;
    default:
      break;
    }
  goto ret0;

 L2748: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2067;
    }
  goto ret0;

 L2067: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 91 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 289;  /* *local_pic_storedidf */
    }
  goto ret0;

 L2749: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2093;
    }
  goto ret0;

 L2093: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 98 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 291;  /* *local_pic_storesidf */
    }
  goto ret0;

 L1853: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == MEM)
    goto L1854;
  goto ret0;

 L1854: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1855;
    }
  goto ret0;

 L1855: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1856;
  goto ret0;

 L1856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2750;
    case SImode:
      goto L2751;
    default:
      break;
    }
  goto ret0;

 L2750: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1857;
    }
  goto ret0;

 L1857: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 57 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 268;  /* *local_pic_loaddf */
    }
  goto ret0;

 L2751: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1883;
    }
  goto ret0;

 L1883: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 64 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_HARD_FLOAT && !TARGET_64BIT && flag_pic && SYMBOL_REF_LOCAL_P (operands[1])) && 
#line 277 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    {
      return 270;  /* *local_pic_loaddf */
    }
  goto ret0;

 L2698: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1946;
  goto ret0;

 L1946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1947;
    }
  goto ret0;

 L1947: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1948;
    }
  goto ret0;

 L1948: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1949;
  goto ret0;

 L1949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2752;
    case SImode:
      goto L2753;
    default:
      break;
    }
  goto ret0;

 L2752: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1950;
    }
  goto ret0;

 L1950: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 280;  /* *local_pic_storediqi */
    }
  goto ret0;

 L2753: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2002;
    }
  goto ret0;

 L2002: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 284;  /* *local_pic_storesiqi */
    }
  goto ret0;

 L2699: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L1959;
  goto ret0;

 L1959: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (absolute_symbolic_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1960;
    }
  goto ret0;

 L1960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1961;
    }
  goto ret0;

 L1961: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1962;
  goto ret0;

 L1962: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L2754;
    case SImode:
      goto L2755;
    default:
      break;
    }
  goto ret0;

 L2754: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1963;
    }
  goto ret0;

 L1963: ATTRIBUTE_UNUSED_LABEL
  if (
#line 77 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 281;  /* *local_pic_storedihi */
    }
  goto ret0;

 L2755: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2015;
    }
  goto ret0;

 L2015: ATTRIBUTE_UNUSED_LABEL
  if (
#line 84 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(!TARGET_64BIT && (flag_pic && SYMBOL_REF_LOCAL_P (operands[0]))))
    {
      return 285;  /* *local_pic_storesihi */
    }
  goto ret0;
 ret0:
  return -1;
}

int
recog (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case SET:
      goto L1;
    case PARALLEL:
      goto L2331;
    case UNSPEC_VOLATILE:
      goto L2332;
    case SIMPLE_RETURN:
      goto L2335;
    case UNSPEC:
      goto L2336;
    case CALL:
      goto L1467;
    case CONST_INT:
      goto L2338;
    case TRAP_IF:
      goto L1565;
    default:
     break;
   }
  goto ret0;

 L1: ATTRIBUTE_UNUSED_LABEL
  return recog_4 (x0, insn, pnum_clobbers);

 L2331: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L205;
    case 3:
      goto L1479;
    default:
      break;
    }
  goto ret0;

 L205: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L206;
    case SIMPLE_RETURN:
      goto L1446;
    case UNSPEC:
      goto L2693;
    case CALL:
      goto L1509;
    default:
     break;
   }
  goto ret0;

 L206: ATTRIBUTE_UNUSED_LABEL
  return recog_5 (x0, insn, pnum_clobbers);

 L1446: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L1447;
  goto ret0;

 L1447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (pmode_register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      return 229;  /* simple_return_internal */
    }
  goto ret0;

 L2693: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 3)
    goto L1450;
  goto ret0;

 L1450: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2756;
    case DImode:
      goto L2757;
    default:
      break;
    }
  goto ret0;

 L2756: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1451;
    }
  goto ret0;

 L1451: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1452;
  goto ret0;

 L1452: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1453;
    }
  goto ret0;

 L1453: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2241 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(! TARGET_64BIT))
    {
      return 230;  /* eh_set_lr_si */
    }
  goto ret0;

 L2757: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1460;
    }
  goto ret0;

 L1460: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1461;
  goto ret0;

 L1461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1462;
    }
  goto ret0;

 L1462: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2247 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return 231;  /* eh_set_lr_di */
    }
  goto ret0;

 L1509: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L1510;
  goto ret0;

 L1510: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1511;
    }
  goto ret0;

 L1511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L1512;

 L1512: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1513;
  goto ret0;

 L1513: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 1)
    {
      return 235;  /* call_internal */
    }
  goto ret0;

 L1479: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L1767;
  goto ret0;

 L1767: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2758;
    case DImode:
      goto L2759;
    default:
      break;
    }
 L1480: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1481;
    }
  goto ret0;

 L2758: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1768;
    }
  goto L1480;

 L1768: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1769;
    }
  x2 = XEXP (x1, 0);
  goto L1480;

 L1769: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1770;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1771;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1771: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 4
      && XINT (x2, 1) == 13)
    goto L1772;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1772: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1773;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1773: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1774;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1774: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L1775;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1775: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (const_int_operand (x3, SImode))
    {
      operands[5] = x3;
      goto L1776;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1776: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1777;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1777: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L1778;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1778: ATTRIBUTE_UNUSED_LABEL
  if (
#line 125 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
    {
      return 261;  /* atomic_cas_value_strongsi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L2759: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1794;
    }
  goto L1480;

 L1794: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1795;
    }
  x2 = XEXP (x1, 0);
  goto L1480;

 L1795: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1796;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1796: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L1797;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1797: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 4
      && XINT (x2, 1) == 13)
    goto L1798;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1798: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1799;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1799: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (reg_or_0_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L1800;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1800: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L1801;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1801: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (const_int_operand (x3, SImode))
    {
      operands[5] = x3;
      goto L1802;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1802: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1803;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1803: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[6] = x2;
      goto L1804;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1804: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 125 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return 262;  /* atomic_cas_value_strongdi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1480;

 L1481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L1482;
  goto ret0;

 L1482: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L1483;
  goto ret0;

 L1483: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L1484;
    }
  goto ret0;

 L1484: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L1485;

 L1485: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1486;
  goto ret0;

 L1486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L1487;
    }
  goto ret0;

 L1487: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L1488;
  goto ret0;

 L1488: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L1489;
  goto ret0;

 L1489: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1490;
  goto ret0;

 L1490: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1491;
  goto ret0;

 L1491: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1492;
  goto ret0;

 L1492: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L2760;
  goto ret0;

 L2760: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1493;
    }
 L2761: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 1)
    {
      return 237;  /* call_value_multiple_internal */
    }
  goto ret0;

 L1493: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2326 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn)))
    {
      return 234;  /* sibcall_value_multiple_internal */
    }
  x1 = XVECEXP (x0, 0, 2);
  x2 = XEXP (x1, 0);
  goto L2761;

 L2332: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 1)
    goto L2762;
  goto ret0;

 L2762: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case HOST_WIDE_INT_CONSTANT (11):
      goto L944;
    case HOST_WIDE_INT_CONSTANT (12):
      goto L946;
    case HOST_WIDE_INT_CONSTANT (10):
      goto L1442;
    default:
      break;
    }
  goto ret0;

 L944: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 155;  /* fence */
    }
  goto ret0;

 L946: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 156;  /* fence_i */
    }
  goto ret0;

 L1442: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 227;  /* blockage */
    }
  goto ret0;

 L2335: ATTRIBUTE_UNUSED_LABEL
  return 228;  /* simple_return */

 L2336: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 1
      && XINT (x0, 1) == 3)
    goto L1455;
  goto ret0;

 L1455: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L2765;
    case DImode:
      goto L2766;
    default:
      break;
    }
  goto ret0;

 L2765: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1456;
    }
  goto ret0;

 L1456: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2241 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(! TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 230;  /* eh_set_lr_si */
    }
  goto ret0;

 L2766: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1465;
    }
  goto ret0;

 L1465: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2247 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 231;  /* eh_set_lr_di */
    }
  goto ret0;

 L1467: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == MEM)
    goto L1468;
  goto ret0;

 L1468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_insn_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L1469;
    }
  goto ret0;

 L1469: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  operands[1] = x1;
  goto L1470;

 L1470: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2291 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn)))
    {
      return 232;  /* sibcall_internal */
    }
 L1518: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 235;  /* call_internal */
    }
  goto ret0;

 L2338: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x0, 0) == HOST_WIDE_INT_CONSTANT (0))
    {
      return 238;  /* nop */
    }
  goto ret0;

 L1565: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L1566;
  goto ret0;

 L1566: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 239;  /* trap */
    }
  goto ret0;
 ret0:
  return -1;
}

rtx
split_insns (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case PARALLEL:
      goto L2767;
    case SET:
      goto L2133;
    default:
     break;
   }
  goto ret0;

 L2767: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 2)
    goto L2100;
  goto ret0;

 L2100: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2101;
    case UNSPEC:
      goto L2768;
    default:
     break;
   }
  goto ret0;

 L2101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case TImode:
      goto L2769;
    case SImode:
      goto L2770;
    case DImode:
      goto L2771;
    default:
      break;
    }
 L2232: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PC)
    goto L2233;
  goto ret0;

 L2769: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TImode))
    {
      operands[0] = x2;
      goto L2102;
    }
  goto L2232;

 L2102: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == MULT)
    goto L2103;
  x2 = XEXP (x1, 0);
  goto L2232;

 L2103: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode)
    goto L2772;
  x2 = XEXP (x1, 0);
  goto L2232;

 L2772: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L2104;
    case ZERO_EXTEND:
      goto L2115;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2104: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2105;
    }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2105: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L2106;
  x2 = XEXP (x1, 0);
  goto L2232;

 L2106: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2107;
    }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2107: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2108;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2108: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2109;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2109: ATTRIBUTE_UNUSED_LABEL
  if (
#line 649 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_298 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2115: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2116;
    }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2116: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode)
    goto L2774;
  x2 = XEXP (x1, 0);
  goto L2232;

 L2774: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2117;
    case SIGN_EXTEND:
      goto L2128;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2117: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2118;
    }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2118: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2119;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2119: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2120;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2120: ATTRIBUTE_UNUSED_LABEL
  if (
#line 649 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_299 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2128: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2129;
    }
  x2 = XEXP (x1, 0);
  goto L2232;

 L2129: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2130;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2130: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2131;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2131: ATTRIBUTE_UNUSED_LABEL
  if (
#line 689 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_300 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2770: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2190;
    }
  goto L2232;

 L2190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (splittable_const_int_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2191;
    }
 L2203: ATTRIBUTE_UNUSED_LABEL
  operands[1] = x2;
  goto L2204;

 L2191: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2192;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L2203;

 L2192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      return gen_split_315 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L2203;

 L2204: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2205;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2206;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2206: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    {
      return gen_split_317 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2771: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2196;
    }
  goto L2232;

 L2196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (splittable_const_int_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2197;
    }
 L2210: ATTRIBUTE_UNUSED_LABEL
  operands[1] = x2;
  goto L2211;

 L2197: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2198;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L2210;

 L2198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2199;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L2210;

 L2199: ATTRIBUTE_UNUSED_LABEL
  if (
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    {
      return gen_split_316 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L2210;

 L2211: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2212;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2212: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2213;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2213: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1473 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL)) && 
#line 254 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    {
      return gen_split_318 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2232;

 L2233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L2234;
  goto ret0;

 L2234: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (equality_operator (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2235;
    }
  goto ret0;

 L2235: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L2776;
    case DImode:
      goto L2777;
    default:
      break;
    }
  goto ret0;

 L2776: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L2236;
  goto ret0;

 L2236: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2237;
    }
  goto ret0;

 L2237: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT)
    goto L2778;
  goto ret0;

 L2778: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x5, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L2238;
 L2779: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L2270;
    }
  goto ret0;

 L2238: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L2239;
    }
  x5 = XEXP (x4, 1);
  goto L2779;

 L2239: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2240;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2240: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L2241;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2241: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L2242;

 L2242: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L2243;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2243: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2244;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2244: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L2245;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2245: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1962 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_337 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2779;

 L2270: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2271;
  goto ret0;

 L2271: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2272;
  goto ret0;

 L2272: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L2273;
  goto ret0;

 L2273: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L2274;

 L2274: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L2275;
  goto ret0;

 L2275: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2276;
  goto ret0;

 L2276: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L2277;
    }
  goto ret0;

 L2277: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1993 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_339 (insn, operands);
    }
  goto ret0;

 L2777: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L2252;
  goto ret0;

 L2252: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L2253;
    }
  goto ret0;

 L2253: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT)
    goto L2780;
  goto ret0;

 L2780: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x5, 0) == HOST_WIDE_INT_CONSTANT (1))
    goto L2254;
 L2781: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L2286;
    }
  goto ret0;

 L2254: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (const_int_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L2255;
    }
  x5 = XEXP (x4, 1);
  goto L2781;

 L2255: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2256;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2256: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L2257;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2257: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L2258;

 L2258: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L2259;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2259: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2260;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L2261;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2261: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1962 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return gen_split_338 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L2781;

 L2286: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2287;
  goto ret0;

 L2287: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2288;
  goto ret0;

 L2288: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L2289;
  goto ret0;

 L2289: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  goto L2290;

 L2290: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L2291;
  goto ret0;

 L2291: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2292;
  goto ret0;

 L2292: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L2293;
    }
  goto ret0;

 L2293: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1993 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    {
      return gen_split_340 (insn, operands);
    }
  goto ret0;

 L2768: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 3)
    goto L2296;
  goto ret0;

 L2296: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2297;
    }
  goto ret0;

 L2297: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2298;
  goto ret0;

 L2298: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L2299;
    }
  goto ret0;

 L2299: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2253 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed))
    {
      return gen_split_350 (insn, operands);
    }
  goto ret0;

 L2133: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DImode:
      goto L2782;
    case SImode:
      goto L2783;
    case HImode:
      goto L2784;
    case DFmode:
      goto L2786;
    case TImode:
      goto L2787;
    case TFmode:
      goto L2788;
    default:
      break;
    }
  goto ret0;

 L2782: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2134;
    }
 L2785: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2216;
    }
  goto ret0;

 L2134: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L2789;
  x1 = XEXP (x0, 0);
  goto L2785;

 L2789: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L2135;
    case AND:
      goto L2140;
    case SIGN_EXTEND:
      goto L2155;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2135: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2792;
    case HImode:
      goto L2793;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2792: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2136;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2136: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1093 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1097 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_304 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2793: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2151;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2151: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 245 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1137 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_307 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2140: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2141;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == HOST_WIDE_INT_CONSTANT (4294967295)
      && (
#line 1113 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1121 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_305 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2155: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L2794;
    case QImode:
      goto L2795;
    case HImode:
      goto L2796;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2794: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2156;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2156: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1181 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1185 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && register_operand (operands[1], VOIDmode))))
    {
      return gen_split_308 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2795: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2171;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2171: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_311 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2796: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2186;
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2186: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 246 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_314 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L2785;

 L2216: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L2217;
    }
  goto ret0;

 L2217: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1706 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed && !TARGET_64BIT
   && riscv_split_64bit_move_p (operands[0], operands[1])))
    {
      return gen_split_326 (insn, operands);
    }
  goto ret0;

 L2783: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L2144;
    }
  goto ret0;

 L2144: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L2797;
  goto ret0;

 L2797: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L2145;
    case SIGN_EXTEND:
      goto L2165;
    default:
     break;
   }
  goto ret0;

 L2145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2146;
    }
  goto ret0;

 L2146: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1137 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    {
      return gen_split_306 (insn, operands);
    }
  goto ret0;

 L2165: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2799;
    case HImode:
      goto L2800;
    default:
      break;
    }
  goto ret0;

 L2799: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2166;
    }
  goto ret0;

 L2166: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    {
      return gen_split_310 (insn, operands);
    }
  goto ret0;

 L2800: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2181;
    }
  goto ret0;

 L2181: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    {
      return gen_split_313 (insn, operands);
    }
  goto ret0;

 L2784: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L2159;
    }
  goto ret0;

 L2159: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == SIGN_EXTEND)
    goto L2160;
  goto ret0;

 L2160: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L2801;
    case HImode:
      goto L2802;
    default:
      break;
    }
  goto ret0;

 L2801: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2161;
    }
  goto ret0;

 L2161: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    {
      return gen_split_309 (insn, operands);
    }
  goto ret0;

 L2802: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2176;
    }
  goto ret0;

 L2176: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1206 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
( reload_completed && REG_P (operands[1])))
    {
      return gen_split_312 (insn, operands);
    }
  goto ret0;

 L2786: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L2220;
    }
  goto ret0;

 L2220: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L2221;
    }
  goto ret0;

 L2221: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1706 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(reload_completed && !TARGET_64BIT
   && riscv_split_64bit_move_p (operands[0], operands[1])))
    {
      return gen_split_327 (insn, operands);
    }
  goto ret0;

 L2787: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L2224;
    }
  goto ret0;

 L2224: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L2225;
    }
  goto ret0;

 L2225: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1717 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && reload_completed))
    {
      return gen_split_328 (insn, operands);
    }
  goto ret0;

 L2788: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L2228;
    }
  goto ret0;

 L2228: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, TFmode))
    {
      operands[1] = x1;
      goto L2229;
    }
  goto ret0;

 L2229: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1717 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT && reload_completed))
    {
      return gen_split_329 (insn, operands);
    }
  goto ret0;
 ret0:
  return 0;
}

rtx
peephole2_insns (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *_pmatch_len ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  if (peep2_current_count >= 2)
    goto L2301;
  goto ret0;

 L2301: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L2302;
  goto ret0;

 L2302: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DImode:
      goto L2803;
    case SImode:
      goto L2804;
    default:
      break;
    }
  goto ret0;

 L2803: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2303;
    }
  goto ret0;

 L2303: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (modular_operator (x1, DImode))
    {
      operands[4] = x1;
      goto L2304;
    }
  goto ret0;

 L2304: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2305;
    }
  goto ret0;

 L2305: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2306;
    }
  goto ret0;

 L2306: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L2307;
  goto ret0;

 L2307: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2308;
    }
  goto ret0;

 L2308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == TRUNCATE)
    goto L2309;
  goto ret0;

 L2309: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0])
      && 
#line 13 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))
   && (GET_CODE (operands[4]) != ASHIFT || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) < 32))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_360 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto ret0;

 L2804: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L2313;
    }
  goto ret0;

 L2313: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == TRUNCATE)
    goto L2314;
  goto ret0;

 L2314: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L2805;
  goto ret0;

 L2805: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2315;
    }
 L2806: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2326;
    }
  goto ret0;

 L2315: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L2316;
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2316: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2317;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (modular_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2318;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2318: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L2319;
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2319: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2320;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2320: ATTRIBUTE_UNUSED_LABEL
  if (
#line 29 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_361 (insn, operands);
      if (tem != 0)
        return tem;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L2806;

 L2326: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L2327;
  goto ret0;

 L2327: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2328;
    }
  goto ret0;

 L2328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (modular_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2329;
    }
  goto ret0;

 L2329: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (reg_or_0_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2330;
    }
  goto ret0;

 L2330: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[0])
      && 
#line 41 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/peephole.md"
(TARGET_64BIT && (REGNO (operands[0]) == REGNO (operands[3]) || peep2_reg_dead_p (2, operands[0]))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_362 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto ret0;
 ret0:
  return 0;
}

