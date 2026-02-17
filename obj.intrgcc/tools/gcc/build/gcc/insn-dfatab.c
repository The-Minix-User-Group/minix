/* Generated automatically by the program `genattrtab'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "insn-attr.h"
#include "tm_p.h"
#include "insn-config.h"
#include "recog.h"
#include "regs.h"
#include "real.h"
#include "output.h"
#include "toplev.h"
#include "flags.h"
#include "function.h"

#define operands recog_data.operand

int
internal_dfa_insn_code (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_mode cached_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 227:  /* blockage */
      return 0;

    case 181:  /* cstoredf4 */
    case 180:  /* cstoresf4 */
      return 10 /* 0xa */;

    case 237:  /* call_value_multiple_internal */
    case 236:  /* call_value_internal */
    case 235:  /* call_internal */
    case 234:  /* sibcall_value_multiple_internal */
    case 233:  /* sibcall_value_internal */
    case 232:  /* sibcall_internal */
    case 229:  /* simple_return_internal */
    case 228:  /* simple_return */
    case 226:  /* tablejumpdi */
    case 225:  /* tablejumpsi */
    case 224:  /* indirect_jumpdi */
    case 223:  /* indirect_jumpsi */
    case 222:  /* jump */
    case 175:  /* *branch_orderdi */
    case 174:  /* *branch_ordersi */
      return 5;

    case 154:  /* store_wordtf */
    case 153:  /* store_worddi */
    case 152:  /* store_worddf */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 3;
        }
      else
        {
	  return 4;
        }

    case 151:  /* load_hightf */
    case 150:  /* load_highdi */
    case 149:  /* load_highdf */
    case 148:  /* load_lowtf */
    case 147:  /* load_lowdi */
    case 146:  /* load_lowdf */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 2;
        }
      else
        {
	  return 4;
        }

    case 142:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 5)
        {
	  return 1;
        }
      else if (((1 << which_alternative) & 0x44))
        {
	  return 2;
        }
      else if (!((1 << which_alternative) & 0x67))
        {
	  return 3;
        }
      else if (which_alternative == 1)
        {
	  return 4;
        }
      else
        {
	  return 9;
        }

    case 144:  /* *movdf_softfloat */
    case 141:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else if (which_alternative == 1)
        {
	  return 2;
        }
      else
        {
	  return 3;
        }

    case 143:  /* *movdf_hardfloat_rv64 */
    case 140:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 7)
        {
	  return 1;
        }
      else if (((1 << which_alternative) & 0x104))
        {
	  return 2;
        }
      else if (!((1 << which_alternative) & 0x1e7))
        {
	  return 3;
        }
      else if (((1 << which_alternative) & 0x62))
        {
	  return 4;
        }
      else
        {
	  return 9;
        }

    case 139:  /* *movqi_internal */
    case 134:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x3))
        {
	  return 1;
        }
      else if (which_alternative == 2)
        {
	  return 2;
        }
      else if (which_alternative == 3)
        {
	  return 3;
        }
      else
        {
	  return 4;
        }

    case 133:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x3))
        {
	  return 1;
        }
      else if (((1 << which_alternative) & 0x24))
        {
	  return 2;
        }
      else if (!((1 << which_alternative) & 0x77))
        {
	  return 3;
        }
      else
        {
	  return 4;
        }

    case 128:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_iesi */
    case 126:  /* got_load_tls_gddi */
    case 125:  /* got_load_tls_gdsi */
    case 122:  /* got_loaddi */
    case 121:  /* got_loadsi */
      return 2;

    case 103:  /* extendhidi2 */
    case 102:  /* extendhisi2 */
    case 101:  /* extendhihi2 */
    case 100:  /* extendqidi2 */
    case 99:  /* extendqisi2 */
    case 98:  /* extendqihi2 */
    case 97:  /* extendsidi2 */
    case 96:  /* zero_extendqidi2 */
    case 95:  /* zero_extendqisi2 */
    case 94:  /* zero_extendqihi2 */
    case 93:  /* zero_extendhidi2 */
    case 92:  /* zero_extendhisi2 */
    case 91:  /* *clear_upper32 */
    case 90:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 83:  /* truncdisi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 120:  /* fixuns_truncsfdi2 */
    case 119:  /* fixuns_truncdfdi2 */
    case 118:  /* fixuns_truncsfsi2 */
    case 117:  /* fixuns_truncdfsi2 */
    case 116:  /* floatunsdisf2 */
    case 115:  /* floatunssisf2 */
    case 114:  /* floatunsdidf2 */
    case 113:  /* floatunssidf2 */
    case 112:  /* floatdisf2 */
    case 111:  /* floatsisf2 */
    case 110:  /* floatdidf2 */
    case 109:  /* floatsidf2 */
    case 108:  /* fix_truncsfdi2 */
    case 107:  /* fix_truncdfdi2 */
    case 106:  /* fix_truncsfsi2 */
    case 105:  /* fix_truncdfsi2 */
    case 104:  /* extendsfdf2 */
    case 82:  /* truncdfsf2 */
      return 8;

    case 73:  /* negdf2 */
    case 72:  /* negsf2 */
    case 71:  /* smaxdf3 */
    case 70:  /* smaxsf3 */
    case 69:  /* smindf3 */
    case 68:  /* sminsf3 */
    case 67:  /* absdf2 */
    case 66:  /* abssf2 */
      return 9;

    case 53:  /* sqrtdf2 */
      return 17 /* 0x11 */;

    case 52:  /* sqrtsf2 */
      return 16 /* 0x10 */;

    case 51:  /* divdf3 */
      return 15 /* 0xf */;

    case 50:  /* divsf3 */
      return 14 /* 0xe */;

    case 49:  /* umoddi3 */
    case 48:  /* moddi3 */
    case 47:  /* umodsi3 */
    case 46:  /* modsi3 */
    case 45:  /* udivdi3 */
    case 44:  /* divdi3 */
    case 43:  /* udivsi3 */
    case 42:  /* divsi3 */
      return 7;

    case 41:  /* usmulsi3_highpart */
    case 40:  /* umulsi3_highpart */
    case 39:  /* mulsi3_highpart */
    case 38:  /* usmuldi3_highpart */
    case 36:  /* umuldi3_highpart */
    case 35:  /* muldi3_highpart */
    case 32:  /* *muldi3 */
    case 31:  /* *muldi3_truncsi */
    case 30:  /* *muldisi3 */
    case 29:  /* *mulsi3 */
    case 28:  /* *mulsi3 */
    case 27:  /* *mulsi3 */
    case 26:  /* *mulsi3 */
      return 6;

    case 65:  /* *nfmsdf4_fastmath */
    case 63:  /* *nfmadf4_fastmath */
    case 61:  /* nfmsdf4 */
    case 59:  /* nfmadf4 */
    case 57:  /* fmsdf4 */
    case 55:  /* fmadf4 */
    case 25:  /* muldf3 */
      return 13 /* 0xd */;

    case 64:  /* *nfmssf4_fastmath */
    case 62:  /* *nfmasf4_fastmath */
    case 60:  /* nfmssf4 */
    case 58:  /* nfmasf4 */
    case 56:  /* fmssf4 */
    case 54:  /* fmasf4 */
    case 24:  /* mulsf3 */
      return 12 /* 0xc */;

    case 13:  /* subdf3 */
    case 12:  /* subsf3 */
    case 2:  /* adddf3 */
    case 1:  /* addsf3 */
      return 11 /* 0xb */;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    case 131:  /* *movdi_32bit */
    case 132:  /* *movdi_64bit */
    case 145:  /* *movti */
      if ((cached_type = get_attr_type (insn)) == TYPE_GHOST)
        {
	  return 0;
        }
      else if ((cached_type == TYPE_UNKNOWN) || ((cached_type == TYPE_CONST) || ((cached_type == TYPE_ARITH) || ((cached_type == TYPE_SHIFT) || ((cached_type == TYPE_SLT) || ((cached_type == TYPE_MULTI) || ((cached_type == TYPE_NOP) || ((cached_type == TYPE_LOGICAL) || (cached_type == TYPE_MOVE)))))))))
        {
	  return 1;
        }
      else if ((cached_type == TYPE_LOAD) || ((cached_type == TYPE_FPLOAD) || (cached_type == TYPE_FPIDXLOAD)))
        {
	  return 2;
        }
      else if ((cached_type == TYPE_STORE) || ((cached_type == TYPE_FPSTORE) || (cached_type == TYPE_FPIDXSTORE)))
        {
	  return 3;
        }
      else if ((cached_type == TYPE_MFC) || (cached_type == TYPE_MTC))
        {
	  return 4;
        }
      else if ((cached_type == TYPE_BRANCH) || ((cached_type == TYPE_JUMP) || (cached_type == TYPE_CALL)))
        {
	  return 5;
        }
      else if (cached_type == TYPE_IMUL)
        {
	  return 6;
        }
      else if (cached_type == TYPE_IDIV)
        {
	  return 7;
        }
      else if (cached_type == TYPE_FCVT)
        {
	  return 8;
        }
      else if (cached_type == TYPE_FMOVE)
        {
	  return 9;
        }
      else if (cached_type == TYPE_FCMP)
        {
	  return 10 /* 0xa */;
        }
      else if (cached_type == TYPE_FADD)
        {
	  return 11 /* 0xb */;
        }
      else if (((cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 12 /* 0xc */;
        }
      else if (((cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 13 /* 0xd */;
        }
      else if ((cached_type == TYPE_FDIV) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 14 /* 0xe */;
        }
      else if ((cached_type == TYPE_FDIV) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 15 /* 0xf */;
        }
      else if ((cached_type == TYPE_FSQRT) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 16 /* 0x10 */;
        }
      else if ((cached_type == TYPE_FSQRT) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 17 /* 0x11 */;
        }
      else
        {
	  return 19 /* 0x13 */;
        }

    default:
      return 1;

    }
}

