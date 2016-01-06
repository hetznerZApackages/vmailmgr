#include "configio.h"
#include <limits.h>

static mystring default_autoresponse_dir("autoresponse");
static const mystring filename_autoresponse_dir = "autoresponse-dir";
mystring configuration::autoresponse_dir() const {
  return read_dir(filename_autoresponse_dir,
                    default_autoresponse_dir,
		    (config_cache<mystring>&)autoresponse_dir_cache);
}
