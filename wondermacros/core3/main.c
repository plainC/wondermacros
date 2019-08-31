#define W_CALL(o,method) \
    (((o)->klass->method) ((void*)(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#include "Test.h"
#include "Symbol.h"
#include "Writer.h"
#include "BinOp.h"
#include "Int.h"
#include "EvalContext.h"
#include "Lisp.h"
#include "oo_introspection.h"


int main()
{
//    W_UNITTEST(Test);
//    W_UNITTEST(Symbol);

    void (*func)(int x) = w_oo_lookup_method(&Object__class_instance, "_test");
    func(42);

    Lisp* interp = W_NEW(Lisp);
    EvalContext* context = W_NEW(EvalContext, .lisp = interp);


    BinOp* oper = W_NEW(BinOp,
            .lhs = W_NEW(Int, .value=11),
            .rhs=W_NEW(Int, .value=31));
    Int* o = (void*) W_CALL(oper,eval)(context);
    printf("value=%d\n", (int) o->value);

    W_CALLV(interp,repl);

    return 0;
}
