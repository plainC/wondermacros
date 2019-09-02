#include "oo_types.h"

#include "Object.h"
#include <ctype.h>


#define NAME _Class
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "<Class:%s>", self->_klass->name);
}

#define NAME _Class
#include "x/class_vtable.h"
