// Copyright (C) 1999,2000 Bruce Guenter <bruceg@em.ca>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include <config.h>
#include <ctype.h>
#include <string.h>
#include "vpwentry.h"

bool vpwentry::from_old_record(const mystring& text)
{
  const char* passptr = text.c_str()+1;
  const char* end = strchr(passptr, ':');
  if(!end) return false;

  pass = text.sub(1, end-passptr);
  ++end;
  if(*end == '.' || *end == '/') {
    mailbox = end;
    forwards = 0;
  }
  else {
    if(*end == '&')
      ++end;
    mailbox = 0;
    forwards = end;
    forwards = forwards.subst(',', '\0');
  }
  set_defaults(false, true);
  return true;
}
