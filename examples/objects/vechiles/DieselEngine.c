#include "forward_declare.h"
#include "DieselEngine.h"
#include "DieselEngine_class.h"
#include <wondermacros/objects/x/class_start.h>

CONSTRUCT(DieselEngine)
{
    self->max_rotations=8000;
    self->min_rotations=1000;
    self->rotations=0;
}

/* Override: start */
METHOD(DieselEngine,public,void,start)
{
    if (self->is_on)
        return;
    self->is_on = 1;
    self->rotations = self->min_rotations;
    printf("Diesel started: rotations=%d\n",self->rotations);
}

/* Override: stop */
METHOD(DieselEngine,public,void,stop)
{
    if (!self->is_on)
        return;
    self->is_on = 0;
    self->rotations = 0;
    printf("Diesel stopped\n");
}

#include <wondermacros/objects/x/class_end.h>
