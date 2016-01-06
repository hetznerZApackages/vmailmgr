#include "configio.h"
#include <limits.h>

static mystring default_default_username("+");
static const mystring filename_default_username = "default-username";
mystring configuration::default_username() const {
  return read_str(filename_default_username,
                    default_default_username,
		    (config_cache<mystring>&)default_username_cache);
}
