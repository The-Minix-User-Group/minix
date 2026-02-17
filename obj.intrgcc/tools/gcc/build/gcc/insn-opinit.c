/* Generated automatically by the program `genopinit'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "flags.h"
#include "insn-config.h"
#include "expr.h"
#include "optabs.h"

struct optab_pat {
  unsigned scode;
  enum insn_code icode;
};

static const struct optab_pat pats[NUM_OPTAB_PATTERNS] = {
  { 0x010405, CODE_FOR_extendqihi2 },
  { 0x010406, CODE_FOR_extendqisi2 },
  { 0x010407, CODE_FOR_extendqidi2 },
  { 0x010505, CODE_FOR_extendhihi2 },
  { 0x010506, CODE_FOR_extendhisi2 },
  { 0x010507, CODE_FOR_extendhidi2 },
  { 0x010607, CODE_FOR_extendsidi2 },
  { 0x011b1c, CODE_FOR_extendsfdf2 },
  { 0x020706, CODE_FOR_truncdisi2 },
  { 0x021c1b, CODE_FOR_truncdfsf2 },
  { 0x030405, CODE_FOR_zero_extendqihi2 },
  { 0x030406, CODE_FOR_zero_extendqisi2 },
  { 0x030407, CODE_FOR_zero_extendqidi2 },
  { 0x030506, CODE_FOR_zero_extendhisi2 },
  { 0x030507, CODE_FOR_zero_extendhidi2 },
  { 0x030607, CODE_FOR_zero_extendsidi2 },
  { 0x06061b, CODE_FOR_floatsisf2 },
  { 0x06061c, CODE_FOR_floatsidf2 },
  { 0x06071b, CODE_FOR_floatdisf2 },
  { 0x06071c, CODE_FOR_floatdidf2 },
  { 0x07061b, CODE_FOR_floatunssisf2 },
  { 0x07061c, CODE_FOR_floatunssidf2 },
  { 0x07071b, CODE_FOR_floatunsdisf2 },
  { 0x07071c, CODE_FOR_floatunsdidf2 },
  { 0x101b06, CODE_FOR_fix_truncsfsi2 },
  { 0x101b07, CODE_FOR_fix_truncsfdi2 },
  { 0x101c06, CODE_FOR_fix_truncdfsi2 },
  { 0x101c07, CODE_FOR_fix_truncdfdi2 },
  { 0x111b06, CODE_FOR_fixuns_truncsfsi2 },
  { 0x111b07, CODE_FOR_fixuns_truncsfdi2 },
  { 0x111c06, CODE_FOR_fixuns_truncdfsi2 },
  { 0x111c07, CODE_FOR_fixuns_truncdfdi2 },
  { 0x120607, CODE_FOR_mulsidi3 },
  { 0x120708, CODE_FOR_mulditi3 },
  { 0x130607, CODE_FOR_umulsidi3 },
  { 0x130708, CODE_FOR_umulditi3 },
  { 0x140607, CODE_FOR_usmulsidi3 },
  { 0x140708, CODE_FOR_usmulditi3 },
  { 0x210006, CODE_FOR_addsi3 },
  { 0x210007, CODE_FOR_adddi3 },
  { 0x21001b, CODE_FOR_addsf3 },
  { 0x21001c, CODE_FOR_adddf3 },
  { 0x250006, CODE_FOR_subsi3 },
  { 0x250007, CODE_FOR_subdi3 },
  { 0x25001b, CODE_FOR_subsf3 },
  { 0x25001c, CODE_FOR_subdf3 },
  { 0x290006, CODE_FOR_mulsi3 },
  { 0x290007, CODE_FOR_muldi3 },
  { 0x29001b, CODE_FOR_mulsf3 },
  { 0x29001c, CODE_FOR_muldf3 },
  { 0x2d0006, CODE_FOR_divsi3 },
  { 0x2d0007, CODE_FOR_divdi3 },
  { 0x2d001b, CODE_FOR_divsf3 },
  { 0x2d001c, CODE_FOR_divdf3 },
  { 0x300006, CODE_FOR_udivsi3 },
  { 0x300007, CODE_FOR_udivdi3 },
  { 0x340006, CODE_FOR_modsi3 },
  { 0x340007, CODE_FOR_moddi3 },
  { 0x350006, CODE_FOR_umodsi3 },
  { 0x350007, CODE_FOR_umoddi3 },
  { 0x370006, CODE_FOR_andsi3 },
  { 0x370007, CODE_FOR_anddi3 },
  { 0x380006, CODE_FOR_iorsi3 },
  { 0x380007, CODE_FOR_iordi3 },
  { 0x390006, CODE_FOR_xorsi3 },
  { 0x390007, CODE_FOR_xordi3 },
  { 0x3a0006, CODE_FOR_ashlsi3 },
  { 0x3a0007, CODE_FOR_ashldi3 },
  { 0x3d0006, CODE_FOR_ashrsi3 },
  { 0x3d0007, CODE_FOR_ashrdi3 },
  { 0x3e0006, CODE_FOR_lshrsi3 },
  { 0x3e0007, CODE_FOR_lshrdi3 },
  { 0x46001b, CODE_FOR_sminsf3 },
  { 0x46001c, CODE_FOR_smindf3 },
  { 0x47001b, CODE_FOR_smaxsf3 },
  { 0x47001c, CODE_FOR_smaxdf3 },
  { 0x4a001b, CODE_FOR_negsf2 },
  { 0x4a001c, CODE_FOR_negdf2 },
  { 0x4e001b, CODE_FOR_abssf2 },
  { 0x4e001c, CODE_FOR_absdf2 },
  { 0x500006, CODE_FOR_one_cmplsi2 },
  { 0x500007, CODE_FOR_one_cmpldi2 },
  { 0x62001b, CODE_FOR_sqrtsf2 },
  { 0x62001c, CODE_FOR_sqrtdf2 },
  { 0x710004, CODE_FOR_movqi },
  { 0x710005, CODE_FOR_movhi },
  { 0x710006, CODE_FOR_movsi },
  { 0x710007, CODE_FOR_movdi },
  { 0x710008, CODE_FOR_movti },
  { 0x71001b, CODE_FOR_movsf },
  { 0x71001c, CODE_FOR_movdf },
  { 0x7e0006, CODE_FOR_cbranchsi4 },
  { 0x7e0007, CODE_FOR_cbranchdi4 },
  { 0x7e001b, CODE_FOR_cbranchsf4 },
  { 0x7e001c, CODE_FOR_cbranchdf4 },
  { 0x820006, CODE_FOR_cstoresi4 },
  { 0x820007, CODE_FOR_cstoredi4 },
  { 0x82001b, CODE_FOR_cstoresf4 },
  { 0x82001c, CODE_FOR_cstoredf4 },
  { 0x850006, CODE_FOR_umulsi3_highpart },
  { 0x850007, CODE_FOR_umuldi3_highpart },
  { 0x890006, CODE_FOR_movmemsi },
  { 0x8c001b, CODE_FOR_fmasf4 },
  { 0x8c001c, CODE_FOR_fmadf4 },
  { 0x8d001b, CODE_FOR_fmssf4 },
  { 0x8d001c, CODE_FOR_fmsdf4 },
  { 0xe40006, CODE_FOR_atomic_addsi },
  { 0xe40007, CODE_FOR_atomic_adddi },
  { 0xe60006, CODE_FOR_atomic_andsi },
  { 0xe60007, CODE_FOR_atomic_anddi },
  { 0xe70006, CODE_FOR_atomic_compare_and_swapsi },
  { 0xe70007, CODE_FOR_atomic_compare_and_swapdi },
  { 0xe80006, CODE_FOR_atomic_exchangesi },
  { 0xe80007, CODE_FOR_atomic_exchangedi },
  { 0xe90006, CODE_FOR_atomic_fetch_addsi },
  { 0xe90007, CODE_FOR_atomic_fetch_adddi },
  { 0xea0006, CODE_FOR_atomic_fetch_andsi },
  { 0xea0007, CODE_FOR_atomic_fetch_anddi },
  { 0xec0006, CODE_FOR_atomic_fetch_orsi },
  { 0xec0007, CODE_FOR_atomic_fetch_ordi },
  { 0xee0006, CODE_FOR_atomic_fetch_xorsi },
  { 0xee0007, CODE_FOR_atomic_fetch_xordi },
  { 0xf30006, CODE_FOR_atomic_orsi },
  { 0xf30007, CODE_FOR_atomic_ordi },
  { 0xf40006, CODE_FOR_atomic_storesi },
  { 0xf40007, CODE_FOR_atomic_storedi },
  { 0xf80006, CODE_FOR_atomic_xorsi },
  { 0xf80007, CODE_FOR_atomic_xordi },
};

void
init_all_optabs (struct target_optabs *optabs)
{
  bool *ena = optabs->pat_enable;
  ena[0] = HAVE_extendqihi2;
  ena[1] = HAVE_extendqisi2;
  ena[2] = HAVE_extendqidi2;
  ena[3] = HAVE_extendhihi2;
  ena[4] = HAVE_extendhisi2;
  ena[5] = HAVE_extendhidi2;
  ena[6] = HAVE_extendsidi2;
  ena[7] = HAVE_extendsfdf2;
  ena[8] = HAVE_truncdisi2;
  ena[9] = HAVE_truncdfsf2;
  ena[10] = HAVE_zero_extendqihi2;
  ena[11] = HAVE_zero_extendqisi2;
  ena[12] = HAVE_zero_extendqidi2;
  ena[13] = HAVE_zero_extendhisi2;
  ena[14] = HAVE_zero_extendhidi2;
  ena[15] = HAVE_zero_extendsidi2;
  ena[16] = HAVE_floatsisf2;
  ena[17] = HAVE_floatsidf2;
  ena[18] = HAVE_floatdisf2;
  ena[19] = HAVE_floatdidf2;
  ena[20] = HAVE_floatunssisf2;
  ena[21] = HAVE_floatunssidf2;
  ena[22] = HAVE_floatunsdisf2;
  ena[23] = HAVE_floatunsdidf2;
  ena[24] = HAVE_fix_truncsfsi2;
  ena[25] = HAVE_fix_truncsfdi2;
  ena[26] = HAVE_fix_truncdfsi2;
  ena[27] = HAVE_fix_truncdfdi2;
  ena[28] = HAVE_fixuns_truncsfsi2;
  ena[29] = HAVE_fixuns_truncsfdi2;
  ena[30] = HAVE_fixuns_truncdfsi2;
  ena[31] = HAVE_fixuns_truncdfdi2;
  ena[32] = HAVE_mulsidi3;
  ena[33] = HAVE_mulditi3;
  ena[34] = HAVE_umulsidi3;
  ena[35] = HAVE_umulditi3;
  ena[36] = HAVE_usmulsidi3;
  ena[37] = HAVE_usmulditi3;
  ena[38] = HAVE_addsi3;
  ena[39] = HAVE_adddi3;
  ena[40] = HAVE_addsf3;
  ena[41] = HAVE_adddf3;
  ena[42] = HAVE_subsi3;
  ena[43] = HAVE_subdi3;
  ena[44] = HAVE_subsf3;
  ena[45] = HAVE_subdf3;
  ena[46] = HAVE_mulsi3;
  ena[47] = HAVE_muldi3;
  ena[48] = HAVE_mulsf3;
  ena[49] = HAVE_muldf3;
  ena[50] = HAVE_divsi3;
  ena[51] = HAVE_divdi3;
  ena[52] = HAVE_divsf3;
  ena[53] = HAVE_divdf3;
  ena[54] = HAVE_udivsi3;
  ena[55] = HAVE_udivdi3;
  ena[56] = HAVE_modsi3;
  ena[57] = HAVE_moddi3;
  ena[58] = HAVE_umodsi3;
  ena[59] = HAVE_umoddi3;
  ena[60] = HAVE_andsi3;
  ena[61] = HAVE_anddi3;
  ena[62] = HAVE_iorsi3;
  ena[63] = HAVE_iordi3;
  ena[64] = HAVE_xorsi3;
  ena[65] = HAVE_xordi3;
  ena[66] = HAVE_ashlsi3;
  ena[67] = HAVE_ashldi3;
  ena[68] = HAVE_ashrsi3;
  ena[69] = HAVE_ashrdi3;
  ena[70] = HAVE_lshrsi3;
  ena[71] = HAVE_lshrdi3;
  ena[72] = HAVE_sminsf3;
  ena[73] = HAVE_smindf3;
  ena[74] = HAVE_smaxsf3;
  ena[75] = HAVE_smaxdf3;
  ena[76] = HAVE_negsf2;
  ena[77] = HAVE_negdf2;
  ena[78] = HAVE_abssf2;
  ena[79] = HAVE_absdf2;
  ena[80] = HAVE_one_cmplsi2;
  ena[81] = HAVE_one_cmpldi2;
  ena[82] = HAVE_sqrtsf2;
  ena[83] = HAVE_sqrtdf2;
  ena[84] = HAVE_movqi;
  ena[85] = HAVE_movhi;
  ena[86] = HAVE_movsi;
  ena[87] = HAVE_movdi;
  ena[88] = HAVE_movti;
  ena[89] = HAVE_movsf;
  ena[90] = HAVE_movdf;
  ena[91] = HAVE_cbranchsi4;
  ena[92] = HAVE_cbranchdi4;
  ena[93] = HAVE_cbranchsf4;
  ena[94] = HAVE_cbranchdf4;
  ena[95] = HAVE_cstoresi4;
  ena[96] = HAVE_cstoredi4;
  ena[97] = HAVE_cstoresf4;
  ena[98] = HAVE_cstoredf4;
  ena[99] = HAVE_umulsi3_highpart;
  ena[100] = HAVE_umuldi3_highpart;
  ena[101] = HAVE_movmemsi;
  ena[102] = HAVE_fmasf4;
  ena[103] = HAVE_fmadf4;
  ena[104] = HAVE_fmssf4;
  ena[105] = HAVE_fmsdf4;
  ena[106] = HAVE_atomic_addsi;
  ena[107] = HAVE_atomic_adddi;
  ena[108] = HAVE_atomic_andsi;
  ena[109] = HAVE_atomic_anddi;
  ena[110] = HAVE_atomic_compare_and_swapsi;
  ena[111] = HAVE_atomic_compare_and_swapdi;
  ena[112] = HAVE_atomic_exchangesi;
  ena[113] = HAVE_atomic_exchangedi;
  ena[114] = HAVE_atomic_fetch_addsi;
  ena[115] = HAVE_atomic_fetch_adddi;
  ena[116] = HAVE_atomic_fetch_andsi;
  ena[117] = HAVE_atomic_fetch_anddi;
  ena[118] = HAVE_atomic_fetch_orsi;
  ena[119] = HAVE_atomic_fetch_ordi;
  ena[120] = HAVE_atomic_fetch_xorsi;
  ena[121] = HAVE_atomic_fetch_xordi;
  ena[122] = HAVE_atomic_orsi;
  ena[123] = HAVE_atomic_ordi;
  ena[124] = HAVE_atomic_storesi;
  ena[125] = HAVE_atomic_storedi;
  ena[126] = HAVE_atomic_xorsi;
  ena[127] = HAVE_atomic_xordi;
}

static int
lookup_handler (unsigned scode)
{
  int l = 0, h = ARRAY_SIZE (pats), m;
  while (h > l)
    {
      m = (h + l) / 2;
      if (scode == pats[m].scode)
        return m;
      else if (scode < pats[m].scode)
        h = m;
      else
        l = m + 1;
    }
  return -1;
}

enum insn_code
raw_optab_handler (unsigned scode)
{
  int i = lookup_handler (scode);
  return (i >= 0 && this_fn_optabs->pat_enable[i]
          ? pats[i].icode : CODE_FOR_nothing);
}

bool
swap_optab_enable (optab op, enum machine_mode m, bool set)
{
  unsigned scode = (op << 16) | m;
  int i = lookup_handler (scode);
  if (i >= 0)
    {
      bool ret = this_fn_optabs->pat_enable[i];
      this_fn_optabs->pat_enable[i] = set;
      return ret;
    }
  else
    {
      gcc_assert (!set);
      return false;
    }
}

const struct convert_optab_libcall_d convlib_def[NUM_CONVLIB_OPTABS] = {
  { "extend", gen_extend_conv_libfunc },
  { "trunc", gen_trunc_conv_libfunc },
  { NULL, NULL },
  { "fix", gen_fp_to_int_conv_libfunc },
  { "fixuns", gen_fp_to_int_conv_libfunc },
  { "float", gen_int_to_fp_conv_libfunc },
  { NULL, gen_ufloat_conv_libfunc },
  { "lrint", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lround", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lfloor", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lceil", gen_int_to_fp_nondecimal_conv_libfunc },
  { "fract", gen_fract_conv_libfunc },
  { "fractuns", gen_fractuns_conv_libfunc },
  { "satfract", gen_satfract_conv_libfunc },
  { "satfractuns", gen_satfractuns_conv_libfunc },
};

const struct optab_libcall_d normlib_def[NUM_NORMLIB_OPTABS] = {
  { '3', "add", gen_int_fp_fixed_libfunc },
  { '3', "add", gen_intv_fp_libfunc },
  { '3', "ssadd", gen_signed_fixed_libfunc },
  { '3', "usadd", gen_unsigned_fixed_libfunc },
  { '3', "sub", gen_int_fp_fixed_libfunc },
  { '3', "sub", gen_intv_fp_libfunc },
  { '3', "sssub", gen_signed_fixed_libfunc },
  { '3', "ussub", gen_unsigned_fixed_libfunc },
  { '3', "mul", gen_int_fp_fixed_libfunc },
  { '3', "mul", gen_intv_fp_libfunc },
  { '3', "ssmul", gen_signed_fixed_libfunc },
  { '3', "usmul", gen_unsigned_fixed_libfunc },
  { '3', "div", gen_int_fp_signed_fixed_libfunc },
  { '3', "divv", gen_int_libfunc },
  { '3', "ssdiv", gen_signed_fixed_libfunc },
  { '3', "udiv", gen_int_unsigned_fixed_libfunc },
  { '3', "usdiv", gen_unsigned_fixed_libfunc },
  { '4', "divmod", gen_int_libfunc },
  { '4', "udivmod", gen_int_libfunc },
  { '3', "mod", gen_int_libfunc },
  { '3', "umod", gen_int_libfunc },
  { '2', "ftrunc", gen_fp_libfunc },
  { '3', "and", gen_int_libfunc },
  { '3', "ior", gen_int_libfunc },
  { '3', "xor", gen_int_libfunc },
  { '3', "ashl", gen_int_fixed_libfunc },
  { '3', "ssashl", gen_signed_fixed_libfunc },
  { '3', "usashl", gen_unsigned_fixed_libfunc },
  { '3', "ashr", gen_int_signed_fixed_libfunc },
  { '3', "lshr", gen_int_unsigned_fixed_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '3', "min", gen_int_fp_libfunc },
  { '3', "max", gen_int_fp_libfunc },
  { '3', "umin", gen_int_libfunc },
  { '3', "umax", gen_int_libfunc },
  { '2', "neg", gen_int_fp_fixed_libfunc },
  { '2', "neg", gen_intv_fp_libfunc },
  { '2', "ssneg", gen_signed_fixed_libfunc },
  { '2', "usneg", gen_unsigned_fixed_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '2', "one_cmpl", gen_int_libfunc },
  { '\0', NULL, NULL },
  { '2', "ffs", gen_int_libfunc },
  { '2', "clz", gen_int_libfunc },
  { '2', "ctz", gen_int_libfunc },
  { '2', "clrsb", gen_int_libfunc },
  { '2', "popcount", gen_int_libfunc },
  { '2', "parity", gen_int_libfunc },
  { '2', "cmp", gen_int_fp_fixed_libfunc },
  { '2', "ucmp", gen_int_libfunc },
  { '2', "eq", gen_fp_libfunc },
  { '2', "ne", gen_fp_libfunc },
  { '2', "gt", gen_fp_libfunc },
  { '2', "ge", gen_fp_libfunc },
  { '2', "lt", gen_fp_libfunc },
  { '2', "le", gen_fp_libfunc },
  { '2', "unord", gen_fp_libfunc },
  { '2', "powi", gen_fp_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
};

enum rtx_code const optab_to_code_[NUM_OPTABS] = {
  UNKNOWN,
  SIGN_EXTEND,
  TRUNCATE,
  ZERO_EXTEND,
  FIX,
  UNSIGNED_FIX,
  FLOAT,
  UNSIGNED_FLOAT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  FRACT_CONVERT,
  UNSIGNED_FRACT_CONVERT,
  SAT_FRACT,
  UNSIGNED_SAT_FRACT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  PLUS,
  PLUS,
  SS_PLUS,
  US_PLUS,
  MINUS,
  MINUS,
  SS_MINUS,
  US_MINUS,
  MULT,
  MULT,
  SS_MULT,
  US_MULT,
  DIV,
  DIV,
  SS_DIV,
  UDIV,
  US_DIV,
  UNKNOWN,
  UNKNOWN,
  MOD,
  UMOD,
  UNKNOWN,
  AND,
  IOR,
  XOR,
  ASHIFT,
  SS_ASHIFT,
  US_ASHIFT,
  ASHIFTRT,
  LSHIFTRT,
  ROTATE,
  ROTATERT,
  ASHIFT,
  ASHIFTRT,
  LSHIFTRT,
  ROTATE,
  ROTATERT,
  SMIN,
  SMAX,
  UMIN,
  UMAX,
  NEG,
  NEG,
  SS_NEG,
  US_NEG,
  ABS,
  ABS,
  NOT,
  BSWAP,
  FFS,
  CLZ,
  CTZ,
  CLRSB,
  POPCOUNT,
  PARITY,
  UNKNOWN,
  UNKNOWN,
  EQ,
  NE,
  GT,
  GE,
  LT,
  LE,
  UNORDERED,
  UNKNOWN,
  SQRT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  SET,
  STRICT_LOW_PART,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  COMPARE,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  FMA,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
};

const optab code_to_optab_[NUM_RTX_CODE] = {
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  mov_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  movstrict_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  cbranch_optab,
  add_optab,
  sub_optab,
  neg_optab,
  smul_optab,
  ssmul_optab,
  usmul_optab,
  sdiv_optab,
  ssdiv_optab,
  usdiv_optab,
  smod_optab,
  udiv_optab,
  umod_optab,
  and_optab,
  ior_optab,
  xor_optab,
  one_cmpl_optab,
  ashl_optab,
  rotl_optab,
  ashr_optab,
  lshr_optab,
  rotr_optab,
  smin_optab,
  smax_optab,
  umin_optab,
  umax_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  ne_optab,
  eq_optab,
  ge_optab,
  gt_optab,
  le_optab,
  lt_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unord_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  abs_optab,
  sqrt_optab,
  bswap_optab,
  ffs_optab,
  clrsb_optab,
  clz_optab,
  ctz_optab,
  popcount_optab,
  parity_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  ssadd_optab,
  usadd_optab,
  sssub_optab,
  ssneg_optab,
  usneg_optab,
  unknown_optab,
  ssashl_optab,
  usashl_optab,
  ussub_optab,
  unknown_optab,
  unknown_optab,
  fma_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
};

