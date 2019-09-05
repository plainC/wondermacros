#ifndef __W_OO_TYPES_H
#define __W_OO_TYPES_H

#ifndef WDEBUG_EXPAND
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <wondermacros/pointer/ref_void_ptr.h>
#endif

#include "oo_types_macros.h"

struct Object;
struct Object__class;
struct Context;
struct Reader;
struct Writer;
struct EvalContext;

typedef struct Object Object;
typedef struct Object__class Class;
typedef struct Context Context;
typedef struct Reader Reader;
typedef struct Writer Writer;
typedef struct EvalContext EvalContext;

enum ClassKind {
    ClassKindSimpleType,
    ClassKindClass,
    ClassKindInterface,
};

struct ClassProperty {
    const char* name;
    size_t offset;
    Class* klass;
};

struct ClassMethod {
    const char* name;
    void (*func)(void);
};


struct UnitTest {
    int (*func)(void*);
    const char* name;
};

#define W_OBJECT_IS(o,Class) ((o)->klass == (void*) (&W_CAT(Class,__class_instance)))
#include "lisp.h"

#endif
