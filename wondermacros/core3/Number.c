#include "oo_types.h"

#include "Object.h"
#include <ctype.h>


#define NAME Number
#include "x/class_generate.h"

Number*
METHODV(abs)
{
    return self;
}

bool
METHOD(accept_rhs)(Number* rhs, void* value)
{
    return false;
}

void
METHOD(add)(void* value)
{
}

#define NAME Number
#include "x/class_vtable.h"
