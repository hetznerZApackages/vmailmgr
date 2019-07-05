#include "configio.h"
#include <limits.h>

static mystring default_qmail_root("/var/qmail");
static const mystring filename_qmail_root = "qmail-root";
mystring configuration::qmail_root() const {
  return read_dir(filename_qmail_root,
                    default_qmail_root,
		    (config_cache<mystring>&)qmail_root_cache);
}
