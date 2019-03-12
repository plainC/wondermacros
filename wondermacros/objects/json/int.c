int
json_int_to_string(int* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%d", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_int_from_string(const char* buffer, const char** endptr, const char* type_name, int* self)
{
    long value = strtol(buffer, (char**) endptr, 10);

    if (value == LONG_MIN || value == LONG_MAX)
        return 1;

    *self = value;

    return 0;
}
