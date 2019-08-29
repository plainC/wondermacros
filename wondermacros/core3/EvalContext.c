#include "Object.h"
#include "Symbol.h"
#include <string.h>


#define NAME EvalContext
#include "x/class_generate.h"

static inline unsigned long
hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

#define W_EQUAL(a,b) (strcmp((const char*) (a), (const char*) (b)) == 0)
#define W_HASH(key,h) (h = hash(key))
#include <wondermacros/array/hash_table.h>

CONSTRUCT
{
}

Symbol*
METHOD(intern)(const char* name)
{
    W_HASH_TABLE_FOR_EACH_MATCH(intern_map_t, match, self->interned, name)
        return match->value;

    Symbol* sym = W_NEW(Symbol, .name = strdup(name));
    W_HASH_TABLE_PUSH(intern_map_t, self->interned, name, sym);

    return sym;
}

#define NAME EvalContext
#include "x/class_vtable.h"

