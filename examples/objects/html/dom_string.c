#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/misc/unused.h>
#endif

#include "html.h"
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
    (struct model* model, struct view_context* context))
{
    context->pos += sprintf(context->buffer + context->pos, "%s", self->value);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
