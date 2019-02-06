#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "ptr_double.h"

#include "ptr_double_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(ptr_double)
{
}

FINALIZE(ptr_double)
{
}

METHOD(ptr_double,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "%g", *self->value);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
