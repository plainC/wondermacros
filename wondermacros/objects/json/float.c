#include <math.h>

int
json_float_to_string(float* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%g", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_float_from_string(const char* buffer, const char** endptr, float* self)
{
    float value = strtof(buffer, (char**) endptr);

    if (value == HUGE_VALF)
        return 1;

    *self = value;

    return 0;
}
