#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/objects/api.h>
#endif

#include "point.h"
#include "colored_point.h"
#include "colored_point3d.h"


int main()
{
    struct ColoredPoint3D* p = W_NEW(ColoredPoint3D, .x=5, .y=2, .z=8, .color="red");
    W_CALL_VOID(p,draw);
}
