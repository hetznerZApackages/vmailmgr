#include "configio.h"
#include <limits.h>

static unsigned default_default_expiry(UINT_MAX);
static const mystring filename_default_expiry = "default-expiry";
unsigned configuration::default_expiry() const {
  return read_uns(filename_default_expiry,
                    default_default_expiry,
		    (config_cache<unsigned>&)default_expiry_cache);
}
