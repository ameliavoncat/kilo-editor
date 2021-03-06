/*** src file index ***/
#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include "src/constants.c"
#include "src/prototypes.c"
#include "src/data/index.c"
#include "src/filetypes/index.c"
#include "src/helpers/index.c"
#include "src/terminal/index.c"
#include "src/syntax_highlighting/index.c"
#include "src/row_operations/index.c"
#include "src/editor_operations/index.c"
#include "src/file_io/index.c"
#include "src/search/index.c"
#include "src/append_buffer/index.c"
#include "src/output/index.c"
#include "src/input/index.c"
#include "src/init/index.c"
