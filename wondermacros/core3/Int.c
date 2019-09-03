#include "oo_types.h"

#include "Object.h"
#include <ctype.h>


#define NAME Int
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "%lld", self->value);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size == 0)
        return W_READ_NOK;

    const char* p = *str;
    bool first_is_digit = isdigit(*p);
    if (first_is_digit || *p == '+' || *p == '-')
        ++p;
    else
        return W_READ_NOK;

    while (isdigit(*p))
        ++p;

    if (!first_is_digit && p - *str == 1)
        return W_READ_NOK;

    char buf[p - *str + 1];
    memcpy(buf, *str, p-*str);
    buf[p-*str] = 0;

    *size -= p - *str;
    *ret = W_NEW(Int, .value = atoi(buf));
    *str = p;
    return W_READ_OK;
}


#define NAME Int
#include "x/class_vtable.h"
