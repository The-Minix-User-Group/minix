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
insn_current_length (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 175:  /* *branch_orderdi */
    case 174:  /* *branch_ordersi */
      extract_insn_cached (insn);
      if ((((INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0) - (insn_current_reference_address (insn))) <= (4088)) && (((insn_current_reference_address (insn)) - (INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0)) <= (4092)))
        {
	  return 4;
        }
      else
        {
	  return 8;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      extract_insn_cached (insn);
      if (get_attr_type (insn) == TYPE_BRANCH)
        {
	  if ((((INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0) - (insn_current_reference_address (insn))) <= (4088)) && (((insn_current_reference_address (insn)) - (INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0)) <= (4092)))
	    {
	      return 4;
	    }
	  else
	    {
	      return 8;
	    }
        }
      else
        {
	  return 0;
        }

    default:
      return 0;

    }
}

int
insn_variable_length_p (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 175:  /* *branch_orderdi */
    case 174:  /* *branch_ordersi */
      return 1;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      if (get_attr_type (insn) == TYPE_BRANCH)
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    default:
      return 0;

    }
}

int
insn_min_length (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 227:  /* blockage */
      return 0;

    case 154:  /* store_wordtf */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 145:  /* *movti */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (which_alternative == 2)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 144:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative == 1)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 143:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0xe2)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1 << which_alternative) & 0x104))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x1e7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 142:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0x22)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1 << which_alternative) & 0x44))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x67))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 141:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 140:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x104))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x1e7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 139:  /* *movqi_internal */
    case 134:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (which_alternative == 3)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 133:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x24))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x77))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 132:  /* *movdi_64bit */
    case 131:  /* *movdi_32bit */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0x51)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (((1 << which_alternative) & 0x24))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x77))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 151:  /* load_hightf */
    case 148:  /* load_lowtf */
    case 97:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 150:  /* load_highdi */
    case 149:  /* load_highdf */
    case 147:  /* load_lowdi */
    case 146:  /* load_lowdf */
    case 96:  /* zero_extendqidi2 */
    case 95:  /* zero_extendqisi2 */
    case 94:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 103:  /* extendhidi2 */
    case 102:  /* extendhisi2 */
    case 101:  /* extendhihi2 */
    case 100:  /* extendqidi2 */
    case 99:  /* extendqisi2 */
    case 98:  /* extendqihi2 */
    case 93:  /* zero_extendhidi2 */
    case 92:  /* zero_extendhisi2 */
    case 91:  /* *clear_upper32 */
    case 90:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 8;
        }
      else
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }

    case 153:  /* store_worddi */
    case 152:  /* store_worddf */
    case 83:  /* truncdisi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 237:  /* call_value_multiple_internal */
    case 236:  /* call_value_internal */
    case 235:  /* call_internal */
    case 234:  /* sibcall_value_multiple_internal */
    case 233:  /* sibcall_value_internal */
    case 232:  /* sibcall_internal */
    case 128:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_iesi */
    case 126:  /* got_load_tls_gddi */
    case 125:  /* got_load_tls_gdsi */
    case 122:  /* got_loaddi */
    case 121:  /* got_loadsi */
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
    case 279:  /* *local_pic_loadusi */
    case 278:  /* *local_pic_loadusi */
    case 277:  /* *local_pic_loadusi */
    case 276:  /* *local_pic_loaduhi */
    case 275:  /* *local_pic_loaduhi */
    case 274:  /* *local_pic_loaduhi */
    case 273:  /* *local_pic_loaduqi */
    case 272:  /* *local_pic_loaduqi */
    case 271:  /* *local_pic_loaduqi */
    case 270:  /* *local_pic_loaddf */
    case 269:  /* *local_pic_loadsf */
    case 268:  /* *local_pic_loaddf */
    case 267:  /* *local_pic_loadsf */
    case 266:  /* *local_pic_loaddi */
    case 265:  /* *local_pic_loadsi */
    case 264:  /* *local_pic_loadhi */
    case 263:  /* *local_pic_loadqi */
      return 8;

    case 262:  /* atomic_cas_value_strongdi */
    case 261:  /* atomic_cas_value_strongsi */
      return 16 /* 0x10 */;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      extract_constrain_insn_cached (insn);
      if ((cached_type = get_attr_type (insn)) == TYPE_BRANCH)
        {
	  return 4;
        }
      else if (cached_type == TYPE_CALL)
        {
	  return 8;
        }
      else if (cached_type == TYPE_GHOST)
        {
	  return 0;
        }
      else if (get_attr_got (insn) == GOT_LOAD)
        {
	  return 8;
        }
      else if ((cached_move_type = get_attr_move_type (insn)) == MOVE_TYPE_SHIFT_SHIFT)
        {
	  return 8;
        }
      else if (((cached_move_type == MOVE_TYPE_MTC) || ((cached_move_type == MOVE_TYPE_MFC) || (cached_move_type == MOVE_TYPE_MOVE))) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 8;
        }
      else if ((cached_move_type == MOVE_TYPE_CONST) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_LOAD) || (cached_move_type == MOVE_TYPE_FPLOAD))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_STORE) || (cached_move_type == MOVE_TYPE_FPSTORE))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    default:
      return 4;

    }
}

int
insn_default_length (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 227:  /* blockage */
      return 0;

    case 154:  /* store_wordtf */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 145:  /* *movti */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (which_alternative == 2)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 144:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative == 1)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 143:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0xe2)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1 << which_alternative) & 0x104))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x1e7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 142:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0x22)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1 << which_alternative) & 0x44))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x67))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 141:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 140:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x104))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x1e7))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 139:  /* *movqi_internal */
    case 134:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (which_alternative == 3)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 133:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (((1 << which_alternative) & 0x24))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x77))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 132:  /* *movdi_64bit */
    case 131:  /* *movdi_32bit */
      extract_constrain_insn_cached (insn);
      if ((((1 << which_alternative) & 0x51)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (((1 << which_alternative) & 0x24))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1 << which_alternative) & 0x77))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 151:  /* load_hightf */
    case 148:  /* load_lowtf */
    case 97:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 150:  /* load_highdi */
    case 149:  /* load_highdf */
    case 147:  /* load_lowdi */
    case 146:  /* load_lowdf */
    case 96:  /* zero_extendqidi2 */
    case 95:  /* zero_extendqisi2 */
    case 94:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 103:  /* extendhidi2 */
    case 102:  /* extendhisi2 */
    case 101:  /* extendhihi2 */
    case 100:  /* extendqidi2 */
    case 99:  /* extendqisi2 */
    case 98:  /* extendqihi2 */
    case 93:  /* zero_extendhidi2 */
    case 92:  /* zero_extendhisi2 */
    case 91:  /* *clear_upper32 */
    case 90:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 8;
        }
      else
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }

    case 153:  /* store_worddi */
    case 152:  /* store_worddf */
    case 83:  /* truncdisi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 237:  /* call_value_multiple_internal */
    case 236:  /* call_value_internal */
    case 235:  /* call_internal */
    case 234:  /* sibcall_value_multiple_internal */
    case 233:  /* sibcall_value_internal */
    case 232:  /* sibcall_internal */
    case 175:  /* *branch_orderdi */
    case 174:  /* *branch_ordersi */
    case 128:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_iesi */
    case 126:  /* got_load_tls_gddi */
    case 125:  /* got_load_tls_gdsi */
    case 122:  /* got_loaddi */
    case 121:  /* got_loadsi */
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
    case 279:  /* *local_pic_loadusi */
    case 278:  /* *local_pic_loadusi */
    case 277:  /* *local_pic_loadusi */
    case 276:  /* *local_pic_loaduhi */
    case 275:  /* *local_pic_loaduhi */
    case 274:  /* *local_pic_loaduhi */
    case 273:  /* *local_pic_loaduqi */
    case 272:  /* *local_pic_loaduqi */
    case 271:  /* *local_pic_loaduqi */
    case 270:  /* *local_pic_loaddf */
    case 269:  /* *local_pic_loadsf */
    case 268:  /* *local_pic_loaddf */
    case 267:  /* *local_pic_loadsf */
    case 266:  /* *local_pic_loaddi */
    case 265:  /* *local_pic_loadsi */
    case 264:  /* *local_pic_loadhi */
    case 263:  /* *local_pic_loadqi */
      return 8;

    case 262:  /* atomic_cas_value_strongdi */
    case 261:  /* atomic_cas_value_strongsi */
      return 16 /* 0x10 */;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      extract_constrain_insn_cached (insn);
      if ((cached_type = get_attr_type (insn)) == TYPE_BRANCH)
        {
	  return 8;
        }
      else if (cached_type == TYPE_CALL)
        {
	  return 8;
        }
      else if (cached_type == TYPE_GHOST)
        {
	  return 0;
        }
      else if (get_attr_got (insn) == GOT_LOAD)
        {
	  return 8;
        }
      else if ((cached_move_type = get_attr_move_type (insn)) == MOVE_TYPE_SHIFT_SHIFT)
        {
	  return 8;
        }
      else if (((cached_move_type == MOVE_TYPE_MTC) || ((cached_move_type == MOVE_TYPE_MFC) || (cached_move_type == MOVE_TYPE_MOVE))) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 8;
        }
      else if ((cached_move_type == MOVE_TYPE_CONST) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 
#line 229 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_LOAD) || (cached_move_type == MOVE_TYPE_FPLOAD))
        {
	  return 
#line 234 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_STORE) || (cached_move_type == MOVE_TYPE_FPSTORE))
        {
	  return 
#line 236 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    default:
      return 4;

    }
}

int
bypass_p (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 0;

    }
}

enum attr_alu_type
get_attr_alu_type (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 129:  /* *lowsi */
    case 130:  /* *lowdi */
      return ALU_TYPE_ADD;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return ALU_TYPE_UNKNOWN;

    }
}

enum attr_cnv_mode
get_attr_cnv_mode (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 104:  /* extendsfdf2 */
      return CNV_MODE_S2D;

    case 82:  /* truncdfsf2 */
      return CNV_MODE_D2S;

    case 105:  /* fix_truncdfsi2 */
    case 107:  /* fix_truncdfdi2 */
    case 117:  /* fixuns_truncdfsi2 */
    case 119:  /* fixuns_truncdfdi2 */
      return CNV_MODE_D2I;

    case 106:  /* fix_truncsfsi2 */
    case 108:  /* fix_truncsfdi2 */
    case 118:  /* fixuns_truncsfsi2 */
    case 120:  /* fixuns_truncsfdi2 */
      return CNV_MODE_S2I;

    case 109:  /* floatsidf2 */
    case 110:  /* floatdidf2 */
    case 113:  /* floatunssidf2 */
    case 114:  /* floatunsdidf2 */
      return CNV_MODE_I2D;

    case 111:  /* floatsisf2 */
    case 112:  /* floatdisf2 */
    case 115:  /* floatunssisf2 */
    case 116:  /* floatunsdisf2 */
      return CNV_MODE_I2S;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return CNV_MODE_UNKNOWN;

    }
}

enum attr_dword_mode
get_attr_dword_mode (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_mode cached_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 145:  /* *movti */
      extract_constrain_insn_cached (insn);
      if ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0))
        {
	  return DWORD_MODE_YES;
        }
      else
        {
	  return DWORD_MODE_NO;
        }

    case 221:  /* *sleu_didi */
    case 220:  /* *sle_didi */
    case 217:  /* *sleu_disi */
    case 216:  /* *sle_disi */
    case 213:  /* *sltu_didi */
    case 212:  /* *slt_didi */
    case 209:  /* *sltu_disi */
    case 208:  /* *slt_disi */
    case 205:  /* *sgeu_didi */
    case 204:  /* *sge_didi */
    case 201:  /* *sgeu_disi */
    case 200:  /* *sge_disi */
    case 197:  /* *sgtu_didi */
    case 196:  /* *sgt_didi */
    case 193:  /* *sgtu_disi */
    case 192:  /* *sgt_disi */
    case 189:  /* *sne_zero_didi */
    case 187:  /* *sne_zero_disi */
    case 185:  /* *seq_zero_didi */
    case 183:  /* *seq_zero_disi */
    case 181:  /* cstoredf4 */
    case 170:  /* lshrdi3 */
    case 169:  /* ashrdi3 */
    case 168:  /* ashldi3 */
    case 154:  /* store_wordtf */
    case 151:  /* load_hightf */
    case 148:  /* load_lowtf */
    case 144:  /* *movdf_softfloat */
    case 143:  /* *movdf_hardfloat_rv64 */
    case 142:  /* *movdf_hardfloat_rv32 */
    case 132:  /* *movdi_64bit */
    case 131:  /* *movdi_32bit */
    case 130:  /* *lowdi */
    case 128:  /* got_load_tls_iedi */
    case 126:  /* got_load_tls_gddi */
    case 124:  /* tls_add_tp_ledi */
    case 122:  /* got_loaddi */
    case 119:  /* fixuns_truncdfdi2 */
    case 117:  /* fixuns_truncdfsi2 */
    case 114:  /* floatunsdidf2 */
    case 113:  /* floatunssidf2 */
    case 110:  /* floatdidf2 */
    case 109:  /* floatsidf2 */
    case 107:  /* fix_truncdfdi2 */
    case 105:  /* fix_truncdfsi2 */
    case 104:  /* extendsfdf2 */
    case 97:  /* extendsidi2 */
    case 96:  /* zero_extendqidi2 */
    case 93:  /* zero_extendhidi2 */
    case 91:  /* *clear_upper32 */
    case 90:  /* zero_extendsidi2 */
    case 81:  /* xordi3 */
    case 79:  /* iordi3 */
    case 77:  /* anddi3 */
    case 75:  /* one_cmpldi2 */
    case 73:  /* negdf2 */
    case 71:  /* smaxdf3 */
    case 69:  /* smindf3 */
    case 67:  /* absdf2 */
    case 65:  /* *nfmsdf4_fastmath */
    case 63:  /* *nfmadf4_fastmath */
    case 61:  /* nfmsdf4 */
    case 59:  /* nfmadf4 */
    case 57:  /* fmsdf4 */
    case 55:  /* fmadf4 */
    case 53:  /* sqrtdf2 */
    case 51:  /* divdf3 */
    case 49:  /* umoddi3 */
    case 48:  /* moddi3 */
    case 45:  /* udivdi3 */
    case 44:  /* divdi3 */
    case 38:  /* usmuldi3_highpart */
    case 36:  /* umuldi3_highpart */
    case 35:  /* muldi3_highpart */
    case 32:  /* *muldi3 */
    case 25:  /* muldf3 */
    case 19:  /* *subsi3_extended */
    case 14:  /* *subdi3 */
    case 13:  /* subdf3 */
    case 7:  /* *adddi3 */
    case 2:  /* adddf3 */
      extract_constrain_insn_cached (insn);
      if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return DWORD_MODE_YES;
        }
      else
        {
	  return DWORD_MODE_NO;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      extract_constrain_insn_cached (insn);
      if ((((cached_mode = get_attr_mode (insn)) == MODE_DI) || (cached_mode == MODE_DF)) && ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return DWORD_MODE_YES;
        }
      else if (((cached_mode == MODE_TI) || (cached_mode == MODE_TF)) && ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return DWORD_MODE_YES;
        }
      else
        {
	  return DWORD_MODE_NO;
        }

    default:
      return DWORD_MODE_NO;

    }
}

enum attr_got
get_attr_got (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 121:  /* got_loadsi */
    case 122:  /* got_loaddi */
    case 125:  /* got_load_tls_gdsi */
    case 126:  /* got_load_tls_gddi */
    case 127:  /* got_load_tls_iesi */
    case 128:  /* got_load_tls_iedi */
      return GOT_LOAD;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return GOT_UNSET;

    }
}

enum attr_jal
get_attr_jal (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 235:  /* call_internal */
    case 236:  /* call_value_internal */
    case 237:  /* call_value_multiple_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return JAL_INDIRECT;
        }
      else
        {
	  return JAL_DIRECT;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return JAL_UNSET;

    }
}

enum attr_mode
get_attr_mode (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 2:  /* adddf3 */
    case 13:  /* subdf3 */
    case 25:  /* muldf3 */
    case 51:  /* divdf3 */
    case 53:  /* sqrtdf2 */
    case 55:  /* fmadf4 */
    case 57:  /* fmsdf4 */
    case 59:  /* nfmadf4 */
    case 61:  /* nfmsdf4 */
    case 63:  /* *nfmadf4_fastmath */
    case 65:  /* *nfmsdf4_fastmath */
    case 67:  /* absdf2 */
    case 69:  /* smindf3 */
    case 71:  /* smaxdf3 */
    case 73:  /* negdf2 */
    case 104:  /* extendsfdf2 */
    case 105:  /* fix_truncdfsi2 */
    case 107:  /* fix_truncdfdi2 */
    case 109:  /* floatsidf2 */
    case 110:  /* floatdidf2 */
    case 113:  /* floatunssidf2 */
    case 114:  /* floatunsdidf2 */
    case 117:  /* fixuns_truncdfsi2 */
    case 119:  /* fixuns_truncdfdi2 */
    case 142:  /* *movdf_hardfloat_rv32 */
    case 143:  /* *movdf_hardfloat_rv64 */
    case 144:  /* *movdf_softfloat */
    case 181:  /* cstoredf4 */
      return MODE_DF;

    case 1:  /* addsf3 */
    case 12:  /* subsf3 */
    case 24:  /* mulsf3 */
    case 50:  /* divsf3 */
    case 52:  /* sqrtsf2 */
    case 54:  /* fmasf4 */
    case 56:  /* fmssf4 */
    case 58:  /* nfmasf4 */
    case 60:  /* nfmssf4 */
    case 62:  /* *nfmasf4_fastmath */
    case 64:  /* *nfmssf4_fastmath */
    case 66:  /* abssf2 */
    case 68:  /* sminsf3 */
    case 70:  /* smaxsf3 */
    case 72:  /* negsf2 */
    case 82:  /* truncdfsf2 */
    case 106:  /* fix_truncsfsi2 */
    case 108:  /* fix_truncsfdi2 */
    case 111:  /* floatsisf2 */
    case 112:  /* floatdisf2 */
    case 115:  /* floatunssisf2 */
    case 116:  /* floatunsdisf2 */
    case 118:  /* fixuns_truncsfsi2 */
    case 120:  /* fixuns_truncsfdi2 */
    case 140:  /* *movsf_hardfloat */
    case 141:  /* *movsf_softfloat */
    case 180:  /* cstoresf4 */
      return MODE_SF;

    case 145:  /* *movti */
      return MODE_TI;

    case 7:  /* *adddi3 */
    case 14:  /* *subdi3 */
    case 19:  /* *subsi3_extended */
    case 32:  /* *muldi3 */
    case 35:  /* muldi3_highpart */
    case 36:  /* umuldi3_highpart */
    case 38:  /* usmuldi3_highpart */
    case 44:  /* divdi3 */
    case 45:  /* udivdi3 */
    case 48:  /* moddi3 */
    case 49:  /* umoddi3 */
    case 75:  /* one_cmpldi2 */
    case 77:  /* anddi3 */
    case 79:  /* iordi3 */
    case 81:  /* xordi3 */
    case 90:  /* zero_extendsidi2 */
    case 91:  /* *clear_upper32 */
    case 93:  /* zero_extendhidi2 */
    case 96:  /* zero_extendqidi2 */
    case 97:  /* extendsidi2 */
    case 122:  /* got_loaddi */
    case 124:  /* tls_add_tp_ledi */
    case 126:  /* got_load_tls_gddi */
    case 128:  /* got_load_tls_iedi */
    case 130:  /* *lowdi */
    case 131:  /* *movdi_32bit */
    case 132:  /* *movdi_64bit */
    case 148:  /* load_lowtf */
    case 151:  /* load_hightf */
    case 154:  /* store_wordtf */
    case 168:  /* ashldi3 */
    case 169:  /* ashrdi3 */
    case 170:  /* lshrdi3 */
    case 183:  /* *seq_zero_disi */
    case 185:  /* *seq_zero_didi */
    case 187:  /* *sne_zero_disi */
    case 189:  /* *sne_zero_didi */
    case 192:  /* *sgt_disi */
    case 193:  /* *sgtu_disi */
    case 196:  /* *sgt_didi */
    case 197:  /* *sgtu_didi */
    case 200:  /* *sge_disi */
    case 201:  /* *sgeu_disi */
    case 204:  /* *sge_didi */
    case 205:  /* *sgeu_didi */
    case 208:  /* *slt_disi */
    case 209:  /* *sltu_disi */
    case 212:  /* *slt_didi */
    case 213:  /* *sltu_didi */
    case 216:  /* *sle_disi */
    case 217:  /* *sleu_disi */
    case 220:  /* *sle_didi */
    case 221:  /* *sleu_didi */
      return MODE_DI;

    case 85:  /* *ashr_trunchi */
    case 88:  /* *lshr32_trunchi */
    case 94:  /* zero_extendqihi2 */
    case 134:  /* *movhi_internal */
    case 135:  /* addhihi3 */
    case 136:  /* addsihi3 */
    case 137:  /* xorhihi3 */
    case 138:  /* xorsihi3 */
      return MODE_HI;

    case 84:  /* *ashr_truncqi */
    case 87:  /* *lshr32_truncqi */
    case 139:  /* *movqi_internal */
      return MODE_QI;

    case 174:  /* *branch_ordersi */
    case 175:  /* *branch_orderdi */
    case 222:  /* jump */
    case 223:  /* indirect_jumpsi */
    case 224:  /* indirect_jumpdi */
    case 225:  /* tablejumpsi */
    case 226:  /* tablejumpdi */
    case 227:  /* blockage */
    case 228:  /* simple_return */
    case 229:  /* simple_return_internal */
    case 238:  /* nop */
      return MODE_NONE;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    case 33:  /* mulditi3 */
    case 34:  /* umulditi3 */
    case 37:  /* usmulditi3 */
    case 155:  /* fence */
    case 156:  /* fence_i */
    case 176:  /* *branch_on_bitsi */
    case 177:  /* *branch_on_bitdi */
    case 178:  /* *branch_on_bit_rangesi */
    case 179:  /* *branch_on_bit_rangedi */
    case 230:  /* eh_set_lr_si */
    case 231:  /* eh_set_lr_di */
    case 232:  /* sibcall_internal */
    case 233:  /* sibcall_value_internal */
    case 234:  /* sibcall_value_multiple_internal */
    case 235:  /* call_internal */
    case 236:  /* call_value_internal */
    case 237:  /* call_value_multiple_internal */
    case 239:  /* trap */
    case 240:  /* mem_thread_fence_1 */
    case 241:  /* atomic_storesi */
    case 242:  /* atomic_storedi */
    case 243:  /* atomic_addsi */
    case 244:  /* atomic_orsi */
    case 245:  /* atomic_xorsi */
    case 246:  /* atomic_andsi */
    case 247:  /* atomic_adddi */
    case 248:  /* atomic_ordi */
    case 249:  /* atomic_xordi */
    case 250:  /* atomic_anddi */
    case 251:  /* atomic_fetch_addsi */
    case 252:  /* atomic_fetch_orsi */
    case 253:  /* atomic_fetch_xorsi */
    case 254:  /* atomic_fetch_andsi */
    case 255:  /* atomic_fetch_adddi */
    case 256:  /* atomic_fetch_ordi */
    case 257:  /* atomic_fetch_xordi */
    case 258:  /* atomic_fetch_anddi */
    case 259:  /* atomic_exchangesi */
    case 260:  /* atomic_exchangedi */
    case 261:  /* atomic_cas_value_strongsi */
    case 262:  /* atomic_cas_value_strongdi */
    case 263:  /* *local_pic_loadqi */
    case 264:  /* *local_pic_loadhi */
    case 265:  /* *local_pic_loadsi */
    case 266:  /* *local_pic_loaddi */
    case 267:  /* *local_pic_loadsf */
    case 268:  /* *local_pic_loaddf */
    case 269:  /* *local_pic_loadsf */
    case 270:  /* *local_pic_loaddf */
    case 271:  /* *local_pic_loaduqi */
    case 272:  /* *local_pic_loaduqi */
    case 273:  /* *local_pic_loaduqi */
    case 274:  /* *local_pic_loaduhi */
    case 275:  /* *local_pic_loaduhi */
    case 276:  /* *local_pic_loaduhi */
    case 277:  /* *local_pic_loadusi */
    case 278:  /* *local_pic_loadusi */
    case 279:  /* *local_pic_loadusi */
    case 280:  /* *local_pic_storediqi */
    case 281:  /* *local_pic_storedihi */
    case 282:  /* *local_pic_storedisi */
    case 283:  /* *local_pic_storedidi */
    case 284:  /* *local_pic_storesiqi */
    case 285:  /* *local_pic_storesihi */
    case 286:  /* *local_pic_storesisi */
    case 287:  /* *local_pic_storesidi */
    case 288:  /* *local_pic_storedisf */
    case 289:  /* *local_pic_storedidf */
    case 290:  /* *local_pic_storesisf */
    case 291:  /* *local_pic_storesidf */
      return MODE_UNKNOWN;

    default:
      return MODE_SI;

    }
}

enum attr_move_type
get_attr_move_type (rtx insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 83:  /* truncdisi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_ARITH;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 94:  /* zero_extendqihi2 */
    case 95:  /* zero_extendqisi2 */
    case 96:  /* zero_extendqidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_ANDI;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 97:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 90:  /* zero_extendsidi2 */
    case 91:  /* *clear_upper32 */
    case 92:  /* zero_extendhisi2 */
    case 93:  /* zero_extendhidi2 */
    case 98:  /* extendqihi2 */
    case 99:  /* extendqisi2 */
    case 100:  /* extendqidi2 */
    case 101:  /* extendhihi2 */
    case 102:  /* extendhisi2 */
    case 103:  /* extendhidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_SHIFT_SHIFT;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 131:  /* *movdi_32bit */
    case 132:  /* *movdi_64bit */
    case 133:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_MFC;
        }
      else
        {
	  return MOVE_TYPE_FPSTORE;
        }

    case 134:  /* *movhi_internal */
    case 139:  /* *movqi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_MTC;
        }
      else
        {
	  return MOVE_TYPE_MFC;
        }

    case 142:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_FMOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 140:  /* *movsf_hardfloat */
    case 143:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_FMOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_MFC;
        }
      else if (which_alternative == 7)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 8)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 141:  /* *movsf_softfloat */
    case 144:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 145:  /* *movti */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 146:  /* load_lowdf */
    case 147:  /* load_lowdi */
    case 148:  /* load_lowtf */
    case 149:  /* load_highdf */
    case 150:  /* load_highdi */
    case 151:  /* load_hightf */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MTC;
        }
      else
        {
	  return MOVE_TYPE_FPLOAD;
        }

    case 152:  /* store_worddf */
    case 153:  /* store_worddi */
    case 154:  /* store_wordtf */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MFC;
        }
      else
        {
	  return MOVE_TYPE_FPSTORE;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return MOVE_TYPE_UNKNOWN;

    }
}

enum attr_type
get_attr_type (rtx insn ATTRIBUTE_UNUSED)
{
  enum attr_alu_type cached_alu_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 154:  /* store_wordtf */
    case 153:  /* store_worddi */
    case 152:  /* store_worddf */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_FPSTORE;
        }
      else
        {
	  return TYPE_MFC;
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
	  return TYPE_FPLOAD;
        }
      else
        {
	  return TYPE_MTC;
        }

    case 145:  /* *movti */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (!((1 << which_alternative) & 0x7))
        {
	  return TYPE_STORE;
        }
      else if ((
#line 96 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0))
        {
	  return TYPE_MULTI;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 144:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return TYPE_STORE;
        }
      else if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 143:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 8)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1 << which_alternative) & 0x1ef))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (((1 << which_alternative) & 0x22))
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 142:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 6)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1 << which_alternative) & 0x6f))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 141:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if (!((1 << which_alternative) & 0x3))
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 140:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 8)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1 << which_alternative) & 0x1ef))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (((1 << which_alternative) & 0x22))
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 139:  /* *movqi_internal */
    case 134:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return TYPE_MTC;
        }
      else if (!((1 << which_alternative) & 0x1f))
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 133:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 5)
        {
	  return TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else if (!((1 << which_alternative) & 0x7f))
        {
	  return TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 132:  /* *movdi_64bit */
    case 131:  /* *movdi_32bit */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 5)
        {
	  return TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else if (!((1 << which_alternative) & 0x7f))
        {
	  return TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 97:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else if ((
#line 92 "/home/donz/minix/tools/gcc/../../external/gpl3/gcc/dist/gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 96:  /* zero_extendqidi2 */
    case 95:  /* zero_extendqisi2 */
    case 94:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else
        {
	  return TYPE_LOGICAL;
        }

    case 103:  /* extendhidi2 */
    case 102:  /* extendhisi2 */
    case 101:  /* extendhihi2 */
    case 100:  /* extendqidi2 */
    case 99:  /* extendqisi2 */
    case 98:  /* extendqihi2 */
    case 93:  /* zero_extendhidi2 */
    case 92:  /* zero_extendhisi2 */
    case 91:  /* *clear_upper32 */
    case 90:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else
        {
	  return TYPE_MULTI;
        }

    case 83:  /* truncdisi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_ARITH;
        }

    case 227:  /* blockage */
      return TYPE_GHOST;

    case 238:  /* nop */
      return TYPE_NOP;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      return TYPE_MULTI;

    case 52:  /* sqrtsf2 */
    case 53:  /* sqrtdf2 */
      return TYPE_FSQRT;

    case 82:  /* truncdfsf2 */
    case 104:  /* extendsfdf2 */
    case 105:  /* fix_truncdfsi2 */
    case 106:  /* fix_truncsfsi2 */
    case 107:  /* fix_truncdfdi2 */
    case 108:  /* fix_truncsfdi2 */
    case 109:  /* floatsidf2 */
    case 110:  /* floatdidf2 */
    case 111:  /* floatsisf2 */
    case 112:  /* floatdisf2 */
    case 113:  /* floatunssidf2 */
    case 114:  /* floatunsdidf2 */
    case 115:  /* floatunssisf2 */
    case 116:  /* floatunsdisf2 */
    case 117:  /* fixuns_truncdfsi2 */
    case 118:  /* fixuns_truncsfsi2 */
    case 119:  /* fixuns_truncdfdi2 */
    case 120:  /* fixuns_truncsfdi2 */
      return TYPE_FCVT;

    case 180:  /* cstoresf4 */
    case 181:  /* cstoredf4 */
      return TYPE_FCMP;

    case 50:  /* divsf3 */
    case 51:  /* divdf3 */
      return TYPE_FDIV;

    case 54:  /* fmasf4 */
    case 55:  /* fmadf4 */
    case 56:  /* fmssf4 */
    case 57:  /* fmsdf4 */
    case 58:  /* nfmasf4 */
    case 59:  /* nfmadf4 */
    case 60:  /* nfmssf4 */
    case 61:  /* nfmsdf4 */
    case 62:  /* *nfmasf4_fastmath */
    case 63:  /* *nfmadf4_fastmath */
    case 64:  /* *nfmssf4_fastmath */
    case 65:  /* *nfmsdf4_fastmath */
      return TYPE_FMADD;

    case 24:  /* mulsf3 */
    case 25:  /* muldf3 */
      return TYPE_FMUL;

    case 1:  /* addsf3 */
    case 2:  /* adddf3 */
    case 12:  /* subsf3 */
    case 13:  /* subdf3 */
      return TYPE_FADD;

    case 66:  /* abssf2 */
    case 67:  /* absdf2 */
    case 68:  /* sminsf3 */
    case 69:  /* smindf3 */
    case 70:  /* smaxsf3 */
    case 71:  /* smaxdf3 */
    case 72:  /* negsf2 */
    case 73:  /* negdf2 */
      return TYPE_FMOVE;

    case 42:  /* divsi3 */
    case 43:  /* udivsi3 */
    case 44:  /* divdi3 */
    case 45:  /* udivdi3 */
    case 46:  /* modsi3 */
    case 47:  /* umodsi3 */
    case 48:  /* moddi3 */
    case 49:  /* umoddi3 */
      return TYPE_IDIV;

    case 26:  /* *mulsi3 */
    case 27:  /* *mulsi3 */
    case 28:  /* *mulsi3 */
    case 29:  /* *mulsi3 */
    case 30:  /* *muldisi3 */
    case 31:  /* *muldi3_truncsi */
    case 32:  /* *muldi3 */
    case 35:  /* muldi3_highpart */
    case 36:  /* umuldi3_highpart */
    case 38:  /* usmuldi3_highpart */
    case 39:  /* mulsi3_highpart */
    case 40:  /* umulsi3_highpart */
    case 41:  /* usmulsi3_highpart */
      return TYPE_IMUL;

    case 182:  /* *seq_zero_sisi */
    case 183:  /* *seq_zero_disi */
    case 184:  /* *seq_zero_sidi */
    case 185:  /* *seq_zero_didi */
    case 186:  /* *sne_zero_sisi */
    case 187:  /* *sne_zero_disi */
    case 188:  /* *sne_zero_sidi */
    case 189:  /* *sne_zero_didi */
    case 190:  /* *sgt_sisi */
    case 191:  /* *sgtu_sisi */
    case 192:  /* *sgt_disi */
    case 193:  /* *sgtu_disi */
    case 194:  /* *sgt_sidi */
    case 195:  /* *sgtu_sidi */
    case 196:  /* *sgt_didi */
    case 197:  /* *sgtu_didi */
    case 198:  /* *sge_sisi */
    case 199:  /* *sgeu_sisi */
    case 200:  /* *sge_disi */
    case 201:  /* *sgeu_disi */
    case 202:  /* *sge_sidi */
    case 203:  /* *sgeu_sidi */
    case 204:  /* *sge_didi */
    case 205:  /* *sgeu_didi */
    case 206:  /* *slt_sisi */
    case 207:  /* *sltu_sisi */
    case 208:  /* *slt_disi */
    case 209:  /* *sltu_disi */
    case 210:  /* *slt_sidi */
    case 211:  /* *sltu_sidi */
    case 212:  /* *slt_didi */
    case 213:  /* *sltu_didi */
    case 214:  /* *sle_sisi */
    case 215:  /* *sleu_sisi */
    case 216:  /* *sle_disi */
    case 217:  /* *sleu_disi */
    case 218:  /* *sle_sidi */
    case 219:  /* *sleu_sidi */
    case 220:  /* *sle_didi */
    case 221:  /* *sleu_didi */
      return TYPE_SLT;

    case 84:  /* *ashr_truncqi */
    case 85:  /* *ashr_trunchi */
    case 86:  /* *ashr_truncsi */
    case 87:  /* *lshr32_truncqi */
    case 88:  /* *lshr32_trunchi */
    case 89:  /* *lshr32_truncsi */
    case 157:  /* ashlsi3 */
    case 158:  /* ashrsi3 */
    case 159:  /* lshrsi3 */
    case 160:  /* *ashldisi3 */
    case 161:  /* *ashrdisi3 */
    case 162:  /* *lshrdisi3 */
    case 163:  /* *ashldi3_truncsi */
    case 164:  /* *ashldisi3 */
    case 165:  /* *ashldisi3 */
    case 166:  /* *ashldisi3 */
    case 167:  /* *ashldisi3 */
    case 168:  /* ashldi3 */
    case 169:  /* ashrdi3 */
    case 170:  /* lshrdi3 */
    case 171:  /* ashlsi3_extend */
    case 172:  /* ashrsi3_extend */
    case 173:  /* lshrsi3_extend */
      return TYPE_SHIFT;

    case 74:  /* one_cmplsi2 */
    case 75:  /* one_cmpldi2 */
    case 76:  /* andsi3 */
    case 77:  /* anddi3 */
    case 78:  /* iorsi3 */
    case 79:  /* iordi3 */
    case 80:  /* xorsi3 */
    case 81:  /* xordi3 */
    case 137:  /* xorhihi3 */
    case 138:  /* xorsihi3 */
      return TYPE_LOGICAL;

    case 130:  /* *lowdi */
    case 129:  /* *lowsi */
    case 3:  /* *addsi3 */
    case 4:  /* *addsi3 */
    case 5:  /* *addsi3 */
    case 6:  /* *addsi3 */
    case 7:  /* *adddi3 */
    case 8:  /* *addsi3_extended */
    case 9:  /* *adddisi3 */
    case 10:  /* *adddisisi3 */
    case 11:  /* *adddi3_truncsi */
    case 14:  /* *subdi3 */
    case 15:  /* *subsi3 */
    case 16:  /* *subsi3 */
    case 17:  /* *subsi3 */
    case 18:  /* *subsi3 */
    case 19:  /* *subsi3_extended */
    case 20:  /* *subdisi3 */
    case 21:  /* *subdisisi3 */
    case 22:  /* *subsidisi3 */
    case 23:  /* *subdi3_truncsi */
    case 123:  /* tls_add_tp_lesi */
    case 124:  /* tls_add_tp_ledi */
    case 135:  /* addhihi3 */
    case 136:  /* addsihi3 */
      return TYPE_ARITH;

    case 128:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_iesi */
    case 126:  /* got_load_tls_gddi */
    case 125:  /* got_load_tls_gdsi */
    case 122:  /* got_loaddi */
    case 121:  /* got_loadsi */
      return TYPE_LOAD;

    case 237:  /* call_value_multiple_internal */
    case 236:  /* call_value_internal */
    case 235:  /* call_internal */
    case 232:  /* sibcall_internal */
    case 233:  /* sibcall_value_internal */
    case 234:  /* sibcall_value_multiple_internal */
      return TYPE_CALL;

    case 222:  /* jump */
    case 223:  /* indirect_jumpsi */
    case 224:  /* indirect_jumpdi */
    case 225:  /* tablejumpsi */
    case 226:  /* tablejumpdi */
    case 228:  /* simple_return */
    case 229:  /* simple_return_internal */
      return TYPE_JUMP;

    case 174:  /* *branch_ordersi */
    case 175:  /* *branch_orderdi */
      return TYPE_BRANCH;

    default:
      return TYPE_UNKNOWN;

    }
}

EXPORTED_CONST int length_unit_log = 0;
