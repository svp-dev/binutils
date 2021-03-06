/* BFD support for the SPARC architecture.
   Copyright 1992, 1995, 1996, 1998, 2000, 2002, 2007
   Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

static const bfd_arch_info_type arch_info_struct[] =
{
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_sparclet,
    "mtsparc",
    "mtsparc:sparclet",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[1],
  },
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_sparclite,
    "mtsparc",
    "mtsparc:sparclite",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[2],
  },
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v8plus,
    "mtsparc",
    "mtsparc:v8plus",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[3],
  },
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v8plusa,
    "mtsparc",
    "mtsparc:v8plusa",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[4],
  },
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_sparclite_le,
    "mtsparc",
    "mtsparc:sparclite_le",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[5],
  },
  {
    64,	/* bits in a word */
    64,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v9,
    "mtsparc",
    "mtsparc:v9",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[6],
  },
  {
    64,	/* bits in a word */
    64,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v9a,
    "mtsparc",
    "mtsparc:v9a",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[7],
  },
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v8plusb,
    "mtsparc",
    "mtsparc:v8plusb",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    &arch_info_struct[8],
  },
  {
    64,	/* bits in a word */
    64,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_sparc_v9b,
    "mtsparc",
    "mtsparc:v9b",
    3,
    FALSE,
    bfd_default_compatible,
    bfd_default_scan,
    0,
  }
};

const bfd_arch_info_type bfd_mtsparc_arch =
  {
    32,	/* bits in a word */
    32,	/* bits in an address */
    8,	/* bits in a byte */
    bfd_arch_mtsparc,
    bfd_mach_mtsparc,
    "mtsparc",
    "mtsparc",
    3,
    TRUE, /* the default */
    bfd_default_compatible,
    bfd_default_scan,
    NULL,//&arch_info_struct[0],
  };
