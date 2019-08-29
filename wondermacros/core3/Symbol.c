#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"


#define NAME Symbol
#include "x/class_generate.h"


void
METHOD(print)(FILE* out)
{
    fprintf(out, "%s", self->name);
}

bool
STATIC_METHOD(to_json)(Object** self, Writer* writer)
{
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
}


#define NAME Symbol
#include "x/class_vtable.h"

