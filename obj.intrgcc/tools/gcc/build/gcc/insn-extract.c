/* Generated automatically by the program `genextract'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "diagnostic-core.h"

/* This variable is used as the "location" of any missing operand
   whose numbers are skipped by a given pattern.  */
static rtx junk ATTRIBUTE_UNUSED;

void
insn_extract (rtx insn)
{
  rtx *ro = recog_data.operand;
  rtx **ro_loc = recog_data.operand_loc;
  rtx pat = PATTERN (insn);
  int i ATTRIBUTE_UNUSED; /* only for peepholes */

#ifdef ENABLE_CHECKING
  memset (ro, 0xab, sizeof (*ro) * MAX_RECOG_OPERANDS);
  memset (ro_loc, 0xab, sizeof (*ro_loc) * MAX_RECOG_OPERANDS);
#endif

  switch (INSN_CODE (insn))
    {
    default:
      /* Control reaches here if insn_extract has been called with an
         unrecognizable insn (code -1), or an insn whose INSN_CODE
         corresponds to a DEFINE_EXPAND in the machine description;
         either way, a bug.  */
      if (INSN_CODE (insn) < 0)
        fatal_insn ("unrecognizable insn:", insn);
      else
        fatal_insn ("insn with invalid code number:", insn);

    case 291:  /* *local_pic_storesidf */
    case 290:  /* *local_pic_storesisf */
    case 289:  /* *local_pic_storedidf */
    case 288:  /* *local_pic_storedisf */
    case 287:  /* *local_pic_storesidi */
    case 286:  /* *local_pic_storesisi */
    case 285:  /* *local_pic_storesihi */
    case 284:  /* *local_pic_storesiqi */
    case 283:  /* *local_pic_storedidi */
    case 282:  /* *local_pic_storedisi */
    case 281:  /* *local_pic_storedihi */
    case 280:  /* *local_pic_storediqi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 270:  /* *local_pic_loaddf */
    case 269:  /* *local_pic_loadsf */
    case 268:  /* *local_pic_loaddf */
    case 267:  /* *local_pic_loadsf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 262:  /* atomic_cas_value_strongdi */
    case 261:  /* atomic_cas_value_strongsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XEXP (XVECEXP (pat, 0, 2), 0));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 260:  /* atomic_exchangedi */
    case 259:  /* atomic_exchangesi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 258:  /* atomic_fetch_anddi */
    case 257:  /* atomic_fetch_xordi */
    case 256:  /* atomic_fetch_ordi */
    case 255:  /* atomic_fetch_adddi */
    case 254:  /* atomic_fetch_andsi */
    case 253:  /* atomic_fetch_xorsi */
    case 252:  /* atomic_fetch_orsi */
    case 251:  /* atomic_fetch_addsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 0);
      recog_data.dup_num[1] = 1;
      break;

    case 250:  /* atomic_anddi */
    case 249:  /* atomic_xordi */
    case 248:  /* atomic_ordi */
    case 247:  /* atomic_adddi */
    case 246:  /* atomic_andsi */
    case 245:  /* atomic_xorsi */
    case 244:  /* atomic_orsi */
    case 243:  /* atomic_addsi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 240:  /* mem_thread_fence_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (pat, 0, 1));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0);
      recog_data.dup_num[0] = 0;
      break;

    case 237:  /* call_value_multiple_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 236:  /* call_value_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 235:  /* call_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 234:  /* sibcall_value_multiple_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 2), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 232:  /* sibcall_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 231:  /* eh_set_lr_di */
    case 230:  /* eh_set_lr_si */
      ro[0] = *(ro_loc[0] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 229:  /* simple_return_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 226:  /* tablejumpdi */
    case 225:  /* tablejumpsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0));
      break;

    case 224:  /* indirect_jumpdi */
    case 223:  /* indirect_jumpsi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 1));
      break;

    case 222:  /* jump */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 181:  /* cstoredf4 */
    case 180:  /* cstoresf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 179:  /* *branch_on_bit_rangedi */
    case 178:  /* *branch_on_bit_rangesi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 177:  /* *branch_on_bitdi */
    case 176:  /* *branch_on_bitsi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 175:  /* *branch_orderdi */
    case 174:  /* *branch_ordersi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 239:  /* trap */
    case 238:  /* nop */
    case 228:  /* simple_return */
    case 227:  /* blockage */
    case 156:  /* fence_i */
    case 155:  /* fence */
      break;

    case 242:  /* atomic_storedi */
    case 241:  /* atomic_storesi */
    case 154:  /* store_wordtf */
    case 153:  /* store_worddi */
    case 152:  /* store_worddf */
    case 151:  /* load_hightf */
    case 150:  /* load_highdi */
    case 149:  /* load_highdf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      break;

    case 145:  /* *movti */
    case 144:  /* *movdf_softfloat */
    case 143:  /* *movdf_hardfloat_rv64 */
    case 142:  /* *movdf_hardfloat_rv32 */
    case 141:  /* *movsf_softfloat */
    case 140:  /* *movsf_hardfloat */
    case 139:  /* *movqi_internal */
    case 134:  /* *movhi_internal */
    case 133:  /* *movsi_internal */
    case 132:  /* *movdi_64bit */
    case 131:  /* *movdi_32bit */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 124:  /* tls_add_tp_ledi */
    case 123:  /* tls_add_tp_lesi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 2));
      break;

    case 148:  /* load_lowtf */
    case 147:  /* load_lowdi */
    case 146:  /* load_lowdf */
    case 128:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_iesi */
    case 126:  /* got_load_tls_gddi */
    case 125:  /* got_load_tls_gdsi */
    case 122:  /* got_loaddi */
    case 121:  /* got_loadsi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 279:  /* *local_pic_loadusi */
    case 278:  /* *local_pic_loadusi */
    case 277:  /* *local_pic_loadusi */
    case 276:  /* *local_pic_loaduhi */
    case 275:  /* *local_pic_loaduhi */
    case 274:  /* *local_pic_loaduhi */
    case 273:  /* *local_pic_loaduqi */
    case 272:  /* *local_pic_loaduqi */
    case 271:  /* *local_pic_loaduqi */
    case 89:  /* *lshr32_truncsi */
    case 88:  /* *lshr32_trunchi */
    case 87:  /* *lshr32_truncqi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      break;

    case 65:  /* *nfmsdf4_fastmath */
    case 64:  /* *nfmssf4_fastmath */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 63:  /* *nfmadf4_fastmath */
    case 62:  /* *nfmasf4_fastmath */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 61:  /* nfmsdf4 */
    case 60:  /* nfmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      break;

    case 59:  /* nfmadf4 */
    case 58:  /* nfmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 57:  /* fmsdf4 */
    case 56:  /* fmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      break;

    case 55:  /* fmadf4 */
    case 54:  /* fmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 266:  /* *local_pic_loaddi */
    case 265:  /* *local_pic_loadsi */
    case 264:  /* *local_pic_loadhi */
    case 263:  /* *local_pic_loadqi */
    case 205:  /* *sgeu_didi */
    case 204:  /* *sge_didi */
    case 203:  /* *sgeu_sidi */
    case 202:  /* *sge_sidi */
    case 201:  /* *sgeu_disi */
    case 200:  /* *sge_disi */
    case 199:  /* *sgeu_sisi */
    case 198:  /* *sge_sisi */
    case 189:  /* *sne_zero_didi */
    case 188:  /* *sne_zero_sidi */
    case 187:  /* *sne_zero_disi */
    case 186:  /* *sne_zero_sisi */
    case 185:  /* *seq_zero_didi */
    case 184:  /* *seq_zero_sidi */
    case 183:  /* *seq_zero_disi */
    case 182:  /* *seq_zero_sisi */
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
    case 83:  /* truncdisi2 */
    case 82:  /* truncdfsf2 */
    case 75:  /* one_cmpldi2 */
    case 74:  /* one_cmplsi2 */
    case 73:  /* negdf2 */
    case 72:  /* negsf2 */
    case 67:  /* absdf2 */
    case 66:  /* abssf2 */
    case 53:  /* sqrtdf2 */
    case 52:  /* sqrtsf2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 41:  /* usmulsi3_highpart */
    case 40:  /* umulsi3_highpart */
    case 39:  /* mulsi3_highpart */
    case 38:  /* usmuldi3_highpart */
    case 36:  /* umuldi3_highpart */
    case 35:  /* muldi3_highpart */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0));
      break;

    case 37:  /* usmulditi3 */
    case 34:  /* umulditi3 */
    case 33:  /* mulditi3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 22:  /* *subsidisi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 233:  /* sibcall_value_internal */
    case 21:  /* *subdisisi3 */
    case 10:  /* *adddisisi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 162:  /* *lshrdisi3 */
    case 161:  /* *ashrdisi3 */
    case 160:  /* *ashldisi3 */
    case 30:  /* *muldisi3 */
    case 20:  /* *subdisi3 */
    case 9:  /* *adddisi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 173:  /* lshrsi3_extend */
    case 172:  /* ashrsi3_extend */
    case 171:  /* ashlsi3_extend */
    case 163:  /* *ashldi3_truncsi */
    case 86:  /* *ashr_truncsi */
    case 85:  /* *ashr_trunchi */
    case 84:  /* *ashr_truncqi */
    case 31:  /* *muldi3_truncsi */
    case 23:  /* *subdi3_truncsi */
    case 19:  /* *subsi3_extended */
    case 11:  /* *adddi3_truncsi */
    case 8:  /* *addsi3_extended */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 221:  /* *sleu_didi */
    case 220:  /* *sle_didi */
    case 219:  /* *sleu_sidi */
    case 218:  /* *sle_sidi */
    case 217:  /* *sleu_disi */
    case 216:  /* *sle_disi */
    case 215:  /* *sleu_sisi */
    case 214:  /* *sle_sisi */
    case 213:  /* *sltu_didi */
    case 212:  /* *slt_didi */
    case 211:  /* *sltu_sidi */
    case 210:  /* *slt_sidi */
    case 209:  /* *sltu_disi */
    case 208:  /* *slt_disi */
    case 207:  /* *sltu_sisi */
    case 206:  /* *slt_sisi */
    case 197:  /* *sgtu_didi */
    case 196:  /* *sgt_didi */
    case 195:  /* *sgtu_sidi */
    case 194:  /* *sgt_sidi */
    case 193:  /* *sgtu_disi */
    case 192:  /* *sgt_disi */
    case 191:  /* *sgtu_sisi */
    case 190:  /* *sgt_sisi */
    case 170:  /* lshrdi3 */
    case 169:  /* ashrdi3 */
    case 168:  /* ashldi3 */
    case 167:  /* *ashldisi3 */
    case 166:  /* *ashldisi3 */
    case 165:  /* *ashldisi3 */
    case 164:  /* *ashldisi3 */
    case 159:  /* lshrsi3 */
    case 158:  /* ashrsi3 */
    case 157:  /* ashlsi3 */
    case 138:  /* xorsihi3 */
    case 137:  /* xorhihi3 */
    case 136:  /* addsihi3 */
    case 135:  /* addhihi3 */
    case 130:  /* *lowdi */
    case 129:  /* *lowsi */
    case 81:  /* xordi3 */
    case 80:  /* xorsi3 */
    case 79:  /* iordi3 */
    case 78:  /* iorsi3 */
    case 77:  /* anddi3 */
    case 76:  /* andsi3 */
    case 71:  /* smaxdf3 */
    case 70:  /* smaxsf3 */
    case 69:  /* smindf3 */
    case 68:  /* sminsf3 */
    case 51:  /* divdf3 */
    case 50:  /* divsf3 */
    case 49:  /* umoddi3 */
    case 48:  /* moddi3 */
    case 47:  /* umodsi3 */
    case 46:  /* modsi3 */
    case 45:  /* udivdi3 */
    case 44:  /* divdi3 */
    case 43:  /* udivsi3 */
    case 42:  /* divsi3 */
    case 32:  /* *muldi3 */
    case 29:  /* *mulsi3 */
    case 28:  /* *mulsi3 */
    case 27:  /* *mulsi3 */
    case 26:  /* *mulsi3 */
    case 25:  /* muldf3 */
    case 24:  /* mulsf3 */
    case 18:  /* *subsi3 */
    case 17:  /* *subsi3 */
    case 16:  /* *subsi3 */
    case 15:  /* *subsi3 */
    case 14:  /* *subdi3 */
    case 13:  /* subdf3 */
    case 12:  /* subsf3 */
    case 7:  /* *adddi3 */
    case 6:  /* *addsi3 */
    case 5:  /* *addsi3 */
    case 4:  /* *addsi3 */
    case 3:  /* *addsi3 */
    case 2:  /* adddf3 */
    case 1:  /* addsf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    }
}
