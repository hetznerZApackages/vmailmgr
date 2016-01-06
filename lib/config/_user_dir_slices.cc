#include "configio.h"
#include <limits.h>

static unsigned default_user_dir_slices(0);
static const mystring filename_user_dir_slices = "user-dir-slices";
unsigned configuration::user_dir_slices() const {
  return read_uns(filename_user_dir_slices,
                    default_user_dir_slices,
		    (config_cache<unsigned>&)user_dir_slices_cache);
}
