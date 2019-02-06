#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "ptr_string.h"

#include "ptr_string_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(ptr_string)
{
}

FINALIZE(ptr_string)
{
}

METHOD(ptr_string,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "%s", *self->value);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
