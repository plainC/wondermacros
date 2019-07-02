#define EXTERN

#include "oo_api.h"

/*** Expand IReader */
#include "IReader__class.h"
#include "oo_expand_begin.h"
/**/

bool
METHOD(is_eof)(IReader* self)
{
}

char
METHOD(peek)(IReader* self)
{
}

char
METHOD(getc)(IReader* self)
{
}

size_t
METHOD(read)(IReader* self,char* buf, size_t size)
{
}

/**/
#include "oo_expand_vtable.h"
