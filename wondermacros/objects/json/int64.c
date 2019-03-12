#include <stdint.h>

int
json_int64_to_string(int64_t* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%lld", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_int64_from_string(const char* buffer, const char** endptr, const char* type_name, int64_t* self)
{
    int64_t value = strtoll(buffer, (char**) endptr, 10);

    if (value == LLONG_MIN || value == LLONG_MAX)
        return 1;

    *self = value;

    return 0;
}
