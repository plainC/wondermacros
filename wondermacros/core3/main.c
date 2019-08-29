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


int main()
{
    W_UNITTEST(Test);
    W_UNITTEST(Symbol);

    EvalContext* context = W_NEW(EvalContext);


    BinOp* oper = W_NEW(BinOp,
            .lhs = W_NEW(Int, .value=11),
            .rhs=W_NEW(Int, .value=31));
    Int* o = (void*) W_CALL(oper,eval)(context);
    printf("value=%d\n", (int) o->value);

    Lisp* interp = W_NEW(Lisp);
    W_CALLV(interp,repl);

    return 0;
}
