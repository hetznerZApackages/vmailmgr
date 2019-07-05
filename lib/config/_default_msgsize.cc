#include "configio.h"
#include <limits.h>

static unsigned default_default_msgsize(UINT_MAX);
static const mystring filename_default_msgsize = "default-msgsize";
unsigned configuration::default_msgsize() const {
  return read_uns(filename_default_msgsize,
                    default_default_msgsize,
		    (config_cache<unsigned>&)default_msgsize_cache);
}
