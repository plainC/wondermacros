#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/misc/unused.h>
#endif

#include "colored_point.h"

#include "colored_point_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(ColoredPoint)
{
    W_UNUSED(self);
}

FINALIZE(ColoredPoint)
{
    W_UNUSED(self);
}

METHOD(ColoredPoint,public,void,draw)
{
    printf("%s point at %d,%d\n", self->color, self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
