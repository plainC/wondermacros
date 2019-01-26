#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "dom_list.h"

#include "dom_list_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(dom_list)
{
}

FINALIZE(dom_list)
{
}

METHOD(dom_list,public,int,append_child,
    (struct html* child))
{
    W_DYNAMIC_ARRAY_PUSH(self->docs, child);
}

METHOD(dom_list,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    W_ARRAY_FOR_EACH(struct html*,doc, self->docs, W_DYNAMIC_ARRAY_GET_SIZE(self->docs))
        W_CALL(doc,to_string)(buffer,size,pos);

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
