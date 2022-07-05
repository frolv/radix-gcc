/* Base configuration file for all Radix targets.
   Copyright (C) 2022 Free Software Foundation, Inc.
   Contributed by Alexei Frolov.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#undef TARGET_RADIX
#define TARGET_RADIX 1

#undef  LIB_SPEC
#define LIB_SPEC "-lc"

#undef  LINK_SPEC
#define LINK_SPEC 						\
	"%{shared:-shared} %{static:-static} "			\
	"%{!shared: %{!static: %{rdynamic:-export-dynamic}}} "	\
	"-z max-page-size=4096"

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC "crtn.o%s crtend.o%s"

#undef  STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/lib/"

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
      builtin_define ("__radix__");		\
      builtin_assert ("system=radix");		\
    }						\
  while (false)

/* String containing the assembler's comment-starter.  */
#undef  ASM_COMMENT_START
#define ASM_COMMENT_START "#"

/* Globalizing directive for a label.  */
#undef  GLOBAL_ASM_OP
#define GLOBAL_ASM_OP "\t.global\t"
