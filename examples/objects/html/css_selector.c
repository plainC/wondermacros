#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
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

METHOD(css_selector,
  public,int,to_string,
    (char* buffer, size_t size, int* pos))
{
    *pos += sprintf(buffer + *pos, "%s", self->elem);
}


#include <wondermacros/objects/x/class_end.h>
