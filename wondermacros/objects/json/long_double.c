#include <math.h>

int
json_long_double_to_string(long double* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%Lg", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_long_double_from_string(const char* buffer, const char** endptr, long double* self)
{
    long double value = strtold(buffer, (char**) endptr);

    if (value == HUGE_VALL)
        return 1;

    *self = value;

    return 0;
}
