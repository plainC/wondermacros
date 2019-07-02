#define EXTERN

#include "oo_api.h"

/*** Expand IWriter */
#include "IWriter__class.h"
#include "oo_expand_begin.h"
/**/

int
METHOD(putc)(IWriter* self,char ch)
{
}

int
METHOD(append)(IWriter* self,char* str, size_t size)
{
}

/**/
#include "oo_expand_vtable.h"
