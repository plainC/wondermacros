#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "colored_point3d.h"

#include "colored_point3d_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(ColoredPoint3D)
{
    W_UNUSED(self);
}

FINALIZE(ColoredPoint3D)
{
    W_UNUSED(self);
}

METHOD(ColoredPoint3D,public,void,draw)
{
    printf("%s point at %d,%d,%d\n", self->color, self->x, self->y, self->z);
}


#include <wondermacros/objects/x/class_end.h>
