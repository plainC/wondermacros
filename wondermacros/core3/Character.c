#include "oo_types.h"

#include "Object.h"
#include <ctype.h>


#define NAME Character
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "#\\%c", self->value);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size < 3 || (*str)[1] != '\\')
        return W_READ_NOK;

    *ret = W_NEW(Character, .value = (*str)[2]);
    *str += 3;
    *size -= 3;

    return W_READ_OK;
}


#define NAME Character
#include "x/class_vtable.h"
