#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/misc/unused.h>
#endif

#include "css_selector.h"

#include "css_selector_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(css_selector)
{
    W_UNUSED(self);
}

FINALIZE(css_selector)
{
    W_UNUSED(self);
}

METHOD(css_selector,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    context->pos += sprintf(context->buffer + context->pos, "%s", self->elem);
}


#include <wondermacros/objects/x/class_end.h>
