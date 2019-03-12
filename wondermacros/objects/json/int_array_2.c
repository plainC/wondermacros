int
json_int_array_2_to_string(int* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "[%d,%d]", self[0], self[1]);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

#define SKIP_WS \
    while (isspace(*p)) \
        p++

#define ACCEPT(ch) \
    if (*p++ == (ch)) \
        {} \
    else \
        return 1

#define READ_INT \
    strtol(p, (char**) endptr, 10); \
    if (!(value == LONG_MIN || value == LONG_MAX)) \
        {p = *endptr;} \
    else \
        return 1

int
json_int_array_2_from_string(const char* buffer, const char** endptr, const char* type_name, int* self)
{
    const char* p = buffer;
    long value;

    ACCEPT('[');
    SKIP_WS;
    value = READ_INT;
    self[0] = value;
    SKIP_WS;
    ACCEPT(',');
    SKIP_WS;
    value = READ_INT;
    self[1] = value;
    SKIP_WS;
    ACCEPT(']');
    SKIP_WS;
    *endptr = p;

    return 0;
}

#undef SKIP_WS
#undef ACCEPT
#undef READ_INT


