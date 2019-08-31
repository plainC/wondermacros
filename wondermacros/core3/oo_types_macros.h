#ifndef __W_OO_TYPES_MACROS_H
#define __W_OO_TYPES_MACROS_H

#define W_CLASS_PROPERTIES                                 \
    enum ClassKind kind;                                   \
    struct Class* super;                                   \
    const char* name;                                      \
    struct ClassProperty* properties;                     \
    struct ClassMethod* methods;                     \
    size_t size                                            \
    /**/

#define W_CLASS_CORE_INTERFACE                             \
    void (*construct)(CLASS* self);                        \
    void* (*_new)(CLASS* self, CLASS* templ);              \
    void (*free)(CLASS* self);                             \
    /**/

#define W_CLASS_SERIALIZE_INTERFACE                        \
    int (*to_string)(void* self, struct Writer* writer);   \
    int (*from_string)(void* self, struct Reader* reader)  \
    /**/

#define W_CLASS_INTERFACE                                  \
    W_CLASS_PROPERTIES;                                    \
    W_CLASS_CORE_INTERFACE;                                \
    W_CLASS_SERIALIZE_INTERFACE                            \
    /**/

#define W_OBJECT_INTERFACE                                 \
    struct W_CAT(CLASS,__class)* klass                     \
    /**/

#define W_OBJECT_AS(o,T) ((T*) (o))

#endif
