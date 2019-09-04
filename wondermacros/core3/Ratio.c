#include "oo_types.h"

#include "Object.h"
#include "Number.h"
#include "Int.h"
#include <ctype.h>
#include <string.h>


#define NAME Ratio
#include "x/class_generate.h"

Number*
METHODV(abs)
{
    if (self->value[0] < 0)
        return W_NEW(Ratio, .value = {-self->value[0], self->value[1] });
    else
        return self;
}

bool
METHOD(accept_rhs)(Number* rhs, void* value)
{
    if (W_OBJECT_IS(rhs, Ratio)) {
        ((int64_t*) value)[0] = RATIO(rhs)[0];
        ((int64_t*) value)[1] = RATIO(rhs)[1];
        return true;
    }
    if (W_OBJECT_IS(rhs, Int)) {
        ((int64_t*) value)[0] = INT(rhs);
        ((int64_t*) value)[1] = 1;
        return true;
    }
    return false;
}

void
METHOD(add)(void* value)
{
    self->value[0] = ((int64_t*) value)[0]*self->value[1] + ((int64_t*) value)[1]*self->value[0];
    self->value[1] = ((int64_t*) value)[1] * self->value[1];
}

void
METHOD(print)(FILE* out)
{
    fprintf(out, "%lld/%lld", self->value[0], self->value[1]);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size == 0)
        return W_READ_NOK;

    int slashes = 0;
    char* sp;
    const char* p = *str;
    bool first_is_digit = isdigit(*p);
    if (first_is_digit || *p == '+' || *p == '-')
        ++p;
    else
        return W_READ_NOK;

    while (*p == '/' || isdigit(*p)) {
        if (*p == '/') {
            ++slashes;
            sp = p;
        }
        ++p;
    }

    if (slashes != 1)
        return W_READ_NOK;
    if (!first_is_digit && p - *str == 1)
        return W_READ_NOK;

    int64_t num = atoi(*str);
    char buf[p - *str + 1];
    memcpy(buf, sp+1, p-sp-1);
    buf[p-sp-1] = 0;

    *size -= p - *str;
    *ret = W_NEW(Ratio, .value = { num, atoi(buf) });
    *str = p;
    return W_READ_OK;
}


#define NAME Ratio
#include "x/class_vtable.h"
