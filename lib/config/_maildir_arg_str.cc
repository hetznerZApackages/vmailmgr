#include "configio.h"
#include <limits.h>

static mystring default_maildir_arg_str("maildir");
static const mystring filename_maildir_arg_str = "maildir-arg-str";
mystring configuration::maildir_arg_str() const {
  return read_str(filename_maildir_arg_str,
                    default_maildir_arg_str,
		    (config_cache<mystring>&)maildir_arg_str_cache);
}
