int
json_string_to_string(char** self, char* buffer, size_t size)
{
    int len = strlen(*self);
    if (len+2 >= size)
        return -1;

    *buffer++ = '\"';
    strncpy(buffer, *self, len);
    buffer += len;
    *buffer++ = '\"';
    return len+2;
}

int
json_string_from_string(const char* buffer, const char** endptr, char** self)
{
    const char* p = buffer;

    if (*p != '\"')
        return 1;
    ++p;
    const char* start = p;
    int backslash = 0;
    while (*p && (*p != '\"' || backslash)) {
        if (*p == '\\')
            backslash = !backslash;
        ++p;
    }
    if (*p != '\"')
        return 1;
    *self = strndup(start, p-start);
    *endptr = p+1;

    return 0;
}


