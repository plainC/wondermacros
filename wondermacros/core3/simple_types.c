#include "oo_types.h"
#include "Object.h"
#include "Writer.h"


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

//    int (*from_string) (void *self, struct Reader * reader);

Class wobject_cstring__simple_instance = {
    .to_json = (void*) cstring_to_json
};

Class wobject_int__simple_instance = {
    .to_json = (void*) int_to_json
};
