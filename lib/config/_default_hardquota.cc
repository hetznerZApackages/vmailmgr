#include "configio.h"
#include <limits.h>

static unsigned default_default_hardquota(UINT_MAX);
static const mystring filename_default_hardquota = "default-hardquota";
unsigned configuration::default_hardquota() const {
  return read_uns(filename_default_hardquota,
                    default_default_hardquota,
		    (config_cache<unsigned>&)default_hardquota_cache);
}
