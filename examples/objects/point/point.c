#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
#endif

#include "classes_declare.h"
#include "point.h"

#include "point_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(Point)
{
    W_UNUSED(self);
}

FINALIZE(Point)
{
    W_UNUSED(self);
}

M_MOVE_UP(Point)
{
    self->x -= steps;
    return 0;
}

M_MOVE_LEFT(Point)
{
    self->y -= steps;
    return 0;
}

M_DRAW(Point)
{
    printf("Point at %d,%d\n", self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
