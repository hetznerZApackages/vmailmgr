#include "configio.h"
#include <limits.h>

static mystring default_global_bulletin_dir("/var/spool/bulletins");
static const mystring filename_global_bulletin_dir = "global-bulletin-dir";
mystring configuration::global_bulletin_dir() const {
  return read_dir(filename_global_bulletin_dir,
                    default_global_bulletin_dir,
		    (config_cache<mystring>&)global_bulletin_dir_cache);
}
