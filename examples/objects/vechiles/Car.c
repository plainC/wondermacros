#include "forward_declare.h"
#include "Car.h"
#include "Car_class.h"
#include <wondermacros/objects/x/class_start.h>

CONSTRUCT(Car)
{
    self->engine = W_NEW(DieselEngine);
    self->weight = 2000;
}

FINALIZE(Car)
{
    W_CALL_VOID(self->engine,free);
}

/* Override: start */
METHOD(Car,public,void,start)
{
    W_CALL_VOID(self->engine,start);
}

/* Override: stop */
METHOD(Car,public,void,stop)
{
    W_CALL_VOID(self->engine,stop);
}

/* Override: turn */
METHOD(Car,public,void,turn,(float angle))
{
}

/* Override: add_speed */
METHOD(Car,public,void,add_speed,(float increment))
{
    if (increment > 0 && !W_CALL_VOID(self->engine,is_running))
        W_CALL_VOID(self,start);
    W_CALL(self->engine,add_rotations)(increment);
    self->speed = W_CALL(self->engine,get_speed)(self->weight);
    printf("Car: Speed set to %f\n", self->speed);
}

#include <wondermacros/objects/x/class_end.h>
