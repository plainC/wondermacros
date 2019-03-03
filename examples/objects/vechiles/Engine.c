#include "forward_declare.h"
#include "Engine.h"
#include "Engine_class.h"
#include <wondermacros/objects/x/class_start.h>

METHOD(Engine,public,void,stop)
{
}

METHOD(Engine,public,int,is_running)
{
    return self->is_on;
}

METHOD(Engine,public,void,start)
{
}

METHOD(Engine,public,float,get_speed,(int weight))
{
    return ((float)self->rotations - self->min_rotations) / weight * 10.0f;
}

METHOD(Engine,public,void,add_rotations,(int increment))
{
    if (self->rotations + increment > self->max_rotations) {
        printf("Engine: max rotations reached\n");
        self->rotations = self->max_rotations;
    } else if (self->rotations + increment < self->min_rotations) {
        printf("Engine: min rotations reached\n");
        self->rotations = self->min_rotations;
    } else {
        self->rotations += increment;
        printf("Engine: rotations=%d\n", self->rotations);
    }
}

#include <wondermacros/objects/x/class_end.h>
