#define EXTERN

#include "oo_api.h"

/*** Expand Nothing */
#include "Nothing__class.h"
#include "oo_expand_begin.h"
/**/

void
METHOD(free)(Nothing* self)
{
    free(self);
}

bool
METHOD(eq)(Nothing* self,Nothing* other)
{
    return self == other;
}

bool
METHOD(equal)(Nothing* self,Nothing* other)
{
    return self == other;
}

/**/
#include "oo_expand_vtable.h"
