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
#include <limits.h>
#include "lookup.h"
#include "list_table.h"
#include "map_table.h"
#include "config/configrc.h"

bool is_local(mystring domain)
{
  mystring tblname = config->qmail_root() + "/control/locals";
  list_table tbl(tblname.c_str());
  if(!tbl)
    return false;
  return tbl[domain];
}

mystring find_virtual(mystring domain)
{
  domain = domain.lower();
  mystring tblname = config->qmail_root() + "/control/virtualdomains";
  map_table tbl(tblname.c_str());
  if(!tbl)
    return "";
  for(unsigned i = 0; i != UINT_MAX && i < domain.length();
      i = domain.find_first('.', i+1)) {
    mystring tmp = tbl[domain.c_str()+i];
    if(!!tmp)
      return tmp;
  }
  return "";
}

