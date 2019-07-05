#include "configio.h"
#include <limits.h>

static unsigned default_user_dir_bits(0);
static const mystring filename_user_dir_bits = "user-dir-bits";
unsigned configuration::user_dir_bits() const {
  return read_uns(filename_user_dir_bits,
                    default_user_dir_bits,
		    (config_cache<unsigned>&)user_dir_bits_cache);
}
