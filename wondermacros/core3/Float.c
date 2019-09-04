#include "oo_types.h"

#include "Object.h"
#include "Number.h"
#include "Int.h"
#include <ctype.h>
#include <string.h>


#define NAME Float
#include "x/class_generate.h"

Number*
METHODV(abs)
{
    if (self->value < 0)
        return W_NEW(Float, .value = -self->value);
    else
        return W_NEW(Float, .value = self->value);
}

bool
METHOD(accept_rhs)(Number* rhs, void* value)
{
    if (W_OBJECT_IS(rhs, Float)) {
        *((float*) value) = FLOAT(rhs);
        return true;
    }
    if (W_OBJECT_IS(rhs, Int)) {
        *((float*) value) = INT(rhs);
        return true;
    }
    return false;
}

void
METHOD(add)(void* value)
{
    self->value += *((float*) value);
}

void
METHOD(print)(FILE* out)
{
    fprintf(out, "%f", self->value);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size == 0)
        return W_READ_NOK;

    int commas = 0;
    const char* p = *str;
    bool first_is_digit = isdigit(*p);
    if (first_is_digit || *p == '+' || *p == '-' || *p == '.')
        ++p;
    else
        return W_READ_NOK;

    while (*p == '.' || isdigit(*p)) {
        if (*p == '.')
            ++commas;
        ++p;
    }

    if (commas != 1)
        return W_READ_NOK;
    if (!first_is_digit && p - *str == 1)
        return W_READ_NOK;

    char buf[p - *str + 1];
    memcpy(buf, *str, p-*str);
    buf[p-*str] = 0;

    *size -= p - *str;
    *ret = W_NEW(Float, .value = atof(buf));
    *str = p;
    return W_READ_OK;
}


#define NAME Float
#include "x/class_vtable.h"
