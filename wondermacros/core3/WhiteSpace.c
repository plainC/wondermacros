#include "oo_types.h"

#include "Object.h"
#include <ctype.h>


#define NAME WhiteSpace
#include "x/class_generate.h"


w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    while (*size && isspace(**str)) {
        ++(*str);
        --(*size);
    }

    return W_READ_EATEN;
}


#define NAME WhiteSpace
#include "x/class_vtable.h"
