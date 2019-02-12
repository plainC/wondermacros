#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/misc/unused.h>
#endif

#include "var_double.h"

#include "var_double_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(var_double)
{
}

FINALIZE(var_double)
{
}

METHOD(var_double,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    double* ptr = W_CALL(model,get)(self->name);
    if (ptr)
        context->pos += sprintf(context->buffer + context->pos,
            self->format ? self->format : "%g", *ptr);
    else
        context->pos += sprintf(context->buffer + context->pos, "#NA!");

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
