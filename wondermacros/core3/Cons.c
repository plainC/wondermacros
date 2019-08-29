//#define UNITTEST_FILE "tests/Symbol.h"

#include "Object.h"
#include "Writer.h"

#define W_OBJECT_IS(o,Class) ((o)->klass = &W_CAT(Class,__class_instance))

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


#define NAME Cons
#include "x/class_vtable.h"

