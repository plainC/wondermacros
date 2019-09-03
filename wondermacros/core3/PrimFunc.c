//#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"
#include "Lisp.h"
#include "EvalContext.h"
#include "Int.h"
#include "Cons.h"
#include "Symbol.h"
#include "_Class.h"
#include "String.h"
#include "Character.h"
#include <ctype.h>
#include <string.h>
#include "oo_introspection.h"

#include "hash_func.h"
#define W_EQUAL(a,b) (strcmp((const char*) (a), (const char*) (b)) == 0)
#define W_HASH(key,h) (h = strhash(key))
#include <wondermacros/array/hash_table.h>


#define NAME PrimFunc
#include "x/class_generate.h"

#define FUNC(cname,name,body)                     \
static Object* W_CAT(__,cname)(Object* args, EvalContext* context) \
{                                           \
    static const char* _fn_ = # name; \
    body                                    \
}
#include "primfunc.h"
#undef FUNC


CONSTRUCT
{
    static const struct {
        char* name;
        Object* (*func)(Object* args, EvalContext* context);
    } map[] = {
#define FUNC(Cname,Name,body) { .name = # Name, .func = W_CAT(__,Cname), },
#include "primfunc.h"
#undef FUNC
        {NULL,NULL}
    };

    if (self->name)
        for (int i=0; map[i].name; i++)
            if (strcmp(map[i].name, self->name) == 0)
                self->func = map[i].func;
}

void
METHOD(print)(FILE* out)
{
    fprintf(out, "<PrimFunc:%p>", self);
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


#define NAME PrimFunc
#include "x/class_vtable.h"

