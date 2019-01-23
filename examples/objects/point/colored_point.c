#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
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

M_DRAW(ColoredPoint)
{
    printf("%s point at %d,%d\n", self->color, self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
