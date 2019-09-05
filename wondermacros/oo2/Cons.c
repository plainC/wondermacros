//#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"
#include "Lisp.h"
#include "PrimFunc.h"
#include "SpecialForm.h"
#include "Symbol.h"
#include "Int.h"
#include <wondermacros/meta/id.h>

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
            goto done;
        }
        self = self->cdr;
    }
    W_CALL(self->car,print)(out);
  done:
    fprintf(out, ")");
}

static Object*
apply(Object* proc, Object* args, EvalContext* context)
{
    if (!proc)
        goto error;

    if (W_OBJECT_IS(proc, PrimFunc)) {
        return W_OBJECT_AS(proc, PrimFunc)->func(args, context);
    }

  error:
    printf("First argument in a list not a function: %s\n",
            proc ? proc->klass->name : "nil");

    exit(0);
}

static Object*
evlis(Cons* exprs, EvalContext* context)
{
    Cons* list = NULL;
    while (exprs) {
        Object* obj = exprs->car ? W_CALL(exprs->car,eval)(context) : NULL; 
        list = W_NEW(Cons, .car = obj, .cdr = list);
        exprs = exprs->cdr;
    }
    REVERSE(list);

    return list;
}

#define IS_SPECIAL_FORM(o) ((Cons*)((o)->klass->superclasses[1]) == &SpecialForm__class_instance)
Object*
METHOD(eval)(EvalContext* context)
{
    if (IS_SPECIAL_FORM(self->car))
        return W_CALL(W_OBJECT_AS(self->car, SpecialForm),eval_special)(self->cdr, context);

    Object* func = W_CALL(self->car,eval)(context);
    return apply(func, evlis(self->cdr, context), context);
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

