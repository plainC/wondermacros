#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "cond.h"

#include "cond_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(cond)
{
}

FINALIZE(cond)
{
}

METHOD(cond,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    int* ptr = W_CALL(model,get)(self->name);
    if (ptr) {
        if (*ptr)
            W_CALL(self->child,to_string)(model, context);
    } else
        context->pos += sprintf(context->buffer + context->pos, "#NA!");

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
