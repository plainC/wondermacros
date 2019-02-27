#include <stdlib.h>

struct object;
struct object_klass {
  struct
  {
    const char *name;
    size_t size;
    const char **property_name;
    const size_t *property_len;
    const size_t *property_offset;
    void *property_type;
  } meta;
  void (*free) (struct object* self);
  int (*to_json)(struct object* self, char* buffer, size_t size);
  int (*from_json)(struct object* self, const char* buffer, const char** endptr);
};

struct object {
    struct object_klass* klass;
};

int
json_object_to_string(struct object** self, char* buffer, size_t size)
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
json_object_from_string(const char* buffer, const char** endptr, struct object** self)
{
    /* The constructor of a class is responsible to create an initial empty object. */
    if (!(*self))
        return 0;

    return W_CALL(*self,from_json)(buffer,endptr);
}
