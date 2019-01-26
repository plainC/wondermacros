#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "dom_string.h"

#include "dom_string_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(dom_string)
{
    self->value = strdup(self->value);
}

FINALIZE(dom_string)
{
    free(self->value);
}

METHOD(dom_string,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "%s", self->value);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
