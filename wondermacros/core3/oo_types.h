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
    const char* key;
    int (*value)(void);
};

struct ClassMeta {
    struct ClassProperty** properties;
    struct ClassMethod* methods;
};

#if 0
#define CLASS Object
struct Class {
    W_CLASS_INTERFACE;
};
#undef CLASS

#define CLASS Reader
struct Reader__class {
    W_CLASS_INTERFACE;
    bool    (*is_eof)(Reader* self);
    bool    (*is_ready)(Reader* self);
    uint8_t (*peek)(Reader* self);
    void    (*next)(Reader* self);
};
#undef CLASS
#endif

struct UnitTest {
    int (*func)(void*);
    const char* name;
};

#endif
