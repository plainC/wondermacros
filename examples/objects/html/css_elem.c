#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "css_elem.h"
#include "css_selector.h"

#include "css_elem_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(css_elem)
{
    W_UNUSED(self);
}

FINALIZE(css_elem)
{
    W_UNUSED(self);
}

METHOD(css_elem,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    W_CALL(self->selector,to_string)(buffer, size, pos);

    *pos += sprintf(buffer + *pos, " {%s",self->declarations);
/*
    W_ARRAY_FOR_EACH(char*,decl, self->declarations, W_DYNAMIC_ARRAY_GET_SIZE(self->declarations)) {
        *pos += sprintf(buffer + *pos, "%s;", decl);
    }
*/
    *pos += sprintf(buffer + *pos, "}");
}


#include <wondermacros/objects/x/class_end.h>
