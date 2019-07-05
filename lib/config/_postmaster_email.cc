#include "configio.h"
#include <limits.h>

static mystring default_postmaster_email("postmaster@");
static const mystring filename_postmaster_email = "postmaster-email";
mystring configuration::postmaster_email() const {
  return read_str(filename_postmaster_email,
                    default_postmaster_email,
		    (config_cache<mystring>&)postmaster_email_cache);
}
