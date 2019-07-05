#include "configio.h"
#include <limits.h>

static mystring default_user_dir("users");
static const mystring filename_user_dir = "user-dir";
mystring configuration::user_dir() const {
  return read_dir(filename_user_dir,
                    default_user_dir,
		    (config_cache<mystring>&)user_dir_cache);
}
