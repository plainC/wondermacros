#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "html_attr.h"

#include "html_attr_class.h"
#include <wondermacros/objects/x/class_start.h>

/**/

/* static const char* html_attr_name[] = { <names > }; */
#define W_NAME html_attr_name
#define W_NAME_INDEX 1
#define W_XFILE "attr_tags.h"
#include <wondermacros/x/string_name.h>
/**/


CONSTRUCT(html_attr)
{
    W_UNUSED(self);
}

FINALIZE(html_attr)
{
    W_UNUSED(self);
}

METHOD(html_attr,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, " %s=\"%s\"", html_attr_name[self->tag], self->value);
}


#include <wondermacros/objects/x/class_end.h>
