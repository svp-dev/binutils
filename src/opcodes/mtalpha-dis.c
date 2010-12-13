/* alpha-dis.c -- Disassemble Alpha AXP instructions
   Copyright 1996, 1998, 1999, 2000, 2001, 2002, 2007
   Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@tamu.edu>,
   patterned after the PPC opcode handling written by Ian Lance Taylor.

   This file is part of libopcodes.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include <stdio.h>
#include "sysdep.h"
#include "dis-asm.h"
#include "opcode/mtalpha.h"

/* OSF register names.  */

static const char * const osf_regnames[64] = {
  "$0.at", "$1.rv", "$2.a5", "$3.a4", "$4.a3", "$5.a2", "$6.a1", "$7.a0",
  "$8.s0", "$9.s1", "$10.s2", "$11.s3", "$12.s4", "$13.s5", "$14.pv", "$15.ra",
  "$16.fp", "$17.gp", "$18.sp", "$19.gsd0", "$20.gsd1", "$21.gsd2", "$22.gsd3", "$23.gsd4",
  "$24.gsd5", "$25.gsd6", "$26.gsd7", "$27.gsd8", "$28.gsd9", "$29.gsd10", "$30.gsd11", "$31.zero",
  "$f0.t0", "$f1.t1", "$f2.t2", "$f3.rv", "$f4.rv2", "$f5.a5", "$f6.a4", "$f7.a3",
  "$f8.a2", "$f9.a1", "$f10.a0", "$f11.s0", "$f12.s1", "$f13.s2", "$f14.s3", "$f15.s4",
  "$f16.s5", "$f17.s6", "$f18.s7", "$f19.gsd0", "$f20.gsd1", "$f21.gsd2", "$f22.gsd3", "$f23.gsd4",
  "$f24.gsd5", "$f25.gsd6", "$f26.gsd7", "$f27.gsd8", "$f28.gsd9", "$f29.gsd10", "$f30.gsd11", "$f31"
};

/* VMS register names.  */

static const char * const vms_regnames[64] = {
  "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7",
  "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15",
  "R16", "R17", "R18", "R19", "R20", "R21", "R22", "R23",
  "R24", "AI", "RA", "PV", "AT", "FP", "SP", "RZ",
  "F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7",
  "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15",
  "F16", "F17", "F18", "F19", "F20", "F21", "F22", "F23",
  "F24", "F25", "F26", "F27", "F28", "F29", "F30", "FZ"
};

/* Disassemble Alpha instructions.  */

int
print_insn_mtalpha (memaddr, info)
     bfd_vma memaddr;
     struct disassemble_info *info;
{
  static const struct alpha_opcode *opcode_index[AXP_NOPS+1];
  const char * const * regnames;
  const struct alpha_opcode *opcode, *opcode_end;
  const unsigned char *opindex;
  unsigned insn, op, isa_mask;
  int need_comma;

  /* Initialize the majorop table the first time through */
  if (!opcode_index[0])
    {
      opcode = mtalpha_opcodes;
      opcode_end = opcode + mtalpha_num_opcodes;

      for (op = 0; op < AXP_NOPS; ++op)
	{
	  opcode_index[op] = opcode;
	  while (opcode < opcode_end && op == AXP_OP (opcode->opcode))
	    ++opcode;
	}
      opcode_index[op] = opcode;
    }

  if (info->flavour == bfd_target_evax_flavour)
    regnames = vms_regnames;
  else
    regnames = osf_regnames;

  isa_mask = AXP_OPCODE_NOPAL;
  switch (info->mach)
    {
    case bfd_mach_mtalpha_ev4:
      isa_mask |= AXP_OPCODE_EV4;
      break;
    case bfd_mach_mtalpha_ev5:
      isa_mask |= AXP_OPCODE_EV5;
      break;
    case bfd_mach_mtalpha_ev6:
      isa_mask |= AXP_OPCODE_EV6;
      break;
    }

  /* Read the insn into a host word */
  {
    bfd_byte buffer[4];
    int status = (*info->read_memory_func) (memaddr, buffer, 4, info);
    if (status != 0)
      {
	(*info->memory_error_func) (status, memaddr, info);
	return -1;
      }
    insn = bfd_getl32 (buffer);
  }

  /* Get the major opcode of the instruction.  */
  op = AXP_OP (insn);

  /* Find the first match in the opcode table.  */
  opcode_end = opcode_index[op + 1];
  for (opcode = opcode_index[op]; opcode < opcode_end; ++opcode)
    {
      if ((insn ^ opcode->opcode) & opcode->mask)
	continue;

      if (!(opcode->flags & isa_mask))
	continue;

      /* Make two passes over the operands.  First see if any of them
	 have extraction functions, and, if they do, make sure the
	 instruction is valid.  */
      {
	int invalid = 0;
	for (opindex = opcode->operands; *opindex != 0; opindex++)
	  {
	    const struct alpha_operand *operand = mtalpha_operands + *opindex;
	    if (operand->extract)
	      (*operand->extract) (insn, &invalid);
	  }
	if (invalid)
	  continue;
      }

      /* The instruction is valid.  */
      goto found;
    }

  /* No instruction found */
  (*info->fprintf_func) (info->stream, ".long %#08x", insn);

  return 4;

found:
  (*info->fprintf_func) (info->stream, "%s", opcode->name);
  if (opcode->operands[0] != 0)
    (*info->fprintf_func) (info->stream, "\t");

  /* Now extract and print the operands.  */
  need_comma = 0;
  for (opindex = opcode->operands; *opindex != 0; opindex++)
    {
      const struct alpha_operand *operand = mtalpha_operands + *opindex;
      int value;

      /* Operands that are marked FAKE are simply ignored.  We
	 already made sure that the extract function considered
	 the instruction to be valid.  */
      if ((operand->flags & AXP_OPERAND_FAKE) != 0)
	continue;

      /* Extract the value from the instruction.  */
      if (operand->extract)
	value = (*operand->extract) (insn, (int *) NULL);
      else
	{
	  value = (insn >> operand->shift) & ((1 << operand->bits) - 1);
	  if (operand->flags & AXP_OPERAND_SIGNED)
	    {
	      int signbit = 1 << (operand->bits - 1);
	      value = (value ^ signbit) - signbit;
	    }
	}

      if (need_comma &&
	  ((operand->flags & (AXP_OPERAND_PARENS | AXP_OPERAND_COMMA))
	   != AXP_OPERAND_PARENS))
	{
	  (*info->fprintf_func) (info->stream, ",");
	}
      if (operand->flags & AXP_OPERAND_PARENS)
	(*info->fprintf_func) (info->stream, "(");

      /* Print the operand as directed by the flags.  */
      if (operand->flags & AXP_OPERAND_IR)
	(*info->fprintf_func) (info->stream, "%s", regnames[value]);
      else if (operand->flags & AXP_OPERAND_FPR)
	(*info->fprintf_func) (info->stream, "%s", regnames[value + 32]);
      else if (operand->flags & AXP_OPERAND_RELATIVE)
	(*info->print_address_func) (memaddr + 4 + value, info);
      else if (operand->flags & AXP_OPERAND_SIGNED)
	(*info->fprintf_func) (info->stream, "%d", value);
      else
	(*info->fprintf_func) (info->stream, "%#x", value);

      if (operand->flags & AXP_OPERAND_PARENS)
	(*info->fprintf_func) (info->stream, ")");
      need_comma = 1;
    }

  return 4;
}
