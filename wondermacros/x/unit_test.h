#include <stdio.h>
#include <stdlib.h>
#include <wondermacros/test/test.h>

#ifndef W_XFILE
# error "W_XFILE not defined"
#endif


int
main(int argc, char**argv)
{
    printf("Unit: %s\n\n", argv[0]);

#include W_XFILE

    return 0;
}