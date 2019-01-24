#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
#endif


/* Include class header. */
#include "point.h"

/* Begin class implementation. */
#include "point_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(Point) /* self */
{
    W_CALL(self,ping)("constructed");
    W_UNUSED(self);
}

FINALIZE(Point) /* self */
{
    W_UNUSED(self);
}

M_PING(Point) /* self, const char* message */
{
    printf("Message: %s\n", message);
}

M_MOVE_UP(Point) /* self, int steps */
{
    if (self->y - steps < 0) {
        W_CALL(self,ping)("Hits the wall");
        self->y = 0;
        return 1;
    }

    self->y -= steps;
    return 0;
}

M_MOVE_LEFT(Point) /* self, int steps */
{
    self->x -= steps;
    return 0;
}

M_DRAW(Point) /* self */
{
    printf("point at %d,%d\n", self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
