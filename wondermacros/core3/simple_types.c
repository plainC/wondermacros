#include "oo_types.h"
#include "Object.h"
#include "Writer.h"
#include "Int.h"
#include "String.h"
#include <string.h>


bool
int_to_json(int* self, struct Writer * writer)
{
    printf("%d", *self);
}

bool
cstring_to_json(const char** self, struct Writer * writer)
{
    printf("\"%s\"", *self);
}

Int*
int_new(Int* self, int* template)
{
    if (!self)
        self = W_NEW(Int);
    self->value = *template;
    return self;
}

String*
string_new(String* self, const char** template)
{
    if (!self)
        self = W_NEW(String);
    self->cstr = strdup(*template);
    return self;
}


bool
int64_to_json(int64_t* self, struct Writer * writer)
{
    printf("%lld", *self);
}

Int*
int64_new(Int* self, int64_t* template)
{
    if (!self)
        self = W_NEW(Int);
    self->value = *template;
    return self;
}

//    int (*from_string) (void *self, struct Reader * reader);

Class wobject_cstring__simple_instance = {
    .to_json = (void*) cstring_to_json,
    ._new = (void*) string_new,
};

Class wobject_int__simple_instance = {
    .to_json = (void*) int_to_json,
    ._new = (void*) int_new,
};

Class wobject_int64__simple_instance = {
    .to_json = (void*) int64_to_json,
    ._new = (void*) int64_new,
};
