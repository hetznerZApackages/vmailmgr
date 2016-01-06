#include "configio.h"
#include <limits.h>

static mystring default_error_maildir("/var/lib/vmailmgr/error-maildir");
static const mystring filename_error_maildir = "error-maildir";
mystring configuration::error_maildir() const {
  return read_dir(filename_error_maildir,
                    default_error_maildir,
		    (config_cache<mystring>&)error_maildir_cache);
}
