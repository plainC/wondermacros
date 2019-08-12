#include "oo_types.h"

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
    Object *(*eval) (Object * self, Object * context);
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
METHOD(eval)(Object* context)
{
    return self;
}

bool
METHOD(equal)(Object* other)
{
    return self == other;
}

bool
METHOD(to_json)(Writer* writer)
{
    W_CALL(writer,put_char)('{');
    for (int i=0; self->klass->properties[i].name; i++) {
        if (i)
            W_CALL(writer,put_char)(',');
        W_CALL(writer,put_char)('\"');
        W_CALL(writer,put_cstr)(self->klass->properties[i].name);
        W_CALL(writer,put_cstr)("\":");
        W_CALL(writer,put_char)('0');
    }
    W_CALL(writer,put_char)('}');
}

#define NAME Object
#include "x/class_vtable.h"

