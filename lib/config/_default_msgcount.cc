#include "configio.h"
#include <limits.h>

static unsigned default_default_msgcount(UINT_MAX);
static const mystring filename_default_msgcount = "default-msgcount";
unsigned configuration::default_msgcount() const {
  return read_uns(filename_default_msgcount,
                    default_default_msgcount,
		    (config_cache<unsigned>&)default_msgcount_cache);
}
