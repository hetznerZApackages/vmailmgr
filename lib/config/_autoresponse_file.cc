#include "configio.h"
#include <limits.h>

static mystring default_autoresponse_file("message.txt");
static const mystring filename_autoresponse_file = "autoresponse-file";
mystring configuration::autoresponse_file() const {
  return read_str(filename_autoresponse_file,
                    default_autoresponse_file,
		    (config_cache<mystring>&)autoresponse_file_cache);
}
