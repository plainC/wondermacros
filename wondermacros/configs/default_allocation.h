
#ifndef W_MALLOC
# ifndef WDEBUG_EXPAND
#  include <stdlib.h>
# endif
# define W_MALLOC(size) malloc(size)
#endif

#ifndef W_MALLOC0
# ifndef WDEBUG_EXPAND
#  include <string.h>
# endif
# define W_MALLOC0(size) memset(malloc(size), 0, size)
#endif

#ifndef W_REALLOC
# define W_REALLOC realloc
#endif

#ifndef W_FREE
# define W_FREE free
#endif

#ifndef W_ERROR_ALLOCATION
# define W_ERROR_ALLOCATION                                         \
    do {                                                            \
        fprintf(stderr, "Unable to allocate memory.\n");            \
        exit(1);                                                    \
    } while (0)
#endif
