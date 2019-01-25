#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
#endif


/* Include class header. */
#include "html.h"
#include "html_elem.h"

/* Begin class implementation. */
#include "html_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(html) /* self */
{
    W_UNUSED(self);
}

FINALIZE(html) /* self */
{
}

METHOD(html,public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
}

#include <wondermacros/objects/x/class_end.h>
