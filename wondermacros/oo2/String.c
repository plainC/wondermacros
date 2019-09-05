#include "oo_types.h"

#include "Object.h"
#include <ctype.h>
#include <string.h>


#define NAME String
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "\"%s\"", self->cstr);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size < 2)
        return W_READ_NOK;

    const char* p = *str+1;

    while (*p != '\"')
        ++p;

    *size -= p - *str;
    *ret = W_NEW(String, .cstr = strndup(*str+1, p - *str - 1));
    *str = p+1;

    return W_READ_OK;
}


#define NAME String
#include "x/class_vtable.h"
