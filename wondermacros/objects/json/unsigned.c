#include <math.h>

int
json_unsigned_to_string(unsigned* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%u", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_unsigned_from_string(const char* buffer, const char** endptr, unsigned* self)
{
    unsigned long value = strtoul(buffer, (char**) endptr, 10);

    *self = value;

    return 0;
}
