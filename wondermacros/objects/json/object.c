#ifndef WDEBUG_EXPAND
# include <stdlib.h>
#endif

#include <wondermacros/objects/meta.h>
#include <wondermacros/objects/object.h>
#include <wondermacros/objects/object_name.h>

int
json_object_to_string(struct CLASS** self, char* buffer, size_t size)
{
    if (!(*self)) {
        if (size < 5)
            return -1;
        strncpy(buffer,"null",4);
        buffer+=4;
        return 4;
    }

    return W_CALL(*self,to_json)(buffer,size);
}

int
json_object_from_string(const char* buffer, const char** endptr, const char* type_name, struct CLASS** self)
{
    /* The constructor of a class is responsible to create an initial empty object. */
    if (!(*self)) {
        w_object_new_with_func new_with = w_class_lookup_new_by_name(type_name);
printf("Lookup by: %s\n", type_name);
        if (!new_with)
            return 0;
        *self = new_with(NULL);
        if (!(*self))
            return 0;
    }

    return W_CALL(*self,from_json)(buffer,endptr);
}
