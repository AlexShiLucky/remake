/* $Id: dbg_fns.h,v 1.2 2005/11/27 01:42:00 rockyb Exp $
Copyright (C) 2005 Free Software Foundation, Inc.
This file is part of GNU Make.

GNU Make is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Make is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Make; see the file COPYING.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* debugger functions */

#ifndef DBG_FNS_H
#define DBG_FNS_H

#include "filedef.h"
#include "trace.h"

extern floc_t *p_target_loc;
extern char   *psz_target_name;

/*! We use the if when we fake a line number because
   a real one hasn't been recorded on the stack. */
extern floc_t  fake_floc;

/*! Parse psz_arg for a signed integer. The value is returned in 
    *pi_result. The retun value is true if parsing succeeded.
 */
extern bool get_int(const char *psz_arg, /*out*/ int *pi_result);

/*! Parse psz_arg for a unsigned integer. The value is returned in 
    *pi_result. The retun value is true if parsing succeeded.
 */
extern bool get_uint(const char *psz_arg, /*out*/ unsigned int *pi_result);

/*! Find the next "word" - skip leading blanks and the "word" is the
   largest non-blank characters after that. ppsz_str is modified to
   point after the portion returned and also the region initially
   pointed to by ppsz_str is modified so that word is zero-byte
   termintated.
 */
extern char *get_word(char **ppsz_str);

/*! Return true if psz_substr is an initial prefix (abbreviation) of
    psz_word. The empty string is not a valid abbreviation. */
extern bool is_abbrev_of(const char* psz_substr, const char* psz_word);

/*! toggle var on or on or off depending on psz_onoff */    
extern void on_off_toggle(const char *psz_onoff, int *var) ;

/** Print where we are in the Makefile. */
extern void print_debugger_location(const file_t *p_target, 
				    const floc_stack_node_t *p_stack_floc);
    
/** Strip whitespace from the start and end of STRING.  Return a pointer
   into STRING. */
extern char *stripwhite (char *string);

/*! Show if i_bool is "on" or "off" */
extern char *var_to_on_off(int i_bool);

#endif /* DBG_FNS_H*/