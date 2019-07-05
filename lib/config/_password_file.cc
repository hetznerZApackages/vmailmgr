#include "configio.h"
#include <limits.h>

static mystring default_password_file("passwd");
static const mystring filename_password_file = "password-file";
mystring configuration::password_file() const {
  return read_str(filename_password_file,
                    default_password_file,
		    (config_cache<mystring>&)password_file_cache);
}
