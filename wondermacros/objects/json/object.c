#ifndef WDEBUG_EXPAND
# include <stdlib.h>
#endif

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
json_object_from_string(const char* buffer, const char** endptr, struct CLASS** self)
{
    /* The constructor of a class is responsible to create an initial empty object. */
    if (!(*self))
        return 0;

    return W_CALL(*self,from_json)(buffer,endptr);
}
