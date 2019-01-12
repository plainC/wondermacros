#include "point3d.h"

#include "point3d_class.h"
#include <wondermacros/objects/x_macro_expand_c.h>

CONSTRUCT {
    printf("Point3D created %p\n", self);
}

FINALIZE {
    printf("Point3D finalized %p\n", self);
}

I__plotting__plot(Point3D) {
    printf("Point at (%d,%d,%d)\n", self->x, self->y, self->z);
}

I__plotting__plot_colored(Point3D) {
    printf("Point %s at (%d,%d,%d)\n", color, self->x, self->y, self->z);
}
