#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/misc/unused.h>
#endif


/* Include class header. */
#include "point.h"
#include "owner.h"

/* Begin class implementation. */
#include "point_class.h"
#include <wondermacros/objects/x/class_start.h>

CONSTRUCT(Point)
{
    self->a = W_NEW(Owner);
}

METHOD(Point,private,void,ping,(const char* message))
{
    printf("Message: %s\n", message);
}

METHOD(Point,public,int,move_up,(int steps))
{
    if (self->y - steps < 0) {
        W_CALL(self,ping)("Hits the wall");
        self->y = 0;
        return 1;
    }

    self->y -= steps;
    return 0;
}

METHOD(Point,public,int,move_left,(int steps))
{
    self->x -= steps;
    return 0;
}

METHOD(Point,public,void,draw)
{
    printf("point at %d,%d\n", self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
