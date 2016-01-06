#include "configio.h"
#include <limits.h>

static unsigned default_default_softquota(UINT_MAX);
static const mystring filename_default_softquota = "default-softquota";
unsigned configuration::default_softquota() const {
  return read_uns(filename_default_softquota,
                    default_default_softquota,
		    (config_cache<unsigned>&)default_softquota_cache);
}
