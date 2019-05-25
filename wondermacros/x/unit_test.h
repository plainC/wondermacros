#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
#endif

#include <wondermacros/misc/unused.h>
#include <wondermacros/test/test.h>

#ifndef W_XFILE
# error "W_XFILE not defined"
#endif


int
main(int argc, char**argv)
{
    W_UNUSED(argc);
    printf("Unit: %s\n\n", argv[0]);

#include W_XFILE

    return 0;
}
