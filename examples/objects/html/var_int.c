#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "var_int.h"

#include "var_int_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(var_int)
{
}

FINALIZE(var_int)
{
}

METHOD(var_int,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    int* ptr = W_CALL(model,get)(self->name);
    if (ptr)
        context->pos += sprintf(context->buffer + context->pos, "%d", *ptr);
    else
        context->pos += sprintf(context->buffer + context->pos, "#NA!");

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
