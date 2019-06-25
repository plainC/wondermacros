#define W_IS_PUBLIC 0
#include "oo_api.h"
#include "Nothing__class.h"

#define Nothing Nothing__private
#include "oo_expand.h"

bool
METHOD(eq)(Nothing* self, Nothing* other)
{
    return self == other;
}

Nothing*
METHOD(clone)(Nothing* self)
{
    return self;
}

void
METHOD(free)(Nothing* self)
{
}
