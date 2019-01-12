#include "point2d.h"

#include "point2d_class.h"
#include <wondermacros/objects/x_macro_expand_c.h>

CONSTRUCT {
    printf("Point2D created %p\n", self);
    printf("<-%p\n", Point2D__plot);
}

FINALIZE {
    printf("Point2D finalized %p\n", self);
}

I__plotting__plot(Point2D) {
    printf("Point at (%d,%d)\n", self->x, self->y);
}

I__plotting__plot_colored(Point2D) {
    printf("Point %s at (%d,%d)\n", color, self->x, self->y);
}
