// Copyright (C) 1999,2000 Bruce Guenter <bruce@untroubled.org>
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
#include "configrc.h"

strlist configuration::read_list(const mystring& file,
				 const strlist& def,
				 config_cache<strlist>& cache) const
{
  if(!cache.value) {
    strlist result;
    const configuration* node = this;
    while(node)
      if(result.read(node->directory + "/" + file))
	break;
      else
	node = node->parent;
    if(!node)
      result = def;
    cache.value = new strlist(result);
  }
  return *cache.value;
}
