#include "oo_types.h"

#include "Object.h"


#define NAME Int
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "%lld", self->value);
}

#define NAME Int
#include "x/class_vtable.h"
