/* Generated automatically by the program `genautomata'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "insn-config.h"
#include "recog.h"
#include "regs.h"
#include "output.h"
#include "insn-attr.h"
#include "diagnostic-core.h"
#include "flags.h"
#include "function.h"
#include "emit-rtl.h"

/* Vector translating external insn codes to internal ones.*/
static const unsigned char alu_translate[] ATTRIBUTE_UNUSED = {
    0,     1,     1,     1,     1,     1,     0,     0,     1,     1,
    1,     1,     1,     1,     1,     1,     1,     1,     2};

/* Vector for state transitions.  */
static const unsigned char alu_transitions[] ATTRIBUTE_UNUSED = {
    0,     1,     0,     1,     2,     0};

/* Vector of min issue delay of insns.  */
static const unsigned char alu_min_issue_delay[] ATTRIBUTE_UNUSED = {
    8};

/* Vector translating external insn codes to internal ones.*/
static const unsigned char imuldiv_translate[] ATTRIBUTE_UNUSED = {
    0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     3};

/* Vector for state transitions.  */
static const unsigned char imuldiv_transitions[] ATTRIBUTE_UNUSED = {
    0,    22,     1,     0,     1,    39,    39,     2,     2,    39,
   39,     3,     3,    39,    39,     4,     4,    39,    39,     5,
    5,    39,    39,     6,     6,    39,    39,     7,     7,    39,
   39,     8,     8,    39,    39,     9,     9,    39,    39,    10,
   10,    39,    39,    11,    11,    39,    39,    12,    12,    39,
   39,    13,    13,    39,    39,    14,    14,    39,    39,    15,
   15,    39,    39,    16,    16,    39,    39,    17,    17,    39,
   39,    18,    18,    39,    39,    19,    19,    39,    39,    20,
   20,    39,    39,    21,    21,    39,    39,    22,    22,    39,
   39,    23,    23,    39,    39,    24,    24,    39,    39,    25,
   25,    39,    39,    26,    26,    39,    39,    27,    27,    39,
   39,    28,    28,    39,    39,    29,    29,    39,    39,    30,
   30,    39,    39,    31,    31,    39,    39,    32,    32,    39,
   39,    33,    33,    39,    39,    34,    34,    39,    39,    35,
   35,    39,    39,    36,    36,    39,    39,    37,    37,    39,
   39,    38,    38,    39,    39,     0};

/* Vector of min issue delay of insns.  */
static const unsigned char imuldiv_min_issue_delay[] ATTRIBUTE_UNUSED = {
    0,     0,     0,     0,     0,    38,    38,     0,     0,    37,
   37,     0,     0,    36,    36,     0,     0,    35,    35,     0,
    0,    34,    34,     0,     0,    33,    33,     0,     0,    32,
   32,     0,     0,    31,    31,     0,     0,    30,    30,     0,
    0,    29,    29,     0,     0,    28,    28,     0,     0,    27,
   27,     0,     0,    26,    26,     0,     0,    25,    25,     0,
    0,    24,    24,     0,     0,    23,    23,     0,     0,    22,
   22,     0,     0,    21,    21,     0,     0,    20,    20,     0,
    0,    19,    19,     0,     0,    18,    18,     0,     0,    17,
   17,     0,     0,    16,    16,     0,     0,    15,    15,     0,
    0,    14,    14,     0,     0,    13,    13,     0,     0,    12,
   12,     0,     0,    11,    11,     0,     0,    10,    10,     0,
    0,     9,     9,     0,     0,     8,     8,     0,     0,     7,
    7,     0,     0,     6,     6,     0,     0,     5,     5,     0,
    0,     4,     4,     0,     0,     3,     3,     0,     0,     2,
    2,     0,     0,     1,     1,     0};


#define DFA__ADVANCE_CYCLE 18

struct DFA_chip
{
  unsigned char alu_automaton_state;
  unsigned char imuldiv_automaton_state;
};


const int max_insn_queue_index = 127;

static int
internal_min_issue_delay (int insn_code, struct DFA_chip *chip ATTRIBUTE_UNUSED)
{
  int temp ATTRIBUTE_UNUSED;
  int res = -1;

  switch (insn_code)
    {
    case 0: /* ghost */
      break;

    case 1: /* generic_alu */
    case 2: /* generic_load */
    case 3: /* generic_store */
    case 4: /* generic_xfer */
    case 5: /* generic_branch */
    case 8: /* generic_fcvt */
    case 9: /* generic_fmove */
    case 10: /* generic_fcmp */
    case 11: /* generic_fadd */
    case 12: /* generic_fmul_single */
    case 13: /* generic_fmul_double */
    case 14: /* generic_fdiv_single */
    case 15: /* generic_fdiv_double */
    case 16: /* generic_fsqrt_single */
    case 17: /* generic_fsqrt_double */

      temp = alu_min_issue_delay [(alu_translate [insn_code] + chip->alu_automaton_state * 3) / 8];
      temp = (temp >> (8 - ((alu_translate [insn_code] + chip->alu_automaton_state * 3) % 8 + 1) * 1)) & 1;
      res = temp;
      break;

    case 6: /* generic_imul */
    case 7: /* generic_idiv */

      temp = imuldiv_min_issue_delay [imuldiv_translate [insn_code] + chip->imuldiv_automaton_state * 4];
      res = temp;
      break;

    case 18: /* $advance_cycle */

      temp = imuldiv_min_issue_delay [imuldiv_translate [insn_code] + chip->imuldiv_automaton_state * 4];
      res = temp;

      temp = alu_min_issue_delay [(alu_translate [insn_code] + chip->alu_automaton_state * 3) / 8];
      temp = (temp >> (8 - ((alu_translate [insn_code] + chip->alu_automaton_state * 3) % 8 + 1) * 1)) & 1;
      if (temp > res)
        res = temp;
      break;


    default:
      res = -1;
      break;
    }
  return res;
}

static int
internal_state_transition (int insn_code, struct DFA_chip *chip ATTRIBUTE_UNUSED)
{
  int temp ATTRIBUTE_UNUSED;

  switch (insn_code)
    {
    case 0: /* ghost */
      {
        return -1;
      }
    case 1: /* generic_alu */
    case 2: /* generic_load */
    case 3: /* generic_store */
    case 4: /* generic_xfer */
    case 5: /* generic_branch */
    case 8: /* generic_fcvt */
    case 9: /* generic_fmove */
    case 10: /* generic_fcmp */
    case 11: /* generic_fadd */
    case 12: /* generic_fmul_single */
    case 13: /* generic_fmul_double */
    case 14: /* generic_fdiv_single */
    case 15: /* generic_fdiv_double */
    case 16: /* generic_fsqrt_single */
    case 17: /* generic_fsqrt_double */
      {

        temp = alu_transitions [alu_translate [insn_code] + chip->alu_automaton_state * 3];
        if (temp >= 2)
          return internal_min_issue_delay (insn_code, chip);
        else
          chip->alu_automaton_state = temp;
        return -1;
      }
    case 6: /* generic_imul */
    case 7: /* generic_idiv */
      {

        temp = imuldiv_transitions [imuldiv_translate [insn_code] + chip->imuldiv_automaton_state * 4];
        if (temp >= 39)
          return internal_min_issue_delay (insn_code, chip);
        else
          chip->imuldiv_automaton_state = temp;
        return -1;
      }
    case 18: /* $advance_cycle */
      {
        unsigned char _imuldiv_automaton_state;

        temp = imuldiv_transitions [imuldiv_translate [insn_code] + chip->imuldiv_automaton_state * 4];
        if (temp >= 39)
          return internal_min_issue_delay (insn_code, chip);
        else
          _imuldiv_automaton_state = temp;

        temp = alu_transitions [alu_translate [insn_code] + chip->alu_automaton_state * 3];
        if (temp >= 2)
          return internal_min_issue_delay (insn_code, chip);
        else
          chip->alu_automaton_state = temp;
        chip->imuldiv_automaton_state = _imuldiv_automaton_state;
        return -1;
      }

    default:
      return -1;
    }
}


static int *dfa_insn_codes;

static int dfa_insn_codes_length;

static void
dfa_insn_code_enlarge (int uid)
{
  int i = dfa_insn_codes_length;
  dfa_insn_codes_length = 2 * uid;
  dfa_insn_codes = XRESIZEVEC (int, dfa_insn_codes,
                 dfa_insn_codes_length);
  for (; i < dfa_insn_codes_length; i++)
    dfa_insn_codes[i] = -1;
}

static inline int
dfa_insn_code (rtx insn)
{
  int uid = INSN_UID (insn);
  int insn_code;

  if (uid >= dfa_insn_codes_length)
    dfa_insn_code_enlarge (uid);

  insn_code = dfa_insn_codes[uid];
  if (insn_code < 0)
    {
      insn_code = internal_dfa_insn_code (insn);
      dfa_insn_codes[uid] = insn_code;
    }
  return insn_code;
}

int
state_transition (state_t state, rtx insn)
{
  int insn_code;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        return -1;
    }
  return internal_state_transition (insn_code, (struct DFA_chip *) state);
}

int
min_issue_delay (state_t state, rtx insn)
{
  int insn_code;

  if (insn != 0)
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        return 0;
    }
  else
    insn_code = DFA__ADVANCE_CYCLE;

  return internal_min_issue_delay (insn_code, (struct DFA_chip *) state);
}

static int
internal_state_dead_lock_p (struct DFA_chip *ARG_UNUSED (chip))
{
  return 0/* FALSE */;
}

int
state_dead_lock_p (state_t state)
{
  return internal_state_dead_lock_p ((struct DFA_chip *) state);
}

int
state_size (void)
{
  return sizeof (struct DFA_chip);
}

static inline void
internal_reset (struct DFA_chip *chip)
{
  memset (chip, 0, sizeof (struct DFA_chip));
}

void
state_reset (state_t state)
{
  internal_reset ((struct DFA_chip *) state);
}

int
min_insn_conflict_delay (state_t state, rtx insn, rtx insn2)
{
  struct DFA_chip DFA_chip;
  int insn_code, insn2_code, transition;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        return 0;
    }

  if (insn2 == 0)
    insn2_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn2_code = dfa_insn_code (insn2);
      if (insn2_code > DFA__ADVANCE_CYCLE)
        return 0;
    }
  memcpy (&DFA_chip, state, sizeof (DFA_chip));
  internal_reset (&DFA_chip);
  transition = internal_state_transition (insn_code, &DFA_chip);
  gcc_assert (transition <= 0);
  return internal_min_issue_delay (insn2_code, &DFA_chip);
}

  static const unsigned char default_latencies[] =
    {
        0,   1,   3,   1,   2,   1,  17,  38,
        1,   2,   3,   4,   7,   8,  23,  36,
       54, 112,
    };
static int
internal_insn_latency (int insn_code ATTRIBUTE_UNUSED,
	int insn2_code ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	rtx insn2 ATTRIBUTE_UNUSED)
{
  if (insn_code >= DFA__ADVANCE_CYCLE || insn2_code >= DFA__ADVANCE_CYCLE)
    return 0;
  switch (insn_code)
    {
    }
  return default_latencies[insn_code];
}

int
insn_latency (rtx insn, rtx insn2)
{
  int insn_code, insn2_code;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        return 0;
    }

  if (insn2 == 0)
    insn2_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn2_code = dfa_insn_code (insn2);
      if (insn2_code > DFA__ADVANCE_CYCLE)
        return 0;
    }
  return internal_insn_latency (insn_code, insn2_code, insn, insn2);
}

static int
internal_maximal_insn_latency (int insn_code ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED)
{
  switch (insn_code)
    {
    }
  return default_latencies[insn_code];
}

int
maximal_insn_latency (rtx insn)
{
  int insn_code;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;


  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        return 0;
    }
  return internal_maximal_insn_latency (insn_code, insn);
}

void
print_reservation (FILE *f, rtx insn ATTRIBUTE_UNUSED)
{
  static const char *const reservation_names[] =
    {
      "nothing",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "imuldiv*17",
      "imuldiv*38",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "alu",
      "nothing"
    };
  int insn_code;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;
  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        insn_code = DFA__ADVANCE_CYCLE;
    }
  fputs (reservation_names[insn_code], f);
}


#if CPU_UNITS_QUERY

int
get_cpu_unit_code (const char *cpu_unit_name)
{
  struct name_code {const char *name; int code;};
  int cmp, l, m, h;
  static struct name_code name_code_table [] =
    {
    };

  /* The following is binary search: */
  l = 0;
  h = sizeof (name_code_table) / sizeof (struct name_code) - 1;
  while (l <= h)
    {
      m = (l + h) / 2;
      cmp = strcmp (cpu_unit_name, name_code_table [m].name);
      if (cmp < 0)
        h = m - 1;
      else if (cmp > 0)
        l = m + 1;
      else
        return name_code_table [m].code;
    }
  return -1;
}

int
cpu_unit_reservation_p (state_t state, int cpu_unit_code)
{
  gcc_assert (cpu_unit_code >= 0 && cpu_unit_code < 0);
  return 0;
}

bool
insn_has_dfa_reservation_p (rtx insn ATTRIBUTE_UNUSED)
{
  int insn_code;

  if (insn == 0)
    insn_code = DFA__ADVANCE_CYCLE;
  else
    {
      insn_code = dfa_insn_code (insn);
      if (insn_code > DFA__ADVANCE_CYCLE)
        insn_code = DFA__ADVANCE_CYCLE;
    }

  return insn_code != DFA__ADVANCE_CYCLE;
}


#endif /* #if CPU_UNITS_QUERY */

void
dfa_clean_insn_cache (void)
{
  int i;

  for (i = 0; i < dfa_insn_codes_length; i++)
    dfa_insn_codes [i] = -1;
}

void
dfa_clear_single_insn_cache (rtx insn)
{
  int i;

  i = INSN_UID (insn);
  if (i < dfa_insn_codes_length)
    dfa_insn_codes [i] = -1;
}

void
dfa_start (void)
{
  dfa_insn_codes_length = get_max_uid ();
  dfa_insn_codes = XNEWVEC (int, dfa_insn_codes_length);
  dfa_clean_insn_cache ();
}

void
dfa_finish (void)
{
  free (dfa_insn_codes);
}

