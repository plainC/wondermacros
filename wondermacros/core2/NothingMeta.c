#include "oo_api.h"
#include "Nothing.h"

bool
NothingMeta__is_super(Class* self, Class* other)
{
    if (!other || !other->_meta->superclasses || self == other)
        return false;

    for (int i=0; other->_meta->superclasses[i]; i++)
        if (self == other->_meta->superclasses[i])
            return true;

    return false;
}


struct W_CLASS_STRUCT_NAME(NothingMeta) W_CLASS_INSTANCE_NAME(NothingMeta) = {
  .klass = NULL,
};
