#include "oo_api.h"

/*** Include superclass */
#include "Nothing.h"
/**/
#include "IWriter.h"
#include "ITest.h"
/*** Expand Point */
#include "Point__class.h"
#include "oo_expand_begin.h"
/**/

void
METHOD(_construct)(Point* self)
{
    printf("Point constructor\n");
}

void
METHOD(_destruct)(Point* self)
{
    printf("Point destruct\n");
}

bool
METHOD(equal)(Point* self, Nothing* other)
{
    Point* o = (Point*) other;
    return self->x == o->x && self->y == o->y;
}

/**/
#include "oo_expand_vtable.h"
