#include "configio.h"
#include <limits.h>

static mystring default_default_maildir("Maildir");
static const mystring filename_default_maildir = "default-maildir";
mystring configuration::default_maildir() const {
  return read_dir(filename_default_maildir,
                    default_default_maildir,
		    (config_cache<mystring>&)default_maildir_cache);
}
