#include "oo_types.h"

#include "Object.h"
#include "Symbol.h"
#include "Lisp.h"
#include <ctype.h>


#define NAME True
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "t");
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size == 1 || ((*str)[1] != 't' && lisp->readtable[(*str)[1]] && lisp->readtable[(*str)[1]][0] != Symbol___read) ) {
        --(*size);
        ++(*str);
        *ret = lisp->t;
        return W_READ_OK;
    }

    return W_READ_NOK;
}


#define NAME True
#include "x/class_vtable.h"
