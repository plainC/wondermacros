#define EXTERN
#include "oo_api.h"
#include "Nothing__class.h"

#define Nothing Nothing__private
#include "oo_expand.h"


bool
METHOD(eq)(Nothing* self, Nothing* other)
{
    return self == other;
}

void
METHOD(free)(Nothing* self)
{
}
