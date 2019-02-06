#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "js_elem.h"

#include "js_elem_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(js_elem)
{
    W_UNUSED(self);
}

FINALIZE(js_elem)
{
    W_UNUSED(self);
}

METHOD(js_elem,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    W_CALL(self->script,to_string)(model, context);
}


#include <wondermacros/objects/x/class_end.h>
