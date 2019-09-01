#include "oo_types.h"

#include "Object.h"
#include "Cons.h"
#include "Lisp.h"
#include "SpecialForm.h"


#define NAME Quote
#include "x/class_generate.h"

void
METHOD(print)(FILE* out)
{
    fprintf(out, "quote");
}

Object*
METHOD(eval)(EvalContext* context)
{
    return self;
}

Object*
METHOD(eval_special)(Object* args, EvalContext* context)
{
    return CAR(args);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (**str == '\'') {
        ++(*str);
        --(*size);
        w_read_status_t status = Lisp___read(str, size, lisp, ret);
        if (status != W_READ_OK)
            exit(0);
        *ret = W_NEW(Cons, .car = lisp->quote, .cdr = W_NEW(Cons, .car = *ret));
        return W_READ_OK;
    }
  printf("Error\n");
}

#define NAME Quote
#include "x/class_vtable.h"
