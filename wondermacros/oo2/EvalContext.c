#include "Object.h"
#include "Symbol.h"
#include "Cons.h"
#include "Int.h"
#include "Lisp.h"
#include "PrimFunc.h"
#include "Test.h"
#include <string.h>


#define NAME EvalContext
#include "x/class_generate.h"


#define Intern(Name) W_CALL(self->lisp,intern)(# Name, sizeof(# Name)-1)
#define Extend(Name,Value) \
do { \
    Symbol* sym = Intern(Name); \
    W_CALL(self,extend)(sym, (Object*) (Value)); \
} while (0)

CONSTRUCT
{
    Extend(a, W_NEW(Int, .value=55));
    Test* t = W_NEW(Test, .a=42, .i="Foobar");
    Extend(t, t);
#define FUNC(Cname,Name,...) \
    Extend(Name, W_NEW(PrimFunc, .name=#Name));
#include "primfunc.h"
#undef FUNC
}

void
METHOD(extend)(Symbol* sym, Object* value)
{
    self->list = W_NEW(Cons,
        .car = W_NEW(Cons, .car = (Object*) sym, .cdr = value),
        .cdr = self->list);
}


Object*
METHOD(assoc)(Object* key)
{
    Object* alist = self->list;
    while (alist) {
        if (CAR(CAR(alist)) == key) {
            return CAR(alist);
        }
        alist = CDR(alist);
    }

    return NULL;
}


#define NAME EvalContext
#include "x/class_vtable.h"

