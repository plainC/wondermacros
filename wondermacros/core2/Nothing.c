#define EXTERN

#include "oo_api.h"

#include "IWriter.h"
/*** Expand Nothing */
#include "Nothing__class.h"
#include "oo_expand_begin.h"
/**/

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
