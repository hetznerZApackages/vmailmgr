#include "configio.h"
#include <limits.h>

static mystring default_socket_file("/tmp/.vmailmgrd");
static const mystring filename_socket_file = "socket-file";
mystring configuration::socket_file() const {
  return read_str(filename_socket_file,
                    default_socket_file,
		    (config_cache<mystring>&)socket_file_cache);
}
