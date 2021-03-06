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
#include "vdomain.h"
#include "misc/autodelete.h"

#if 0
response vdomain::lookup(mystring username)
{
  autodelete<vpwentry> vpw = table()->getbyname(username);
  if(!vpw)
    RETURN(err, "Invalid or unknown virtual user");
  const mystring dest = vpw->dest;
  if(dest.empty())
    RETURN(err, "Invalid virtual password entry");
  else
    RETURN(ok, dest);
}
#endif

bool vdomain::exists(mystring name)
{
  return table()->exists(name);
}

vpwentry* vdomain::lookup(mystring name, bool nodefault)
{
  vpwentry* vpw;
  if(!name)
    vpw = 0;
  else {
    vpw = table()->getbyname(name);
    if(!vpw && !nodefault)
      vpw = table()->getbyname(config.default_username());
  }
  return vpw;
}
