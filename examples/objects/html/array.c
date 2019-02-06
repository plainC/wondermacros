#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "array.h"

#include "array_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(array)
{
}

FINALIZE(array)
{
}

METHOD(array,public,int,to_string,
    (struct model* model, struct view_context* context))
{
    double* array = W_CALL(model,get)(self->name);
    if (array) {
        double e;
        W_CALL(model,bind_ptr)("@elem",1,&e);
        for (int i=0; i < W_DYNAMIC_ARRAY_GET_SIZE(array); i++) {
            e = array[i];
            W_CALL(self->child,to_string)(model, context);
        }
    }

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
