#include "Object.h"
#include "Symbol.h"
#include <string.h>

#define NAME EvalContext
#include "x/class_generate.h"

CONSTRUCT
{
}

Symbol*
METHOD(intern)(const char* name)
{
    Symbol* sym = W_NEW(Symbol, .name = strdup(name));
    return sym;
}

#define NAME EvalContext
#include "x/class_vtable.h"

