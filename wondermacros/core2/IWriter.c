#define EXTERN

#include "oo_api.h"

/*** Expand IWriter */
#include "IWriter__class.h"
#include "oo_expand_begin.h"
/**/

int
METHOD(put)(void* self,char ch)
{
printf("PUT\n");
}

int
METHOD(append)(void* self,char* str, size_t size)
{
printf("APPEND\n");
}

/**/
#include "oo_expand_vtable.h"
