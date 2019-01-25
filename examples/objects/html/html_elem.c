#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/dynamic_array.h>
#endif

#include "html_elem.h"
#include "html_attr.h"


#include "html_elem_class.h"
#include <wondermacros/objects/x/class_start.h>

/**/

/* static const char* html_elem_name[] = { <names > }; */
#define W_NAME html_elem_name
#define W_XFILE "html_tags.h"
#include <wondermacros/x/string_name.h>
/**/


enum html_elem_flag {
    HTML_ELEM_FLAG_NONE         = 0,
    HTML_ELEM_FLAG_SELF_CLOSING = 1,
    HTML_ELEM_FLAG_BLOCK        = 2,
    HTML_ELEM_FLAG_INLINE       = 4,
    HTML_ELEM_FLAG_META         = 8,
    HTML_ELEM_FLAG_DEPRECATED   = 16,
    HTML_ELEM_FLAG_EXPERIMENTAL = 32,
};

/* static enum html_elem_flag html_elem_flags[] = { <flags > }; */
#define INLINE HTML_ELEM_FLAG_INLINE |
#define BLOCK HTML_ELEM_FLAG_BLOCK |
#define META HTML_ELEM_FLAG_META |
#define DEPRECATED HTML_ELEM_FLAG_DEPRECATED |
#define EXPERIMENTAL HTML_ELEM_FLAG_EXPERIMENTAL |
#define SELF_CLOSING HTML_ELEM_FLAG_SELF_CLOSING |

#define W_NAME       html_elem_flags
#define W_NAME_INDEX 1
#define W_TYPE       enum html_elem_flag
#define W_POSTFIX    HTML_ELEM_FLAG_NONE
#define W_XFILE     "html_tags.h"
#include <wondermacros/x/value_array.h>

#undef INLINE
#undef DEPRECATED
#undef SELF_CLOSING
#undef META
#undef BLOCK
#undef EXPERIMENTAL
/**/



CONSTRUCT(html_elem)
{
    W_UNUSED(self);
}

FINALIZE(html_elem)
{
    W_UNUSED(self);
}

METHOD(html_elem,public,int,append_child,
    (struct html* child))
{
    if (W_OBJECT_IS(child,html_attr))
        W_DYNAMIC_ARRAY_PUSH(self->attrs, W_OBJECT_AS(child,html_attr));
    else
        W_DYNAMIC_ARRAY_PUSH(self->next, child);
}

METHOD(html_elem,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "<%s", html_elem_name[self->tag]);
    W_ARRAY_FOR_EACH(struct html_attr*, attr, self->attrs, W_DYNAMIC_ARRAY_GET_SIZE(self->attrs))
        W_CALL(attr,to_string)(buffer, size, pos);
    *pos += sprintf(buffer + *pos, ">");
    if (!(html_elem_flags[self->tag] & HTML_ELEM_FLAG_SELF_CLOSING)) {
        W_ARRAY_FOR_EACH(struct html*, elem, self->next, W_DYNAMIC_ARRAY_GET_SIZE(self->next))
            W_CALL(elem,to_string)(buffer, size, pos);
        *pos += sprintf(buffer + *pos, "</%s>", html_elem_name[self->tag]);
    }

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
