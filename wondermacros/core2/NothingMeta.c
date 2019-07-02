#include "oo_api.h"
#include "Nothing.h"

bool
NothingMeta__is_super(Class* self, Class* other)
{
#if 0
    if (!other || !other->__meta->superclasses || self == other)
        return false;

    for (int i=0; other->__meta->superclasses[i]; i++)
        if (self == other->__meta->superclasses[i])
            return true;
#endif
    return false;
}


struct W_CLASS_STRUCT_NAME(NothingMeta) W_CLASS_INSTANCE_NAME(NothingMeta) = {
  .klass = NULL,
};
