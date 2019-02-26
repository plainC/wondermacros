#include <math.h>

int
json_double_to_string(double* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%g", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_double_from_string(const char* buffer, const char** endptr, double* self)
{
    double value = strtod(buffer, (char**) endptr);

    if (value == HUGE_VAL)
        return 1;

    *self = value;

    return 0;
}
