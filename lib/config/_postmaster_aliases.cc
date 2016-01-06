#include "configio.h"
#include <limits.h>

static strlist default_postmaster_aliases(mystring("mailer-daemon\0postmaster\0root",29));
static const mystring filename_postmaster_aliases = "postmaster-aliases";
strlist configuration::postmaster_aliases() const {
  return read_list(filename_postmaster_aliases,
                    default_postmaster_aliases,
		    (config_cache<strlist>&)postmaster_aliases_cache);
}
