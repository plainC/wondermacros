#ifndef __W_OBJECT_META_H
#define __W_OBJECT_META_H

#include <wondermacros/objects/object.h>


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

