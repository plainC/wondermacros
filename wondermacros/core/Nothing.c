#define EXTERN
#include "oo_api.h"
#include "Nothing__class.h"

struct Nothing__private;

#include "oo_x_macros/expand_before_aliasing.h"
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
