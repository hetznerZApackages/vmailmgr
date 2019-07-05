#include "configio.h"
#include <limits.h>

static mystring default_bulletin_dir("bulletins");
static const mystring filename_bulletin_dir = "bulletin-dir";
mystring configuration::bulletin_dir() const {
  return read_dir(filename_bulletin_dir,
                    default_bulletin_dir,
		    (config_cache<mystring>&)bulletin_dir_cache);
}
