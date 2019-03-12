#include <stdint.h>

int
json_unsigned64_to_string(uint64_t* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%llu", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_unsigned64_from_string(const char* buffer, const char** endptr, const char* type_name, uint64_t* self)
{
    unsigned long long value = strtoull(buffer, (char**) endptr, 10);

    *self = value;

    return 0;
}
