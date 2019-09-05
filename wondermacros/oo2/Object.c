#include "platform.h"
#include "oo_types.h"
#include <wondermacros/pointer/ref_void_ptr.h>

struct Object;
typedef struct Object Object;

struct Writer__class
{
    enum ClassKind kind;
    struct Class *super;
    const char *name;
    struct ClassProperty **properties;
    size_t size;
    void (*construct) (Writer * self);
    void *(*_new) (Writer * self, Writer * templ);
    void (*free) (Writer * self);;
    int (*to_string) (void *self, struct Writer * writer);
    int (*from_string) (void *self, struct Reader * reader);
    Object *(*eval) (Object * self, EvalContext* context);
      bool (*equal) (Object * self, Object * other);
      bool (*to_json) (Object * self, Writer * writer);
      bool (*put_char) (Writer * self, char ch);
      bool (*put_cstr) (Writer * self, const char *str);
};

struct Writer
{
    struct Writer__class* klass;
};

typedef struct Writer Writer;


#define NAME Object
#include "x/class_generate.h"


CONSTRUCT
{
}

Object*
METHOD(eval)(EvalContext* context)
{
    return self;
}

w_read_status_t
STATIC_METHOD(_read)(const char** str, size_t* size, Lisp* lisp, Object** ret)
{
    return false;
}

void
METHOD(print)(FILE* out)
{
    fprintf(out, "<%s: %p>", self->klass->name, self);
}

bool
METHOD(equal)(Object* other)
{
    return self == other;
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
printf("I=%d\n", i);
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

void
STATIC_METHOD(_test)(int x)
{
    printf("Test: %d\n", x);
}

#define NAME Object
#include "x/class_vtable.h"
