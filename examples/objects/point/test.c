#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
#include <wondermacros/meta/declare.h>
# include <stdio.h>
# include <wondermacros/objects/api.h>
#endif

#include "point.h"
#include "colored_point.h"
#include "colored_point3d.h"


int main()
{
    struct Point* array[] = {
        (void*) W_NEW(Point, .x = 2, .y = 7),
        (void*) W_NEW(ColoredPoint, .x = 4, .y = 9, .color = "red"),
        (void*) W_NEW(ColoredPoint3D, .x=5, .y=2, .z=8, .color="green"),
    };

    W_ARRAY_FOR_EACH(struct Point*, point, array)
        W_CALL_VOID(point,draw);
}
