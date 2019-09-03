#include "oo_types.h"

#include "Object.h"
#include "Symbol.h"
#include "Lisp.h"
#include <ctype.h>


#define NAME Nil
#include "x/class_generate.h"

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size >= 3 && strncmp(*str, "nil", 3)==0) {
        *size -= 3;
        *str += 3;
        *ret = NULL;
        return W_READ_OK;
    }

    return W_READ_NOK;
}


#define NAME Nil
#include "x/class_vtable.h"
