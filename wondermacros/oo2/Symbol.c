#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"
#include "Lisp.h"
#include "EvalContext.h"
#include "Cons.h"
#include <ctype.h>


#define NAME Symbol
#include "x/class_generate.h"


void
METHOD(print)(FILE* out)
{
    fprintf(out, "%s", self->name);
}

Object*
METHOD(eval)(EvalContext* context)
{
    Cons* o = W_CALL(context,assoc)(self);
    if (!o) {
        printf("ERROR: Unbounded symbol\n");
        return NULL;
    }
    return o->cdr;
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    if (*size == 0)
        return W_READ_NOK;

    const char* p = *str+1;

    while ((*size - (p - *str)) && W_CALL(lisp,has_mapping)(*p, Symbol___read)) {
        ++p;
    }

    *size -= p - *str;
    *ret = W_CALL(lisp,intern)(*str, p - *str);
    *str = p;

    return W_READ_OK;
}

bool
STATIC_METHOD(to_json)(Object** self, Writer* writer)
{
#if 0
    if (!(*self)) {
        W_CALL(writer,put_cstr)("null");
        return false;
    }

    W_CALL(writer,put_char)('{');
    for (int i=0; (*self)->klass->properties[i].name; i++) {
        if (i)
            W_CALL(writer,put_char)(',');
        W_CALL(writer,put_char)('\"');
        W_CALL(writer,put_cstr)((*self)->klass->properties[i].name);
        W_CALL(writer,put_cstr)("\":");
        (*self)->klass->properties[i].klass->to_json(
                W_REF_VOID_PTR(*self, (*self)->klass->properties[i].offset),
                writer);
    }
    W_CALL(writer,put_char)('}');
    return false;
#endif
}


#define NAME Symbol
#include "x/class_vtable.h"

