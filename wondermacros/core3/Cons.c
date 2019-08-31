//#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"
#include "Lisp.h"
#include "PrimFunc.h"


#define NAME Cons
#include "x/class_generate.h"


void
METHOD(print)(FILE* out)
{
    fprintf(out, "(");
    while (self->cdr) {
        W_CALL(self->car,print)(out);
        fprintf(out, " ");
        if (!W_OBJECT_IS(self->cdr, Cons)) {
            fprintf(out, ". ");
            W_CALL(self->cdr,print)(out);
            break;
        }
        self = self->cdr;
    }
    W_CALL(self->car,print)(out);
    fprintf(out, ")");
}

static Object*
apply(Object* proc, Object* args, EvalContext* context)
{
printf("In apply\n");
    if (W_OBJECT_IS(proc, PrimFunc)) {
printf("Primfunc\n");
        return W_OBJECT_AS(proc, PrimFunc)->func(args);
    }
}

static Object*
evlis(Cons* exprs, EvalContext* context)
{
printf("Evlis\n");
    Cons* list = NULL;
    while (exprs) {
        list = W_NEW(Cons, .car = W_CALL(exprs->car,eval)(context), .cdr = list);
        exprs = exprs->cdr;
    }

    return list;
}

Object*
METHOD(eval)(EvalContext* context)
{
    /* Todo special forms */
    return apply(W_CALL(self->car,eval)(context), evlis(self->cdr, context), context);
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    /* Eat '(' */
    ++(*str);
    --(*size);

    WhiteSpace___read(str, size, lisp, ret);

    Cons* list = NULL;
    Cons* last;
    do {
        w_read_status_t status = Lisp___read(str, size, lisp, ret);
        Cons* item = W_NEW(Cons, .car = *ret);
        if (!list)
            list = item;
        else
            last->cdr = item;
        last = item;
        WhiteSpace___read(str, size, lisp, ret);
    } while (**str != ')');

    /* Eat ')' */
    ++(*str);
    --(*size);
    *ret = list;

    return W_READ_OK;
}

#define NAME Cons
#include "x/class_vtable.h"

