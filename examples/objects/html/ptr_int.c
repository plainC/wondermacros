#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "ptr_int.h"

#include "ptr_int_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(ptr_int)
{
}

FINALIZE(ptr_int)
{
}

METHOD(ptr_int,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "%d", *self->value);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
