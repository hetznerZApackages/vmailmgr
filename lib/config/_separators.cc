#include "configio.h"
#include <limits.h>

static mystring default_separators("@:");
static const mystring filename_separators = "separators";
mystring configuration::separators() const {
  return read_str(filename_separators,
                    default_separators,
		    (config_cache<mystring>&)separators_cache);
}
