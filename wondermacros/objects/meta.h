#ifndef __W_OBJECT_META_H
#define __W_OBJECT_META_H

#include <wondermacros/objects/object.h>


#define W_HASH(key,x)                                             \
    do {                                                          \
        x = key[0]; \
        x |= key[0] ? key[1] << 8 : 0; \
    } while (0)

#define W_EQUAL(a,b) (strcmp(a,b) == 0)

#include <wondermacros/array/hash_table.h>


struct w_object_class_map {
    const char* key;
    CLASS_T* value;
};

extern struct w_object_class_map* w_object_classes;

static inline CLASS_T*
w_class_dup(CLASS_T* klass)
{
    CLASS_T* self = malloc(sizeof(CLASS_T));
    memcpy(self, klass, sizeof(CLASS_T));
    return self;
}

static inline int
w_class_register_dynamic(const char* name, CLASS_T* klass)
{
    W_HASH_TABLE_FOR_EACH_MATCH(struct w_object_class_map, map, w_object_classes, name)
        return 1;

    W_HASH_TABLE_PUSH(struct w_object_class_map, w_object_classes, name, klass);
    return 0;
}

static inline CLASS_T*
w_class_lookup_by_name(const char* name)
{
    W_HASH_TABLE_FOR_EACH_MATCH(struct w_object_class_map, map, w_object_classes, name)
        return map->value;

    return NULL;
}

typedef OBJECT_T* (*w_object_new_with_func)(OBJECT_T* o);

static inline w_object_new_with_func
w_class_lookup_new_by_name(const char* class_name)
{
    CLASS_T* klass = w_class_lookup_by_name(class_name);

    if (!klass)
        return NULL;

    return (w_object_new_with_func) klass->new_with;
}

static inline int
w_class_is_subclass_of(void* _klass, void* _super)
{
    CLASS_T* klass = (CLASS_T*) _klass;
    CLASS_T* super = (CLASS_T*) _super;

    while (klass->meta.super) {
        if (klass->meta.super == super)
            return 1;
        klass = klass->meta.super;
    }

    return 0;
}

static inline int
w_class_is_superclass_of(void* klass, void* sub)
{
    return w_class_is_subclass_of(sub, klass);
}

static inline int
w_object_is_subclass_of(void* self, void* o)
{
    return w_class_is_subclass_of( ((OBJECT_T*)(self))->klass, ((OBJECT_T*)(o))->klass);
}

static inline int
w_object_is_superclass_of(void* self, void* o)
{
    return w_class_is_subclass_of( ((OBJECT_T*)(o))->klass, ((OBJECT_T*)(o))->klass);
}

#endif

